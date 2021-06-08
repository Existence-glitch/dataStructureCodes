all: tarea5

tarea5: quicksort.o
	g++ quicksort.o -o tarea5
	
quicksort.o: quicksort.cpp
	g++ -c quicksort.cpp

clean:
	rm -rf *o tarea5
