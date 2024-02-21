all:
	gcc ../src/window.c ../src/init_window.c ../src/main.c -I../include/SDL2 -L../lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o test