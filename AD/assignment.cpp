#include <iostream>
using namespace std;

class BankAccount
{
    int accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount()
    {
        accountNumber = 0;
        accountHolder = "";
        balance = 0;
    }

    BankAccount(int accountNumber, string accountHolder, double balance)
    {
        this->accountNumber = accountNumber;
        this->accountHolder = accountHolder;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        this->balance += amount;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "Error: Info is incorrect" << endl;
        }
    }

    void withdraw(double amount) const
    {
        cout << " Your account is currently frozen/deactivated" << endl;
    }

    // - a function that transfers the specified
    // amount from the current account to the specified other account. If the amount is greater
    // than the current account's balance, an error message should be displayed.,
    void transfer(BankAccount &other, double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            other.balance += amount;
        }
        else
        {
            cout << "Error: Info is incorrect" << endl;
        }
    }

    void transfer(BankAccount &other, double amount) const
    {
        cout << " Your account is currently frozen/deactivated" << endl;
    }

    void displayAccountInfo() const
    {
        cout << "Account number: " << getAccountNumber() << endl;
        cout << "Account holder: " << getAccountHolder() << endl;
        cout << "Account balance: " << getBalance() << endl;
    }

    void setAccountNumber(int accountNumber)
    {
        this->accountNumber = accountNumber;
    }

    int getAccountNumber() const
    {
        return accountNumber;
    }

    void setAccountHolder(string accountHolder)
    {
        this->accountHolder = accountHolder;
    }

    string getAccountHolder() const
    {
        return accountHolder;
    }

    double getBalance() const
    {
        return balance;
    }
};

void display(const BankAccount& obj)
{
    obj.displayAccountInfo();
}

int main()
{
    system("cls");

    BankAccount account1(13, "Khadija Hamid", 10.0);
    BankAccount account2(15, "Saad Hamid", 50.0);

    // deposit and withdraw
    account1.deposit(200.0);
    account1.withdraw(100.0);
    account1.withdraw(1500.0); //  display error message

    account1.displayAccountInfo();
    account2.displayAccountInfo();

    // transfer
    account1.transfer(account2, 300.0);
    account1.transfer(account2, 2000.0); //  display error message

    // const object
    const BankAccount account3(14, "Walid Hamid", 70.0);
    account3.displayAccountInfo();

    // account3.deposit(100.0); //  print error message
    // account3.withdraw(50.0); //  print error message

    return 0;
}