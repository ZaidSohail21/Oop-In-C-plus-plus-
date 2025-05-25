//#include <iostream>
//#include <string>
//using namespace std;
//class Rectangle {
//	int imaginary, real;
//public:
//	// Default Constructor
//	Rectangle() : imaginary(0), real(0) { }
//
//	// Parameterized Constructor
//	Rectangle(int a, int b) : imaginary(a), real(b) { }
//	//copy constructor
//	Rectangle(Rectangle& obj) :imaginary(obj.imaginary), real(obj.real){ }
//	// Setters
//	void imaginarysetter(int a) { imaginary = a; }
//	void realsetter(int b) { real = b; }
//
//
//	// Getters
//	int imaginarygetter() const { return imaginary; }
//	int realgetter() const { return real; }
//	// Display
//	void display(){
//		cout << "Imaginary :" << imaginarygetter() << endl;
//		cout << "Real :" << realgetter() << endl;
//	}
//	//operators
//	Rectangle operator+(const Rectangle& other){
//		Rectangle Temp;
//		Temp.imaginary = this->imaginary + other.imaginary;
//		Temp.real = this->real + other.real;
//		cout << Temp.imaginary << endl;
//		cout << Temp.real << endl;
//		return Temp;
//	}
//	Rectangle operator-(const Rectangle& other){
//
//		imaginary = imaginary - other.imaginary;
//		real = real - other.real;
//		return *this;
//	}
//	
//	bool operator==(const Rectangle& other){
//		if (this->imaginary == other.imaginary && this->real == other.real){
//			return true;
//		}
//		else{
//			return false;
//		}
//	}
//	bool operator!=(const Rectangle& other){
//		if (this->imaginary == other.imaginary && this->real == other.real){
//			return false;
//		}
//		else{
//			return true;
//		}
//	}
//	Rectangle operator++(){
//		++real;
//		++imaginary;
//		return *this;
//	}
//	Rectangle operator++(int){
//		real++;
//		imaginary++;
//		return *this;
//	}
//	friend ostream& operator << (ostream& out, const Rectangle& obj);
//
//};
//ostream& operator << (ostream& out, const Rectangle& obj){
//	out << "length :" << obj.imaginary << endl;
//	out << "width :" << obj.real << endl;
//	return out;
//}
//int main() {
//	Rectangle r1;
//	Rectangle r2(1, 2);
//	Rectangle r3;
//	 r1 + r2;
//	cout << r3;
//	Rectangle r4 = r3 - r2;
//	cout << r4;
//	if (r4 == r1){
//		cout << "they are equal" << endl;
//	}
//	else{
//		cout << "They are not equal" << endl;
//	}
//	r4++;
//	cout << r4;
//	cout << endl;
//	system("pause");
//	return 0;
//}