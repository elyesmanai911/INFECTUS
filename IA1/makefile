prog:main.o Hero.o background.o ennemi.o text.o
	gcc main.o Hero.o background.o ennemi.o text.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g
Hero.o:Hero.c
	gcc -c Hero.c -g
background.o:background.c
	gcc -c background.c -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -g
text.o:text.c
	gcc -c text.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
