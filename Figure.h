#include <iostream>

class Excpt: public std::exception { /*КЛАСС ИСКЛЮЧЕНИЙ*/
public:
	char msg[128];
	Excpt();
	Excpt(const char*);
	const char* what();
};

void clean_stdin(void); /*Очистка потока ввода*/

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

class Rectangle: Figure{ /*КЛАСС ПРЯМОУГОЛЬНИК*/

public:
Rectangle(double,double,double);
~Rectangle();
virtual void print(double,double) const;
virtual double area() const;
virtual double volume() const;
};

class Triangle: Figure{ /*КЛАСС ТРЕУГОЛЬНИК*/

public:
Triangle(double,double,double);
~Triangle();
virtual void print(double,double) const;
virtual double area() const;
virtual double volume() const;
};

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

class Parall: Figure{ /*КЛАСС ПАРАЛЛЕЛЕПИПЕД*/

public:
Parall();
Parall(double l1,double,double);
~Parall();
virtual void print(double,double) const;
virtual double area() const;
virtual double volume() const;
double Section(double,double) const; /*Метод нахождения площади сечения*/
};

class Notch: public Parall,public Sphere{ /*Класс-сечение для ромбовидного наследования*/

public:
Notch();
~Notch();
};

void TotalPrint(Figure *p[], int n);/*Вывод информации о всех фигурах*/
void TotalArea(Figure *p[], int n); /*Подсчёт общей площади фигур*/
