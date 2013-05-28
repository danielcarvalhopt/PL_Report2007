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
	Author author;
} Report;



void printHTML();
void printAUTORES();
