//#include <iostream>
//#include <string>
//using namespace std;
//
//void CompareArea();
//
//class person{
//	string* name=new string;
//	int age;
//public:
//	person(){
//		cout << "Default constructor " << endl;
//		*name = 'null';
//		age = 0;
//	}
//	person(string* l, int w){
//		cout << "Paramatric constructor " << endl;
//		*name = *l;
//		age= w;
//	}
//	/*person(person &ra){
//		cout << "Shallow constructor " << endl;
//		name = ra.name;
//		age = ra.age;
//	}*/
//	person(person &ra){
//		cout << "Deep constructor " << endl;
//		name =new string( *ra.name);
//		age = ra.age;
//	}
//	//setter
//	void setter(string *nam, int w){
//		this->name = nam;
//		this->age = age;
//	}
//	//gettter
//	void namegetter(){ cout << *name; }
//	void agegetter(){ cout << age; }
//	
//	//display function
//	void display(){
//		cout << "Name  : ";
//		namegetter();
//		cout << endl;
//		
//		cout << "Age  : ";
//		agegetter();
//		cout << endl;
//		
//	}
//
//
//	// Deleting object
//	~person(){
//		cout << "Default destructor " << endl;
//	}
//
//};
//int main(){
//	
//	int a;
//	string *ptr = new string[1];
//	person p1;
//	cout << "Enter name :";
//	cin >> *ptr ;
//	cout << "Enter age :";
//	cin >> a;
//	p1.setter(ptr, a);
//
//	cout << "Enter name :";
//	cin >> *ptr;
//	cout << "Enter age :";
//	cin >> a;
//	person p2;
//	p2.setter(ptr, a);
//	cout << "P1 display :" << endl;
//	p1.display();
//
//	cout << "P2 display :" << endl;
//	p2.display();
//	
//	cout << endl;
//	system("pause");
//	return 0;
//}
