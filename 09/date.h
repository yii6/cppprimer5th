/*  Author
	whulinus 1034765650@qq.com
Program
	process date data.
History
	version 1.0
	2016.6.29
*/
#ifndef DATE_H
#define DATE_H
#include <string>
#include <sstream>
#include <iostream>
class Date {
    unsigned year;
    unsigned month;
    unsigned day;
public:
    Date()=default;
    //these are constructors
    Date(const std::string &);
    friend std::ostream& print(std::ostream &,const Date &);
};
Date::Date(const std::string &cs) {
	std::string s(cs);
    year=stod(std::string{s.end()-4,s.end()});
    s=std::string{s.begin(),s.end()-5};
    if(isdigit(s[0])) {
        s.replace(s.find_first_of("/"),1," ");
        std::istringstream record(s);
        record>>month>>day;
    }
    else {
        std::string mon;
        std::istringstream record(s);
        record>>mon>>day;
        mon=mon.substr(0,3); 
        if(mon=="Jan")
            month=1;
        else if(mon=="Feb")
            month=2;
        else if(mon=="Mar")
            month=3;
        else if(mon=="Apr")
            month=4;
        else if(mon=="May")
            month=5;
        else if(mon=="Jun")
            month=6;
        else if(mon=="Jul")
            month=7;
        else if(mon=="Aug")
            month=8;
        else if(mon=="Sep")
            month=9;
        else if(mon=="Oct")
            month=10;
        else if(mon=="Nov")
            month=11;
        else if(mon=="Dec")
            month=12;
    }
}
std::ostream& print(std::ostream &os,const Date &d){
	os<<d.year<<"."<<d.month<<"."<<d.day;
	return os;
}
#endif

