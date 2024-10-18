#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Toll amounts for each vehicle type (modifiable in settings)
int BUS_TOLL = 500;
int TRUCK_TOLL = 400;
int CAR_TOLL = 150;

// Base class for Vehicle
class Vehicle {
protected:
    string regNo, date, time, vechicle;
    int operatorID;
    int tollAmount; // The toll amount specific to each vehicle type

public:
    virtual void getInput() = 0;
    virtual int tollCalculate() = 0;
    string getRegNo() { return regNo; }
    string getDate() { return date; }
    string getTime() { return time; }
    string getVechicle() { return vechicle; }
    int getOperatorID() { return operatorID; }
    int getTollAmount() { return tollAmount; }
    void setTollAmount(int toll) { tollAmount = toll; }
    void setOperator(int opID){ operatorID = opID; }
    void setDate(string currDate){ date = currDate;  }
    void setTime(string currTime){ time = currTime;  }
    void setVechicle(string vecl){ vechicle = vecl;  }
};

// Derived class for Bus
class Bus : public Vehicle {
private:
    int seats;

public:
    void getInput() override {
        cout << "Enter Bus Registration No: ";
        cin >> regNo;
        // cout << "Enter Date (dd/mm/yyyy): ";
        // cin >> date;
        // cout << "Enter Time (hh:mm): ";
        // cin >> time;
        // cout << "Enter Operator ID: ";
        // cin >> operatorID;
        cout << "Enter Seats: ";
        cin >> seats;
    }

    int tollCalculate() override {
        return BUS_TOLL; // Modifiable toll amount for bus
    }
};

// Derived class for Truck
class Truck : public Vehicle {
private:
    int weight, height;

public:
    void getInput() override {
        cout << "Enter Truck Registration No: ";
        cin >> regNo;
        // cout << "Enter Date (dd/mm/yyyy): ";
        // cin >> date;
        // cout << "Enter Time (hh:mm): ";
        // cin >> time;
        // cout << "Enter Operator ID: ";
        // cin >> operatorID;
        cout << "Enter Weight (Max 2000 kg): ";
        cin >> weight;
        cout << "Enter Height (Max 15 ft): ";
        cin >> height;
    }

    int tollCalculate() override {
        return TRUCK_TOLL; // Modifiable toll amount for truck
    }
};

// Derived class for Car
class Car : public Vehicle {
private:
    string owner;

public:
    void getInput() override {
        cout << "Enter Car Registration No: ";
        cin >> regNo;
        // cout << "Enter Date (dd/mm/yyyy): ";
        // cin >> date;
        // cout << "Enter Time (hh:mm): ";
        // cin >> time;
        // cout << "Enter Operator ID: ";
        // cin >> operatorID;
        cout << "Enter Owner Name: ";
        cin >> owner;
    }

    int tollCalculate() override {
        return CAR_TOLL; // Modifiable toll amount for car
    }
};


// Current Date
string getCurrentDate() {
    time_t now = time(0);            // Get current time
    tm *ltm = localtime(&now);       // Convert to local time structure

    // Extract day, month, year and format them as dd/mm/yyyy
    int day = ltm->tm_mday;
    int month = 1 + ltm->tm_mon;     // tm_mon gives months since January, so +1
    int year = 1900 + ltm->tm_year;  // tm_year gives years since 1900, so +1900

    // Format the date in dd/mm/yyyy format
    stringstream ss;
    ss << setw(2) << setfill('0') << day << "/"
       << setw(2) << setfill('0') << month << "/"
       << year;
    
    return ss.str();  // Return the formatted date as a string
}

// Current Time
string getCurrentTime() {
    time_t now = time(0);            // Get current time
    tm *ltm = localtime(&now);       // Convert to local time structure

    // Extract hour and minute
    int hour = ltm->tm_hour;         // Hour (0-23)
    int minute = ltm->tm_min;        // Minutes (0-59)

    // Format the time in hh:mm format
    stringstream ss;
    ss << setw(2) << setfill('0') << hour << ":"
       << setw(2) << setfill('0') << minute;

    return ss.str();  // Return the formatted time as a string
}



string OperatorName(int opID){
    string fileUsername, filePassword;
    ifstream file("operators.txt");
    if (file.is_open()) {
        int lineNum = 0;
        while (file >> fileUsername >> filePassword) {
            lineNum++;
            if (lineNum == opID) {
                return fileUsername;
                file.close();
                // return OpID;
            }
        }
        // file.close();
    }
}

// Function to save toll data to a file
void saveToFile(Vehicle* v, int collectedAmount, int returnAmount) {
    ofstream file("toll_data.txt", ios::app);
    if (file.is_open()) {
        file << v->getRegNo() << " " << v->getDate() << " " << v->getTime() <<  " " << OperatorName(v->getOperatorID()) << " " << v->getTollAmount() 
             << " " << v->getVechicle() << endl; 
        // file << v->getRegNo() << " " << v->getDate() << " " << v->getTime() <<  " " << OperatorName(v->getOperatorID()) << " " << v->getTollAmount() 
        //      << " " << collectedAmount << " " << returnAmount << endl;
        file.close();
        cout << "Toll collection saved successfully!" << endl;
    } else {
        cout << "Unable to open file for saving toll data!" << endl;
    }
}

void DataTableHead(){
     // Print table header
    cout << left << setw(15) << "Reg No" 
         << setw(15) << "Date" 
         << setw(15) << "Time" 
         << setw(15) << "Toll (Tk)" 
         << setw(15) << "Vechicle" 
         << setw(15) << "Operator" << endl;
    
    // Print separator
    cout << string(90, '-') << endl;

}

void displayTollData(const string& regNo, const string& date,string time, double toll,string vehicle ,string operatorID) {
   
    // Print data
    cout << left << setw(15) << regNo 
         << setw(15) << date 
         << setw(15) << time 
         << setw(15) << toll 
         << setw(15) << vehicle 
        //  << setw(15) << returnAmount
         << setw(15) << operatorID << endl;
}



// Function to register a new operator
bool registerOperator() {
    string username, password, confirmPassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "Reconfirm password: ";
    cin >> confirmPassword;

    if (password == confirmPassword) {
        ofstream file("operators.txt", ios::app);
        if (file.is_open()) {
            file << username << " " << password << endl;
            file.close();
            cout << "Registration successful!" << endl;
            return true;
        } else {
            cout << "Error registering the operator!" << endl;
        }
    } else {
        cout << "Passwords do not match!" << endl;
    }
    return false;
}

// Function to log in an existing operator
int loginOperator(string& loggedInOperator) {
    string username, password, fileUsername, filePassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("operators.txt");
    if (file.is_open()) {
        int OpID = 0;
        while (file >> fileUsername >> filePassword) {
            OpID++;
            if (fileUsername == username && filePassword == password) {
                loggedInOperator = username;
                cout << "Login successful!" << endl;
                file.close();
                return OpID;
            }
        }
        file.close();
        cout << "Invalid username or password!" << endl;
    } else {
        cout << "Unable to open operators file!" << endl;
    }
    return 0;
}

// Function to calculate toll and handle the amount collected
void collectToll(Vehicle* v) {
    int collectedAmount, returnAmount, tollAmount;

    // Get toll amount for the specific vehicle type
    tollAmount = v->tollCalculate();
    v->setTollAmount(tollAmount);

    cout << "The toll amount is: " << tollAmount << " Tk" << endl;
    cout << "Enter the amount collected from the driver: ";
    cin >> collectedAmount;

    // Calculate return/change amount
    if (collectedAmount >= tollAmount) {
        returnAmount = collectedAmount - tollAmount;
        cout << "Toll collection is successful. Return amount: " << returnAmount << " Tk" << endl;
    } else {
        cout << "Insufficient amount provided. Collect at least " << tollAmount << " Tk." << endl;
        return; // Exit without saving if amount is insufficient
    }

    // Save the toll collection data
    saveToFile(v, collectedAmount, returnAmount);
}

// Function to search a vehicle by its registration number
void searchVehicle(string regNo) {
    ifstream file("toll_data.txt");
    string r, d,t,vechicle, opID;
    int toll;
    bool found = false;

    DataTableHead();
    while (file >> r >> d >> t >> opID >> toll >> vechicle) {
        if (r == regNo) {
           
            displayTollData(r,d,t,toll,vechicle,opID);
            found = true;
            break;
        }
    }
   

   if(!found) {
        cout << "Vehicle not found!" << endl;
    }

    file.close();
}

// Function to search vehicles between two dates
void searchDateToDate(string startDate, string endDate) {
    ifstream file("toll_data.txt");
    string r, d,t,vechicle, opID;
    int toll;
    bool found = false;

    DataTableHead();
    while (file >> r >> d >> t >> opID >> toll >> vechicle) {
        if (d >= startDate && d <= endDate) {
            // cout << "Reg No: " << r << ", Date: " << d << ", Operator: " << opID 
            //      << ", Toll: " << toll << " Tk, Collected: " << collectedAmount 
            //      << " Tk, Return: " << returnAmount << " Tk" << endl;
            displayTollData(r,d,t,toll,vechicle,opID);
            found = true;
            // break;
        }
    }
       //Data table header
   

    if (!found) {
        cout << "No records found in this date range!" << endl;
    }

    file.close();
}


// Function to search vehicles by operator ID
void searchOperator(string operatorID) {
    ifstream file("toll_data.txt");
    string r, d,t,vechicle, opID;
    int toll;
    bool found = false;
    DataTableHead();
    while (file >> r >> d >> t >> opID >> toll >> vechicle) {
        if (opID == operatorID) {
            // cout << "Reg No: " << r << ", Date: " << d << ", Toll: " << toll 
            //      << " Tk, Collected: " << collectedAmount << " Tk, Return: " << returnAmount << " Tk" << endl;
           displayTollData(r,d,t,toll,vechicle,opID);
            found = true;
            // break;
        }
    }
   

    if(!found) {
        cout << "No records found for this operator!" << endl;
    }

    file.close();
}

// Function to display toll statistics for a specific day
void tollStatistics(string startDate, string endDate) {
    ifstream file("toll_data.txt");
    string r, d, t, opID, vechicle;
    int toll;
    int busCount = 0, truckCount = 0, carCount = 0;
    int busTotal = 0, truckTotal = 0, carTotal = 0;

    while (file >> r >> d >> t >> opID >> toll >> vechicle) {
        if (d >= startDate && d <= endDate) {
            if (toll == BUS_TOLL) {
                busCount++;
                busTotal += toll;
            } else if (toll == TRUCK_TOLL) {
                truckCount++;
                truckTotal += toll;
            } else if (toll == CAR_TOLL) {
                carCount++;
                carTotal += toll;
            }
        }
    }

    cout << "Vehicle Toll Statistics for " << startDate << " - " << endDate  << ":\n";
   

     cout << left << setw(15) << "Vehicle" 
         << setw(15) << "Number" 
         << setw(15) << "Amount" 
         << endl;
    
    // Print separator
    cout << string(45, '-') << endl;
    cout << left << setw(15) << "Buses" 
         << setw(15) << busCount 
         << setw(15) << busTotal 
         << endl;
    cout << left << setw(15) << "Truck" 
         << setw(15) << truckCount 
         << setw(15) << truckTotal 
         << endl;
    cout << left << setw(15) << "Car" 
         << setw(15) << carCount 
         << setw(15) << carTotal 
         << endl;
    cout << "Grand Total: " << busTotal + truckTotal + carTotal << " Tk\n";

    file.close();
}

// Function to change toll values (admin only)
void tollSettings() {
    int newBusToll, newTruckToll, newCarToll;
    string adminUser, adminPass;

    cout << "Enter Admin Username: ";
    cin >> adminUser;
    cout << "Enter Admin Password: ";
    cin >> adminPass;

    if (adminUser == "admin" && adminPass == "1234") {
        cout << "Enter New Toll for Bus: ";
        cin >> newBusToll;
        cout << "Enter New Toll for Truck: ";
        cin >> newTruckToll;
        cout << "Enter New Toll for Car: ";
        cin >> newCarToll;

        // Update the global toll values
        BUS_TOLL = newBusToll;
        TRUCK_TOLL = newTruckToll;
        CAR_TOLL = newCarToll;

        cout << "Toll values updated successfully!" << endl;
    } else {
        cout << "Invalid Admin credentials!" << endl;
    }
}

// Toll plaza menu
void tollPlazaMenu(int operatorID) {
    int option;
    do {
        cout << "\n******* Toll Plaza Menu ******\n";
        cout << "1. Bus\n2. Truck\n3. Car\n4. Search\n5. Statistics\n6. Toll Settings (admin)\n7. Save and Logout\n";
        cout << "Enter Your Option (1-7): ";
        cin >> option;

        Vehicle* v;
        string vec_name; 
        if (option == 1) {
            v = new Bus();
            vec_name = "Bus";
        } else if (option == 2) {
            v = new Truck();
            vec_name = "Truck";
        } else if (option == 3) {
            v = new Car();
            vec_name = "Car";
        }

        if (option >= 1 && option <= 3) {
            v->getInput();
            v->setOperator(operatorID);
            v->setDate(getCurrentDate());
            v->setTime(getCurrentTime());
            v->setVechicle(vec_name);
            collectToll(v); // Collect toll and handle amount input
            delete v; // Free the memory
        } else if (option == 4) {
            int searchOption;
            cout << "\n*** Toll Plaza: Search ***\n1. Vehicle\n2. Date to Date\n3. Operator\n4. Back\nEnter Your Option (1-4): ";
            cin >> searchOption;

            if (searchOption == 1) {
                string regNo;
                cout << "Enter Vehicle Registration No: ";
                cin >> regNo;
                searchVehicle(regNo);
            } else if (searchOption == 2) {
                string startDate, endDate;
                cout << "Enter Start Date (dd/mm/yyyy): ";
                cin >> startDate;
                cout << "Enter End Date (dd/mm/yyyy): ";
                cin >> endDate;
                searchDateToDate(startDate, endDate);
            } else if (searchOption == 3) {
                string searchOperatorID;
                cout << "Enter Operator Name: ";
                cin >> searchOperatorID;
                searchOperator(searchOperatorID);
            }
        } else if (option == 5) {
            string Sdate, eDate;
            cout << "Enter Start Date (dd/mm/yyyy): ";
            cin >> Sdate;
            cout << "Enter End Date (dd/mm/yyyy): ";
            cin >> eDate;
            tollStatistics(Sdate, eDate); 
        } else if (option == 6) {
            tollSettings();
        }

    } while (option != 7);

    cout << "Saving data and logging out..." << endl;
}

// Main function
int main() {
    string loggedInOperator;
    int choice;

    do {
        cout << "\n*** Toll Plaza: Operator ***\n";
        cout << "1. Login\n2. Register\n3. Exit\nEnter Your Option: ";
        cin >> choice;

        if (choice == 1) {
            int opID = loginOperator(loggedInOperator);
            if (opID) {
                // loggedInOperator = 
                tollPlazaMenu(opID);
            }
        } else if (choice == 2) {
            registerOperator();
        }
    } while (choice != 3);

    cout << "Exiting the program..." << endl;
    return 0;
}
