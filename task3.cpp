//#include <iostream>
//#include <string>
//using namespace std;
//class Sports{
//public:
//	string name;
//	int id;
//	
//
//	Sports() :name("null"), id(0){ cout << "Sports Constructor " << endl; }
//	Sports(string n, int i) :name(n), id(i){ cout << "Sports Constructor " << endl; }
//
//	//display
//	void display(){
//		cout << "Name :" << name << endl;
//		cout << "ID :" << id << endl;
//	}
//};
//class Team :public Sports{
//public:
//	string teamname;
//	Team() :Sports(),teamname("null") { cout << "Team  Constructor " << endl; }
//	Team(string n, int i,string t ) :Sports(n, i),teamname(t){ cout << "Team  Constructor " << endl; }
//};
//class Player:public Team{
//public:
//	string name;
//	int years;
//
//
//	Player() :name("null"), years(0){ cout << "Player Constructor " << endl; }
//	Player(string name,int id,string t,string n, int i) :Team(name,id,t),name(n), years(i){ cout << "Player Constructor " << endl; }
//
//	//display
//	void display(Sports s1,Team t1){
//		cout << "SportsName :" << s1.name << endl;
//		cout << "Playerid :" << s1.id << endl;
//		cout << "Teamname :" << t1.teamname << endl;
//		cout << "PLayer Name :" << name << endl;
//		cout << "Expyears :" << years << endl;
//	}
//};
//int main(){
//	Sports s1("cricket", 0314);
//	Team t1("cricket", 0314,"lahore");
//	Player p1("cricket", 0314, "lahore", "zaid", 5);
//	p1.display(s1, t1);
//	system("pause");
//	return 0;
//}