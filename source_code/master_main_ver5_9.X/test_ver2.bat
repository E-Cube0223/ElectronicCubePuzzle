@echo off

rem ���l�^
rem read:https://oshiete.goo.ne.jp/qa/8950484.html
rem http://language-and-engineering.hatenablog.jp/entry/20130502/PatternsOfMSDOSorBAT#batTemplatesTopAndEnd

rem  set FILE_NAME="�ϐ���"

rem set /P FILE_NAME="�t�@�C����(�g���q�͕t���Ȃ��ŉ������B) >"
rem echo.

gcc animation.c IDA_CES.c CES_main.c operation_CES.c solution_CES.c printf_CES.c make_log.c change_need_CE.c -o CES_main.exe

CES_main.exe

echo �v���O�����I��

pause > nul
rem > nul�͂��̏�̕�����\�����Ȃ�
rem exit