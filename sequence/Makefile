
all: array_seq.exe linked_list_seq.exe dynamic_array_seq.exe

array_seq.exe: sequence.hpp array_seq.cpp array_seq.hpp test_array_seq.cpp
	g++ -Wall array_seq.cpp test_array_seq.cpp -o array_seq.exe

linked_list_seq.exe: sequence.hpp linked_list_seq.cpp linked_list_seq.hpp test_linked_list_seq.cpp 
	g++ -Wall linked_list_seq.cpp test_linked_list_seq.cpp -o linked_list_seq.exe

dynamic_array_seq.exe: sequence.hpp dynamic_array_seq.cpp dynamic_array_seq.hpp test_dynamic_array_seq.cpp
	g++ -Wall dynamic_array_seq.cpp test_dynamic_array_seq.cpp -o dynamic_array_seq.exe

clean:
	rm *.exe