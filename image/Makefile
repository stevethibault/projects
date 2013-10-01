test:
	make build;
	make run;
build:
	gcc -I"/usr/include/SDL" -I"/usr/include/GL" -c imgshow.c image.c
	gcc imgshow.o image.o -lSDL -lGL -o imgshowrun:
	./imageinfo;
clean:
	-rm imageinfo.o;
	-rm imageinfo;
