CFLAGS = -O
CC = g++

kmeans: kmeans.o
	$(CC) $(CFLAGS) -o kmeans kmeans.o graph.o --std=c++11

kmeans.o: graph.o kmeans.cpp
	$(CC) $(CFLAGS) -c kmeans.cpp --std=c++11

graph.o: graph.h graph.cpp
	$(CC) $(CFLAGS) -c graph.cpp --std=c++11

run:
	./kmeans

clean:
	rm -f core *.o
