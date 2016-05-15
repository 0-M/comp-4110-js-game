
all: space

Universe_class.o: space.hpp Universe_class.cpp
	g++ -g -c Universe_class.cpp

Star_class.o: space.hpp Star_class.cpp
	g++ -g -c Star_class.cpp

Space_Object.o: space.hpp Space_Object.cpp
	g++ -g -c Space_Object.cpp

Body.o: space.hpp Body.cpp
	g++ -g -c Body.cpp

main.o: main.cpp
	g++ -g -c main.cpp

space: Star_class.o Universe_class.o Space_Object.o main.o Body.o
	g++ -o space Universe_class.o Star_class.o Space_Object.o  Body.o main.o -lsfml-graphics -lsfml-window -lsfml-system
clean:
	$(RM) all space main.o Star_class.o Universe_class.o Space_Object.o Body.o
