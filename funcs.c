#include <stdio.h>
#include "report.h"

extern Report r;

#define OPEN(X) printf("<"); printf(#X); printf(">");
#define CLOSE(X) printf("</"); printf(#X); printf(">\n");
#define PRINT_HTML(X, TAG) OPEN(TAG) printf("%s",r.X); CLOSE(TAG)

void printHTML(){
	puts("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"><html><head><META http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">");
	PRINT_HTML(title,title);
	puts("</head><body>");
    printf("<hr><h3><u>Title:</u> ");PRINT_HTML(title, k);printf("</h3>");
    printf("<h3><u>Subtitle:</u> ");PRINT_HTML(subtitle,k);printf("</h3>");
    printAUTORES();
    printf("<h3><u>Date:</u></h3>");
    PRINT_HTML(date,h3);
    printf("<hr><hr>");
    PRINT_HTML(body, tag_name);
    
  
    puts("</body></html>");
}

void printAUTORES() {
	Author *a; 
	int i;
	
	printf("<h3><u>Authors:</u></h3>");
    printf("<table border=\"2\"><tr><td><b>Name</b></td><td><b>Number</b></td><td><b>Email</b></td></tr>");
    for (i = 0; i <r.authors->len ; i++)
    {
    	a = &g_array_index(r.authors,Author,i);
    	printf("<tr>");
    	printf("<td>%s</td>",a->name);
    	printf("<td>%s</td>",a->number);
    	printf("<td>%s</td>",a->mail);
    	printf("</tr>");
	}
    printf("</table>");

}


void initReport() {
	
	r.authors = g_array_new(FALSE,FALSE,sizeof(Author));

}