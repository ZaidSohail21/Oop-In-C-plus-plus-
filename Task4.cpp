//#include <iostream>
//#include <string>
//using namespace std;
//class property{
//	float size;
//public:
//	// constructor 
//	property() : size(0){}
//	property(float s) : size(s){}
//	//display,
//	void display(){
//		cout << "Size :" << size << endl;
//	}
//};
//class owner{
//	int id;
//	string name;
//public:
//	//constructor
//	owner(int i, string n) :id(i), name(n){ }
//	// display
//	void displayOwner(){
//		cout << "Id :" << id << endl;
//		cout << "Name :" << name << endl;
//	}
//};
//class  ResidentialProperty :public property{
//	int bednum;
//	bool hasgarden;
//public:
//	ResidentialProperty(float s, int b, bool ba) :property(s), bednum(b), hasgarden(ba){ }
//	//display
//	void displayResidentialProperty(){
//		cout << "Numbers of bed room is :" << bednum << endl;
//		if (hasgarden == true){
//			cout << "Yes! it has a garden " << endl;
//		}
//		else{
//			cout << "No! it not have a garden" << endl;
//		}
//	}
//};
//class CommercialProperty :public property{
//	string buisnesstype;
//	int NoFloors;
//public:
//	CommercialProperty(float s, int i, string n) :property(s), NoFloors(i), buisnesstype(n){ }
//	// display
//	void displayCommercialProperty(){
//		cout << "NoFloors :" << NoFloors << endl;
//		cout << "buisnesstype :" << buisnesstype << endl;
//	}
//
//};
//class RentalProperty :public ResidentialProperty, public owner{
//	double rentalPrice;
//public:
//
//	RentalProperty(float s, int bedrooms, bool garden, int id, string n, double price) : ResidentialProperty(s, bedrooms, garden), owner(id, n), rentalPrice(price) {}
//
//	void displayRentalProperty() {
//		displayOwner();
//		displayResidentialProperty();
//		cout << "Rental Price: $" << rentalPrice << std::endl;
//	}
//};
//
//int main(){
//
//	ResidentialProperty residential(150, 3, true);
//	cout << "--- Residential Property ---" << std::endl;
//	residential.displayResidentialProperty();
//	cout << endl;
//
//	CommercialProperty commercial(150, "Retail", 2);
//	cout << "--- Commercial Property ---" << endl;
//	commercial.displayCommercialProperty();
//	cout << endl;
//
//	RentalProperty rental(100, 2, false, 123, "John Doe", 1200.0);
//	cout << "--- Rental Property ---" << endl;
//	rental.displayRentalProperty();
//
//	cout << endl;
//	system("pause");
//	return 0;
//}