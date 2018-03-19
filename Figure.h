#include <iostream>

class Excpt: public std::exception { /*КЛАСС ИСКЛЮЧЕНИЙ*/
public:
	char msg[128];
	Excpt();
	Excpt(const char*);
	const char* what();
};

class Figure{ /*КЛАСС ФИГУРА*/

protected:
void print_info()const;

public:
double length; /*Длина*/
double width; /*Ширина*/
double heigth; /*Высота*/

Figure(double,double,double);
Figure();
virtual ~Figure();
virtual void print(double,double) const =0; /*Функция печати информации*/
virtual double area() const =0; /*Функция нахождения площади фигуры*/
virtual double volume() const =0; /*Функция нахождения объёма фигуры*/
};

void clean_stdin(void); /*Очистка потока ввода*/
void TotalPrint(Figure *p[], int n);/*Вывод информации о всех фигурах*/
void TotalArea(Figure *p[], int n); /*Подсчёт общей площади фигур*/
