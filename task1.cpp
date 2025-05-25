//#include <iostream>
//using namespace std;
//
//void CompareArea(){
//
//
//}
//class rectangle {
//	int length;
//	int width;
//public:
//	rectangle(){
//		cout << "Default constructor " << endl;
//		length = 0;
//		width = 0;
//	}
//	rectangle(int l, int w){
//		cout << "Paramatric constructor " << endl;
//		length = l;
//		width = w;
//	}
//	rectangle(rectangle &ra){
//		cout << "Shallow constructor " << endl;
//		length = ra.length;
//		width = ra.width;
//	}
//	//setter
//	void setter(int l,int w){
//		length = l;
//		width = w;
//	}
//	//gettter
//	void lengthgetter(){ cout << length; }
//	void widthgetter(){ cout << width; }
//	int area(){ return length*width; }
//	//display function
//	void display(){
//		cout << "Length : ";
//		lengthgetter();
//		cout << endl;
//		int z=area();
//		cout << "Width : ";
//		widthgetter();
//		cout << endl;
//		cout << "ARea :" << z << endl;
//	}
//
//
//	// Deleting object
//	~rectangle(){
//		cout << "Default constructor " << endl;
//	}
//
//};
//int main(){
//	int a, b;
//	rectangle r1;
//	cout << "Enter length :";
//	cin >> a;
//	cout << "Enter width :";
//	cin >> b;
//	r1.setter(a, b);
//	rectangle r2(23, 43);
//	rectangle r3 = r2;
//	r1.display();
//	r2.display();
//	r3.display();
//
//	cout << endl;
//	system("pause");
//	return 0;
//}