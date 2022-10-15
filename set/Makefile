SEQ_DIR=../sequence

all: sorted_array_set.exe

sorted_array_set.exe: set.hpp sorted_array_set.hpp test_sorted_array_set.cpp \
${SEQ_DIR}/sequence.hpp ${SEQ_DIR}/array_seq.hpp 
	g++ test_sorted_array_set.cpp -o sorted_array_set.exe

clean:
	rm *.exe