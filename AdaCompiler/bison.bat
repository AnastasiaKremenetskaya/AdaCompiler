@echo off

flex.exe ada.flex
bison.exe -d --verbose ada_bison.y

start /wait gcc lex.yy.c ada_bison_tab.c -o app.exe
start /wait app.exe