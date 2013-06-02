#include <glib.h>

/**/
typedef struct sParagraph
{
	GArray* prg_elem;
} Paragraph;

typedef struct sFrontMatter {
	char* title;
	char* subtitle;
	GArray* authors;	
	char* date;
	char* institution
	GArray* keywords;	
	Abstract abstract;
	Aknowls aknow;
	int index;
	int figures_index;
	int tables_index;
} FrontMatter;
/**/



typedef struct sAbstract
{
	GArray* paragraphs;
} Abstract;

typedef struct sAknowledgements
{
	GArray* paragraphs;
} Aknowls;

typedef struct sAuthor
{
	char* name;
	char* number;
	char* mail;
} Author;


typedef struct sBody
{
	GArray* chapters;
} Body;


typedef struct sChapter
{
	char* title;
	GArray* elems;
} Chapter;

typedef struct sFigure
{
	char* caption;
	char* path;
	char* format;
	float size;
} Figure;

typedef struct sTable
{
	char* caption;
	GArray* rows;
} Table;

typedef struct sRow
{
	GArray * cells;
} Row;

typedef struct sCell
{
	char * text;
} Cell;

typedef struct sSection
{
	char* title;
	GArray* elems;
} Section;


typedef struct sList
{
	GArray* items;
}List;


typedef union uElems
{
	Paragraph paragraph;
	Figure fig;
	Table table;
	List list;
	Section section;
	char* codeblock;
	char* summary;
} Elem;

typedef struct sFootnote{
	char* text;
} Footnote;
typedef struct sRef{
	char* text;
} Ref;
typedef struct sXref{
	char* text;
} Xref;
typedef struct sCitref{
	char* text;
} Citref;
typedef struct sIterm{
	char* text;
} Iterm;
typedef struct sBold{
	char* text;
} Bold;
typedef struct sItalic{
	char* text;
} Italic;
typedef struct sUnderline{
	char* text;
} Underline;
typedef struct sInlineCode{
	char* text;
} InlineCode;
typedef struct sAcronym{
	char* text;
} Acronym;

typedef union uParagraphElems
{
	char* text;
	Footnote footnote;
	Ref ref;
	Xref xref;
	Citref citref;
	Iterm iterm;
	Bold bold;
	Italic italic;
	Underline underline;
	InlineCode inlineCode;
	Acronym acronym;
} Paragraph_Elems;

typedef union uElemsSec
{
	Paragraph paragraph;
	Figure fig;
	Table table;
	List list;
	char* codeblock;
	char* summary;
} ElemSec;

typedef struct sBackMatter
{
	GArray* paragraphs;
} BackMatter;

typedef struct sReport
{
	FrontMatter frontmatter;
	Body body;
	BackMatter backMatter;
} Report;

/* BackMatter */



/*Procedures*/
void printHTML();
void printAUTORES();
void initReport();
void printDataHtml();
void printFrontMatter();
void printParapraph(Paragraph);
