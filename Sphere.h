#include <iostream>
#include "Triangle.h"

class Sphere: Figure{ /*КЛАСС СФЕРА*/

public:
Sphere();
Sphere(double,double,double);
~Sphere();
virtual void print(double,double) const; 
virtual double area() const; 
virtual double volume() const; 
double Section(double) const; /*Метод нахождения площади сечения*/
};
