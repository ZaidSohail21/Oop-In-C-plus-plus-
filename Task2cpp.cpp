#include <iostream>
#include <string>
using namespace std;

class BankAccount;  // Forward declaration of the BankAccount class

class Bank {
private:
	static int totalAccounts;  // Static member for the total number of accounts
	static float totalBalance; // Static member for the total balance in the bank

public:
	Bank() {
		totalAccounts = 0;
		totalBalance = 0.0f;
	}

	// Public getter function for totalBalance
	static float getTotalBalance() {
		return totalBalance;
	}

	// Public getter function for totalAccounts
	static int getTotalAccounts() {
		return totalAccounts;
	}

	// Add an account to the bank and update static count and total balance
	void addAccount(BankAccount& account);

	// Display the total accounts and total balance in the bank
	void displayBankInfo() const {
		cout << "Total Accounts: " << getTotalAccounts() << endl;
		cout << "Total Balance: $" << totalBalance << endl;
	}

	// Friend function to perform a deposit or withdrawal
	friend void performDepositOrWithdrawal(BankAccount& account, float amount, int transactionType);
};

// Static member initialization
int Bank::totalAccounts = 0;
float Bank::totalBalance = 0.0f;

class BankAccount {
private:
	char* name;
	char* accountNumber;
	float balance;

public:
	BankAccount(const char* n, const char* accNo, float bal) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		accountNumber = new char[strlen(accNo) + 1];
		strcpy(accountNumber, accNo);
		balance = bal;
	}

	// Destructor to free dynamically allocated memory
	~BankAccount() {
		delete[] name;
		delete[] accountNumber;
	}

	// Display account details
	void display() const {
		cout << "Account Holder: " << name << endl;
		cout << "Account Number: " << accountNumber << endl;
		cout << "Balance: $" << balance << endl;
	}

	// Getter function for balance
	float getBalance() const {
		return balance;
	}

	// Friend function to perform a deposit or withdrawal
	friend void performDepositOrWithdrawal(BankAccount& account, float amount, int transactionType);

	// Overloaded + operator to add the balances of two accounts
	BankAccount operator + (const BankAccount& other) const {
		float newBalance = this->balance + other.balance;
		// Create a new BankAccount with the combined balance (assuming names are the same for simplicity)
		return *this;
	}

	// Static method to increment the number of accounts
	//static void incrementAccountCount() {
	//	Bank::totalAccounts++;  // Access the static member via the class name
	//}
};

// Friend function definition to perform a deposit or withdrawal
void performDepositOrWithdrawal(BankAccount& account, float amount, int transactionType) {
	if (transactionType == 1) {  // Deposit operation
		account.balance += amount;
		Bank::totalBalance += amount;  // Add to the total balance in the bank
		cout << "$" << amount << " deposited successfully." << endl;
	}
	else if (transactionType == 2) {  // Withdraw operation
		if (account.balance >= amount) {
			account.balance -= amount;
			Bank::totalBalance -= amount;  // Subtract from the total balance in the bank
			cout << "$" << amount << " withdrawn successfully." << endl;
		}
		else {
			cout << "Error: Insufficient funds for withdrawal!" << endl;
		}
	}
	else {
		cout << "Invalid transaction type!" << endl;
	}
}

// Implement Bank::addAccount function
void Bank::addAccount(BankAccount& account) {
	totalAccounts++;     	// Increment the account count
	totalBalance += account.getBalance(); // Update total balance in bank
}

// Main Function to demonstrate the Banking System
int main() {
	// Create instances of Bank and BankAccount
	Bank myBank;

	BankAccount acc1("John Doe", "12345", 1000.0f);
	BankAccount acc2("Jane Smith", "67890", 1500.0f);

	// Add accounts to the bank and update the bank's total balance
	myBank.addAccount(acc1);
	myBank.addAccount(acc2);

	// Display account details
	cout << "\nAccount Details:" << endl;
	acc1.display();
	acc2.display();

	// Perform transactions using friend function (1 = Deposit, 2 = Withdrawal)
	performDepositOrWithdrawal(acc1, 500, 1);    // Deposit operation

	// Display updated account details
	cout << "\nAfter Transactions:" << endl;
	acc1.display();

	// Overload + operator to combine two accounts' balances
	BankAccount combinedAccount = acc1 + acc2;
	cout << "\nCombined Account:" << endl;
	combinedAccount.display();

	// Display bank information
	myBank.displayBankInfo();

	return 0;
}
