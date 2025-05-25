#include <iostream>
#include <string>
using namespace std;
class rec
{
	double length;
	double width;
public:
	void display()
	{
		cout << "Enter the width: ";
		cin >> width;
		cout << "Enter the length: ";
		cin >> length;
	}
	void setValue()
	{
		cout << "The lenght is: " << width << endl;
		cout << "The width is: " << length << endl;
	}
	double calArea()
	{
		double area = length*width;
		return area;

	}
};
class Student
{
	int studentID;
	double GPA;
	string degreeName, studentName;
public:
	void display()
	{
		cout << "Enter the Student ID: ";
		cin >> studentID;
		cout << "Enter your Name: ";
		cin >> studentName;
		cout << "Enter the Dergree: ";
		cin >> degreeName;
		cout << "Enter the GPA: ";
		cin >> GPA;
	}
	double calculatePercentage(double total, double obt)
	{
		double per = (obt / total) * 100;
		return per;
	}
	void disPercantage(double Percentage)
	{

		if (Percentage >= 86)
		{
			cout << "The Grade is 'A+'.";
		}
		else if (Percentage >= 82)
		{
			cout << "The Grade is 'A'.";
		}
		else if (Percentage >= 78)
		{
			cout << "The Grade is 'B+'.";
		}
		else if (Percentage >= 74)
		{
			cout << "The Grade is 'B'.";
		}
		else if (Percentage >= 70)
		{
			cout << "The Grade is 'B-'.";
		}
		else if (Percentage >= 66)
		{
			cout << "The Grade is 'C+'.";
		}
		else if (Percentage >= 62)
		{
			cout << "The Grade is 'C'.";
		}
		else if (Percentage >= 58)
		{
			cout << "The Grade is 'C-'.";
		}
		else if (Percentage >= 54)
		{
			cout << "The Grade is 'D+'.";
		}
		else if (Percentage >= 50)
		{
			cout << "The Grade is 'D'.";
		}
		else if (Percentage <50)
		{
			cout << "The Grade is 'F'.";
		}

	}
};
class Complex{
	double real;
	double imaginary;
public:
	Complex(){
		cout << "Default constructor" << endl;
		real = 0;
		imaginary = 0;
	}
	Complex(double r, double i){
		cout << "Partialized Construstor " << endl;
		real = 0;
		imaginary = 0;
	}
	//setter
	void setValue(){
		cout << "Enter the real number  :";
		cin >> real;
		cout << "Enter the Imaginary number  :";
		cin >> imaginary;
	}
	//getter
	int getreal(){
		return real;
	}
	int getimaginary(){
		return imaginary;
	}
	// Displaying Results
	void display(){
		cout << "Real number :" << real << endl;
		cout << "Imaginary Number :" << imaginary << endl;
	}
	void sum(double w, double x, double y, double z){
		double a = w + y;
		double b = x + z;
		cout << "the sum of two complex number : " << a << endl;
		cout << "the sum of two imaginary number : " << b << endl;
	}
	void dif(double w, double x, double y, double z){
		double a = w - y;
		double b = x - z;
		cout << "The difference of two complex number : " << a << endl;
		cout << "The difference of two imaginary number : " << b << endl;
	}

};
class Time{
	int hour;
	int min;
	int sec;
public:
	Time(){
		cout << "Default constructor" << endl;
		hour = 0;
		min = 0;
		sec = 0;
	}
	Time(int h,int m,int s){
		cout << "Partialized Construstor " << endl;
		hour = 0;
		min = 0;
		sec = 0;
	}
	//setter
	void setValue(){
		cout << "Enter the HOURS  :";
		cin >> hour;
		cout << "Enter the min :";
		cin >> min;
		cout << "Enter the SEC :";
		cin >> sec;
	}
	//getter
	int gethour(){
		return hour;
	}
	int getmin(){
		return min;
	}
	int getsec(){
		return sec;
	}
	// Displaying Results
	void display(){
		cout << "Hours :" << hour << endl;
		cout << "Minutes :" << min << endl;
		cout << "Seconds :" << sec << endl;
	}
	void sum(double w, double x, double y, double z){
		double a = w + y;
		double b = x + z;
		cout << "the sum of two complex number : " << a << endl;
		cout << "the sum of two imaginary number : " << b << endl;
	}
	void dif(double w, double x, double y, double z){
		double a = w - y;
		double b = x - z;
		cout << "The difference of two complex number : " << a << endl;
		cout << "The difference of two imaginary number : " << b << endl;
	}

};
int main(){
	int a ;
	do{
		cout << "Press 1 for Rectangle class" << endl;
		cout << "Press 2 for Student class" << endl;
		cout << "Press 3 for Comlex Number class" << endl;
		cout << "Press 4 for Time class" << endl;
		cout << "Press 0 for exit" << endl;
		cin >> a;
		if (a == 1){
				rec name;
				name.display();
				name.setValue();
				double var = name.calArea();
				cout << "The area is: " << var << endl;
				
		}
		else if (a == 2){
			Student s1;
				s1.display();
			
				double total, obtain;
				cout << "Enter Your obtained marks: ";
				cin >> obtain;
				cout << "Enter Your total marks: ";
				cin >> total;
			
				double Percentage = s1.calculatePercentage(total, obtain);
				s1.disPercantage(Percentage);
				cout << endl;
		}

		else if (a == 3){
				Complex com1;
				double a, b;
				cout << "1st complex number " << endl;
				com1.setValue();
				a=com1.getreal();
				b = com1.getimaginary();
				// display
				com1.display();
			
				double c, d;
				Complex com2;
				cout << "2nd complex number " << endl;
				com2.setValue();
				c = com2.getreal();
				d = com2.getimaginary();
				// display
				com2.display();
				com1.sum(a, b, c, d);
				com1.dif(a, b, c, d);
			
		}

		else if (a == 4){
				int hours, mins, secs;
				Time t1;
				t1.setValue();
				hours = t1.gethour();
				mins = t1.getmin();
				secs = t1.getsec();
				cout << "Displaying DATA :" << endl;
				t1.display();
				int hours2, mins2, secs2;
				Time t2;
				t2.setValue();
				hours2 = t2.gethour();
				mins2 = t2.getmin();
				secs2 = t2.getsec();
				cout << "Displaying DATA :" << endl;
				t2.display();
				cout << endl;
		}

		else if (a == 0){
			break;
		}
		else
		{
			cout << "enter a valid number" << endl;
		}


	} while (a!=0);
	cout << endl;
	system("pause");
	return 0;
}