#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {
protected:
	string name;
	string address;
public:
	Person() : name(""), address("") {}

	Person(const string& n, const string& a) : name(n), address(a) {}

	void setName(const string& n) {
		name = n;
	}

	void setAddress(const string& a) {
		address = a;
	}

	string getName() const {
		return name;
	}

	string getAddress() const {
		return address;
	}
};

class Subject {

private:

	string subjectName;
	int creditHours;
	float marks;

public:

	Subject() : subjectName(""), creditHours(0), marks(0.0f) {}

	Subject(const string& SN, int CH, float M) : subjectName(SN), creditHours(CH), marks(M) {}

	void setSubject(const string& n, int c, float m)
	{
		subjectName = n;
		creditHours = c;
		marks = m;
	}

	string getSubjectName() const {
		return subjectName;
	}

	int getCreditHours() const {
		return creditHours;
	}

	float getMarks() const {
		return marks;
	}
};

class Student : public Person {

private:

	int rollNumber;
	Subject subjects[5];
	int subjectCount;

public:

	Student() : Person(), rollNumber(0), subjectCount(0) {}

	Student(const string& n, const string& a, int RN) : Person(n, a), rollNumber(RN), subjectCount(0) {}

	void setRollNumber(int RN) {
		rollNumber = RN;
	}

	int getRollNumber() const {
		return rollNumber;
	}

	void addSubject(const Subject& subject) {
		if (subjectCount < 5) {
			subjects[subjectCount++] = subject;
		}
		else
		{
			cout << "Cannot add more than 5 subjects." << endl;
		}
	}

	float calculateGPA() const
	{
		float totalGPA = 0.0f;    //typecasting or to display it like float in points
		int CreditHours = 0;

		for (int i = 0; i < subjectCount; ++i)
		{
			totalGPA += subjects[i].getMarks() * subjects[i].getCreditHours();
			CreditHours += subjects[i].getCreditHours();
		}

		if (CreditHours > 0)
		{
			float gpa = totalGPA / CreditHours;  

			
			return gpa*0.04;

		}
		else
		{
			return 0.0f;
		}
	}
	
	void display() const
	{
		cout << "Name: " << name << endl;
		cout << "Address: " << address << endl;
		cout << "Roll Number: " << rollNumber << endl;
		cout << "Subjects:" << endl;
		for (int i = 0; i < subjectCount; ++i) {
			cout << "  " << subjects[i].getSubjectName() << " (Credits: " << subjects[i].getCreditHours() << ", Marks: " << subjects[i].getMarks() << ")" << endl;
		}
		cout << "GPA: " << calculateGPA() << endl;
	}

	bool operator<(const Student& other) const {
		return calculateGPA() < other.calculateGPA();
	}

	bool operator>(const Student& other) const {
		return calculateGPA() > other.calculateGPA();
	}
};

class UndergraduateStudent : public Student {

public:

	UndergraduateStudent(const string& name = "", const string& address = "", int roll = 0) : Student(name, address, roll) {}
};

class PostgraduateStudent : public Student {

private:

	string thesisTopic;

public:

	PostgraduateStudent(const string& name = "", const string& address = "", int roll = 0, const string& topic = "") : Student(name, address, roll), thesisTopic(topic) {}

	void setThesisTopic(const string& topic) {
		thesisTopic = topic;
	}

	string getThesisTopic() const {
		return thesisTopic;
	}
};

void readStudentsFromFile(const string& filename, Student students[], int& count)
{
	ifstream inFile;
	inFile.open(filename);
	if (inFile.is_open())
	{
		count = 0;
		while (inFile && count < 3)
		{
			string name, address, subjectName;
			int rollNumber, creditHours;
			float marks;

			inFile >> name >> address >> rollNumber;
			students[count] = Student(name, address, rollNumber);

			int subjectCount;
			inFile >> subjectCount;

			for (int i = 0; i < subjectCount; ++i)
			{
				inFile >> subjectName >> marks >> creditHours;
				students[count].addSubject(Subject(subjectName, creditHours, marks));
			}
			++count;
		}
	}
	else
	{
		cout << "Error: Unable to open file " << filename << endl;
	}
	inFile.close();
}



void writeStudentsToFile(const string& filename, Student students[], int& count)
{
	ofstream outFile;
	outFile.open(filename);
	if (outFile.is_open())
	{
		for (int i = 0; i < count; ++i)
		{
			outFile << students[i].getName() << " " << students[i].getRollNumber() << " " << students[i].calculateGPA() << endl;
		}
	}
	else
	{
		cout << "Error: Unable to open file " << filename << endl;
	}
	outFile.close();
}

class Grade
{
private:

	float gpa;

public:

	Grade(float gpa = 0.0f) : gpa(gpa) {}


	bool operator<(const Grade& other) const {
		return gpa < other.gpa;
	}

	bool operator>(const Grade& other) const {
		return gpa > other.gpa;
	}

	Grade operator+(const Grade& other) const {
		return Grade(gpa + other.gpa);
	}
};

int main() {

	Student students[3];
	int studentCount = 0;

	readStudentsFromFile("students.txt", students, studentCount);

	for (int i = 0; i < studentCount; ++i)
	{
		students[i].display();
	}

	if (students[1] > students[0]) {
		cout << students[1].getName() << " has a higher GPA than " << students[0].getName() << ".\n";
	}
	if (students[1] > students[2]) {
		cout << students[1].getName() << " has a higher GPA than " << students[2].getName() << ".\n";
	}
	if (students[2] > students[0]) {
		cout << students[2].getName() << " has a higher GPA than " << students[0].getName() << ".\n";
	}
	if (students[2] > students[1]) {
		cout << students[2].getName() << " has a higher GPA than " << students[1].getName() << ".\n";
	}
	if (students[0] > students[1]) {
		cout << students[0].getName() << " has a higher GPA than " << students[1].getName() << ".\n";
	}
	if (students[0] > students[2]) {
		cout << students[0].getName() << " has a higher GPA than " << students[2].getName() << ".\n";
	}

	writeStudentsToFile("output.txt", students, studentCount);

	system("pause");
	return 0;
}
