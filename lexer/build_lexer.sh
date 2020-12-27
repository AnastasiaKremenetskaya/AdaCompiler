#!/bin/bash
#flex ada.yy #generates lex.yy.c
#g++ -c ../build/lex.yy.c -v -stdlib=libstdc++ #generates lex.yy.o
gcc  ada.tab.c lex.yy.c -o lexer -g #-stdlib=libstdc++