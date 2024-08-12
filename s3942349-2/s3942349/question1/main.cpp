#include <iostream>
#include "WardHandler.cpp"      

int main() {
    //creating 5 different wards
    WardHandler wh;
    wh.initWards();

    Patient patient("John", "DOB", 1234567, {});
    Patient patient2("Jim", "DOB2", 7654321, {});
    wh.w.pr.patientRegisterVector.push_back(patient);
    wh.w.pr.patientRegisterVector.push_back(patient2); // <- what i used to test the ward system

    std::cout << "Hospital Manager System" << std::endl;
    bool userExit = false;
    
    while (!userExit) {
        std::cout << "\nCommands:" << std::endl;
        std::cout << "1. Add Patient" << std::endl;
        std::cout << "2. Remove Patient" << std::endl;
        std::cout << "3. Get the amount of patients in register" << std::endl;
        std::cout << "4. Check for patient" << std::endl;
        std::cout << "5. Retrive patient data" << std::endl;
        std::cout << "6. Add patient to ward" << std::endl;
        std::cout << "7. Remove patient from ward" << std::endl;
        std::cout << "8. Get amount of patients in all wards" << std::endl;
        std::cout << "9. Get amount of patients in specific ward" << std::endl;
        std::cout << "10. Get ward that specific patient is in" << std::endl;
        std::cout << "Type \"quit\" to quit." << std::endl;

        std::string userInput;
        getline(std::cin, userInput);

        if (userInput == "1")
        {
            wh.w.pr.addPatient();
        }
        else if (userInput == "2")
        {
            std::cout << "Type the number of the patient you want to remove: " << std::endl;
            std::string userInput;
            getline(std::cin, userInput);
            try
            {
                wh.w.pr.removePatient(stoi(userInput));
            }
            catch(const std::exception& e)
            {
                std::cout << "Error, make sure to give valid input\n";
            }
            
        }
        else if (userInput == "3")
        {
            std::cout << "Amount of patients in register: " << wh.w.pr.getNumPatient();
        }
        else if (userInput == "4")
        {
            std::cout << "Type the number of the patient you want to search for: " << std::endl;
            std::string userInput;
            getline(std::cin, userInput);
            try
            {
                wh.w.pr.checkForPatient(stoi(userInput));
            }
            catch(const std::exception& e)
            {
                std::cout << "Error, make sure to give valid input\n";
            }
            
        }
        else if (userInput == "5")
        {
            std::cout << "Type the number of the patient you want to retrieve the data of: " << std::endl;
            std::string userInput;
            getline(std::cin, userInput);
            try
            {
                std::cout << wh.w.pr.getPatient(stoi(userInput));
            }
            catch(const std::exception& e)
            {
                std::cout << "Error, make sure to give valid input\n";
            }
            
            
        }
        else if (userInput == "6")
        {
            std::cout << "Type the name of the ward you want to add the patient to: " << std::endl;
            std::string ward;
            getline(std::cin, ward);
            if (ward == "First Ward" || ward == "Second Ward" || ward == "Third Ward" || ward == "Fourth Ward" || ward == "Fifth Ward") {
                std::cout << "Type the number of the patient you want to add to the ward: " << std::endl;
                std::string number;
                getline(std::cin, number);
                try {
                    std::string pat = wh.getPatientWard(stoi(number));
                    if (pat == "Patient was not found") {
                        wh.addPatientToWard(ward, stoi(number));
                    }
                    else {
                        std::cout << "Error, patient is already in a ward\n";
                    }
                }
                catch(const std::exception& e)
                {
                    std::cout << "Error, make sure to give valid input\n";
                }
            }
            else {
                std::cout << "Error, make sure to give valid input\n";
            }
        }
        else if (userInput == "7")
        {
            std::cout << "Type the name of the ward you want to remove the patient from: " << std::endl;
            std::string ward;
            getline(std::cin, ward);
            if (ward == "First Ward" || ward == "Second Ward" || ward == "Third Ward" || ward == "Fourth Ward" || ward == "Fifth Ward") {
                std::cout << "Type the number of the patient you want to remove from the ward: " << std::endl;
                std::string number;
                getline(std::cin, number);
                try {
                    wh.removePatientFromWard(ward, stoi(number));
                }
                catch(const std::exception& e)
                {
                    std::cout << "Error, make sure to give valid input\n";
                }
            }
            else {
                std::cout << "Error, make sure to give valid input\n";
            }
        }
        else if (userInput == "8")
        {
            std::cout << "Amount of patients in all wards: " << wh.getAllPatientsAmount();
        }
        else if (userInput == "9")
        {
            std::cout << "Type the name of the ward you want to view the amount of patients of: " << std::endl;
            std::string ward;
            getline(std::cin, ward);
            if (ward == "First Ward" || ward == "Second Ward" || ward == "Third Ward" || ward == "Fourth Ward" || ward == "Fifth Ward") {
                try {
                std::cout << "Amount of patients in " << ward << ": " << wh.getWardPatientsAmount(ward);
                }
                catch(const std::exception& e)
                {
                    std::cout << "Error, make sure to give valid input\n";
                }
            }
            else {
                std::cout << "Error, make sure to give valid input\n";
            }
        }
        else if (userInput == "10")
        {
            std::cout << "Type the number of the patient you want to find within the wards: " << std::endl;
            std::string number;
            getline(std::cin, number);
            try {
                std::cout << wh.getPatientWard(stoi(number));
            }
            catch(const std::exception& e)
            {
                std::cout << "Error, make sure to give valid input\n";
            }
        }
        else if (userInput == "quit") {
            userExit = true;
        }
    }
}

//g++ -Wall -Werror -std=c++14 -O -o a3  main.cpp Patient.cpp PatientRegister.cpp Ward.cpp WardHandler.cpp
//./a3

/*
notes:
history information for patient objects is kinda sketch. it works, but there are some improvments that could be made for sure.
the five ward names that are created are {First Ward, Second Ward, Third Ward, Fourth Ward, Fifth Ward} declared in the WardHandler initWards function
*/ 
