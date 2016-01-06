#ifndef CCat_HEADER
#define CCat_HEADER
#include <iostream>

using namespace std;


class CCat: public CPet
{
        public:
        CCat(const char * PetName) : CPet(PetName) {}

        void Eat(){cout << "I'm eating cat food!" << endl; mealAdder();}
        void Sleep(){cout << "Time for a long cat nap..." << endl; napAdder();}

        int mealCount;
        int napCount;

        char *name;
};

#endif // CCat_HEADER

