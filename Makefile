sample: sample.o imageio.o tasks.o
	g++ -o sample sample.o imageio.o tasks.o

sample.o: sample.cpp imageio.h tasks.h

imageio.o: imageio.cpp imageio.h

tasks.o: tasks.cpp imageio.h tasks.h

clean:
	rm -f sample.o imageio.o
