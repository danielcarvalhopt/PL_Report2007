#include <glib.h>

/**/

#define FIGURE 1
#define TABLE 2
#define LIST 3
#define SECTION 4
#define CODEBLOCK 5
#define SUMMARY 6

#define TEXT 7
#define FOOTNOTE 8
#define REF 9
#define CITREF 10
#define ITERM 11
#define BOLD 12
#define ITALIC 13
#define UNDERLINE 14
#define INLINECODE 15
#define ACRONYM 16

typedef struct sAbstract
{
	GArray* paragraphs;
} Abstract;

typedef struct sAknowledgements
{
	GArray* paragraphs;
} Aknowls;

typedef struct sParagraph
{
	GArray* prg_elem;
} Paragraph;

typedef struct sFrontMatter {
	char* title;
	char* subtitle;
	GArray* authors;	
	char* date;
	char* institution;
	GArray* keywords;	
	Abstract abstract;
	Aknowls aknow;
	int index;
	int figures_index;
	int tables_index;
} FrontMatter;
/**/

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
	int size;
} Table;

typedef struct sRow
{
	GArray * cells;
	int size;
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
} ElemU;

typedef struct sElem
{
	ElemU e;
	int id;
}Elem;

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

typedef union uParagraphElem
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
} Paragraph_ElemU;

typedef struct sParagraphElem
{
	Paragraph_ElemU e;
	int id;
}Paragraph_Elem;

typedef union uElemsSec
{
	Paragraph paragraph;
	Figure fig;
	Table table;
	List list;
	char* codeblock;
	char* summary;
} SecElemU;

typedef struct sElemsSec
{
	SecElemU e;
	int id;
}SecElem;

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




/*Initialization procedures*/
void initReport();
void initAbstract();
void initKeywords();
void initAuthors();
void initAknowls();
void initBody();
Chapter initChapter(Chapter c);
Table initTable(Table t);
Table initRow(Table t);
Section initSection(Section s);
List initList(List s);

/*Printing procedures*/
void printHTML();
void printAUTORES();
void printDataHtml();
void printFrontMatter();
void printParapraph(Paragraph);
