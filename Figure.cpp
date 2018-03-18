#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "Figure.h"
using namespace std;

Excpt::Excpt(){};
Excpt::Excpt(const char* Mes) {strcpy(this->msg,Mes);};
const char* Excpt::what() {return msg;}

void clean_stdin(void) /*Функция очистки stdin*/
{
int c;
do c = getchar();	
while (c != '\n' && c != EOF);
return;
}

void Figure::print_info()const{
	cout << "Фигура. ";
}
Figure::Figure(double l1,double w1=0,double h1=0){ /*Присваиваем значения полям*/
	this->length=l1;
	this->width=w1;
	this->heigth=h1;
}
Figure::Figure(){};
 Figure::~Figure() {};


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

Notch::Notch(){};
Notch::~Notch(){};

void TotalPrint(Figure *p[], int n){ /*Вывод информации о всех фигурах*/
double S=0,V=0;
for (int i=0; i<n; i++){
	cout<<"Figure #" <<i+1<<":"<<endl;
	S=p[i]->area();
	V=p[i]->volume();
	p[i]->print(S,V); 
	cout<<endl;
}
}

void TotalArea(Figure *p[], int n){ /*Подсчёт общей площади фигур*/
double ResArea=0;
for (int i=0; i<n; i++){
	ResArea+=p[i]->area();
}
cout<<"Total Area = " << ResArea <<endl; 
}
