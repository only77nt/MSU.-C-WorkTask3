#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "Sphere.h"
using namespace std;

Sphere::Sphere(){};
Sphere::Sphere(double l1,double w1=0,double h1=0): Figure(l1,w1,h1){};
Sphere::~Sphere(){};
void Sphere::print(double area,double volume) const{
	print_info();
	cout << "Я сфера. ";
	cout << "Площадь моей поверхности равна " << area << '.';
	cout << " Мой объём равен " << volume << '.';
}
double Sphere::area() const{
	double res=0;
	res=4*3.14*(this->length)*(this->length); /* 4*PI*R^2 */
	return res;
}
double Sphere::volume() const{
	double res=0;
	res=1.33 * 3.14 * (this->length * this->length * this->length); /* (4/3)*PI*R^3 */
	return res;
}	

double Sphere::Section(double h) const{
	double res=0;
	res=3.14*(h*h); /* Сечение по экватору, PI*R^2 */
return res;
}
