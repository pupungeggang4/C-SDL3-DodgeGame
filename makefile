win-mingw:
	gcc src/*.c -o main.exe -Iinclude -Ilib/SDL3-3.4.0/x86_64-w64-mingw32/include -Llib/SDL3-3.4.0/x86_64-w64-mingw32/lib -lSDL3 -lmingw32 -w -g

win-mingw-prod:
	gcc src/*.c -o main.exe -Iinclude -Ilib/SDL3-3.4.0/x86_64-w64-mingw32/include -Llib/SDL3-3.4.0/x86_64-w64-mingw32/lib -lSDL3 -lmingw32 -w -mwindows

mac:
	gcc src/*.c -o main.out -Iinclude -FLibrary/Frameworks -framework SDL3 -rpath Library/Frameworks -w -g
