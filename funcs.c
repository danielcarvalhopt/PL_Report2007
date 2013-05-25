#include <stdio.h>
#include "report.h"

extern Report r;

#define OPEN(X) printf("<"); printf(#X); printf(">");
#define CLOSE(X) printf("</"); printf(#X); printf(">\n");
#define PRINT_HTML(X, TAG) OPEN(TAG) printf("%s",r.X); CLOSE(TAG)

void printHTML(){
    puts("<html>");
    PRINT_HTML(title, title);
    PRINT_HTML(body, tag_name);
    puts("</html>");
}