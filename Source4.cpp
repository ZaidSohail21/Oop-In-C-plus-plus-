//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class BankAccount {
//private:
//	string accountHolder;
//	double balance;
//
//public:
//	// Constructor
//	BankAccount(string name, double initialBalance) {
//		accountHolder = name;
//		balance = initialBalance;
//	}
//
//	// Method to deposit money
//	void deposit(double amount) {
//		balance += amount;
//	}
//
//	// Method to withdraw money
//	void withdraw(double amount) {
//		if (amount <= balance) {
//			balance -= amount;
//		}
//		else {
//			cout << "Insufficient balance!" << endl;
//		}
//	}
//
//	// Method to display account information
//	void displayAccountInfo() const {
//		cout << "Account Holder: " << accountHolder << endl;
//		cout << "Balance: $" << balance << endl;
//	}
//
//	// Getter for account holder name
//	string getAccountHolder() const {
//		return accountHolder;
//	}
//
//	// Getter for account balance
//	double getBalance() const {
//		return balance;
//	}
//};
//
//class Bank {
//private:
//	static BankAccount** accounts;  // Pointer to an array of pointers to BankAccount
//	static int totalAccounts;       // To track the number of accounts
//
//public:
//	// Method to add a BankAccount to the Bank
//	static void addAccount(BankAccount* account) {
//		// Dynamically allocate a new array to accommodate the new account
//		BankAccount** newAccounts = new BankAccount*[totalAccounts + 1];
//
//		// Copy existing accounts into the new array
//		for (int i = 0; i < totalAccounts; ++i) {
//			newAccounts[i] = accounts[i];
//		}
//
//		// Add the new account to the new array
//		newAccounts[totalAccounts] = account;
//
//		// Delete the old array and update the accounts pointer
//		delete[] accounts;
//		accounts = newAccounts;
//
//		// Increment the total number of accounts
//		totalAccounts++;
//	}
//
//	// Method to display all accounts
//	static void displayAllAccounts() {
//		for (int i = 0; i < totalAccounts; ++i) {
//			accounts[i]->displayAccountInfo();
//			cout << "-------------------------" << endl;
//		}
//	}
//
//	// Destructor to clean up the dynamically allocated memory
//	static void cleanup() {
//		for (int i = 0; i < totalAccounts; ++i) {
//			delete accounts[i];
//		}
//		delete[] accounts;
//	}
//};
//
//// Initialize the static members of the Bank class
//BankAccount** Bank::accounts = nullptr;
//int Bank::totalAccounts = 0;
//
//int main() {
//	// Create BankAccount objects
//	BankAccount* account1 = new BankAccount("John Doe", 1500.0);
//	BankAccount* account2 = new BankAccount("Jane Smith", 2500.0);
//	BankAccount* account3 = new BankAccount("Alice Brown", 3200.0);
//
//	// Add accounts to the Bank
//	Bank::addAccount(account1);
//	Bank::addAccount(account2);
//	Bank::addAccount(account3);
//
//	// Display all accounts
//	cout << "All Bank Accounts: " << endl;
//	Bank::displayAllAccounts();
//
//	// Example of performing some operations
//	account1->deposit(500.0);  // Deposit to account1
//	account2->withdraw(1000.0); // Withdraw from account2
//
//	cout << "\nAfter some transactions:\n";
//	Bank::displayAllAccounts();
//
//	// Clean up dynamically allocated memory
//	Bank::cleanup();
//
//	return 0;
//}