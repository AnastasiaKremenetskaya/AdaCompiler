@echo off

flex.exe ada.flex
bison.exe -d --verbose ada_bison.y

:start
cls
echo Compiling...
gcc lex.yy.c ada_bison_tab.c -o ada_bison.exe
timeout 500
:wait
if exist ada_bison.exe (ada_bison.exe) else (timeout 500 && goto wait)
pause
goto start