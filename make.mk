all:
	gcc src/main.c src/window.c src/init_window.c -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -o main