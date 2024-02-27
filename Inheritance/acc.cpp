#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int accountNumber;
    string accountType;
    float balance;

public:
    Account() : accountNumber(0), accountType(""), balance(0) {}
    Account(int accNum, string accType, float bal) : accountNumber(accNum), accountType(accType), balance(bal) {}
    Account(const Account &obj) : accountNumber(obj.accountNumber), accountType(obj.accountType), balance(obj.balance) {}
    void Display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
    int GetAccountNumber() { return accountNumber; }
    string GetAccountType() { return accountType; }
    float GetBalance() { return balance; }
    void Deposit(float amount) { balance += amount; }
    virtual void Withdraw(float amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient balance." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        }
    }
};

class SavingsAccount : public Account
{
private:
    float interestRate;

public:
    SavingsAccount() : interestRate(0) {}
    SavingsAccount(int accNum, string accType, float bal, float intRate) : Account(accNum, accType, bal), interestRate(intRate) {}
    SavingsAccount(const SavingsAccount &obj) : Account(obj), interestRate(obj.interestRate) {}
    float GetInterestRate() { return interestRate; }
    void SetInterestRate(float rate) { interestRate = rate; }
};

class CheckingAccount : public Account
{
private:
    float overdraftLimit;

public:
    CheckingAccount() : overdraftLimit(0) {}
    CheckingAccount(int accNum, string accType, float bal, float odl) : Account(accNum, accType, bal), overdraftLimit(odl) {}
    CheckingAccount(const CheckingAccount &obj) : Account(obj), overdraftLimit(obj.overdraftLimit) {}
    float GetOverdraftLimit() { return overdraftLimit; }
    void SetOverdraftLimit(float limit) { overdraftLimit = limit; }
    void Withdraw(float amount) override
    {
        if (amount > balance + overdraftLimit)
        {
            cout << "Withdrawal amount exceeds the overdraft limit." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        }
    }
};

int main()
{
    // Create a savings account object
    SavingsAccount sa(1001, "Savings", 5000, 0.05);
    sa.Display();

    // Deposit some money into the savings account
    sa.Deposit(1000);
    cout << "After deposit:" << endl;
    sa.Display();

    // Withdraw some money from the savings account
    sa.Withdraw(2000);
    cout << "After withdrawal:" << endl;
    sa.Display();

    // Create a checking account object
    CheckingAccount ca(2001, "Checking", 10000, 5000);
    ca.Display();

    // Withdraw some money from the checking account
    ca.Withdraw(15000);
    cout << "After withdrawal:" << endl;
    ca.Display();

    return 0;
}
