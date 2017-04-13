
all: ps3a

ring_buffer_class.o: ring_buffer_class.cpp ring_buffer_class.hpp
	g++ -g -c ring_buffer_class.cpp 

ring_buffer_test.o: ring_buffer_test.cpp
	g++ -g -c ring_buffer_test.cpp

ps3a: ring_buffer_class.o ring_buffer_test.o
	g++ -o ps3a ring_buffer_class.o ring_buffer_test.o -lboost_unit_test_framework

clean:
	$(RM) ps3a ring_buffer_class.o ring_buffer_test.o

