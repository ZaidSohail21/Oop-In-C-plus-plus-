#include <iostream>
using namespace std;

int Area(int l){
	int s = l*l;
	return s;
}
int Area(int b, int h){
	int w = b*h;
	return w / 2;
}
double Area(double r){
	int cir = r*r;
	return 3.14*cir;
}

int main(){
	double length, base,height;
	double radius;
	cout << "Enter the Length :";
	cin >> length;

	cout << "Enter the Base :";
	cin >> base;

	cout << "Enter the Height :";
	cin >> height;

	cout << "Enter the Radius :";
	cin >> radius;
	cout << "The area of a square is :";
	int square = Area(length);
	cout << square << endl;

	cout << "The area of a Triangle is :";
	int triangle = Area(base, height);
	cout << triangle << endl;

	cout << "The area of a circle is :";
	double circle = Area(radius);
	cout << circle << endl;

	cout << endl;
	system("pause");
	return 0;
}