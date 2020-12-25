#!/bin/bash
flex ada.yy
g++ -c lex.yy.c
g++ lex.yy.o -o lexer
