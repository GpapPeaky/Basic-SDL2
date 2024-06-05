all:
	g++ src/init_window.c src/main.c -Iinclude/SDL2 -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o win