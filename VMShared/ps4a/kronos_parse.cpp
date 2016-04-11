// "Copyright 2016 <Copyright Zachary Krausman>"
#include <stdlib.h>
#include <boost/regex.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "boost/date_time/posix_time/posix_time.hpp"

int main(int argc, char* argv[]) {
  using boost::posix_time::time_from_string;

  std::fstream input, output;
  std::string line, start_s, success_s;
  std::string date_start_s, time_start_s, date_end_s, time_end_s;
  boost::smatch match_start, match_end;
  int lineNum = 0;
  input.open(argv[1], std::fstream::in);
  std::string temp = argv[1];
  std::string temp2 = temp + ".rpt";
  output.open(temp2.c_str(), std::fstream::out);
  boost::regex start, success;
  bool look_for_completed = 1;
  start_s = ("[0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}:"
  " \\(log.c.166\\) server started");
  success_s = ("oejs.AbstractConnector:Started SelectChannelConnector");
//  boost::regex success();
try {
  start = boost::regex(start_s);
  success = boost::regex(success_s);
} catch (boost::regex_error& exc) {
  std::cout << "Regex constructor failed with code " << exc.code() << std::endl;
  return 1;
}
while (!input.eof()) {
  getline(input, line);
  lineNum++;
  if (look_for_completed == 0)  {
    if (boost::regex_search(line, match_start, start)) {
      output << "**** Incomplete Boot ****" << std::endl << std::endl;
      look_for_completed = 1;
    }
    if (boost::regex_search(line, match_end, success)) {
      std::string temp_time;
      date_end_s = line.substr(0, 10);
      time_end_s = line.substr(11, 8);
      output << lineNum << "(" << argv[1] << "): " << date_end_s << " ";
      output << time_end_s << " Boot Completed" << std::endl;
      look_for_completed = 1;
      temp_time = date_start_s + " " + time_start_s;
      boost::posix_time::ptime t1(time_from_string(temp_time));
      temp_time = date_end_s + " " + time_end_s;
      boost::posix_time::ptime t2(time_from_string(temp_time));
      boost::posix_time::time_duration diff = t2 - t1;
      output << "Boot time: " << diff.total_milliseconds();
      output << "ms" << std::endl << std::endl;
    }
  }
  if (boost::regex_search(line, match_start, start)) {
    std::string date_s, time_s;
    date_start_s = line.substr(0, 10);
    time_start_s = line.substr(11, 8);
    output << "=== Device boot ===" << std::endl;
    output << lineNum << "(" << argv[1] << "): " << date_start_s << " ";
    output << time_start_s << " Boot Start" << std::endl;
    look_for_completed = 0;
  }
    }


  input.close();
  output.close();
}
