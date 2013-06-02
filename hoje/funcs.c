#include <stdio.h>
#include "report.h"

extern Report r;
/*
#define OPEN(X) printf("<"); printf(#X); printf(">");
#define CLOSE(X) printf("</"); printf(#X); printf(">\n");
#define PRINT_HTML(X, TAG) OPEN(TAG) printf("%s",r.X); CLOSE(TAG)

void printHTML() {
    
    puts("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"><html><head><META http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">");
    printFrontMatter();
    puts("</body></html>");
}

void printParagraph(Paragraph p) {
    puts(p.texto);
    puts("\n");
}

void printFrontMatter() {
    PRINT_HTML(frontmatter.title,title);
    puts("</head><body>");
    printf("<hr><h3><u>Title:</u> ");PRINT_HTML(frontmatter.title, k);printf("</h3>");
    printf("<h3><u>Subtitle:</u> ");PRINT_HTML(frontmatter.subtitle,k);printf("</h3>");
    printAUTORES();
    printf("<h3><u>Date:</u></h3>");
    if (r.frontmatter.date == NULL) 
        printDataHtml();
    else 
        {
            PRINT_HTML(frontmatter.date,k);
        }
    printf("<hr>");
    printf("<h1>Abstract</h1>");
    int i;
    Paragraph *p;
    for (i = 0; i <r.frontmatter.abstract.paragraphs->len ; i++) {
        p = &g_array_index(r.frontmatter.abstract.paragraphs,Paragraph,i);
        printParagraph(*p);
    }
    printf("\n");
}


void printAUTORES() {
	Author *a; 
	int i;
	
	printf("<h3><u>Authors:</u></h3>");
    printf("<table border=\"2\"><tr><td><b>Name</b></td><td><b>Number</b></td><td><b>Email</b></td></tr>");
    for (i = 0; i <r.frontmatter.authors->len ; i++) {
    	a = &g_array_index(r.frontmatter.authors,Author,i);
    	printf("<tr>");
    	printf("<td>%s</td>",a->name);
    	printf("<td>%s</td>",a->number);
    	printf("<td>%s</td>",a->mail);
    	printf("</tr>");
	}
    printf("</table>");
}   

void printDataHtml() {
printf("<script>");
printf("var mydate=new Date()\n");
printf("var year=mydate.getYear()\n");
printf("if (year < 1000)\n");
printf("year+=1900\n");
printf("var day=mydate.getDay()\n");
printf("var month=mydate.getMonth()\n");
printf("var daym=mydate.getDate()\n");
printf("if (daym<10)\n");
printf("daym=\"0\"+daym\n");
printf("var dayarray=new\n");
printf("Array(\"Domingo\",\"Segunda-Feira\",\"Terça-Feira\",\"Quarta-Feira\",\"Quinta-Feira\",\"Sexta-Feira\",\"Sábado\")\n");
printf("var montharray=new\n");
printf("Array(\"Janeiro\",\"Fevereiro\",\"Março\",\"Abril\",\"Maio\",\"Junho\",\"Julho\",\"Agosto\",\"Setembro\",\"Outubro\",\"Novembro\",\"Dezembro\")\n");
printf("document.write(\"\"+dayarray[day]+\", \"+daym+\" de \"+montharray[month]+\" de \"+year+\"</b></font></small>\")\n");
printf("</script>\n");
}

*/
void initAbstract(){r.frontmatter.abstract.paragraphs = g_array_new(FALSE,FALSE,sizeof(Paragraph_Elem));}
void initKeywords(){r.frontmatter.abstract.keywords = g_array_new(FALSE,FALSE,sizeof(char*));}
void initAuthors(){r.frontmatter.authors = g_array_new(FALSE,FALSE,sizeof(Author));}
void initAknowls(){r.frontmatter.abstract.abstract = g_array_new(FALSE,FALSE,sizeof(Paragraph));}
void initBody(){r.body.chapters = g_array_new(FALSE,FALSE,sizeof(Chapter));}

Paragraph initParagraph(Paragraph p){p.prg_elem= g_array_new(FALSE, FALSE, sizeof(P));return p;} 
Chapter initChapter(Chapter c){ c.elems =g_array_new(FALSE, FALSE, sizeof(Elem));return c;}
Table initTable(Table t){ t.rows =g_array_new(FALSE, FALSE, sizeof(Row)); t.size=0; return t;}

//Table initRow(Table t){ =g_array_new(FALSE, FALSE, sizeof()); t.size++;return t;}

Section initSection(Section s){ s.elems=g_array_new(FALSE, FALSE, sizeof(SecElem));return s;}
List initList(List l){ l.items =g_array_new(FALSE, FALSE, sizeof(char*));return l;}

void initReport() {
	initAbstract();
    initKeywords();
    initAuthors();
    initAknowls();
    initBody();
}
