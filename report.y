%{
#include <stdio.h>
#include "report.h"
#include <string.h>

Report r;
Author a;
int yyerror(char *s);
extern FILE* yyin;
extern FILE* yyout;


%}

%union {
    char *str;
}

%token BEGIN_REPORT
%token END_REPORT
%token BEGIN_FM
%token END_FM
%token BEGIN_TITLE
%token END_TITLE
%token BEGIN_SUBTITLE
%token END_SUBTITLE
%token BEGIN_DATE
%token END_DATE
%token BEGIN_AUTHOR
%token END_AUTHOR
%token BEGIN_NAME
%token END_NAME
%token BEGIN_NUMBER
%token END_NUMBER
%token BEGIN_MAIL
%token END_MAIL
%token BEGIN_ABS
%token END_ABS
%token BEGIN_AKN
%token END_AKN

%token BEGIN_BODY
%token END_BODY
%token BEGIN_CHAP
%token END_CHAP
%token BEGIN_PARA
%token END_PARA

%token <str> TEXT
%type <str> text

%%

Report: BEGIN_REPORT FrontMatter Body END_REPORT ;

FrontMatter: BEGIN_FM Title Subtitle Authors Date Abstract Aknow END_FM
	| ;
Title: BEGIN_TITLE text END_TITLE   { r.frontmatter.title = strdup($2);};
Subtitle: BEGIN_SUBTITLE text END_SUBTITLE      { r.frontmatter.subtitle = strdup($2);};
Author: BEGIN_AUTHOR Name Number Mail END_AUTHOR    {g_array_append_val(r.frontmatter.authors,a);};
Authors: Author 
	| Authors Author ;
Name: BEGIN_NAME text END_NAME  { a.name = strdup($2);};
Number: BEGIN_NUMBER text END_NUMBER    { a.number = strdup($2);} 
	| ;	
Mail: BEGIN_MAIL text END_MAIL  { a.mail = strdup($2);} 
	|;
Date: BEGIN_DATE text END_DATE  { r.frontmatter.date = strdup($2);};

Paragraph: BEGIN_PARA text END_PARA ;

Paragraphs: Paragraph 
    | Paragraphs Paragraph;

Abstract: BEGIN_ABS Paragraphs END_ABS ;

Aknow: BEGIN_AKN Paragraphs END_AKN

    | ;
Body: BEGIN_BODY Chapters END_BODY
    | ;

Chapter: BEGIN_CHAP Title END_CHAP ;
Chapters: Chapter
    | Chapters Chapter;

text: TEXT {$$=$1;};

%%

int yyerror(char *s){fprintf(stderr,"%s\n",s);}

int main(int argc, char *argv[]){ 
    if(argc > 1) {
    	yyin = fopen(argv[1],"r");
    	yyout = fopen("report.html","w+");
    	initReport();
    	yyparse();
    	printHTML();
    	fclose(yyin);
    }
    else {
    	initReport();
    	yyparse();
    	printHTML();
    	perror("Insira pelo menos o path para um ficheiro a ser convertido\n");
   	}
   return 0;
}