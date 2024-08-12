#include <string>
#include <vector>
#include "Patient.cpp"

class PatientRegister {

public:

    std::vector<Patient> patientRegisterVector;

    PatientRegister(std::vector<Patient> patients) {
        patientRegisterVector = patients;
    }
    PatientRegister() {
    }
    ~PatientRegister() {
    }

    void addPatient() {
        bool patientAddGood = true;
        while (patientAddGood) {
            //get name
            std::string name;
            std::cout << "Input the name of the patient: \n";
            getline(std::cin, name);

            //get dob
            std::string dob;
            std::cout << "Input the DOB of the patient: \n";
            getline(std::cin, dob);

            //get number
            std::string readNumber;
            int number;
            bool notInt = true;
            while (notInt) {
                std::cout << "Input the number of the patient: [make sure input is an int]\n";
                getline(std::cin, readNumber);
                for (int i = 0; i < int(readNumber.size()); i++) {
                    if (isdigit(readNumber[i])) {
                        notInt = false;  //the varible is not a number
                    }
                }
            }
            number = stoi(readNumber);
            for (unsigned int i = 0; i < patientRegisterVector.size(); i++) {
                if (patientRegisterVector[i].getNumber() == number) {
                    patientAddGood = false; //patient already exists
                    std::cout << "Patient with this number already exists\n";
                    return;
                }
            }
            //get history
            bool userExitHistory = false;
            std::vector<History> patientHistory;
            while (!userExitHistory) {

                std::string admission;
                std::cout << "Input the first admission of the patient: \n";
                std::cin >> admission;

                std::string discharge;
                std::cout << "Input the first discharge of the patient: \n";
                std::cin >> discharge;

                std::string ward;
                std::cout << "Input the first ward of the patient: \n";
                std::cin >> ward;

                //add history to vector
                History history(admission, discharge, ward);
                patientHistory.push_back(history);

                //repeat check
                std::string userInput;
                std::cout << "Do you want to cancel adding more history for this patient? [n if no, anything else if yes]: \n";
                std::cin >> userInput;

                if (userInput == "n") {
                    userExitHistory = true;
                }
            }
            Patient patient(name, dob, number, patientHistory);
            patientRegisterVector.push_back(patient);
            patientAddGood = false; //nothing bad happened counter to what the bool says, ending loop to finish adding patients
            std::cin.clear();
        }
    }

    void removePatient(int number) {
        bool patientFound = false;
        for (unsigned int i = 0; i < patientRegisterVector.size(); i++) {
            if (patientRegisterVector[i].getNumber() == number) {
                patientRegisterVector.erase(patientRegisterVector.begin() + i);
                patientFound = true;
                std::cout << "Patient removed." << std::endl;
            }
        }
        if (!patientFound) {
            std::cout << "Patient not found." << std::endl;
        }
    }
        
    int getNumPatient() {
        return patientRegisterVector.size();
    }

    void checkForPatient(int number) {
        bool patientFound = false;
        for (unsigned int i = 0; i < patientRegisterVector.size(); i++) {
            if (patientRegisterVector[i].getNumber() == number) {
                patientFound = true;
                std::cout << "Patient found." << std::endl;
            }
        }
        if (!patientFound) {
            std::cout << "Patient not found." << std::endl;
        }
    }

    Patient getPatient(int number) { //probs not great
        bool patientFound = false;
        Patient searchPatient;
        for (unsigned int i = 0; i < patientRegisterVector.size(); i++) {
            if (patientRegisterVector[i].getNumber() == number) {
                patientFound = true;
                searchPatient = patientRegisterVector[i];
            }
        }
        if (!patientFound) {
            std::cout << "Patient not found." << std::endl;

        }
        return searchPatient;
    }
};