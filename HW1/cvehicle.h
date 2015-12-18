// ============================================================================
// File: cvehicle.h (Fall 2015)
// ============================================================================

#ifndef CVEHICLE_HEADER
#define CVEHICLE_HEADER

#include <iostream>
#include <cstring>
using namespace std;


// constants
const   int         BUFLEN = 256;

// class declaration
class   CVehicle
{
public:
    // ??


    CVehicle();
    CVehicle(string make, string model );
    void  WriteVehicle() const;
    void  ReadVehicle();
    string Make() const;
    string Model() const;

private:
    char    m_make[BUFLEN];
    char    m_model[BUFLEN];
};


// non-member functions
istream&    operator>>(istream  &inStream, CVehicle  &rhs);
ostream&    operator<<(ostream  &outStream, const CVehicle  &rhs);

#endif  // CVEHICLE_HEADER

