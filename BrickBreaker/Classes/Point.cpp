#include "Point.h"

Point::Point()
{
    x=0;
    y=0;//ctor
}

Point::~Point()
{
    //dtor
}
void Point::Setx(int x)
{
    this->x= x;
}
void Point::Sety(int y)
{
    this->y= y;
}
int Point::Getx()
{
    return this->x;
}
int Point::Gety()
{
    return this->y;
}
