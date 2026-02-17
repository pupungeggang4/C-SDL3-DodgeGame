win-mingw:
	gcc src/*.c -o main.exe -Ilib/SDL3-3.4.0/x86_64-w64-mingw32/include -Llib/SDL3-3.4.0/x86_64-w64-mingw32/lib -lSDL3 -lmingw32 -w -g -std=c++17

win-mingw-prod:
	gcc src/*.c -o main.exe -Ilib/SDL3-3.4.0/x86_64-w64-mingw32/include -Llib/SDL3-3.4.0/x86_64-w64-mingw32/lib -lSDL3 -lmingw32 -w -mwindows -std=c++17
