REM @echo off

@set CPP_NAME=main.cpp
@set EXE_NAME=%~n0.exe
@set GPP_PATH=C:\MINGW\x86_64-13.2.0-release-posix-seh-ucrt-rt_v11-rev1\mingw64\bin

@set GPP_FLAGS_1=-static -O2 -Wall -Wextra -Wsign-conversion -Werror -Wuninitialized -pedantic
@set GPP_FLAGS_2=-o

	%GPP_PATH%\g++ %GPP_FLAGS_1% %CPP_NAME% %GPP_FLAGS_2% %EXE_NAME%
	%EXE_NAME%
	
pause