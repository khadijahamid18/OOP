#include <iostream>
using namespace std;

class Account
{
protected:

    int accountNumber;
    string accountType;
    float balance;

public:
    Account()
    {
        this->accountNumber = 0;
        this->accountType = "";
        this->balance = 0;
    }

    Account(const Account &obj)
    {
        this->accountNumber = obj.accountNumber;
        this->accountType = obj.accountType;
        this->balance = obj.balance;
    }

    // Member Functions

    void display()
    {
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Account Type: " << getAccountType() << endl;
        cout << "Balance: " << getBalance() << endl;
        cout << endl;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    string getAccountType()
    {
        return accountType;
    }

    float getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        this->balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount > this->balance)
        {
            cout << "Error: The balance is not sufficient" << endl;
        }
        else
        {
            this->balance -= amount;
        }
    }
};

class SavingsAccount : public Account
{
    float interestRate;

public:

    SavingsAccount() : Account()
    {
        this->interestRate = 0;
    }

    SavingsAccount(const SavingsAccount &obj) : Account(obj)
    {
        this->interestRate = obj.interestRate;
    }

    SavingsAccount(int accNum, string accType, float balance, float intRate)
    {
        this->accountNumber = accNum;
        this->accountType = accType;
        this->balance = balance;
        this->interestRate = intRate;
    }

    // Member Function

    float getInterestRate()
    {
        return interestRate;
    }

    void setInterestRate(float intRate)
    {
        this->interestRate = intRate;
    }
};

class CheckingAccount : public Account
{
    float overDraftLimit;

public:

    CheckingAccount(int accNum, string accType, float balance, float limit)
    {
        this->accountNumber = accNum;
        this->accountType = accType;
        this->balance = balance;
        this->overDraftLimit = limit;
    }

    float getOverDraftLimit()
    {
        return overDraftLimit;
    }

    void setOverDraftLimit(float limit)
    {
        this->overDraftLimit = limit;
    }

};

int main()
{
    system("cls");

    SavingsAccount obj(13, "Dija", 5000, 0.5);
    CheckingAccount obj1(15, "Check", 1000, 0.5);
    obj.display();

    obj.deposit(200);
    obj.display();

    obj.withdraw(1000);
    obj.display();

    obj1.deposit(300);
    obj1.display();



    return 0;
}