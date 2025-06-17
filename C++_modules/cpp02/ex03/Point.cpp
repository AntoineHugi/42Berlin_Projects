#include "Point.hpp"

Point::Point()
{
	return ;
}
Point::Point(const float x, const float y):_x(x), _y(y)
{
	return ;
}
Point::Point(const Point& other):_x(other._x), _y(other._y)
{
	return ;
}

Point::~Point()
{
	return ;
}

Point& Point::operator=(const Point& other) = delete;