SEQ_DIR=../sequence
SORT_DIR=../sorting

all: array_set.exe sorted_array_set.exe

array_set.exe: set.hpp array_set.hpp test_array_set.cpp \
${SEQ_DIR}/sequence.hpp ${SEQ_DIR}/array_seq.hpp
	g++ test_array_set.cpp -o array_set.exe

sorted_array_set.exe: set.hpp sorted_array_set.hpp test_sorted_array_set.cpp \
${SEQ_DIR}/sequence.hpp ${SEQ_DIR}/array_seq.hpp \
${SORT_DIR}/merge_sort.hpp
	g++ test_sorted_array_set.cpp -o sorted_array_set.exe

clean:
	rm *.exe