#include <glib.h>

typedef struct sAuthor
{
	char* name;
	char* number;
	char* mail;
} Author;

typedef struct sReport
{
	char* title;
	char* date;
	char* body;
	char* subtitle;
	GArray* authors;
} Report;

typedef struct sChapter
{
	char* title;
	GArray* elems;
};

typedef struct sParagraph
{
	char* text;
} Paragraph;

typedef struct sFloat
{
	char* text;	
} Float;

typedef union uElms
{
	Paragraph* paragraph;
	Float* fl;
} Elms;


void printHTML();
void printAUTORES();
void initReport();
