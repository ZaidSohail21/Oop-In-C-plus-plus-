#include <iostream>
#include <string>

using namespace std;

class Teacher {
protected:
	string name;
	int age;
	string qualification;
	int numberOfStudents;

public:
	string getName() const { return name; }
	void setName(const string& n) { name = n; }

	int getAge() const { return age; }
	void setAge(int a) { age = a; }

	string getQualification() const { return qualification; }
	void setQualification(const string& q) { qualification = q; }

	int getNumberOfStudents() const { return numberOfStudents; }
	void setNumberOfStudents(int nos) { numberOfStudents = nos; }

	void display() const{
		cout << "Name: " << name << ", Age: " << age << ", Qualification: " << qualification << ", Number of Students: " << numberOfStudents << endl;
	}
};

class Permanent : public Teacher {
protected:
	string schoolName;

public:
	Permanent() : schoolName("Example High School") {}
	string getName() const{
		return schoolName;
	}
	void show() const {
		cout << "Name (from Teacher): " << Teacher::name << ", School Name: " << schoolName << endl;
	}
};

class Visiting : public Teacher {};

int main() {
	Permanent permanentTeacher;
	permanentTeacher.setName("Alice Johnson");
	permanentTeacher.setAge(35);
	permanentTeacher.setQualification("MSc Mathematics");
	permanentTeacher.setNumberOfStudents(50);

	cout << "Permanent Staff" << endl;
	permanentTeacher.display();
	cout << endl;

	Teacher teacherFromPermanent = permanentTeacher;
	cout << "Accessing Superclass Member after Assignment" << endl;
	cout << "Name: " << teacherFromPermanent.getName() << endl;
	cout << endl;


	Visiting visitingStaff[3];
	visitingStaff[0].setName("Bob Williams");
	visitingStaff[0].setAge(40);
	visitingStaff[0].setQualification("PhD Physics");
	visitingStaff[0].setNumberOfStudents(30);

	visitingStaff[1].setName("Carol Davis");
	visitingStaff[1].setAge(28);
	visitingStaff[1].setQualification("MA English");
	visitingStaff[1].setNumberOfStudents(25);

	visitingStaff[2].setName("David Rodriguez");
	visitingStaff[2].setAge(45);
	visitingStaff[2].setQualification("MBA Finance");
	visitingStaff[2].setNumberOfStudents(40);

	cout << "Visiting Staff" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "Name\t\tAge\tQualification\tNumber of Students" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (int i = 0; i< 3; i++){
		cout << visitingStaff[i].getName() << "\t\t" << visitingStaff[i].getAge() << "\t" << visitingStaff[i].getQualification() << "\t\t" << visitingStaff[i].getNumberOfStudents() << endl;
	}
	cout << "----------------------------------------------------------------" << endl;
	cout << endl;

	Teacher* teacherPtr = &permanentTeacher;
	cout << "Permanent Staff accessed using Superclass Pointer" << endl;
	teacherPtr->display();
	cout << endl;

	teacherPtr = &visitingStaff[1];
	teacherPtr->setName("Updated Carol Davis");
	teacherPtr->setAge(29);
	teacherPtr->setQualification("Updated MA English");
	teacherPtr->setNumberOfStudents(26);

	cout << "Visiting Staff with Object 2 Set using Superclass Pointer" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "Name\t\tAge\tQualification\tNumber of Students" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (int i = 0; i< 3; i++){
		cout << visitingStaff[i].getName() << "\t\t" << visitingStaff[i].getAge() << "\t" << visitingStaff[i].getQualification() << "\t\t" << visitingStaff[i].getNumberOfStudents() << endl;
	}
	cout << "----------------------------------------------------------------" << endl;
	cout << endl;

	Teacher* anotherTeacherPtr = &visitingStaff[0];
	cout << "Visiting Staff Accessed Using Pointer" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "Name\t\tAge\tQualification\tNumber of Students" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (int i = 0; i< 3; i++){
		cout << anotherTeacherPtr[i].getName() << "\t\t" << anotherTeacherPtr[i].getAge() << "\t" << anotherTeacherPtr[i].getQualification() << "\t\t" << anotherTeacherPtr[i].getNumberOfStudents() << endl;
	}
	cout << "----------------------------------------------------------------" << endl;
	cout << endl;

	Permanent permanentTeacher2;
	permanentTeacher2.setName("Original Name");
	permanentTeacher2.setAge(42);
	permanentTeacher2.setQualification("PhD History");
	permanentTeacher2.setNumberOfStudents(60);

	cout << "Permanent Teacher with Overridden Name" << endl;
	cout << "Name (using getName()): " << permanentTeacher2.getName() << endl; //Outputs the School name.
	cout << "Name (using Teacher::getName()): " << permanentTeacher2.Teacher::getName() << endl; //Outputs the name set with setName.
	permanentTeacher2.show();
	cout << endl;
	system("pause");
	return 0;
}