// ============================================================================
// File: main.cpp (Fall 2015)
// ============================================================================
// Study the code below to see what this program does. Then complete the class
// CVehicle and implement it so this program works.
//
// Sample run:
//
//  carOne = Hyundai Sonata
//  carTwo = Hyundai Sonata
//  carThree =
//  Enter the make an model of a vehicle: Toyota Corolla
//  You entered: Toyota Corolla
//
//  Testing the assignment operator...
//  carOne == Hyundai Sonata
//  carTwo == Hyundai Sonata
//  carThree == Hyundai Sonata
//
//  Here are the contents of the car file:
//  Lamborghini Muira
//  Ferrari Enzo
//  Porsche GT2
//  Ford Mustang
//  Chevrolet Corvette
//  Kia Rio
//  Nissan Versa
//
// ============================================================================


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "cvehicle.h"
using namespace std;


// ==== main ==================================================================
//
// ============================================================================

int     main(void)
{
    // test the constructors
    CVehicle            carOne("Hyundai", "Sonata");
    const   CVehicle    carTwo = carOne;
    CVehicle            carThree;

    // display the contents of each newly-constructed object...

    // should see "Hyundai Sonata"
    cout << "carOne = ";
    carOne.WriteVehicle();
    cout << endl;

    // should see "Hyundai Sonata" again
    cout << "carTwo = ";
    carTwo.WriteVehicle();
    cout << endl;

    // should see nothing
    cout << "carThree = ";
    carThree.WriteVehicle();
    cout << endl;

    // try the "read" function
    cout << "Enter the make and model of a vehicle: ";
    carThree.ReadVehicle();
    cout << "You entered: " << carThree << endl << endl;

    // try the assignment operator
    carOne = carThree = carTwo;
    cout << "Testing the assignment operator..." << endl;
    cout << "carOne == " << carOne << endl;
    cout << "carTwo == " << carTwo << endl;
    cout << "carThree == " << carThree << endl << endl;

    // open the car data file
    ifstream        carFile("cars.dat");
    if (carFile.fail())
        {
        cerr << "Error opening the input file..." << endl;
        exit(EXIT_FAILURE);
        }
    // use the object to display the contents of the car data file
    cout << "Here are the contents of the car file: " << endl;
    while (carFile >> carThree)
        {
        cout << carThree << endl;
        }

    // close the file stream and return
    carFile.close();
    return EXIT_SUCCESS;

}  // end of "main"

