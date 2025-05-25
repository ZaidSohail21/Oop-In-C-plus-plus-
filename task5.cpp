#include <iostream>
using namespace std;
class rectangle {
	int length;
	int width;
public:
	rectangle(){
		cout << "Default constructor " << endl;
		length = 0;
		width = 0;
	}
	rectangle(int l, int w){
		cout << "Paramatric constructor " << endl;
		length = l;
		width = w;
	}
	rectangle(rectangle &ra){
		cout << "Shallow constructor " << endl;
		length = ra.length;
		width = ra.width;
	}
	//setter
	void setter(int l,int w){
		length = l;
		width = w;
	}
	//gettter
	void lengthgetter(){ cout << length; }
	void widthgetter(){ cout << width; }
	int area(){ return length*width; }
	//display function
	void display(){
		cout << "Length : ";
		lengthgetter();
		cout << endl;
		int z=area();
		cout << "Width : ";
		widthgetter();
		cout << endl;
		cout << "ARea :" << z << endl;
	}


	// Deleting object
	~rectangle(){
		cout << "Default constructor " << endl;
	}

};
class person{
	string* name=new string;
	int age;
public:
	person(){
		cout << "Default constructor " << endl;
		*name = 'null';
		age = 0;
	}
	person(string* l, int w){
		cout << "Paramatric constructor " << endl;
		*name = *l;
		age= w;
	}
	/*person(person &ra){
		cout << "Shallow constructor " << endl;
		name = ra.name;
		age = ra.age;
	}*/
	person(person &ra){
		cout << "Deep constructor " << endl;
		name =new string( *ra.name);
		age = ra.age;
	}
	//setter
	void setter(string *nam, int w){
		this->name = nam;
		this->age = age;
	}
	//gettter
	void namegetter(){ cout << *name; }
	void agegetter(){ cout << age; }
	
	//display function
	void display(){
		cout << "Name  : ";
		namegetter();
		cout << endl;
		
		cout << "Age  : ";
		agegetter();
		cout << endl;
		
	}


	// Deleting object
	~person(){
		cout << "Default destructor " << endl;
	}

};
class student{
	string* name=new string;
	int age;
	int id;
public:
	student(){
		cout << "Default constructor " << endl;
		*name = 'null';
		age = 0;
		id = 0;
	}
	student(string* l, int w,int i){
		cout << "Paramatric constructor " << endl;
		*name = *l;
		age= w;
		id = i;
	}
	 student(student &ra){
		cout << "Shallow constructor " << endl;
		name = ra.name;
		age = ra.age;
		id = ra.id;

	}
	/*student(student &ra){
		cout << "Deep constructor " << endl;
		name =new string( *ra.name);
		age = ra.age;
		id = ra.id;
	}*/
	//setter
	void setter(string *nam, int age, int id ){
		this->name = nam;
		this->age = age;
		this->id = id;
	}
	//gettter
	void namegetter(){ cout << *name; }
	void agegetter(){ cout << age; }
	void idgetter(){ cout << id; }
	
	//display function
	void display(){
		cout << "Name  : ";
		namegetter();
		cout << endl;
		
		cout << "grade  : ";
		agegetter();
		cout << endl;

		cout << "ID : ";
		idgetter();
		cout << endl;	
	}
	// Deleting object
	~student(){
		delete []name;
		cout << "Default destructor " << endl;
	}
};

int main(){
	int a = 0;
	do{
		cout << "press 1 for rectangle" << endl;
		cout << "press 2 for person" << endl;
		cout << "press 3 for student " << endl;
		cout << "press 4 for book " << endl;
		cout << "press 0 for exit " << endl;
		cin >> a;
		if (a = 1){
				int a, b;
				rectangle r1;
				cout << "Enter length :";
				cin >> a;
				cout << "Enter width :";
				cin >> b;
				r1.setter(a, b);
				rectangle r2(23, 43);
				rectangle r3 = r2;
				r1.display();
				r2.display();
				r3.display();
			
		}
		else if (a = 2){
				int a;
				string *ptr = new string[1];
				person p1;
				cout << "Enter name :";
				cin >> *ptr ;
				cout << "Enter age :";
				cin >> a;
				p1.setter(ptr, a);
			
				cout << "Enter name :";
				cin >> *ptr;
				cout << "Enter age :";
				cin >> a;
				person p2;
				p2.setter(ptr, a);
				cout << "P1 display :" << endl;
				p1.display();
			
				cout << "P2 display :" << endl;
				p2.display();
				
		}
		else if (a = 3){
				int a,b;
				string *ptr = new string[1];
				student s[3];
				for (int i = 0; i < 2; i++){
					cout << "Enter name :";
					cin >> *ptr;
					cout << "Enter grade :";
					cin >> a;
					cout << "Enter ID :";
					cin >> b;
					s[i].setter(ptr, a, b);
				}
				for (int i = 0; i < 3; i++){
					s[i].display();
				}
				cout << "Now after copying constructor" << endl;
				s[1] = s[2];
			
				for (int i = 0; i < 3; i++){
					s[i].display();
				}
		}
		else{
			cout << "Enter a valid number! " << endl;
		}
	}while (a != 0);
	system("pause");
	return 0;
}