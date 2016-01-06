#ifndef CPET_HEADER
#define CPET_HEADER
#include <cstring>
using namespace std;

class CPet
{
        public:
                CPet();
                ~CPet();
                CPet(const char *PetName);
                void SayName()const ;
                virtual void Eat();
                virtual void Sleep();
                void DispState() const;
                void Destroy();
                CPet & operator=(const CPet &rhs);
                CPet(const CPet &other);
                void CopyPet(const CPet &other);
                void mealAdder();
                void napAdder();

                char *name;
                int mealCount;
                int napCount;
};

#endif // CPET_HEADER

