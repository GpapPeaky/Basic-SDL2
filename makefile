all:
	g++ src/init_window.cpp src/main.cpp src/event.cpp -Iinclude/SDL2 -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o win