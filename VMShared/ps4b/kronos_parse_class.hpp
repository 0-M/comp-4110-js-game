#include <stdlib.h>
#include <boost/regex.hpp>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "boost/date_time/posix_time/posix_time.hpp"

namespace Kronos
{
 class Service {

 public:
  friend std::ostream & operator << (std::ostream & out, const Service & service);
 private:
 int start_line;
 int end_line;
 int duration;
 bool completed;
 };

 class Boot {
 public:
   friend std::ostream & operator << (std::ostream & out, const Boot & boot);
 Boot(std::string file_name,boost::gregorian::date d,boost::posix_time::ptime start_time,int start_line) : file_name_(file_name),d_(d),start_time_(start_time),start_line_(start_line){}
 private:
 std::string file_name_;
 boost::gregorian::date d_;
 boost::posix_time::ptime start_time_,end_time_;
 int start_line_,end_line_;
 std::map<std::string,Service> services;
};


} //namespace Kronos
