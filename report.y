%{
#include <stdio.h>
#include "report.h"
#include <string.h>

Report r;
int yyerror(char *s);
extern FILE* yyin;
extern FILE* yyout;


%}

%union {
    char *str;
}

%token BEGIN_REPORT
%token END_REPORT
%token BEGIN_BODY
%token END_BODY
%token BEGIN_TITLE
%token END_TITLE
%token BEGIN_FM
%token END_FM
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

%token <str> TEXT
%type <str> text

%%

Report: BEGIN_REPORT FrontMatter Body END_REPORT ;

FrontMatter: BEGIN_FM Title Subtitle Authors Date END_FM
	| ;

Title: BEGIN_TITLE text END_TITLE { r.title = strdup($2);};

Subtitle: BEGIN_SUBTITLE text END_SUBTITLE { r.subtitle = strdup($2);};

Author: BEGIN_AUTHOR Name Number Mail END_AUTHOR ;

Authors: Author 
	| Authors Author ;

Name: BEGIN_NAME text END_NAME { r.author.name = strdup($2);};

Number: BEGIN_NUMBER text END_NUMBER { r.author.number = strdup($2);} 
	| ;	

Mail: BEGIN_MAIL text END_MAIL { r.author.mail = strdup($2);} 
	|;


Date: BEGIN_DATE text END_DATE { r.date = strdup($2);};

Body: BEGIN_BODY text END_BODY {r.body = strdup($2);}
    | ;


text: TEXT {$$=$1;};

%%

int yyerror(char *s){fprintf(stderr,"%s\n",s);}

int main(int argc, char *argv[]){ 
    if(argc > 1) yyin = fopen(argv[1],"r");
    else perror("Insira pelo menos o path para um ficheiro a ser convertido\n");
    yyout = fopen("report.html","w+");
    yyparse();
    printHTML();
    fclose(yyin);
}