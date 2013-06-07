#include <stdio.h>
#include "report.h"

extern Report r;
FILE* out;
int footnotes;
/*
#define OPEN(X) printf("<"); printf(#X); printf(">");
#define CLOSE(X) printf("</"); printf(#X); printf(">\n");
#define PRINT_HTML(X, TAG) OPEN(TAG) printf("%s",r.X); CLOSE(TAG)
*/

void printAUTORES() {
	Author *a; 
	int i;
	
	fprintf(out,"<h3><u>Authors:</u></h3>");
    fprintf(out,"<table border=\"2\" class=\"selectorsReview\"><thead><tr><th>Name</th><th>Number</th><th>Email</th></tr><thead><tbody>");
    for (i = 0; i <r.frontmatter.authors->len ; i++) {
    	a = &g_array_index(r.frontmatter.authors,Author,i);
    	fprintf(out,"<tr>");
    	fprintf(out,"<td>%s</td>",a->name);
    	fprintf(out,"<td>%s</td>",a->number);
    	fprintf(out,"<td>%s</td>",a->mail);
    	fprintf(out,"</tr>");
	}
    fprintf(out,"</tbody></table>");
}   

void printDATE() {
fprintf(out,"<script>");
fprintf(out,"var mydate=new Date()\n");
fprintf(out,"var year=mydate.getYear()\n");
fprintf(out,"if (year < 1000)\n");
fprintf(out,"year+=1900\n");
fprintf(out,"var day=mydate.getDay()\n");
fprintf(out,"var month=mydate.getMonth()\n");
fprintf(out,"var daym=mydate.getDate()\n");
fprintf(out,"if (daym<10)\n");
fprintf(out,"daym=\"0\"+daym\n");
fprintf(out,"var dayarray=new\n");
fprintf(out,"Array(\"Domingo\",\"Segunda-Feira\",\"Terça-Feira\",\"Quarta-Feira\",\"Quinta-Feira\",\"Sexta-Feira\",\"Sábado\")\n");
fprintf(out,"var montharray=new\n");
fprintf(out,"Array(\"Janeiro\",\"Fevereiro\",\"Março\",\"Abril\",\"Maio\",\"Junho\",\"Julho\",\"Agosto\",\"Setembro\",\"Outubro\",\"Novembro\",\"Dezembro\")\n");
fprintf(out,"document.write(\"\"+dayarray[day]+\", \"+daym+\" de \"+montharray[month]+\" de \"+year+\"</b></font></small>\")\n");
fprintf(out,"</script>\n");
}

void printABSTRACT() {
    fprintf(out,"<div>");
    fprintf(out,"<hr>");
    fprintf(out,"<h1>Abstract</h1>");
    int i;
    Paragraph *p;
    for (i = 0; i <r.frontmatter.abstract.paragraphs->len ; i++) {
        p = &g_array_index(r.frontmatter.abstract.paragraphs,Paragraph,i);
        printPARAGRAPH(*p);
    }
    fprintf(out, "</div>" );
}

void printAKNOW() {
    fprintf(out,"<hr>");
    fprintf(out,"<h1>Aknowledgements</h1>");
    int i;
    Paragraph *p;
    for (i = 0; i <r.frontmatter.aknow.paragraphs->len ; i++) {
        p = &g_array_index(r.frontmatter.aknow.paragraphs,Paragraph,i);
        printPARAGRAPH(*p);
    }

}

void printCHAPTER(Chapter c){
    fprintf(out,"<hr>");
    fprintf(out,"<h1><a name=\"%s\">%s</a></h1>",c.title,c.title);
    Elem* elem;
    int i;
    for (i = 0; i <c.elems->len ; i++) {
        elem = &g_array_index(c.elems,Elem,i);
        switch(elem->id){
            case PARAGRAPH: 
                printPARAGRAPH(elem->e.paragraph);
            break;
            case FIGURE: 
                printFIGURE(elem->e.fig);
            break;
            case TABLE: 
                printTABLE(elem->e.table);
            break;  
            case LIST: 
                printLIST(elem->e.list);
            break;
            case SECTION: 
                printSECTION(elem->e.section);
            break;
            case CODEBLOCK: 
                printCODEBLOCK(elem->e.codeblock);
            break;
            case SUMMARY: 
                printSUMMARY(elem->e.summary);
            break;
        }

    }
}
void printFRONTMATTER() {
    fprintf(out,"<hr><h1>%s</h1>",r.frontmatter.title);
    fprintf(out,"<h2>%s</h2>",r.frontmatter.subtitle);
    printAUTORES();
    fprintf(out,"<h3><u>Date: </u></h3>");
    if (r.frontmatter.date == NULL) 
        printDATE();
    else 
        {
            fprintf(out,"%s",r.frontmatter.date);
        }
    fprintf(out,"<h3><u>Institution:</u> %s</h3>",r.frontmatter.institution);
    int i;
    char** s;
    fprintf(out,"<div style=\"text-align:center;\">");
    for (i = 0; i < r.frontmatter.keywords->len; i++) {
    s = &g_array_index(r.frontmatter.keywords,char*,i);
        fprintf(out,"- %s -",*s);
    }
    fprintf(out,"</div>");
    printABSTRACT();
    printAKNOW();
    printINDEX();
    printINDEXFIG();
    printINDEXTAB();
    fprintf(out,"<hr>");
}

void printPARAGRAPH(Paragraph p) {
    Paragraph_Elem* ph;
    int i;
    fprintf(out,"<p>");
    for (i = 0; i <p.prg_elem->len ; i++) {
    ph = &g_array_index(p.prg_elem,Paragraph_Elem,i);
    switch(ph->id){
        case TEXTO: 
            printTEXTO(ph->e.text);
        break;
        case FOOTNOTE: 
            printFOOTNOTE(ph->e.footnote);
        break;  
        case REF: 
             printREF(ph->e.ref);
        break;
        case XREF: 
             printXREF(ph->e.xref);
        break;
        case CITREF: 
            printCITREF(ph->e.citref);
        break;
        case ITERM: 
            printITERM(ph->e.iterm);
        break;
         case BOLD: 
            printBOLD(ph->e.bold);
        break;
        case ITALIC: 
            printITALIC(ph->e.italic);
        break;
        case UNDERLINE: 
            printUNDERLINE(ph->e.underline);
        break;
        case INLINECODE: 
            printINLINECODE(ph->e.inlineCode);
        break;

        case ACRONYM: 
            printACRONYM(ph->e.acronym);
        break;
        }
    }
    fprintf(out,"</p>");
}

void printFIGURE(Figure f){
    fprintf(out, "<div style=\"text-align:center;\">");
    fprintf(out,"<figure><img src=\"%s\"><figcaption><a name=\"%s\">%s</a></figcaption></figure>",f.path,f.caption,f.caption);
    fprintf(out, "</div>");
}

void printTABLE(Table t){
    fprintf(out,"<table border=2 class=\"selectorsReview\" style=\"margin-left:auto; margin-right:auto; padding-top:25px;padding-bottom:25px;\">");
    int i;
    Row* r;
    for (i = 0; i <t.rows->len ; i++) {
    r = &g_array_index(t.rows,Row,i);
    printROW(*r);
    }
    fprintf(out,"<caption><a name=\"%s\">%s</a></caption>",t.caption,t.caption);
    fprintf(out,"</table>");
}

void printROW(Row r){
    int i;
    Cell* c;
    fprintf(out,"<tr>");
    for (i = 0; i <r.cells->len ; i++) {
    c = &g_array_index(r.cells,Cell,i);
    printCELL(*c);
    }
    fprintf(out,"</tr>");
}

void printCELL(Cell c){
    fprintf(out, "<td>%s</td>",c.text);
}


void printSECTION(Section c){
    fprintf(out,"<hr>");
    fprintf(out,"<h2>%s</h2>",c.title);
    Elem* elem;
    int i;
    for (i = 0; i <c.elems->len ; i++) {
        elem = &g_array_index(c.elems,Elem,i);
        switch(elem->id){
            case FIGURE: 
                printFIGURE(elem->e.fig);
            break;
            case TABLE: 
                printTABLE(elem->e.table);
            break;  
            case LIST: 
                printLIST(elem->e.list);
            break;
            case CODEBLOCK: 
                printCODEBLOCK(elem->e.codeblock);
            break;
            case SUMMARY: 
                printSUMMARY(elem->e.summary);
            break;
        }

    }
}

void printLIST(List list){
    fprintf(out,"<ul>");
    int i;
    char** s;
    for (i = 0; i < list.items->len; i++) {
    s = &g_array_index(list.items,char*,i);
        fprintf(out,"<li>%s</li>",*s);
        
    }
    fprintf(out,"</ul>");
}

void printCODEBLOCK(char* t){
    fprintf(out,"<div class=\"example\"><p><pre>%s</pre></p></div>",t);
}

void printSUMMARY(char* t){
    fprintf(out,"<p style=\"text-align: center;\">%s</p>",t);
}

void printTEXTO(char* t){
    fprintf(out, " %s ",t);
}

void printFOOTNOTE(Footnote fn){

    fprintf(out,"<sup><a href=\"#fn%d\" id=\"ref1\">%d</a></sup>",footnotes,footnotes);
    fprintf(out,"<sup id=\"fn%d\">%d. [%s]<a href=\"#ref%d\" title=\"Jump back to footnote %d in the text.\">↩</a></sup>",footnotes,footnotes,fn.text,footnotes,footnotes);
    footnotes++;
}

void printREF(Ref r){
    fprintf(out,"<a href=http://%s>%s</a>",r.text,r.text);
}

void printXREF(Xref xr){
    fprintf(out,"<a href=\"%s\">%s</a>",xr.text,xr.text);
}

void printCITREF(Citref ct){
    fprintf(out,"<a href=\"%s\">%s</a>",ct.text,ct.text);
}

void printITERM(Iterm i){
    fprintf(out,"<a href=\"%s\">%s</a>",i.text,i.text);
}

void printBOLD(Bold b){
    fprintf(out,"<b>%s</b>",b.text);
}

void printITALIC(Italic i){
    fprintf(out,"<i>%s</i>",i.text);
}

void printUNDERLINE(Underline un){
    fprintf(out,"<u>%s</u>",un.text);
}

void printINLINECODE(InlineCode in){
    fprintf(out,"<u>%s</u>",in.text);
}

void printACRONYM(Acronym a){
    fprintf(out,"<acronym title= \"%s\">%s </acronym>",a.text,a.text);
}

void printBODY(){
    int i;
    Chapter *c;
    for (i = 0; i <r.body.chapters->len; i++) {
    c = &g_array_index(r.body.chapters,Chapter,i);
    printCHAPTER(*c);     
    }
}

void printBACKMATTER(){
    fprintf(out,"<hr>");
    fprintf(out,"<hr>");
    fprintf(out,"<h2>Epilogue</h2>");
    int i;
    Paragraph *p;
    for (i = 0; i <r.backMatter.paragraphs->len ; i++) {
        p = &g_array_index(r.backMatter.paragraphs,Paragraph,i);
        printPARAGRAPH(*p);
    }


}

void printINDEX() {
    if(r.frontmatter.index) {
    fprintf(out,"<hr>");
    fprintf(out,"<h2>Table of Contents</h2>");
    int i;
    Chapter *c;
        for (i = 0; i <r.body.chapters->len; i++) {
            c = &g_array_index(r.body.chapters,Chapter,i);
            fprintf(out,"<p><a href=\"#%s\">%s<a/></p>\n",c->title,c->title);     
        }
    }
}

void printINDEXFIG() {
    if(r.frontmatter.figures_index) {
    fprintf(out,"<hr>");
    fprintf(out,"<h2>Index of Figures</h2>");
    Chapter* c;
    Elem* elem;
    int i,j;

        for (i = 0; i <r.body.chapters->len; i++) {
            c = &g_array_index(r.body.chapters,Chapter,i);    
                for (j = 0; j <c->elems->len ; j++) {
                    elem = &g_array_index(c->elems,Elem,j);
                    if(elem->id == FIGURE){
                    fprintf(out,"<p><a href=\"#%s\">%s<a/></p>",elem->e.fig.caption,elem->e.fig.caption);     
                    }
                }

        }   
    }
}   


void printINDEXTAB() {
    if(r.frontmatter.tables_index) {
    fprintf(out,"<hr>");
    fprintf(out,"<h2>Index of Tables</h2>");
    Chapter* c;
    Elem* elem;
    int i,j;

        for (i = 0; i <r.body.chapters->len; i++) {
            c = &g_array_index(r.body.chapters,Chapter,i);    
                for (j = 0; j <c->elems->len ; j++) {
                    elem = &g_array_index(c->elems,Elem,j);
                    if(elem->id == TABLE){
                    fprintf(out,"<p><a href=\"#%s\">%s<a/></p>",elem->e.fig.caption,elem->e.fig.caption);     
                    }
                }

        }   
    }

}

void printREPORT(FILE* f){
    footnotes=0;
    out = f;
    fprintf(out,"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"><html><head><META http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">");
    fprintf(out, "<title>%s</title><link href=\"./css/default.css\" rel=\"stylesheet\" type=\"text/css\"><link href=\"./css/W3C-REC.css\" rel=\"stylesheet\" type=\"text/css\"> <style type=\"text/css\"></style><script type=\"text/javascript\" src=\"chrome-extension://bfbmjmiodbnnpllbbbfblcplfjjepjdn/js/injected.js\"></script></head><body>",r.frontmatter.title);
    //fprintf(out,"<p><img style=\"text-align:center;\" alt=\"W3C\" height=\"48\" src=\"./images/icon.png\" width=\"72\">");
    printFRONTMATTER();
    printBODY();
    printBACKMATTER();
    fprintf(out,"</body></html>");
}

void printReportLatex(FILE* f){
    footnotes=0;
    out = f;
    fprintf(out,"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"><html><head><META http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">");
    fprintf(out, "<title>%s</title><link href=\"./css/default.css\" rel=\"stylesheet\" type=\"text/css\"><link href=\"./css/W3C-REC.css\" rel=\"stylesheet\" type=\"text/css\"> <style type=\"text/css\"></style><script type=\"text/javascript\" src=\"chrome-extension://bfbmjmiodbnnpllbbbfblcplfjjepjdn/js/injected.js\"></script></head><body>",r.frontmatter.title);
    //fprintf(out,"<p><img style=\"text-align:center;\" alt=\"W3C\" height=\"48\" src=\"./images/icon.png\" width=\"72\">");
    printFRONTMATTER();
    printBODY();
    printBACKMATTER();
    fprintf(out,"</body></html>");


}

void initAbstract(){r.frontmatter.abstract.paragraphs = g_array_new(FALSE,FALSE,sizeof(Paragraph_Elem));}
void initKeywords(){r.frontmatter.keywords = g_array_new(FALSE,FALSE,sizeof(char*));}
void initAuthors(){r.frontmatter.authors = g_array_new(FALSE,FALSE,sizeof(Author));}
void initAknowls(){r.frontmatter.aknow.paragraphs = g_array_new(FALSE,FALSE,sizeof(Paragraph));}
void initBody(){r.body.chapters = g_array_new(FALSE,FALSE,sizeof(Chapter));}

Paragraph initParagraph(Paragraph p){p.prg_elem= g_array_new(FALSE, FALSE, sizeof(Paragraph_Elem));return p;} 
Chapter initChapter(Chapter c){ c.elems =g_array_new(FALSE, FALSE, sizeof(Elem));return c;}
Table initTable(Table t){ t.rows =g_array_new(FALSE, FALSE, sizeof(Row)); return t;}
Row initRow(Row r){ r.cells = g_array_new(FALSE, FALSE, sizeof(Cell)); ;return r;}
Section initSection(Section s){ s.elems=g_array_new(FALSE, FALSE, sizeof(SecElem));return s;}
List initList(List l){ l.items =g_array_new(FALSE, FALSE, sizeof(char*));return l;}

void initReport() {
	initAbstract();
    initKeywords();
    initAuthors();
    initAknowls();
    initBody();
}
