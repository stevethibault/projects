test:
	make build;
	make run;
build:
	gcc -c image.c -o imageinfo.o;
	gcc imageinfo.o -o imageinfo;
run:
	./imageinfo;
clean:
	-rm imageinfo.o;
	-rm imageinfo;
