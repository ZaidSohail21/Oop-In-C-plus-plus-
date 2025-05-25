//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class BankAccount;  // Forward declaration of the BankAccount class
//
//class Bank {
//private:
//    static int totalAccounts;  // Static member for the total number of accounts
//    static float totalBalance; // Static member for the total balance in the bank
//
//public:
//    Bank() {
//        totalAccounts = 0;
//        totalBalance = 0.0f;
//    }
//
//    // Public getter function for totalBalance
//    static float getTotalBalance() {
//        return totalBalance;
//    }
//
//    // Public getter function for totalAccounts
//    static int getTotalAccounts() {
//        return totalAccounts;
//    }
//
//    // Add an account to the bank and update static count and total balance
//    void addAccount(BankAccount& account);
//
//    // Display the total accounts and total balance in the bank
//    void displayBankInfo() const {
//        
//
//    }
//
//    // Friend function to perform a deposit or withdrawal
//    friend void performDepositOrWithdrawal(BankAccount& account, float amount, int transactionType);
//};
//
//// Static member initialization
//int Bank::totalAccounts = 0;
//float Bank::totalBalance = 0.0f;
//
//class BankAccount {
//private:
//    char* name;
//    char* accountNumber;
//    float balance;
//
//public:
//    BankAccount(const char* n, const char* accNo, float bal) {
//        name = new char[strlen(n) + 1];
//        strcpy(name, n);
//        accountNumber = new char[strlen(accNo) + 1];
//        strcpy(accountNumber, accNo);
//        balance = bal;
//    }
//
//    // Destructor to free dynamically allocated memory
//    ~BankAccount() {
//        delete[] name;
//        delete[] accountNumber;
//    }
//
//    // Display account details
//    void display() const {
//
//
//
//    }
//
//    // Getter function for balance
//    float getBalance() const {
//        return balance;
//    }
//
//    // Friend function to perform a deposit or withdrawal
//    friend void performDepositOrWithdrawal(BankAccount& account, float amount, int transactionType);
//
//    // Overloaded + operator to add the balances of two accounts
//    BankAccount operator + (const BankAccount& other) const {
//*********************************************************
//Fill this missing code to add balance of two BankAccount objects.
//*********************************************************
//    }
//
//    // Static method to increment the number of accounts
//    static void incrementAccountCount() {
//        Bank::totalAccounts++;  // Access the static member via the class name
//    }
//};
//
//// Friend function definition to perform a deposit or withdrawal
//
//void performDepositOrWithdrawal(BankAccount& account, float amount, int transactionType) {
//    // For transactionType, consider 1 for deposit and 2 for withdrawal
//
//    if (transactionType == 1) 
//     { // Deposit operation
//        *********************************************************
//Fill this missing code to add balance for transactionType 1 in totalBalance
//*********************************************************
//
//    } 
//else if (transactionType == 2)   
//         { // Withdraw operation
//       
//*********************************************************
//Fill this missing code to remove balance for transactionType 2 in totalBalance
//*********************************************************
//        } 
//
//else 
//{
//            cout << "Error: Insufficient funds for withdrawal!" << endl;
//        
//}
//    } 
//
//else 
//{
//        cout << "Invalid transaction type!" << endl;
// }
//}
//
//// Implement Bank::addAccount function
//void Bank::addAccount(BankAccount& account) 
//{
//    totalAccounts++;     	// Increment the account count
//    totalBalance += account.getBalance(); // Update total balance in bank
//}
//
//// Main Function to demonstrate the Banking System
//int main() 
//{
//    // Create atleast two or more bank instance or objects
//
//    // Create bank account instances
//    
//
//    // Add accounts to the bank and update the bank's total balance
//    myBank.addAccount(acc1);
//
//    // Display account details
//
//    // Perform transactions using friend function (1 = Deposit, 2 = Withdrawal)
//    performDepositOrWithdrawal(acc1, 500, 1);    // Deposit operation
//    
//
//    // Display updated account details
//    cout << "\nAfter Transactions:" << endl;
//
//    // Overload + operator to combine two accounts' balances
//    BankAccount combinedAccount = acc1 + acc2;
//    cout << "\nCombined Account:" << endl;
// 
//
//    // Display bank information
//  
//  myBank.displayBankInfo();
//
//    return 0;
//}
