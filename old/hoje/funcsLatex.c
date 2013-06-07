#include <stdio.h>
#include "report.h"

void printDATE() {
fprintf(out,"\\date{\\today}");
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