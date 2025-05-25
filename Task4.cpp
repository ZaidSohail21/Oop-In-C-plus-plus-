#include <iostream>
#include <string>
using namespace std;
class Vehicle{
public:
	string brand;
	int regno;


	Vehicle() :brand("null"), regno(0){ cout << "Sports Constructor " << endl; }
	Vehicle(string n, int i) :brand(n), regno(i){ cout << "Sports Constructor " << endl; }
	//setter
	void setbrand(string b){ brand=b; }
	void setregno(int r){  regno=r; }
	//getter
	string getbrand(){ return brand; }
	int getregno(){ return regno; }
	//display
	void display(){
		cout << "Name :" << brand << endl;
		cout << "ID :" << regno << endl;
	}
};
class RoadVehicle{
public:
	
	int noofwheel;
	//setter
	void setnoof(int w){ noofwheel=w; }
	//getter
	int noof(){ return noofwheel; }


	RoadVehicle() :noofwheel(0){ cout << "Sports Constructor " << endl; }
	RoadVehicle(int i) :noofwheel(i){ cout << "Sports Constructor " << endl; }

	//display
	void display(){
		cout << "No Of Wheel :" << noofwheel << endl;
	}
};
class car :public Vehicle,public RoadVehicle{
public:
	string color;
	int miles;
	//setter
	void setcolor(string c){  color=c; }
	void setmiles(int m){  miles=m; }
	//getter
	string getcolor(){ return color; }
	int getmiles(){ return miles; }

	car() :Vehicle(), RoadVehicle(), color("null"), miles(0){}
	car(string c, int m,string b,int r,int w ) :color(c), miles(m),Vehicle(c,r),RoadVehicle(w){}
	
};

int main(){
	car c1("white",2000,"toyota",1234,10);
	
	system("pause");
	return 0;
}