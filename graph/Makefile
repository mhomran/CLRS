all: graph.exe

valgrind: graph.exe
	valgrind ./graph.exe

graph.exe: test_graph.cpp graph.hpp vertex.hpp priority_queue.hpp
	g++ -Wall -g test_graph.cpp -o graph.exe

clean:
	rm *.exe
