#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Transaction {
private:
	T amount;
	int transactionID;
	char* transactionType;
	string date;

public:
	Transaction(T amt, int id, const char* type, const string& txnDate) {
		amount = amt;
		transactionID = id;
		transactionType = new char[strlen(type) + 1];
		strcpy(transactionType, type);
		date = txnDate;
	}

	~Transaction() {
		delete[] transactionType;
	}

	bool validate(T accountBalance) {
		if (strcmp(transactionType, "credit") == 0) {
			return amount > 0;
		}
		else if (strcmp(transactionType, "debit") == 0) {
			return amount > 0 && amount <= accountBalance;
		}
		return false;
	}

	void process(T &accountBalance) {
		if (validate(accountBalance)) {
			if (strcmp(transactionType, "credit") == 0) {
				accountBalance += amount;
			}
			else if (strcmp(transactionType, "debit") == 0) {
				accountBalance -= amount;
			}
		}
		else {
			cout << "Transaction is not valid." << endl;
		}
	}

	void display() const {
		cout << "Transaction ID: " << transactionID << endl;
		cout << "Transaction Type: " << transactionType << endl;
		cout << "Amount: " << amount << endl;
		cout << "Date: " << date << endl;
	}
};

int main() {
	int accountBalanceInt = 1000;
	Transaction<int> txn1(200, 101, "credit", "2025-01-28");
	txn1.display();
	txn1.process(accountBalanceInt);
	cout << "New account balance: " << accountBalanceInt << endl;

	float accountBalanceFloat = 500.5f;
	Transaction<float> txn2(100.25f, 102, "debit", "2025-01-28");
	txn2.display();
	txn2.process(accountBalanceFloat);
	cout << "New account balance: " << accountBalanceFloat << endl;

	double accountBalanceDouble = 2500.75;
	Transaction<double> txn3(300.50, 103, "credit", "2025-01-28");
	txn3.display();
	txn3.process(accountBalanceDouble);
	cout << "New account balance: " << accountBalanceDouble << endl;

	char accountBalanceChar = 50;
	Transaction<char> txn4(20, 104, "debit", "2025-01-28");
	txn4.display();
	txn4.process(accountBalanceChar);
	cout << "New account balance: " << (int)accountBalanceChar << endl;
	cout << "hi" << endl;
	system("pause");
	return 0;
}
