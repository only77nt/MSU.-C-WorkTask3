#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Excpt: public std::exception { /*КЛАСС ИСКЛЮЧЕНИЙ*/
public:
	char msg[128];
	Excpt(){};
	Excpt(const char* Mes) {strcpy(this->msg,Mes);};
	const char* what() {return msg;}
};

void clean_stdin(void) /*Функция очистки stdin*/
{
int c;
do c = getchar();	
while (c != '\n' && c != EOF);
return;
}

class Figure{ /*КЛАСС ФИГУРА*/

protected:
void print_info()const{
	cout << "Фигура. ";
}

public:
double length; /*Длина*/
double width; /*Ширина*/
double heigth; /*Высота*/

Figure(double l1,double w1=0,double h1=0){ /*Присваиваем значения полям*/
	this->length=l1;
	this->width=w1;
	this->heigth=h1;
}

Figure(){};
virtual ~Figure() {};
virtual void print(double area,double volume=0) const =0;
virtual double area() const =0;
virtual double volume() const=0;
};

class Rectangle: Figure{ /*КЛАСС ПРЯМОУГОЛЬНИК*/

public:
Rectangle(double l1,double w1,double h1=0): Figure(l1,w1,h1){};
~Rectangle(){};

virtual void print(double area,double volume=0) const{
	print_info();
	cout << "Я прямоугольник. ";
	cout << "Моя площадь равна " << area << '.';
}

virtual double area() const{ /* Длина*ширина */
	double res=0;
	res=this->length * this->width;
	return res;
}

virtual double volume() const { /*Плоская фигура -> объём=0*/
	double res=0;
	return res;
}
};

class Triangle: Figure{ /*КЛАСС ТРЕУГОЛЬНИК*/

public:
Triangle(double l1,double w1,double h1=0): Figure(l1,w1,h1){};
~Triangle(){};

virtual void print(double area,double volume=0) const{
	print_info();
	cout << "Я треугольник. ";
	cout << "Моя площадь равна " << area << '.';
}

virtual double area() const{
	double res=0;
	res=0.5 * this->length * this->heigth; /* (1/2)*высота*основание */
	return res;
}	

virtual double volume() const { /*Плоская фигура -> объём=0*/
	double res=0;
	return res;
}
};

class Sphere: Figure{ /*КЛАСС СФЕРА*/

public:
Sphere(){};
Sphere(double l1,double w1=0,double h1=0): Figure(l1,w1,h1){};
~Sphere(){};

virtual void print(double area,double volume) const{
	print_info();
	cout << "Я сфера. ";
	cout << "Площадь моей поверхности равна " << area << '.';
	cout << " Мой объём равен " << volume << '.';
}

virtual double area() const{
	double res=0;
	res=4*3.14*(this->length)*(this->length); /* 4*PI*R^2 */
	return res;
}

virtual double volume() const{
	double res=0;
	res=1.33 * 3.14 * (this->length * this->length * this->length); /* (4/3)*PI*R^3 */
	return res;
}	

double Section(double h) const{
	double res=0;
	res=3.14*(h*h); /* Сечение по экватору, PI*R^2 */
return res;
}
};

class Parall: Figure{ /*КЛАСС ПАРАЛЛЕЛЕПИПЕД*/

public:
Parall(){};
Parall(double l1,double w1,double h1): Figure(l1,w1,h1){};
~Parall(){};

virtual void print(double area,double volume) const{
	print_info();
	cout << "Я параллелепипед. ";
	cout << "Площадь моей поверхности равна " << area << '.';
	cout << " Мой объём равен " << volume << '.';
}

virtual double area() const{
	double res=0;
	res=2*(this->heigth*this->width+this->heigth*this->length+this->length*this->width); /* 2*(пов.+пов.+пов.)*/
	return res;
}

virtual double volume() const{ 
	double res=0;
	res=this->heigth*this->width*this->length; /* Высота*длина*ширина */
	return res;
}	

double Section(double l,double w) const{
	double res=0;
	res=l*w; /* Сечение посередине (Длина на ширину) */
return res;
}
};

class Notch: public Parall,public Sphere{ /*Класс-сечение для ромбовидного наследования*/

public:
Notch(){};
~Notch(){};
};

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

int main(void){ /*Функция-MAIN*/
	double S=0,V=0,RES=0;
	double Se1=0,Se2=0,SeRes=0;
	double l=0,w=0,h=0;
	int input;

while(1)
{
try{
sleep(1); /*Можно убрать*/
printf("\nВыберите один из пунктов: \n");
printf("1. Найти площадь прямоугольника\n");
printf("2. Найти площадь треугольника\n");
printf("3. Найти площадь поверхности и объём сферы\n");
printf("4. Найти площадь поверхности и объём параллелепипеда\n");
printf("5. Найти площадь фигуры полученной в результате наложения прямоугольника и круга\n");
printf("6. Вывести информацию о всех имеющихся фигурах\n");
printf("7. Сумма площадей всех фигур\n");
printf("8. Clear\n");
printf("9. Exit\n");
cin >> input;
switch(input){
case 1: {	/*Прямоугольник*/
			cout << "Введите длину и ширину: ";
			cin >> l >> w;
			if(l<=0 || w<=0)
			{
				Excpt A;
				strcpy(A.msg,"Wrong options!");
				throw A;
			}
			clean_stdin();
			Rectangle Rec(l,w);
			S=Rec.area();
			Rec.print(S); 
			cout << endl;
			break;
		}
case 2: {	/*Треугольник*/
			cout << "Введите длину и высоту: ";
			cin >> l >> h;
			if(l<=0 || h<=0)
			{
				Excpt A;
				strcpy(A.msg,"Wrong options!");
				throw A;
			}
			clean_stdin();
			Triangle Tri(l,0,h);
			S=Tri.area();
			Tri.print(S); 
			cout << endl;
			break;
		}
case 3: {	/*Сфера*/
			cout << "Введите радиус: ";
			cin >> h;
			if(h<=0)
			{
				Excpt A;
				strcpy(A.msg,"Wrong options!");
				throw A;
			}
			clean_stdin();
			Sphere Sph(h);
			S=Sph.area();
			V=Sph.volume();
			Sph.print(S,V);
			cout << endl;
			break;
		}
case 4: {	/*Параллелепипед*/
			cout << "Введите длину, ширину, высоту: ";
			cin >> l >> w >> h;
			if(l<=0 || w<=0 || h<=0)
			{
				Excpt A;
				strcpy(A.msg,"Wrong options!");
				throw A;
			}
			clean_stdin();
			Parall Par(l,w,h);
			S=Par.area();
			V=Par.volume();
			Par.print(S,V);
			cout << endl;
			break;
		}
case 5: {	/*Сечение с дыркой*/
			cout << "Введите длину и ширину параллелепипеда: ";
			cin >> l >> w;
			if(l<=0 || w<=0)
			{
				Excpt A("Wrong options! Parall.");
				throw A;
			}
			clean_stdin();
			cout << "Введите радиус сферы: ";
			cin >> h;
			if(h<=0)
			{
				Excpt A("Wrong options! Sphere.");
				throw A;
			}
			clean_stdin();
			Notch Sec;
			Se1=Sec.Parall::Section(l,w);
			Se2=Sec.Sphere::Section(h);
			//cout << Se1 << ":::" << Se2 << endl;
			if(Se1>=Se2)
				SeRes=Se1-Se2;
			else
				SeRes=Se2-Se1;
			cout << "Площадь сечения с дыркой равна " << SeRes << "." << endl;
			break;
		}
case 6: {	/*Информация о всех фигурах*/
			Rectangle Rec(2,3); /*S=6*/
			Triangle Tri(4,0,5); /*S=10*/
			Sphere Sph(0.5); /*S=3.14*/
			Parall Par(1,2,3); /*S=22*/
			Figure *arr[] = {(Figure *) &Rec, (Figure *) &Tri, (Figure *) &Sph, (Figure *) &Par};
			TotalPrint(arr,sizeof(arr)/sizeof(Figure*));
			break;
		}
case 7: {	/*Общая площадь всех фигур*/
			Rectangle Rec(2,3); /*S=6*/
			Triangle Tri(4,0,5); /*S=10*/
			Sphere Sph(0.5); /*S=3.14*/
			Parall Par(1,2,3); /*S=22*/
			Figure *arr[] = {(Figure *) &Rec, (Figure *) &Tri, (Figure *) &Sph, (Figure *) &Par};
			TotalArea(arr,sizeof(arr)/sizeof(Figure*));
			break;
		}
case 8: {   /*Clear*/
			system("clear");
			break;
		}
case 9: {   /*Exit*/			
			exit(0);
		}
}
}
catch(Excpt& e) {cout << e.what() << endl;} /*Отлавливаем исключение и пишем ошибку*/
}	
return 0;
}
