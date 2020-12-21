all: clean ada

ada: ada.tab.c lex.yy.c
	g++ lex.yy.c ada.tab.c -o ada

lex.yy.c:
	flex ../parser/ada.flex

ada.tab.c:
	bison -d ../parser/ada.y

clean:
	rm -rf *.o *.h *.c ada