all: test.exe

test.exe: test.cpp selection_sort.hpp insertion_sort.hpp merge_sort.hpp \
direct_access_array_sort.hpp priority_queue_sort.hpp
	g++ test.cpp -g -Wall -o test.exe

valgrind: test.exe
	valgrind ./test.exe

clean:
	rm -f test.exe