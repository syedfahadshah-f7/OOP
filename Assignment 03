#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Medicine {
protected:
    string name, formula, mDate, eDate; // mDate == manufacture date , eDate = Expiry date
    float retailPrice;

public:
    Medicine(string n, string f, string mDate, string eDate, float price)
        : name(n), formula(f), mDate(mDate), eDate(eDate), retailPrice(price) {}

    void set_name(string name) {
        this->name = name;
    }
    void set_formula(string formula) {
        this->formula = formula;
    }
    void set_mDate(string date) {
        this->mDate = date;
    }
    void set_eDate(string date) {
        this->eDate = date;
    }
    void set_retailPrice(float price) {
        this->retailPrice = price;
    }

    string get_name() const {
        return name;
    }
    string get_formula() const {
        return formula;
    }
    string get_mDate() const {
        return mDate;
    }
    string get_eDate() const {
        return eDate;
    }
    float get_retailPrice() const {
        return retailPrice;
    }

    virtual void printing() const {
        cout << "Name: " << name << endl
             << "Formula: " << formula << endl
             << "Manufacture Date: " << mDate << endl
             << "Expiry Date: " << eDate << endl
             << "Retail Price: " << retailPrice << endl;
    }

    bool operator==(const Medicine &med) const {
        return this->eDate.substr(0, 4) == med.eDate.substr(0, 4);
    }
};

class Tablets : public Medicine {
protected:
    float surcoseLevel;

public:
    Tablets(float srLevel, string n, string f, string mDate, string eDate, float price)
        : surcoseLevel(srLevel), Medicine(n, f, mDate, eDate, price) {}

    void printing() const override {
        Medicine::printing();
        cout << "Surcose Level: " << surcoseLevel << endl;
    }
};

class Capsule : public Medicine {
protected:
    float absorptionPer;

public:
    Capsule(float abPer, string n, string f, string mDate, string eDate, float price)
        : absorptionPer(abPer), Medicine(n, f, mDate, eDate, price) {}

    void printing() const override {
        Medicine::printing();
        cout << "Absorption Percentage: " << absorptionPer << endl;
    }
};

class Syrup : public Medicine {
protected:
    float alcohol;

public:
    Syrup(float alcohol, string n, string f, string mDate, string eDate, float price)
        : alcohol(alcohol), Medicine(n, f, mDate, eDate, price) {}

    void printing() const override {
        Medicine::printing();
        cout << "Percentage of Alcohol: " << alcohol << endl;
    }
};

class Pharmacist {
public:
    void Search_Medicine(const vector<Medicine> &medicines, const string &formula) const {
        for (const auto &medicine : medicines) {
            if (medicine.get_formula() == formula) {
                medicine.printing();
            }
        }
    }
};

class Counter {
    float totalRevenue;

public:
    void Search_Medicine(const vector<Medicine> &medicines, const string &name) const {
        for (const auto &medicine : medicines) {
            if (medicine.get_name() == name) {
                medicine.printing();
            }
        }
    }

    void Update_Revenue(float price) {
        this->totalRevenue += price;
    }
};

int main() {
    vector<Medicine> medicines;
    Medicine med1("Panadol", "form1", "2024-04-15", "2024-07-20", 2.5);
    Tablets tab1(0.65, "Risik", "form2", "2024-04-15", "2026-07-20", 20.05);
    Capsule cap1(75, "Rithmo", "form3", "2024-04-15", "2027-07-20", 50.8);
    Syrup syr1(200, "Accyfyl", "form4", "2024-04-15", "2024-07-20", 200);

    medicines.push_back(med1);
    medicines.push_back(tab1);
    medicines.push_back(cap1);
    medicines.push_back(syr1);

    Pharmacist pharmacist;
    Counter counter;

    pharmacist.Search_Medicine(medicines, "form3");
    counter.Search_Medicine(medicines, "Panadol");
    counter.Update_Revenue(1500.9);

    return 0;
}
