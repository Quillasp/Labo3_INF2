/**
 * @file Point.cpp
 * @author Janssens emmanuel
 * @brief Coordonées dans le plan réel et toute les fonctions qui vont avec
 * @version 0.1
 * @date 2019-03-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Point.h"
#include <cmath>

Point::Point()
: x(0),y(0)
{}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

float Point::distance()const
{
    float dist = 0;

    dist = (float)sqrt(pow(x,2)+ pow(y,2));

    return dist;
}

bool Point::operator<(const Point& p) const
{
    if(this->distance()== p.distance())
        return false;    

    return (this->distance()< p.distance());
}
bool Point::operator>(const Point& p) const
{
    if(this->distance()== p.distance())
        return false;    

    return (p<*this);
}
bool Point::operator>=(const Point& p) const
{
    return !(p<*this);
}
bool Point::operator<=(const Point& p) const
{
    return !(p>*this);
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os<<"("<<point.x<<";"<<point.y<<") dist = "<<point.distance();
    return os;
}