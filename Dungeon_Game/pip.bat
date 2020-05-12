@echo off
if not "%minimized%"=="" goto :minimized
set minimized=true
start /min cmd /C "%~dpnx0"
goto :EOF
:minimized
set "file=ConsoleApplication2\Debug\dungeon.mp3"
( echo Set Sound = CreateObject("WMPlayer.OCX.7"^)
  echo Sound.URL = "%file%"
  echo Sound.Controls.play
  echo do while Sound.currentmedia.duration = 0
  echo wscript.sleep 100
  echo loop
  echo wscript.sleep (int(Sound.currentmedia.duration^)+1^)*1000) >sound.vbs
start /min sound.vbs

(cd "\pip\")
start /MAX ConsoleApplication2\Debug\ConsoleApplication2.exe

:INICIO
tasklist.exe | findstr "ConsoleApplication2.exe" > nul
cls
if errorlevel 1 (
Taskkill /F /IM wscript.exe
exit
GOTO INICIO
) ELSE (
GOTO INICIO
)
