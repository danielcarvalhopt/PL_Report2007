NAME = report
sourceFiles = lex.yy.c y.tab.c y.tab.h
EXE = report2007

compile: $(NAME).fl $(NAME).y
	flex $(NAME).fl
	yacc -d $(NAME).y 
	gcc $(sourceFiles) -o $(EXE)

clean: rm $(sourceFiles)

