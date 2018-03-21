#include <iostream>
#include "Figure.h"

class Rectangle: virtual public Figure{ /*КЛАСС ПРЯМОУГОЛЬНИК*/

public:
Rectangle(double,double,double);
~Rectangle();
virtual void print(double,double) const;
virtual double area() const;
virtual double volume() const;
void cprint() const;
};
