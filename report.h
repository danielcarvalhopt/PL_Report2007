#include <glib.h>

typedef struct sAuthor
{
	char* name;
	char* number;
	char* mail;
} Author;

typedef struct sAbstract
{
	GArray* paragraphs;
} Abstract;

typedef struct sAknowledgements
{
	GArray* paragraphs;
} Aknowls;

typedef struct sFrontMatter {
	char* title;
	char* subtitle;
	GArray* authors;	
	char* date;
	Abstract abstract;
	Aknowls aknow;
} FrontMatter;

typedef struct sChapter
{
	char* title;
	GArray* elems;
} Chapter;

typedef struct sParagraph
{
	char* text;
} Paragraph;

typedef struct sFloat
{
	char* text;	
} Float;

typedef struct sSection
{
	char* title;
	GArray* elems;
} Section;

typedef union uElms
{
	Paragraph paragraph;
	Float fl;
	Section section;
} Elms;

typedef struct sBody
{
	GArray* chapters;
} Body;

typedef struct sReport
{
	FrontMatter frontmatter;
	Body body;
} Report;



void printHTML();
void printAUTORES();
void initReport();
void printDataHtml();
