#include <stdio.h>
#include "report.h"

extern Report r;

void printHTML_title(){
    puts("<title>");
    puts(r.title);
    puts("</title>");
}

void printHTML(){
    puts("<html>");
    printHTML_title();
    puts("</html>");
}