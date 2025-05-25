//#include <iostream>
//
//using namespace std;
//
//class Person {
//protected:
//	char name[50];
//	int age;
//
//public:
//	Person() {
//		cout << "Person constructor called." << endl;
//		name[0] = '\0';
//		age = 0;
//	}
//
//	Person(const char* n, int a) : age(a) {
//		cout << "Person parameterized constructor called." << endl;
//		int i = 0;
//		while (n[i] != '\0' && i < 49) {
//			name[i] = n[i];
//			i++;
//		}
//		name[i] = '\0';
//	}
//
//	void display() const {
//		cout << "Name: " << name << ", Age: " << age << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	Student() {
//		cout << "Student constructor called." << endl;
//	}
//
//	Student(const char* n, int a) : Person(n, a) {
//		cout << "Student parameterized constructor called." << endl;
//	}
//};
//
//class Teacher : public Person {
//public:
//	Teacher() {
//		cout << "Teacher constructor called." << endl;
//	}
//
//	Teacher(const char* n, int a) : Person(n, a) {
//		cout << "Teacher parameterized constructor called." << endl;
//	}
//};
//
//class TA : public Student, public Teacher {
//public:
//	TA() {
//		cout << "TA constructor called." << endl;
//	}
//
//	TA(const char* n, int a) : Student(n, a), Teacher(n, a) {
//		cout << "TA parameterized constructor called." << endl;
//	}
//};
//
//int main() {
//	cout << "Creating TA object using default constructor:" << endl;
//	TA ta1;
//	cout << endl;
//
//	cout << "Creating TA object using parameterized constructor:" << endl;
//	TA ta2("John Smith", 25);
//	cout << endl;
//
//	cout << "Calling display() using default object:" << endl;
//	ta1.Student::display();//resolving ambiguity using scope resolution
//	cout << endl;
//	cout << "Calling display() using parameterized object:" << endl;
//	ta2.Student::display();//resolving ambiguity using scope resolution
//	system("pause");
//	return 0;
//}