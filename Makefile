main: main.o imageio.o tasks.o
	g++ -o main main.o imageio.o tasks.o

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

main.o: main.cpp imageio.h tasks.h

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h

tasks.o: tasks.cpp imageio.h tasks.h

clean:
	rm -f main.o sample.o imageio.o tasks.o

clean-all:
	rm -f main sample main.o sample.o imageio.o tasks.o task*.pgm outImage.pgm
