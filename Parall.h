#include <iostream>
#include "Sphere.h"

class Parall: Figure{ /*КЛАСС ПАРАЛЛЕЛЕПИПЕД*/

public:
Parall();
Parall(double l1,double,double);
~Parall();
virtual void print(double,double) const;
virtual double area() const;
virtual double volume() const;
double Section(double,double) const; /*Метод нахождения площади сечения*/
};
