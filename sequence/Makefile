
all: array_seq.exe linked_list_seq.exe dynamic_array_seq.exe binary_tree_seq.exe

array_seq.exe: sequence.hpp array_seq.hpp test_array_seq.cpp
	g++ -g -Wall test_array_seq.cpp -o array_seq.exe

linked_list_seq.exe: sequence.hpp linked_list_seq.hpp test_linked_list_seq.cpp 
	g++ -g -Wall test_linked_list_seq.cpp -o linked_list_seq.exe

dynamic_array_seq.exe: sequence.hpp dynamic_array_seq.hpp test_dynamic_array_seq.cpp
	g++ -g -Wall test_dynamic_array_seq.cpp -o dynamic_array_seq.exe

binary_tree_seq.exe: sequence.hpp binary_tree_seq.hpp test_binary_tree_seq.cpp \
../bst/*.hpp dynamic_array_seq.hpp
	g++ -g -Wall test_binary_tree_seq.cpp -o binary_tree_seq.exe

valgrind: array_seq.exe linked_list_seq.exe dynamic_array_seq.exe
	valgrind ./array_seq.exe
	valgrind ./linked_list_seq.exe
	valgrind ./dynamic_array_seq.exe
	valgrind ./binary_tree_seq.exe

clean:
	rm *.exe