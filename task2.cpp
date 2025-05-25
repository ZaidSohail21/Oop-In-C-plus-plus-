//#include <iostream>
//#include <string>
//using namespace std;
//class Employee{
//public:
//	string name;
//	int id;
//	double salary;
//
//	Employee() :name("null"), id(0), salary(0){ cout << "Employee Constructor " << endl; }
//	Employee(string n, int i, double s) :name(n), id(i), salary(s){ cout << "Employee Constructor " << endl; }
//	
//	//display
//	void display(){
//		cout << "Name :" << name << endl;
//		cout << "ID :" << id << endl;
//		cout << "Salary :" << salary << endl;
//	}
//};
//class Manager :public Employee{
//public:
//	int teamsize;
//	Manager() :Employee(), teamsize(0){ cout << "Manager Constructor " << endl; }
//	Manager(string n, int i, double s, int t) :Employee(n, i, s), teamsize(t){ cout << "Manager Constructor " << endl; }
//	void display(Employee s1){
//		cout << "Name :" << s1.name << endl;
//		cout << "id :" << s1.id << endl;
//		cout << "Salary :" << s1.salary << endl;
//	}
//
//
//};
//int main(){
//	Manager m1;
//	
//	system("pause");
//	return 0;
//}