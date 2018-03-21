#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "Corners.h"
using namespace std;

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
printf("8. Показать сколько углов у треугольника и прямоугольника\n");
printf("9. Clear\n");
printf("10. Exit\n");
cin >> input;
if(input<1 || input>10)
{
	Excpt A;
	strcpy(A.msg,"Wrong input!");
	throw A;
}
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
			Rectangle Rec(l,w,0);
			S=Rec.area();
			Rec.print(S,0); 
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
			Tri.print(S,0); 
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
			Sphere Sph(h,0,0);
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
			Rectangle Rec(2,3,0); /*S=6*/
			Triangle Tri(4,0,5); /*S=10*/
			Sphere Sph(0.5,0,0); /*S=3.14*/
			Parall Par(1,2,3); /*S=22*/
			Figure *arr[] = {(Figure *) &Rec, (Figure *) &Tri, (Figure *) &Sph, (Figure *) &Par};
			TotalPrint(arr,sizeof(arr)/sizeof(Figure*));
			break;
		}
case 7: {	/*Общая площадь всех фигур*/
			Rectangle Rec(2,3,0); /*S=6*/
			Triangle Tri(4,0,5); /*S=10*/
			Sphere Sph(0.5,0,0); /*S=3.14*/
			Parall Par(1,2,3); /*S=22*/
			Figure *arr[] = {(Figure *) &Rec, (Figure *) &Tri, (Figure *) &Sph, (Figure *) &Par};
			TotalArea(arr,sizeof(arr)/sizeof(Figure*));
			break;
		}
case 8: {   /*Углы*/
			Rectangle Rec(2,3,0);
			Triangle Tri(4,0,5);
			Rec.corners=4;
			Rec.cprint();
			Tri.corners=3;
			Tri.cprint();
			Corner C(0,0,0);
			C.corners=4;
			C.CornPrint(Tri.corners,Rec.corners,C.corners);
			break;
		}
case 9: {   /*Clear*/
			system("clear");
			break;
		}
case 10: {   /*Exit*/			
			exit(0);
		}
}
}
catch(Excpt& e) {cout << e.what() << endl;} /*Отлавливаем исключение и пишем ошибку*/
}	
return 0;
}
