#include <string>
#include <vector>
#include "Ward.cpp"


class WardHandler {

public:

Ward w;

    Ward ward1;
    Ward ward2;
    Ward ward3;
    Ward ward4;
    Ward ward5;

void initWards() {
    ward1.setName("First Ward");
    ward2.setName("Second Ward");
    ward3.setName("Third Ward");
    ward4.setName("Fourth Ward");
    ward5.setName("Fifth Ward");
}

Ward* identifyWard(std::string ward) {
        Ward* wardPtr;
        if (ward == "First Ward")
        {
            wardPtr = &ward1;
        }
        else if (ward == "Second Ward")
        {
            wardPtr = &ward2;
        }
        else if (ward == "Third Ward")
        {
            wardPtr = &ward3;
        }
        else if (ward == "Fourth Ward")
        {
            wardPtr = &ward4;
        }
        else if (ward == "Fifth Ward")
        {
            wardPtr = &ward5;
        }
        return wardPtr;
}

void addPatientToWard(std::string ward, int number) {
        Ward* wardPtr = identifyWard(ward);
        wardPtr->wardPatients.push_back(w.pr.getPatient(number));
    }

void removePatientFromWard(std::string ward, int number) {
        bool patientFound = false;
        Ward* wardPtr = identifyWard(ward);
        for (unsigned int i = 0; i < wardPtr->wardPatients.size(); i++) {
            if (wardPtr->wardPatients[i].getNumber() == number) {
                wardPtr->wardPatients.erase(wardPtr->wardPatients.begin() + i);
                patientFound = true;
                std::cout << "Patient removed from ward." << std::endl;
            }
        }
        if (!patientFound) {
            std::cout << "Patient not found within ward." << std::endl;
        }
    }

int getAllPatientsAmount() {
        return ward1.wardPatients.size() +
        ward2.wardPatients.size() +
        ward3.wardPatients.size() +
        ward4.wardPatients.size() +
        ward5.wardPatients.size();
    }

int getWardPatientsAmount(std::string ward) {
        Ward* wardPtr = identifyWard(ward);
        return wardPtr->wardPatients.size();
    }

std::string getPatientWard(int number) {
        Ward ward;
        bool patientFound = false;
        for (unsigned int i = 0; i < ward1.wardPatients.size(); i++) {
            if (ward1.wardPatients[i].getNumber() == number) {
                ward = ward1;
                patientFound = true;
            }
        }
        for (unsigned int i = 0; i < ward2.wardPatients.size(); i++) {
            if (ward2.wardPatients[i].getNumber() == number) {
                ward = ward2;
                patientFound = true;
            }
        }
        for (unsigned int i = 0; i < ward3.wardPatients.size(); i++) {
            if (ward3.wardPatients[i].getNumber() == number) {
                ward = ward3;
                patientFound = true;
            }
        }
        for (unsigned int i = 0; i < ward4.wardPatients.size(); i++) {
            if (ward4.wardPatients[i].getNumber() == number) {
                ward = ward4;
                patientFound = true;
            }
        }
        for (unsigned int i = 0; i < ward5.wardPatients.size(); i++) {
            if (ward5.wardPatients[i].getNumber() == number) {
                ward = ward5;
                patientFound = true;
            }
        }
        if(!patientFound) {
            return "Patient was not found";
        }
        else {
            return ward.wardName;
        }
    }
};