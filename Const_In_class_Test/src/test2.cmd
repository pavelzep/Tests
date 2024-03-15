REM @echo off

@set CPP_NAME=main.cpp
@set EXE_NAME=%~n0.exe
@set GPP_PATH=C:\MINGW\x86_64-13.2.0-release-posix-seh-ucrt-rt_v11-rev1\mingw64\bin

@set GPP_FLAGS=-static -o -O2 -Wall -Wuninitialized -Werror -pedantic

REM @set GPP_FLAGS=-static -o -Wall -Wextra -Wsign-conversion
REM @set GPP_FLAGS=-O2 -Wuninitialized -Werror -pedantic

	%GPP_PATH%\g++ %CPP_NAME% %GPP_FLAGS% %EXE_NAME%
	%EXE_NAME%
	
pause
