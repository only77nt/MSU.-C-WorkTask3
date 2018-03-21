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
	this->corners=0;
}
Figure::Figure(){};
Figure::~Figure() {};

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
