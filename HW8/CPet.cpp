#include <iostream>
#include "CPet.h"


using namespace std;

CPet::CPet(const char * PetName)
{
        name = new char[strlen(PetName)+ 1 ];
        strcpy(name,PetName);
        mealCount = 0;
        napCount = 0;
}

void CPet::Destroy()
{
        delete name;

}

CPet::~CPet()
{
        Destroy();


}

void CPet::napAdder()
{
        napCount++;
}

void CPet::mealAdder()
{
        mealCount++;

}

CPet & CPet::operator=(const CPet & rhs)
{
        if(this != &rhs)
        {
                CopyPet(rhs);

        }
        return *this;
}


CPet::CPet(const CPet &other)
{
        CopyPet(other);
}


void CPet::CopyPet(const CPet &other)
{
        this->mealCount = other.mealCount;
        this->napCount = other.napCount;
        this->name = other.name;

}
void CPet::Eat()
{
        cout << "I'm Eating generic pet food!" << endl;
        mealCount++;
}

void CPet::SayName()const
{
        cout << name << ": ";

}

void CPet::Sleep()
{
        cout << "CPet sleeing generically" << endl;
        napCount++;

}


void CPet::DispState()const
{
        cout << "So far I have had " << mealCount << " meals " << "and " << napCount << " naps!" << endl;

}