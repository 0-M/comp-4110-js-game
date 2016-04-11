
all: ps4a


kronos_parse.o: kronos_parse.cpp
	g++ -g -c kronos_parse.cpp

ps4a: kronos_parse.o
	g++ -o ps4a kronos_parse.o -lboost_regex -lboost_date_time

clean:
	$(RM) ps4a kronos_parse.o
