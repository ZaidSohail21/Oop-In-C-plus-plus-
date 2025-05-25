//#include <iostream>
//#include <string>
//using namespace std;
//class Rectangle {
//	int x, y;
//public:
//	// Default Constructor
//	Rectangle() : x(0), y(0) { }
//
//	// Parameterized Constructor
//	Rectangle(int a, int b) : x(a), y(b) { }
//	//copy constructor
//	Rectangle(Rectangle& obj) :x(obj.x), y(obj.y){ }
//	// Setters
//	void xsetter(int a) { x = a; }
//	void ysetter(int b) { y = b; }
//
//
//	// Getters
//	int xgetter() const { return x; }
//	int ygetter() const { return y; }
//	// Display
//	void display(){
//		cout << "Imaginary :" << xgetter() << endl;
//		cout << "Real :" << ygetter() << endl;
//	}
//	//operators
//	Rectangle operator+(const Rectangle& other){
//		Rectangle Temp;
//		Temp.x = this->x + other.x;
//		Temp.y = this->y + other.y;
//		cout << Temp.x << endl;
//		cout << Temp.y << endl;
//		return Temp;
//	}
//	Rectangle operator-(const Rectangle& other){
//		Rectangle Temp;
//		Temp.x = this->x - other.x;
//		Temp.y = this->y - other.y;
//		cout << Temp.x << endl;
//		cout << Temp.y << endl;
//		return Temp;
//	}
//
//	bool operator==(const Rectangle& other){
//		if (this->y == other.y && this->x == other.x){
//			return true;
//		}
//		else{
//			return false;
//		}
//	}
//	bool operator!=(const Rectangle& other){
//		if (this->x == other.x && this->y == other.y){
//			return false;
//		}
//		else{
//			return true;
//		}
//	}
//	Rectangle operator++(){
//		++x;
//		++y;
//		return *this;
//	}
//	Rectangle operator++(int){
//		x++;
//		y++;
//		return *this;
//	}
//	Rectangle operator--(){
//		--x;
//		--y;
//		return *this;
//	}
//	Rectangle operator--(int){
//		x--;
//		y--;
//		return *this;
//	}
//	friend ostream& operator << (ostream& out, const Rectangle& obj);
//
//};
//ostream& operator << (ostream& out, const Rectangle& obj){
//	out << "length :" << obj.x << endl;
//	out << "width :" << obj.y << endl;
//	return out;
//}
//int main() {
//	Rectangle r1;
//		Rectangle r2(1, 2);
//		Rectangle r5(2, 3);
//		Rectangle r3=r5 + r2;
//		cout << r3;
//		
//		Rectangle r4 = r5- r2;
//		cout << r4;
//		if (r4 == r1){
//			cout << "they are equal" << endl;
//		}
//		else{
//			cout << "They are not equal" << endl;
//		}
//		r4++;
//		r4--;
//	cout << endl;
//	system("pause");
//	return 0;
//}