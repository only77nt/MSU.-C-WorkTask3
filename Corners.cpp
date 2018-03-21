#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "Corners.h"
using namespace std;

Corner::Corner(double l1,double w1,double h1=0): Rectangle(l1,w1,h1), Triangle(l1,w1,h1){};

void Corner::CornPrint(int a,int b,int c) const{
char input;
int s=0;
cout << "Хотите добавить углов к общей сумме? y/n" << endl;
clean_stdin();
cin >> input;
if(input=='y')
{
	s=c;
}
cout << "Сумма углов треугольника и прямоугольника (+добавочные) равна " << a+b+s << endl;
}
void Corner::print(double area,double volume=0) const{
	print_info();
	cout << "Я угол. У меня нет площади и объёма.";
}
double Corner::area() const{ /* У углов нет площади */
	double res=0;
	return res;
}
double Corner::volume() const { /* У углов нет объёма */
	double res=0;
	return res;
}
