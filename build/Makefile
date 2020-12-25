all: clean adalp
	
adalp: ada.tab.o lex.yy.o
	g++ lex.yy.o ada.tab.o -o adalp

ada.tab.o: ada.tab.c tree_nodes.h
	g++ -c ada.tab.c

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

ada.tab.c:
		bison -d ../parser/ada.y

lex.yy.c:
		flex ../lexer/ada.yy

ada: ada.tab.c lex.yy.c
	g++ lex.yy.c ada.tab.c -o ada

tree_nodes.h:
	cp ../parser/tree_nodes.h ./

clean:
	rm -rf *.o *.h *.c ada
