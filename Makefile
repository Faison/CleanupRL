CFLAGS = -std=c99

config: objects
	mkdir -p build
	gcc -o build/cleanuprl src/cleanuprl.c obj/menus.o obj/dialog.o $(CFLAGS) -lncurses

objects:
	mkdir -p obj
	gcc -c src/menus.c -o obj/menus.o $(CFLAGS)
	gcc -c src/dialog.c -o obj/dialog.o $(CFLAGS)
