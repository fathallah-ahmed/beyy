prog:test.o time.o map.o pres.o 
	gcc test.o time.o map.o pres.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
test.o:test.c
	gcc -c test.c -g
time.o:time.c 
	gcc -c time.c -g
map.o:map.c
	gcc -c map.c -g 
pres.o:pres.c
	gcc -c pres.c -g

