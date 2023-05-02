#include "ForstersAuto.h"

using namespace std;


int main() {
    double partPrice = 0.0;
    double money = 0.0;
    // Create stacks for each part at a max quantity of 50
    stack<string> motorOilStack;
    stack<string> airFilterStack;
    stack<string> sparkPlugStack;
    stack<string> brakePadsStack;
    stack<string> alternatorStack;
    stack<string> transmissionFluidStack;
    stack<string> fuelPumpStack;

    for (int i = 0; i < 50; i++) {
        motorOilStack.push("5W-30 Motor Oil");
        airFilterStack.push("Air Filter");
        sparkPlugStack.push("Spark Plug");
        brakePadsStack.push("Brake Pads");
        alternatorStack.push("Alternator");
        transmissionFluidStack.push("Transmission Fluid");
        fuelPumpStack.push("Fuel Pump");
    }

    char order;

    // Open file for writing order details
    ofstream outFile("ForstersAutoReceipt.txt");
    if (!outFile) {
        cout << "Failed to open file" << endl;
        return 1;
    }


    //Create random number based queue for the user
    queue<string> userQueue;
    srand(time(NULL));
        for (int i = 1; i <= rand() % (100 + 1) - 1; i++) { // This looks a little strange, but when I had this written out as "rand() % 50 + 1",  
            userQueue.push("User " + to_string(i));         // it would mostly output small, single digit numbers.
        }                                                   // This is just a bizarre workaround I found while toying with it.



    // Seed the random number generator with current time
    srand(time(0));

    // Create an array to hold parts menu items
    string partsMenu[] = {
        "5W-30 Motor Oil",
        "Air Filter",
        "Spark Plug",
        "Brake Pads",
        "Alternator",
        "Transmission Fluid",
        "Fuel Pump"
    };

    int n = sizeof(partsMenu) / sizeof(partsMenu[0]);

    // Sort the parts menu by alphabetical order using the bubble sort
    bubbleSort(partsMenu, n);

    // Display menu to user and process their selection
    while (true) {
        cout << "Welcome to Forster's Automotive" << endl;
        cout << "-------------------------------" << endl;
        for (int i = 0; i < n; i++) {
            string partName = partsMenu[i];

            // Set part price based on part name
            if (partName == "5W-30 Motor Oil") {
            partPrice = MOTOR_OIL_PRICE;
            } else if (partName == "Air Filter") {
            partPrice = AIR_FILTER_PRICE;
            } else if (partName == "Spark Plug") {
            partPrice = SPARK_PLUG_PRICE;
            } else if (partName == "Brake Pads") {
            partPrice = BRAKE_PADS_PRICE;
            } else if (partName == "Alternator") {
            partPrice = ALTERNATOR_PRICE;
            } else if (partName == "Transmission Fluid") {
            partPrice = TRANSMISSION_FLUID_PRICE;
            } else if (partName == "Fuel Pump") {
            partPrice = FUEL_PUMP_PRICE;
            }




            // Display part and its price to the user
            cout << i + 1 << ". " << setw(20) << left << partName << "$" << partPrice;

            // Display remaining parts in the stack for each part
            if (partName == "5W-30 Motor Oil") {
                cout << "\tCurrent supply: " << motorOilStack.size() << endl;
            }  if (partName == "Air Filter") {
                cout << "\tCurrent supply: " << airFilterStack.size() << endl;
            }  if (partName == "Spark Plug") {
                cout << "\tCurrent supply: " << sparkPlugStack.size() << endl;
            }  if (partName == "Brake Pads") {
                cout << "\tCurrent supply: " << brakePadsStack.size() << endl;
            }  if (partName == "Alternator") {
                cout << "\tCurrent supply: " << alternatorStack.size() << endl;
            }  if (partName == "Transmission Fluid") {
                cout << "\tCurrent supply: " << transmissionFluidStack.size() << endl;
            }  if (partName == "Fuel Pump") {
                cout << "\tCurrent supply: " << fuelPumpStack.size() << endl;
            }
        }
        cout << "-------------------------------" << endl;

        // Ask user for their selection
        cout << "Line is " << userQueue.size() << endl; // Output the current size of the queue (this was made random to simulate a real line)
        cout << "Enter the number of the part you want to order (Q to exit or C to checkout): \n";
        cin >> order;




                // Check if the user queue is empty
                if (userQueue.empty()) {
                    cout << "All users have been served. Exiting program." << endl;
                    break;
                }
                    if (order == 'c') {
                        // Process checkout and update the queue
                         cout << "\033[2J\033[1;1H";
                        checkout(userQueue, money);
                        continue;
                    }




        if (order == 'Q' || order == 'q') {
            break; // Exit loop if user enters Q
        }

        // Process user's order
        int partIndex = order - '1';
        if (partIndex >= 0 && partIndex < n) {
            string partName = partsMenu[partIndex];


            // Check if stock for selected part is available
            if ((partName == "5W-30 Motor Oil" && !motorOilStack.empty()) ||
                (partName == "Air Filter" && !airFilterStack.empty()) ||
                (partName == "Spark Plug" && !sparkPlugStack.empty()) ||
                (partName == "Brake Pads" && !brakePadsStack.empty()) ||
                (partName == "Alternator" && !alternatorStack.empty()) ||
                (partName == "Transmission Fluid" && !transmissionFluidStack.empty()) ||
                (partName == "Fuel Pump" && !fuelPumpStack.empty())) {
                // Deduct stock for selected part and update the total cost of the items in the current user's cart
                if (partName == "5W-30 Motor Oil") {
                    motorOilStack.pop();
                    money = money + MOTOR_OIL_PRICE;
                } else if (partName == "Air Filter") {
                    airFilterStack.pop();
                    money = money + AIR_FILTER_PRICE;
                } else if (partName == "Spark Plug") {
                    sparkPlugStack.pop();
                    money = money + SPARK_PLUG_PRICE;
                } else if (partName == "Brake Pads") {
                    brakePadsStack.pop();
                    money = money + BRAKE_PADS_PRICE;
                } else if (partName == "Alternator") {
                    alternatorStack.pop();
                    money = money + ALTERNATOR_PRICE;
                } else if (partName == "Transmission Fluid") {
                    transmissionFluidStack.pop();
                    money = money + TRANSMISSION_FLUID_PRICE;
                } else if (partName == "Fuel Pump") {
                    fuelPumpStack.pop();
                    money = money + FUEL_PUMP_PRICE;
                }

                // Update total cost and write order details to file
                writeOrderToFile(partName, money, outFile);

                cout  << partName << " added to your cart." << endl;

                cout << "Continue shopping? Y to continue, or Q to quit\n";
                cin >> order;
                if(order == 'Y' || order == 'y'){
                     cout << "\033[2J\033[1;1H"; // deletes the previous screen to clean up the menu
                    continue;

                }
                else if(order == 'Q' || order == 'q'){
                    break;
                }

            } else {
                cout << "Sorry, " << partName << " is out of stock." << endl;
            }
        } else {
            cout << "\033[2J\033[1;1H";
            cout << "Invalid selection. Please try again." << endl;
            continue;
        }

    }

    // Close file for writing order details
    outFile.close();

    // Display total cost to user
    cout << "----------------------" << endl;

    cout << "Total cost of your order: $" << money << endl;

    return 0;

    }
