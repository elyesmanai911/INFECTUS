prog:main.o voiture.o background.o text.o
	gcc main.o voiture.o background.o text.o -o prog -lSDL -lSDL_ttf -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g
voiture.o:voiture.c
	gcc -c voiture.c -g
background.o:background.c
	gcc -c background.c -g
text.o:text.c
	gcc -c text.c -g
clean:
	rm -fr *.o
mrproper:clean
	rm -f prog
