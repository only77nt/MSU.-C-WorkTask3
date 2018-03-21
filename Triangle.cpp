#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "Triangle.h"
using namespace std;

Triangle::Triangle(double l1,double w1,double h1=0): Figure(l1,w1,h1){};
Triangle::~Triangle(){};
void Triangle::print(double area,double volume=0) const{
	print_info();
	cout << "Я треугольник. ";
	cout << "Моя площадь равна " << area << '.';
}
double Triangle::area() const{
	double res=0;
	res=0.5 * this->length * this->heigth; /* (1/2)*высота*основание */
	return res;
}	
double Triangle::volume() const { /*Плоская фигура -> объём=0*/
	double res=0;
	return res;
}
void Triangle::cprint() const {	
	cout << "Я треугольник. У меня " << this->corners << " угла!" << endl;
}


