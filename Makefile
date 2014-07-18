SDL_FLAGS = $(shell sdl-config --cflags --libs) -lSDL_image -lSDL_ttf -lSDL_mixer

fantasy : sdl_utils.o hero.o location.o timer.o board.o game.o main.o 
	gcc $(SDL_FLAGS) -o fantasy main.o game.o board.o timer.o location.o hero.o sdl_utils.o

main.o : main.c game.h
	gcc -c main.c

game.o : game.c game.h board.h timer.h
	gcc -c game.c

board.o : board.c board.h location.h
	gcc -c board.c

timer.o : timer.c timer.h
	gcc -c timer.c

hero.o : hero.c hero.h location.h sdl_utils.h
	gcc -c hero.c

location.o : location.c location.h sdl_utils.h
	gcc -c location.c

sdl_utils.o : sdl_utils.c sdl_utils.h
	gcc -c sdl_utils.c

clean :
	rm fantasy main.o game.o board.o timer.o location.o sdl_utils.o

