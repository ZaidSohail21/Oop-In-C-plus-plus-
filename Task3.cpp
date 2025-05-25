//#include <iostream>
//using namespace std;
//class Student {
//private:
//	char name[50];
//	int age;
//
//public:
//	Student(const char* n, int a) {
//		int i = 0;
//		while (n[i] != '\0' && i < 49) {
//			name[i] = n[i];
//			i++;
//		}
//		name[i] = '\0';
//		age = a;
//	}
//
//	void displayInfo() const {
//		std::cout << "  Name: " << name << ", Age: " << age << std::endl;
//	}
//};
//
//class Teacher {
//private:
//	char name[50];
//	Student* students[10];
//	int studentCount;
//	const int maxStudents;
//
//public:
//	Teacher(const char* n, int max) : studentCount(0), maxStudents(max) {
//		int i = 0;
//		while (n[i] != '\0' && i < 49) {
//			name[i] = n[i];
//			i++;
//		}
//		name[i] = '\0';
//	}
//
//	bool addStudent(const Student& student) {
//		if (studentCount < maxStudents) {
//			students[studentCount] = new Student(student);
//			studentCount++;
//			return true;
//		}
//		else {
//			std::cout << "Maximum student capacity reached for " << name << "." << std::endl;
//			return false;
//		}
//	}
//
//	void display() const {
//		std::cout << "Teacher: " << name << std::endl;
//		if (studentCount == 0) {
//			std::cout << "No students assigned yet." << std::endl;
//			return;
//		}
//		std::cout << "Students:" << std::endl;
//		for (int i = 0; i < studentCount; i++) {
//			students[i]->displayInfo();
//		}
//	}
//	~Teacher(){
//		for (int i = 0; i< studentCount; i++){
//			delete students[i];
//		}
//	}
//};
//
//int main() {
//	Teacher teacher1("Mr. Smith", 3);
//
//	Student student1("Alice", 18);
//	Student student2("Bob", 19);
//	Student student3("Charlie", 20);
//	Student student4("David", 21);
//	teacher1.addStudent(student1);
//	teacher1.addStudent(student2);
//	teacher1.addStudent(student3);
//	teacher1.addStudent(student4);
//
//
//	Teacher teacher2("Ms. Johnson", 2);
//	Student student5("Eve", 19);
//	Student student6("Frank", 20);
//	teacher2.addStudent(student5);
//	teacher2.addStudent(student6);
//
//	teacher1.display();
//	cout << endl;
//	teacher2.display();
//	system("pause");
//	return 0;
//}