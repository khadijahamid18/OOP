#include <iostream>
using namespace std;

class Package
{
protected:
    string nameOfSender;
    string nameOfReceiver;
    string addressOfSender;
    string addressOfReceiver;
    string cityOfSender;
    string cityOfReceiver;
    float weight;
    float costPerOunce;

public:
    Package(string nS, string nR, string aS, string aR, string cS, string cR, float w, float c)
    {
        this->nameOfSender = nS;
        this->nameOfReceiver = nR;
        this->addressOfSender = aS;
        this->addressOfReceiver = aR;
        this->cityOfSender = cS;
        this->cityOfReceiver = cR;

        if (w > 0)
        {
            this->weight = w;
        }
        else
        {
            cout << "Please enter the positive value for weight" << endl;
            weight = 0;
        }

        if (c > 0)
        {
            this->costPerOunce = c;
        }
        else
        {
            cout << "Please enter the positive value for cost" << endl;
            costPerOunce = 0;
        }
    }

    virtual float calculateCost()
    {
        float total;
        total = weight * costPerOunce;
        return total;
    }
};

class TwoDayPackage : public Package
{
    float flatFee;

public:
    TwoDayPackage(string nS, string nR, string aS, string aR, string cS, string cR, float w, float c, float fee) : Package(nS, nR, aS, aR, cS, cR, w, c)
    {
        if (fee > 0)
        {
            flatFee = fee;
        }
        else
        {
            cout << "Please enter the positive value for fee" << endl;
            flatFee = 0;
        }
    }

    float calculateCost()
    {
        float fee = this->Package::calculateCost();
        return fee + flatFee;
    }
};

class OverNightPackage : public Package
{
    float feePerOunce;

public:
    OverNightPackage(string nS, string nR, string aS, string aR, string cS, string cR, float w, float c, float fee) : Package(nS, nR, aS, aR, cS, cR, w, c)
    {
        if (fee > 0)
        {
            feePerOunce = fee;
        }
        else
        {
            cout << "Please enter the positive value for fee" << endl;
            fee = 0;
        }
    }

    virtual float calculateCost() override
    {
        return weight * (costPerOunce + feePerOunce);
    }
};

int main()
{
    system("cls");

    Package p("Ab", "Re", "Lahore", "Lahore", "Lahore", "Lahore", 2.5, 10);
    cout << p.calculateCost() << endl;

    TwoDayPackage t("Ab", "Re", "Lahore", "Lahore", "Lahore", "Lahore", 2.5, 10, 100);
    cout << t.calculateCost() << endl;

    OverNightPackage m("Ab", "Re", "Lahore", "Lahore", "Lahore", "Lahore", 2.5, 10, 10);
    cout << m.calculateCost() << endl;

    Package *ptr = &m;
    cout << ptr->calculateCost() << endl;

    return 0;
}