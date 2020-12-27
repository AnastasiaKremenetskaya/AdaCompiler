all: clean adalp

adalp: ada.tab.o lex.yy.o
	g++ lex.yy.o ada.tab.o -o adalp

ada.tab.o: ada.tab.c tree_nodes.h
	g++ -c ada.tab.c

ada.tab.c:
	bison -d ../parser/ada.y

lexer: lex.yy.o
	g++ lex.yy.o

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c:
		flex ../lexer/ada.yy

#ada: ada.tab.c lex.yy.c
	#//g++ lex.yy.c ada.tab.c -o ada

tree_nodes.h:
	cp ../parser/tree_nodes.h ./

grammar.tab.h:
	cp ../lexer/grammar.tab.h ./

clean:
	rm -rf *.o *.h *.c adalp lexer
