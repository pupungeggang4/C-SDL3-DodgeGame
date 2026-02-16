win-mingw:
	gcc src/*.cpp -o main.exe -Iinclude -Ilib/SDL3-*/x86_64-w64-mingw32/include -Llib/SDL3-*/x86_64-w64-mingw32/lib -lSDL3 -w -std=c++17

win-mingw-prod:
	gcc
