test:
	make build;
	make run;
build:
	gcc -I"/usr/include/SDL" -I"/usr/include/GL" -c image.c
	gcc image.o -lSDL -lGL -o imageshow
run:
	./imageshow
clean:
	-rm image.o;
	-rm imageshow;
