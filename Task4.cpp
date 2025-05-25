//#include <iostream>
//using namespace std;
//class Time{
//	int hour;
//	int min;
//	int sec;
//public:
//	Time(){
//		cout << "Default constructor" << endl;
//		hour = 0;
//		min = 0;
//		sec = 0;
//	}
//	Time(int h,int m,int s){
//		cout << "Partialized Construstor " << endl;
//		hour = 0;
//		min = 0;
//		sec = 0;
//	}
//	//setter
//	void setValue(){
//		cout << "Enter the HOURS  :";
//		cin >> hour;
//		cout << "Enter the min :";
//		cin >> min;
//		cout << "Enter the SEC :";
//		cin >> sec;
//	}
//	//getter
//	int gethour(){
//		return hour;
//	}
//	int getmin(){
//		return min;
//	}
//	int getsec(){
//		return sec;
//	}
//	// Displaying Results
//	void display(){
//		cout << "Hours :" << hour << endl;
//		cout << "Minutes :" << min << endl;
//		cout << "Seconds :" << sec << endl;
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
//	int hours, mins, secs;
//	Time t1;
//	t1.setValue();
//	hours = t1.gethour();
//	mins = t1.getmin();
//	secs = t1.getsec();
//	cout << "Displaying DATA :" << endl;
//	t1.display();
//	int hours2, mins2, secs2;
//	Time t2;
//	t2.setValue();
//	hours2 = t2.gethour();
//	mins2 = t2.getmin();
//	secs2 = t2.getsec();
//	cout << "Displaying DATA :" << endl;
//	t2.display();
//	cout << endl;
//	system("pause");
//	return 0;
//}