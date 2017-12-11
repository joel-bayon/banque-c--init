#ifndef DATE_H_
#define DATE_H_

#include <ctime>
#include <string>
#include <sstream>

class Date
	{
		time_t date;
		std::stringstream ss;

	public:
		Date();
		Date(const std::string&);
		~Date();
		Date(const Date &) = default;
		Date& operator = (const Date &) = default;
		std::string toString() const { return ss.str(); }
	};

#endif /*DATE_H_*/
