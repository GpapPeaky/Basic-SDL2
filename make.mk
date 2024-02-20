all:
	gcc src/main.c src/window.c src/init_window.c -Iinclude -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o main