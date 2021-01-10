all: clean adalp

adalp: ada.tab.o lex.yy.o
	clang lex.yy.o ada.tab.o -o adalp

ada.tab.o: ada.tab.c tree_nodes.h
	clang -c ada.tab.c

ada.tab.c:
	bison -d --report=state ../parser/ada.y

lex.yy.o: lex.yy.c
	clang++ -c lex.yy.c

lex.yy.c:
	flex ../lexer/ada.yy

tree_nodes.h:
	cp ../parser/tree_nodes.h ./

semantic_tables.h:
	cp ../parser/semantic_tables.h ./

clean:
	rm -rf *.o *.h *.c adalp lexer
