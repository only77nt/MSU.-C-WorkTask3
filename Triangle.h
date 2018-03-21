#include <iostream>
#include "Rectangle.h"

class Triangle: virtual public Figure{ /*КЛАСС ТРЕУГОЛЬНИК*/

public:
Triangle(double,double,double);
~Triangle();
virtual void print(double,double) const;
virtual double area() const;
virtual double volume() const;
void cprint() const;
};
