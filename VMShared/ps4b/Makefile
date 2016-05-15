
all: ps4b


kronos_parse_class.o: kronos_parse_class.hpp kronos_parse_class.cpp
	g++ -g -c kronos_parse_class.cpp

kronos_main.o: kronos_main.cpp
		g++ -g -c kronos_main.cpp

ps4b: kronos_parse_class.o kronos_main.o
	g++ -o ps4b kronos_parse_class.o kronos_main.o -lboost_regex -lboost_date_time

clean:
	$(RM) ps4b kronos_parse_class.o kronos_main.o
