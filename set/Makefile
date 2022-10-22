SEQ_DIR=../sequence
SORT_DIR=../sorting

all: hash_table_set.exe array_set.exe sorted_array_set.exe direct_access_array_set.exe

array_set.exe: set.hpp set_from_seq.hpp test_array_set.cpp \
${SEQ_DIR}/sequence.hpp ${SEQ_DIR}/array_seq.hpp
	g++ test_array_set.cpp -o array_set.exe

sorted_array_set.exe: set.hpp sorted_array_set.hpp test_sorted_array_set.cpp \
${SEQ_DIR}/sequence.hpp ${SEQ_DIR}/array_seq.hpp \
${SORT_DIR}/merge_sort.hpp
	g++ test_sorted_array_set.cpp -o sorted_array_set.exe

direct_access_array_set.exe: set.hpp direct_access_array_set.hpp test_direct_access_array_set.cpp
	g++ test_direct_access_array_set.cpp -o direct_access_array_set.exe

hash_table_set.exe: set.hpp hash_table_set.hpp test_hash_table_set.cpp \
set_from_seq.hpp \
${SEQ_DIR}/sequence.hpp ${SEQ_DIR}/linked_list_seq.hpp \

	g++ test_hash_table_set.cpp -o hash_table_set.exe
clean:
	rm *.exe