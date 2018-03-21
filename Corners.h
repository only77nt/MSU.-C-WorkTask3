#include <iostream>
#include "Notch.h"

class Corner: public Rectangle, public Triangle{ /*КЛАСС УГЛЫ*/

public:

Corner(double,double,double);
void CornPrint(int,int,int) const;
virtual void print(double,double) const;
virtual double area() const;
virtual double volume() const;
};
