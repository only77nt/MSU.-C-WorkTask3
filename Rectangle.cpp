#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(double l1,double w1,double h1=0): Figure(l1,w1,h1){};
Rectangle::~Rectangle(){};
void Rectangle::print(double area,double volume=0) const{
	print_info();
	cout << "Я прямоугольник. ";
	cout << "Моя площадь равна " << area << '.';
}
double Rectangle::area() const{ /* Длина*ширина */
	double res=0;
	res=this->length * this->width;
	return res;
}
double Rectangle::volume() const { /*Плоская фигура -> объём=0*/
	double res=0;
	return res;
}
