#include <iostream>

using namespace std;



//Recursive rabbit function with default indent value.
int Rabbits(int months, int indent = 0)
{
        //initialized and assigns the leaveValue to 0 so that it can be returned at the end of the function.
        int leaveValue = 0;

        //the higher int indent is in value the more indents the for loop will create.
        for(int i = 0; i < indent; i++)
        {
                cout << "   ";
        }

        cout << "Enter rabbit: n = " << months << endl;

        //when the value of months is equal to 1 or 2 leaveValue will be assigned to the value 1.
        if((1 == months) || (2 == months))
        {
                leaveValue = 1;

        }
        else
        {
                //Follows fib sequence. adds one more value to the indent and overrides the default value.
                leaveValue = Rabbits(months - 1, indent + 1) + Rabbits(months  - 2, indent + 1);

        }

        //prints indent based on int indent value
        for(int i = 0; i < indent; i++)
        {
                cout << "   ";

        }

        //tells n vlaue and the beginning the the leave value. then ends the function by returning the leaveValue.
        cout << "Leave rabbit: n = " << months << "\t value = " << leaveValue << endl;
        return leaveValue;
}

int main()
{
        int numOfMonths = 0;

        //calls user to input the amount of months.
        cout << "Enter number of months: ";
        cin >> numOfMonths;
        Rabbits(numOfMonths);



}
