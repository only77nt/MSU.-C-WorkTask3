#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "Parall.h"
using namespace std;

Parall::Parall(){};
Parall::Parall(double l1,double w1,double h1): Figure(l1,w1,h1){};
Parall::~Parall(){};
void Parall::print(double area,double volume) const{
	print_info();
	cout << "Я параллелепипед. ";
	cout << "Площадь моей поверхности равна " << area << '.';
	cout << " Мой объём равен " << volume << '.';
}
double Parall::area() const{
	double res=0;
	res=2*(this->heigth*this->width+this->heigth*this->length+this->length*this->width); /* 2*(пов.+пов.+пов.)*/
	return res;
}
double Parall::volume() const{ 
	double res=0;
	res=this->heigth*this->width*this->length; /* Высота*длина*ширина */
	return res;
}	
double Parall::Section(double l,double w) const{
	double res=0;
	res=l*w; /* Сечение посередине (Длина на ширину) */
return res;
}
