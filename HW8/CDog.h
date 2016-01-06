#ifndef CDOG_HEADER
#define CDOG_HEADER
#include <iostream>

using namespace std;

class CDog: public CPet
{
        public:
        CDog(const char * PetName) : CPet(PetName) {}


        void Eat(){ cout << "I'm eating dog food!" << endl; mealAdder(); }
        void Sleep() {cout << "Time for a dog nap..." << endl; napAdder();}
        int mealCount;
        int napCountl;
        char *name;
};

#endif // CDOG_HEADER

