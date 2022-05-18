/*На базі класу Точка на площині створіть клас Точка3Д(точка в просторі).Реалізуйте методи введення, виведення.Реалізуйте методи за допомогою  даних класів клас Відрізок,
що дозволяє працювати з точками розмірностей 2 та 3  введення та виведення, визначення довжини відрізка. Вказівка: визначіть додатковий  член "розмірність" в класах Точка,Точка3Д
Додаткова задача - визначення чи перетинаються два відрізки.*/
#include <iostream>
#include <cmath>
using namespace std;
class Point {//клас Точка на площині
protected:
	double x1,x2;
	double y1, y2;
	double dimension;
public:
	Point(){
		x1 = 0; x2 = 0; y1 = 0; y2 = 0; dimension = 0;
	}


	void Input() {
		cout << "Enter coordinates x1, x2, y1, y2:" << endl;
		cin >> x1 >> x2 >> y1 >> y2;
	}


	double getDimension() {// знаходимо довжину відрізка
		dimension =sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		return dimension;
	}


	void Output() {
		cout << "Dimension of Point is: " << getDimension()<< endl;
	}


	~Point() {}
};
class Point3D{//клас Точка3Д(точка в просторі)
protected:
	double X1, X2, Y1, Y2, Z1, Z2;
	double dimension;
public:
	Point3D() {
		X1 = 0; X2 = 0; Y1 = 0; Y2 = 0; Z1 = 0; Z2 = 0; dimension = 0;
	}


	void Input3D() {
		cout << "Enter coordinates x1, x2, y1, y2, z1, z2:" << endl;
		cin >> X1 >> X2 >> Y1 >> Y2 >> Z1 >> Z2;
	}
	

	double  getDimension3D() {// знаходимо довжину відрізка
		dimension =sqrt(pow((X2 - X1), 2) + pow((Y2 - Y1), 2)+ pow((Z2 - Z1), 2));
		return dimension;
	}


	void Output3D() {
		cout << "Dimension of Point 3D is: " << getDimension3D()<< endl;
	}


	~Point3D() {}
};
class Segment: public Point, public Point3D{
protected:
	double A, B, C1, C2;
public:
	Segment(){}
	double Vector() {//шукаємо координати векторів АВ та АС1, АС2
		A = (x2 - x1);
		B = (y2 - y1);
		C1 = (X2 - X1);
		C2 = (Y2 - Y1);
	}


	double cos1() {//кут між векторами АВ та АС1
		return (A * A + B * C1) / ((sqrt(pow(A, 2) + pow(B, 2))) * (sqrt(pow(A, 2) + pow(C1, 2))));
	}


	double cos2() {//кут між векторами АВ та АС2
		return (A * A + B * C1) / ((sqrt(pow(A, 2) + pow(B, 2))) * (sqrt(pow(A, 2) + pow(C2, 2))));
	}
	//оскільки відрізки знаходяться в різних площинах, то пересіктись вони зможуть якщо точка (X1,Y1,Z1) або (X2,Y2,Z2) буде лежати на відрізку в Point2D, 
	//а це можливо якщо координати z1 чи z2 будуть рівними 0, тобто точки з площини 3D будуть в площині 2D
	bool cheakPoint() {
		if (Z2 == 0 or Z1==0) {
			if ((x1 == X1 and y1 == Y1) or (x2 == X2 and y2 == Y2))return true;//умова за якої одна початкова чи остання точка з 3D лежить  на початковій чи останній точці з 2D 
			if (cos1() == 1 or cos2() == 1)return true;//якщо косинуси відповідних векторів дорівнюють 0, то початкова чи остання точка з 3D лежить на відрізку з 2D
		}
		else return false;
	}


	~Segment(){}
};

int main()
{	Segment A;
    A.Input();
	A.Output();
	A.Input3D();
	A.Output3D();
	cout<<"Segment in 3D cross with segment 2D- true=1, false=0 is= "<<A.cheakPoint();
}