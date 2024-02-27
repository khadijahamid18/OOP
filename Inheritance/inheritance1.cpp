#include <iostream>
using namespace std;

class Account
{
protected:
    string firstName;
    string lastName;
    double currentBalance;

public:
    Account(string firstName, string lastName, double currentBalance)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->currentBalance = currentBalance;
    }

    virtual string getAcctType() const
    {
        return "Account";
    }

    virtual double debitTransaction(double debitamount)
    {
        currentBalance -= debitamount;
        return currentBalance;
    }

    virtual double creditTransaction(double creditamount)
    {
        currentBalance += creditamount;
        return currentBalance;
    }

    void print()
    {
        cout << firstName << " " << lastName << " " << getAcctType() << " " << currentBalance << endl;
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(string firstName, string lastName, double currentBalance) : Account(firstName, lastName, currentBalance)
    {
    }

    virtual string getAcctType() const
    {
        return "CheckingAccount";
    }

    virtual double debitTransaction(double debitamount)
    {
        chargeFee();
        // currentBalance -= debitamount;
        return Account::debitTransaction(debitamount);
    }

    virtual double creditTransaction(double creditamount)
    {
        chargeFee();
        // currentBalance += creditamount;
        return Account::creditTransaction(creditamount);
    }

private:
    void chargeFee()
    {
        currentBalance -= 10;
    }
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(string firstName, string lastName, double currentBalance) : Account(firstName, lastName, currentBalance)
    {
    }

    virtual string getAcctType() const
    {
        return "SavingsAccount";
    }

    virtual double debitTransaction(double debitamount)
    {
        payInterest();
        int transaction;
        if (transaction < 2)
        {
            transaction++;
            return Account::debitTransaction(debitamount);
        }
        return currentBalance;
    }

    virtual double creditTransaction(double creditamount)
    {
        payInterest();
        int transaction;
        if (transaction < 2)
        {
            transaction++;
            return Account::creditTransaction(creditamount);
        }
        return currentBalance;
    }

    void payInterest()
    {
        currentBalance *= 0.02;
    }
};

int main()
{
    system("cls");
    Account *ac2 = new SavingsAccount("Saud", "Yaseen", 200.0);
    Account *ac1 = new CheckingAccount("Hunain", "Shahid", 1000.0);

    cout << "*** Two accounts ***" << endl;
    ac2->print();
    ac1->print();

    cout << "=== Test for CheckingAccount ===" << endl;
    cout << "(1) Debitting 150.00 -- The balance is " << ac1->debitTransaction(150.0) << endl;
    cout << "(2) Debitting 5.00 -- The balance is " << ac1->debitTransaction(5.0) << endl;
    cout << "(3) Crediting 200.00 -- The balance is " << ac1->creditTransaction(200.0) << endl;
    cout << "(*) Final account information" << endl;

    return 0;
}