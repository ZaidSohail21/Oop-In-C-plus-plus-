//#include<iostream>
//#include<string>
//using namespace std;
//class Student
//{
//	int studentID;
//	double GPA;
//	string degreeName, studentName;
//public:
//	void display()
//	{
//		cout << "Enter the Student ID: ";
//		cin >> studentID;
//		cout << "Enter your Name: ";
//		cin >> studentName;
//		cout << "Enter the Dergree: ";
//		cin >> degreeName;
//		cout << "Enter the GPA: ";
//		cin >> GPA;
//	}
//	double calculatePercentage(double total, double obt)
//	{
//		double per = (obt / total) * 100;
//		return per;
//	}
//	void disPercantage(double Percentage)
//	{
//
//		if (Percentage >= 86)
//		{
//			cout << "The Grade is 'A+'.";
//		}
//		else if (Percentage >= 82)
//		{
//			cout << "The Grade is 'A'.";
//		}
//		else if (Percentage >= 78)
//		{
//			cout << "The Grade is 'B+'.";
//		}
//		else if (Percentage >= 74)
//		{
//			cout << "The Grade is 'B'.";
//		}
//		else if (Percentage >= 70)
//		{
//			cout << "The Grade is 'B-'.";
//		}
//		else if (Percentage >= 66)
//		{
//			cout << "The Grade is 'C+'.";
//		}
//		else if (Percentage >= 62)
//		{
//			cout << "The Grade is 'C'.";
//		}
//		else if (Percentage >= 58)
//		{
//			cout << "The Grade is 'C-'.";
//		}
//		else if (Percentage >= 54)
//		{
//			cout << "The Grade is 'D+'.";
//		}
//		else if (Percentage >= 50)
//		{
//			cout << "The Grade is 'D'.";
//		}
//		else if (Percentage <50)
//		{
//			cout << "The Grade is 'F'.";
//		}
//
//	}
//};
//int main()
//{
//	Student s1;
//	s1.display();
//
//	double total, obtain;
//	cout << "Enter Your obtained marks: ";
//	cin >> obtain;
//	cout << "Enter Your total marks: ";
//	cin >> total;
//
//	double Percentage = s1.calculatePercentage(total, obtain);
//	s1.disPercantage(Percentage);
//	cout << endl;
//	system("pause");
//	return 0;
//}
