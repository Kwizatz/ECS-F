@echo off
rem Astyle.exe can be found here: http://sourceforge.net/projects/astyle/files/
Astyle.exe --options=astylerc engine\*.cpp include\*.h
