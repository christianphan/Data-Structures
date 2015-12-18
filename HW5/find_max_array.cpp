// ============================================================================
// File: find_max_array.cpp (Fall 2015)
// ============================================================================
// This program is an exercise in working with two-dimensional arrays and
// pointers-to-pointers. A two-dimensional array of ints is allocated from the
// stack and initialized in "main". This is passed to FindMaxArray, along with
// the address of a local pointer-to-an-int. After the function returns, the
// local int pointer should be pointing to the array with the largest sum.
//
// Output:
//      Here is the array with the maximum sum:
//      22 + 500 + -67 + 1 = 456
//
// ============================================================================

#include    <iostream>
using namespace std;


// constants
#define NUM_ARRAYS          5
#define NUM_ELEMS           4


// function prototypes (fill in any missing formal parameter lists)
int     CalcArraySum(int  array[], int  numItems);
void    DispArray(int  array[], int  numItems);
int     FindMaxArray(int array[][NUM_ELEMS], int numArrays,int  **arrayPtr);


// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    int         intArrays[NUM_ARRAYS][NUM_ELEMS] = {  {10, 20, 30, 40} // 100
                                                    , {1, 2, 3, 4}     // 10
                                                    , {5, 2, -8, 22}   // 21
                                                    , {99, 3, 10, 34}  // 146
                                                    , {22, 500, -67, 1}// 456
                                                   };
    int         *arrayPtr;
    int         sum;

    sum = FindMaxArray(intArrays, NUM_ARRAYS, &arrayPtr);
    cout << "Here is the array with the maximum sum:\n";
    DispArray(arrayPtr, NUM_ELEMS);
    cout << " = " << sum << endl;

    return  0;

}  // end of "main"

int CalcArraySum(int array[], int numItems)
{
        int sum = 0;
        for(int i =0; i < numItems; i++)
        {
                sum += array[i];
        }

        return sum;
}
void    DispArray(int  array[], int  numItems)
{
        for(int i =0; i < numItems; i++)
        {
                cout << array[i];

                if(i + 1 < numItems)
                {
                        cout << " + ";

                }
        }
}

int     FindMaxArray(int intArrays[][NUM_ELEMS], int numArrays, int **arrayPtr  )
{
        int sum = 0;
        for(int i = 0; i < numArrays; i++)
        {
                *arrayPtr = &intArrays[i][0];
                if(sum < CalcArraySum(*arrayPtr,NUM_ELEMS))
                {
                        sum = CalcArraySum(*arrayPtr,NUM_ELEMS);

                }
        }

        return sum;
}


