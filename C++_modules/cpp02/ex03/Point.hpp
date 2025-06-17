#include "Fixed.hpp"

#ifndef POINT_H
# define POINT_H

class Point {

private:
	const Fixed _x;
	const Fixed _y;

public:
	/**** Constructors ****/
		Point();
		Point(const float x, const float y);
		Point(const Point& other);


	/**** Destructor ****/
		~Point();


	/**** Overload operators ****/
		Point& operator=(const Point& other) = delete;

};

#endif