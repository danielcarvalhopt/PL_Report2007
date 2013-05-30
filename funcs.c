#include <stdio.h>
#include "report.h"

extern Report r;

#define OPEN(X) printf("<"); printf(#X); printf(">");
#define CLOSE(X) printf("</"); printf(#X); printf(">\n");
#define PRINT_HTML(X, TAG) OPEN(TAG) printf("%s",r.X); CLOSE(TAG)

void printHTML() {
	puts("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"><html><head><META http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">");
	PRINT_HTML(frontmatter.title,title);
	puts("</head><body>");
    printf("<hr><h3><u>Title:</u> ");PRINT_HTML(frontmatter.title, k);printf("</h3>");
    printf("<h3><u>Subtitle:</u> ");PRINT_HTML(frontmatter.subtitle,k);printf("</h3>");
    printAUTORES();
    printf("<h3><u>Date:</u></h3>");
    printDataHtml();
    printf("<hr><hr>");
    puts("</body></html>");
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


void initReport() {
	
	r.frontmatter.authors = g_array_new(FALSE,FALSE,sizeof(Author));
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