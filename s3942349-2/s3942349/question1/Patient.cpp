#include <iostream>
#include <string>
#include <vector>

class History {
    std::string admission, discharge, ward;
public:
    History(std::string ad, std::string di, std::string wa) {
        admission = ad;
        discharge = di;
        ward = wa;
    }
    History() {
    }
    friend std::ostream& operator<<(std::ostream& os, const History& hs) {
        os << hs.admission << " - " << hs.discharge << " - " << hs.ward << std::endl;
        return os;
    }
};

class Patient {

    std::string pName, pDOB;
    int pNumber;
    std::vector<History> pHistory;

public:
    Patient(std::string name, std::string dob, int number, std::vector<History> history)
    {
        pName = name;
        pDOB = dob;
        pNumber = number;
        pHistory = history;
    }
    Patient() {
    }
    ~Patient() {
    }
    friend std::ostream& operator<<(std::ostream& os, const Patient& pt) {
        os << pt.pName << '\n' << pt.pDOB << '\n' << pt.pNumber << "\n";
        for (History i: pt.pHistory) {
            os << i;
        }
        return os;
    }

    int getNumber() {
        return pNumber;
    }
};
