@echo off

rem 元ネタ
rem read:https://oshiete.goo.ne.jp/qa/8950484.html
rem http://language-and-engineering.hatenablog.jp/entry/20130502/PatternsOfMSDOSorBAT#batTemplatesTopAndEnd

rem  set FILE_NAME="変数名"

rem set /P FILE_NAME="ファイル名(拡張子は付けないで下さい。) >"
rem echo.

gcc animation.c IDA_CES.c CES_main.c operation_CES.c solution_CES.c printf_CES.c make_log.c change_need_CE.c -o CES_main.exe

CES_main.exe

echo プログラム終了

pause > nul
rem > nulはその状の文字を表示しない
rem exit