#include <iostream>
#include "cvehicle.h"
#include <cstring>
#include <string>

using namespace std;



//default constructor with arguments
CVehicle::CVehicle(string make, string model)
{
        //copies string from parameters arguments and sets them to  the character array
        strcpy(m_make, make.c_str());
        strcpy(m_model, model.c_str());

}

// Default construtor so when user creates a object, the objects array will be replaced by a space rather than a
//bunch of unknown memory.
CVehicle::CVehicle()
{


        strcpy(m_make, "\0");
        strcpy(m_model, "\0");

}




//Returns string value of m_make. First if converts the character array into a string then returns value.
string CVehicle::Make() const
{
        string make = string(m_make);
        return make;

}


//returns string value of model so thatn nonmember function and get a value
string CVehicle::Model() const
{
        string model = string(m_model);
        return model;


}


//getter function that prints out the make and model of the car when called
void CVehicle::WriteVehicle() const
{

        for(int i = 0; i < strlen(m_make); i++)
        {
                cout << m_make[i];

        }

        cout << " ";


        for(int i = 0; i < strlen(m_model); i++)
        {

        cout << m_model[i];

        }
}


//When function is called, it will take user input and set them in m_make and m_model character array
//Once the user presses space the second word will go into the m_model array.
void CVehicle::ReadVehicle()
{
        cin >> m_make >> m_model;

}



//Reads object from input stream
istream& operator>>(istream &inStream, CVehicle &rhs)
{
        string make;
        string model;

        if(inStream >> make >> model)
        {
                rhs = CVehicle(make, model);

        }

        return inStream;

}


//writes the Make and Model of the car to the output stream
ostream& operator<<(ostream &outStream, const CVehicle &rhs)
{

        return outStream << rhs.Make() <<  " "  << rhs.Model();

}

