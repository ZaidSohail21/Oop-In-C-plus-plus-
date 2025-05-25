//#include <iostream>
//using namespace std;
//class Complex{
//	double real;
//	double imaginary;
//public:
//	Complex(){
//		cout << "Default constructor" << endl;
//		real = 0;
//		imaginary = 0;
//	}
//	Complex(double r, double i){
//		cout << "Partialized Construstor " << endl;
//		real = 0;
//		imaginary = 0;
//	}
//	//setter
//	void setValue(){
//		cout << "Enter the real number  :";
//		cin >> real;
//		cout << "Enter the Imaginary number  :";
//		cin >> imaginary;
//	}
//	//getter
//	int getreal(){
//		return real;
//	}
//	int getimaginary(){
//		return imaginary;
//	}
//	// Displaying Results
//	void display(){
//		cout << "Real number :" << real << endl;
//		cout << "Imaginary Number :" << imaginary << endl;
//	}
//	void sum(double w, double x, double y, double z){
//		double a = w + y;
//		double b = x + z;
//		cout << "the sum of two complex number : " << a << endl;
//		cout << "the sum of two imaginary number : " << b << endl;
//	}
//	void dif(double w, double x, double y, double z){
//		double a = w - y;
//		double b = x - z;
//		cout << "The difference of two complex number : " << a << endl;
//		cout << "The difference of two imaginary number : " << b << endl;
//	}
//
//};
//int main(){
//	Complex com1;
//	double a, b;
//	cout << "1st complex number " << endl;
//	com1.setValue();
//	a=com1.getreal();
//	b = com1.getimaginary();
//	// display
//	com1.display();
//
//	double c, d;
//	Complex com2;
//	cout << "2nd complex number " << endl;
//	com2.setValue();
//	c = com2.getreal();
//	d = com2.getimaginary();
//	// display
//	com2.display();
//	com1.sum(a, b, c, d);
//	com1.dif(a, b, c, d);
//
//
//
//	cout << endl;
//	system("pause");
//	return 0;
//}