//#include <iostream>
//#include <string>
//using namespace std;
//class Rectangle {
//	double length;
//	double width;
//
//public:
//	// Default Constructor
//	Rectangle() : length(0), width(0) { }
//
//	// Parameterized Constructor
//	Rectangle(double a,double b) : length(a), width(b) { }
//	//copy constructor
//	Rectangle(Rectangle& obj) :length(obj.length), width(obj.width){ }
//	// Setters
//	void numbersetter(double a) { length = a; }
//	void balancesetter(double b) { width = b; }
//	
//
//	// Getters
//	double lengthgetter() const { return length; }
//	double widthgetter() const { return width; }
//	// Display
//	void display(){
//		cout << "Length :" << lengthgetter() << endl;
//		cout << "Width :" << widthgetter() << endl;
//	}
//	//operators
//	Rectangle operator+(const Rectangle& other){
//		Rectangle temp;
//		temp.length = this->length + other.length;
//		temp.width = this->width + other.width;
//		return temp;
//	}
//	Rectangle operator*(const Rectangle& other){
//		Rectangle temp;
//		temp.length =length * other.length;
//		temp.width = width * other.width;
//		return temp;
//	}
//	Rectangle operator*(int scalar){
//		
//		this->length = this->length*scalar;
//		this->width = this->width*scalar;
//		return *this;
//	}
//	bool operator==(const Rectangle& other){
//		if (this->length == other.length && this->width == other.width){
//			return true;
//		}
//		else{
//			return false;
//		}
//	}
//	bool operator!=(const Rectangle& other){
//		if (this->length == other.length && this->width == other.width){
//			return false;
//		}
//		else{
//			return true;
//		}
//	}
//	friend ostream& operator << (ostream& out, const Rectangle& obj);
//
//};
//ostream& operator << (ostream& out, const Rectangle& obj){
//	out << "length :" << obj.length << endl;
//	out << "width :" << obj.width << endl;
//	return out;
//}
//int main() {
//	int x;
//	Rectangle r1;
//	Rectangle r2(2, 5);
//	Rectangle r3=r1 + r2;
//	r3.display();
//	r3 * 2;
//	cout << r3;
//	r3*r2;
//	if (r2 == r3){
//		cout << "They are equal" << endl;
//	}
//	else{
//		cout << "They are not equal" << endl;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

