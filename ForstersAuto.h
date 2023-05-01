#ifndef FORSTERSAUTO_H
#define FORSTERSAUTO_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // added setprecision()
#include <stack>
#include <queue>
#include <cstdlib> // Added rand() and srand() functions
#include <ctime> // Added time() function

using namespace std;

// Constants for part prices
const double MOTOR_OIL_PRICE = 24.99;
const double AIR_FILTER_PRICE = 12.99;
const double SPARK_PLUG_PRICE = 4.99;
const double BRAKE_PADS_PRICE = 49.99;
const double ALTERNATOR_PRICE = 129.99;
const double TRANSMISSION_FLUID_PRICE = 19.99;
const double FUEL_PUMP_PRICE = 99.99;


void writeOrderToFile(const string& partName, double partPrice, ofstream& outFile);
void checkout(queue<string>& userQueue, double& totalOrder);
void bubbleSort(string arr[], int n);
#endif // FORSTERSAUTO_H
