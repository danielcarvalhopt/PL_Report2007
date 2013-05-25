NAME = report
generatedFiles = lex.yy.c y.tab.c y.tab.h
sourceFiles = funcs.c report.h
EXEC = report2007
T=2

compile: $(NAME).fl $(NAME).y
	flex $(NAME).fl
	yacc -d $(NAME).y 
	gcc $(sourceFiles) $(generatedFiles) -o $(EXEC)

clean: $(generatedFiles) $(EXEC)
	rm $(generatedFiles) $(EXEC)

test: $(EXEC)
	./$(EXEC) testes/t$(T).txt

