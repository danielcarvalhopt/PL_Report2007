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
%token <str> TEXT
%type <str> text

%%

Report: BEGIN_REPORT Title Body END_REPORT  ;

Title: BEGIN_TITLE text END_TITLE { r.title = strdup($2);};

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