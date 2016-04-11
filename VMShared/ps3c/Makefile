
all: GuitarHero

ring_buffer_class.o: ring_buffer_class.cpp ring_buffer_class.hpp
	g++ -g -c ring_buffer_class.cpp

guitar_string_class.o: guitar_string_class.cpp guitar_string_class.hpp
	g++ -g -c guitar_string_class.cpp

guitar_hero.o: guitar_hero.cpp
	g++ -g -c guitar_hero.cpp

GuitarHero: ring_buffer_class.o guitar_string_class.o guitar_hero.o
	g++ -o GuitarHero guitar_hero.o ring_buffer_class.o guitar_string_class.o -lsfml-graphics -lsfml-system -lsfml-audio -lsfml-window -lboost_unit_test_framework

clean:
	$(RM) GuitarHero ring_buffer_class.o guitar_string_class.o guitar_hero.o

