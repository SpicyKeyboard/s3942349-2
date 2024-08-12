#include <string>
#include <vector>
#include "PatientRegister.cpp"

class Ward {

public:

    std::string wardName;
    std::vector<Patient> wardPatients;
    PatientRegister pr;

    Ward(std::string name, std::vector<Patient> patients) {
        wardName = name;
        wardPatients = patients;
    }
    Ward() {}
    ~Ward() {}
    friend std::ostream& operator<<(std::ostream& os, const Ward& w) {
        for (Patient i: w.wardPatients) {
            os << i;
        }
        return os;
    }

    void setName(std::string name) {
        this->wardName = name;
    }
};


