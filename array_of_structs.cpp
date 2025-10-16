

#include <iostream>
#include <fstream>
using namespace std;

struct TemperatureRecord { // TODO: Step 1 - Define the struct TemperatureRecord    
    int day;
    int temperature; // It should contain two integer fields: day and temperature.
};

const int MAX_DAYS = 31; // Constants
// Function Prototypes
void readTemperatures(TemperatureRecord records[], int & size); 
void printTemperatures(const TemperatureRecord records[], int size);
TemperatureRecord findMin(const TemperatureRecord records[], int size);
TemperatureRecord findMax(const TemperatureRecord records[], int size);
double findAverage(const TemperatureRecord records[], int size);

int main() {
    
    TemperatureRecord records[MAX_DAYS]; // TODO: Step 2 - Declare an array of TemperatureRecord structs (MAX_DAYS size)    
    int size = 0; // Actual number of records read
   
    readTemperatures(records, size); // TODO: Step 3 - Call readTemperatures() to load data from file
    printTemperatures(records, size); // TODO: Step 4 - Print the temperatures    
    TemperatureRecord minTemp = findMin(records, size);
    TemperatureRecord maxTemp = findMax(records, size);
    double avgerage = findAverage(records, size); // TODO: Step 5 - Compute and display min, max, and average temperature
   
    cout << "Lowest Temperature: Day " << minTemp.day << ": " << minTemp.temperature << endl;
    cout << "Highest Temperature: Day " << maxTemp.day << ": " << maxTemp.temperature << endl;
    cout << "Average Temperature: " << avgerage << endl;
    
    return 0;
}
    void readTemperatures(TemperatureRecord records[], int &size) { // TODO: Step 6 - Implement readTemperatures()       
       ifstream file("temps.txt");
        
        if (!file) {
            cout << "Error opening file" << endl;
            return;
            }
        size = 0;
        while (file >> records[size].day >> records[size].temperature) {
            size++;
            if (size >= MAX_DAYS) {
                break;
            }
        }
        file.close();
    }

void printTemperatures(const TemperatureRecord records[], int size) { // TODO: Step 7 - Implement printTemperatures()    
    cout << "Day Temperature: ";
    for (int i = 0; i < size; i++) {
        cout << records[i].day << ", " << records[i].temperature << endl;
    } // Print all stored temperatures in a formatted table
}

TemperatureRecord findMin(const TemperatureRecord records[], int size) {
    TemperatureRecord min = records[0];
    for (int i = 1; i < size; i++) {
        if (records[i].temperature < min.temperature) {
            min = records[i]; // TODO: Step 8 - Implement findMin()       
        }
    }
    return min; // Return the TemperatureRecord with the lowest temperature
}

TemperatureRecord findMax(const TemperatureRecord records[], int size) {
    TemperatureRecord max = records[0];
    for (int i = 1; i < size; i++) {
        if (records[i].temperature > max.temperature) {
            max = records[i];
        } // TODO: Step 9 - Implement findMax()    
    }
    return max;// Return the TemperatureRecord with the highest temperature
}
double findAverage(const TemperatureRecord records[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += records[i].temperature;
        } // TODO: Step 10 - Implement findAverage()
   if (size == 0) {
        return 0;
    }
    return total / size; // Compute and return the average temperature
}






