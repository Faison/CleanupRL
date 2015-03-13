CFLAGS = -std=c99

config: objects
	mkdir -p build
	gcc -o build/cleanuprl src/cleanuprl.c obj/menus.o obj/dialog.o obj/house.o obj/player.o obj/collision.o obj/player_renderer.o obj/house_renderer.o $(CFLAGS) -lncurses

objects:
	mkdir -p obj
	gcc -c src/menus.c -o obj/menus.o $(CFLAGS)
	gcc -c src/dialog.c -o obj/dialog.o $(CFLAGS)
	gcc -c src/house.c -o obj/house.o $(CFLAGS)
	gcc -c src/player.c -o obj/player.o $(CFLAGS)
	gcc -c src/collision.c -o obj/collision.o $(CFLAGS)
	gcc -c src/player_renderer.c -o obj/player_renderer.o $(CFLAGS)
	gcc -c src/house_renderer.c -o obj/house_renderer.o $(CFLAGS)

