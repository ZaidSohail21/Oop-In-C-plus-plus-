#include <iostream>
using namespace std;
class bankaccount;
class bank{

public:
	static int total;
	void addaccount(bankaccount&obj){
		total++;
	}
	void display()const{
		cout << "Total account :" << total << endl;
	}
};
class bankaccount{
	int x;
public:
	bankaccount() :x(0){ }

};
int bank::total = 0;
int main(){
	bank hbl;
	bankaccount zaid;
	hbl.addaccount(zaid);
	bankaccount ali;
	hbl.addaccount(ali);
	bankaccount basil;
	hbl.addaccount(basil);
	hbl.display();
	system("pause");
	return 0;

}