#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std;

class USD {
    // Class that represents a US denomination and its attributes
    public:

    string denomination; // Name of denomination
    float value; // Float value of denomination in USD
    int amount; // Number of the denomination in question

};

class Register {
    // Class that simulates basic functions of a cash register
    public:

        USD cash[10]; // Create an array of 10 objects (one for each denominee) of the USD Class 
        float subTotal; // variable to hold SubTotal amount
        float change; // variable to holds change of the total - payment amount

        void getCash() {

            // array of denomination names from highest to lowest worth
            string name[10] = {"hundred", "fifty", "twenty", "ten", "five", "one", "quarter", "dime", "nickel", "penny"};
            // array of denomination USD values in decimal from highest to lowest
            float worth[10] = {100, 50, 20, 10, 5, 1, 0.25, 0.10, 0.05, 0.01};

            for (int i = 0; i < 10; i++) {
                // configure denomination names, values, and amounts of each USD object created
                cash[i].denomination = name[i];
                cash[i].value = worth[i];
                cash[i].amount = 0;

            }

        }
        
        void getTotal() {// Function that gets randomized total price

            srand((unsigned) time(0));

            int randInt;
            float randDecimal;

            randInt = (rand() % 150) + 1; // randomized integer
            randDecimal = (float) rand() / RAND_MAX; // randomized decimal number less than 1
            // add random numbers to make a random floating point number that makes up total price
            subTotal = randInt + randDecimal; 
        
            cout << endl << "Your total is $" << setprecision(2) << fixed << subTotal << endl << endl;
            
        }

        void getChange() { // Function that calculates and outputs the difference of total price and payment amount

            float cashValue;
            float payment;

            for (int i = 0; i < 10; i++) {

                cashValue = cash[i].value * cash[i].amount;
                payment += cashValue;
            
            }

            if (payment < subTotal) {

                change = subTotal - payment;
                
                cout << endl << "You need $" << setprecision(2) << fixed << change << " more to complete transaction." << endl;

            } else if (payment == subTotal) {

                cout << endl << "Change Due: $0.00" << endl;

            } else {

                change = payment - subTotal;
                
                cout << endl << "Change Due: $" << setprecision(2) << fixed << change << endl;
            }
        }
};

int main() {

    Register reg;
    int amount;

    reg.getCash();

    reg.getTotal();

    cout << "Enter payment (number of each denomination)" << endl;

    for (int i = 0; i < 10; i++) { // Convert denomination names to display correctly when grabbing output

    string denomName = reg.cash[i].denomination;

    if (denomName == "fifty" || denomName == "twenty" || denomName == "penny") {

        denomName = toupper(denomName[0]);
        denomName.append(reg.cash[i].denomination.begin()+1,reg.cash[i].denomination.end()-1);
        denomName.append("ies");

    } else {

        denomName = toupper(denomName[0]);
        denomName.append(reg.cash[i].denomination.begin()+1,reg.cash[i].denomination.end());
        denomName.append("s");

    }

    cout << denomName << ": ";
    cin >> amount;
    reg.cash[i].amount = amount;

    }

    reg.getChange();

    return 0;
}