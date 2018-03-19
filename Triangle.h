#include <iostream>
#include "Rectangle.h"

class Triangle: Figure{ /*КЛАСС ТРЕУГОЛЬНИК*/

public:
Triangle(double,double,double);
~Triangle();
virtual void print(double,double) const;
virtual double area() const;
virtual double volume() const;
};
