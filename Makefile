all: demo runthru

demo: demo.o sketch.o 
	g++ demo.o sketch.o -o demo

runthru: runthru.o sketch.o
	g++ runthru.o sketch.o -o runthru

demo.o: demo.cpp
	g++ -c demo.cpp

runthru.o: runthru.cpp
	g++ -c runthru.cpp

sketch.o: sketch.cpp
	g++ -c sketch.cpp

clean:
	rm -rf *.o demo runthru
