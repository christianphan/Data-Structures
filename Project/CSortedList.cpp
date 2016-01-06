#include <iostream>
#include "CSortedList.h"


using namespace std;



//copy constructor
//makes a deep copy and avoids shallow copy
CSortedList::CSortedList(const CSortedList &object)
{
        //copies the object's list as long as it is not empty
        if(object.m_headPtr != NULL)
        {
                CopyList(object);
        }

}




/*********************************
Name            :DestroyList
Arguments       :None
Returns         :None
PreCondition    :None
Postcondition   :Will destory the list of nodes in a list
Description     :This function will find every node within a list and destory them.
                Used in the destructor and the CopyList function
************************************/
void CSortedList::DestroyList()
{
        ItemNode *listPtr;
        ItemNode *listPtrNext;

        listPtr = m_headPtr;

        while(listPtr != NULL)
        {
                listPtrNext = listPtr->next;
                delete listPtr;
                listPtr = listPtrNext;
        }
        m_numItems = 0;

}

/*********************************
Name            :DispRetVal
Arguments       :const char* szMessage, LStatus value
Returns         :None
PreCondition    :None
Postcondition   :Will display LStatus values
Description     :Gets callled on and displays what ever LStatus value is
                 passed on
************************************/
void CSortedList::DispRetVal(const char* szMessage, LStatus value) const
{
        #ifdef DEBUG_LIST
        cerr <<szMessage << ": ";
        switch(value)
        {
                case L_FULL:
                        cerr << "L_FULL\n";
                        break;
                case L_EMPTY:
                        cerr << "L_EMPTY\n";
                        break;
                case L_ERROR:
                        cerr << "L_ERROR\n";
                        break;
                case L_SUCCESS:
                        cerr << "L_SUCCESS\n";
                        break;
                case L_INVALID_INDEX:
                        cerr << "L_INVALID_INDEX\n";
                        break;
                case L_DUPLICATE:
                        cerr << "L_INVALID_INDEX\n";
                        break;
                case L_NOT_EXIST:
                        cerr << "L_NOT_EXIST\n";
                        break;
                default:
                default:
                        cerr << "Unrocognized error code\n";
                        break;


        }


        #endif //DEUB_LIST
}

/*********************************
Name            :Insert
Arguments       :const ListType &newItem
Returns         :LStatus value
PreCondition    :Node
Postcondition   :Will create a new node for the new value if one does not already exist and organizes it in numeric order
Description     :Creates node to be inserted into list that is called from the main.cpp file
************************************/
LStatus CSortedList::Insert(const ListType &newItem)
{

        ItemNode *listPtr;

        //listPtrPrev will point to the node previous of listPtr
        ItemNode *listPtrPrev = NULL;
        ItemNode *newNode;

        //creates new node with its *next set to NULL and its value equal to what ever the user inputs
        newNode = new ItemNode;
        newNode->next = NULL;
        newNode->value = newItem;

        //if the list is empty the headPtr will point to the newly created node
        while(NULL == m_headPtr)
        {
                m_headPtr = newNode;
                m_numItems++;
                return L_SUCCESS;
        }


        listPtr = m_headPtr;

        //loops until newItem item is less than the value list pointer is pointing to or until
        while ((newItem > listPtr->value) && (listPtr->next != NULL))
        {
                listPtrPrev = listPtr;
                listPtr = listPtr->next;

        }


        //if there is a duplicate
        if(newItem == listPtr->value)
        {
                delete newNode;
                return L_DUPLICATE;
        }

        if(newItem < listPtr->value)
        {
                if( NULL != listPtrPrev)
                {
                        listPtrPrev->next = newNode;
                }

                newNode->next = listPtr;


                //changes the m_headPtr to point to new node if the original headPtr points to a
                // node where that value is greater than the newItem being inserted.
                //only if listPtr is equal to the headPtr
                if(listPtr == m_headPtr)
                {
                        m_headPtr = newNode;

                }

        }

        else
        {
                listPtr->next = newNode;

        }

        m_numItems++;
        return L_SUCCESS;
}



/*********************************
Name            :Remove
Arguments       :const ListType &targetItem
Returns         :LStatus
PreCondition    :Node
Postcondition   :Deletes a node from a list
Description     :Find the targetItem value and if there is a node with the same item
                the function will delete that node and reconnect the previous node
                to the the next node in the list
************************************/
LStatus CSortedList::Remove(const ListType &targetItem)
{
        ItemNode *listPtr;
        listPtr = m_headPtr;

        ItemNode *listPtrPrev = NULL;
        ItemNode *listPtrNext = NULL;

        if(listPtr == NULL)
        {
                return L_EMPTY;
        }

        //will loop until listPtr has a value that is equal to our targetItem or until it reaches the end
        //of the list.
        while((listPtr->value != targetItem) && (listPtr != NULL) )
        {
                listPtrPrev = listPtr;
                listPtr = listPtr->next;
        }


        //checks to make sure that the list has not come to an end
        //if listPtr is equal to NULL that means that no values of the targetItem exist
        if(listPtr == NULL)
        {
                return L_NOT_EXIST;

        }


        //sets the listPtrNext to point to the address that comes next after our pointer
        //delete s the pointer, and sets the previous node's next to point t listPtrNext.
        listPtrNext = listPtr->next;

        if(listPtrPrev != NULL)
        {
                listPtrPrev->next = listPtrNext;
        }

        else if(listPtrPrev == NULL)
        {
                m_headPtr = listPtrNext;
        }

        delete listPtr;

        //subtracts the number of items in the list.
        --m_numItems;
        return L_SUCCESS;
}




/*********************************
Name            :operator=
Arguments       :const CSORTEDLIST &rhs
Returns         :None
PreCondition    :None
Postcondition   :Assigns a CSortedList object to have the same value to object to the right
Description     :Overloads the assigment operator of the CSortedList class so that it can
                copy list values from the ojbect on the right hand side.
************************************/
CSortedList & CSortedList::operator=(const CSortedList &rhs)
{
        //checks for self assignment
        //CSL1 = CSL1;
        //if current CSortedList is not the same as the one on the right hand side if statement will run
        if(this != &rhs)
        {
                //Copies list from rhs
                CopyList(rhs);
        }

        return *this;

}



/*********************************
Name            :CopyList
Arguments       :const CSortedList &other
Returns         :None
PreCondition    :None
Postcondition   :Called from the copy constructor of the overloaded assignmnet operator
Description     :Copies all of the nodes from on CSL object to another
************************************/

int CSortedList::CopyList(const CSortedList &other)
{
        //if the other object is not the same
        if(this != &other)
        {
                DestroyList();
        }
        //if they are the same returns 0 and ends the function. No need to copy anything
        else if(this == &other)
        {
                return 0;
        }

        //listPtr points to the address of the first node in the list from the other object
        ItemNode *listPtr;
        listPtr = other.m_headPtr;

        ItemNode *CurrentListPtr;


        //loops run until listPtr is equal to a NULL value, so until it reaches end of node list.
        while(listPtr != NULL)
        {

                //creates new nodes and copies values of the node that the listPtr is pointing to
                CurrentListPtr = new ItemNode;
                CurrentListPtr->value = listPtr->value;
                CurrentListPtr->next = listPtr->next;
                listPtr = listPtr->next;

                if(m_numItems == 0)
                {
                        m_headPtr = CurrentListPtr;
                }

                m_numItems++;
        }

        return 0;
}



/*********************************
Name            :GetItem
Arguments       :index, &item
Returns         :LStatus L_SUCCESS, L_EMPTY
PreCondition    :None
Postcondition   :Called from the main.cpp file to display current items in list
Description     :Sets the item in the parameter called from the main.cpp to display
                the node based on the index in the parameter
************************************/
LStatus CSortedList::GetItem(int index, ListType &item) const
{
        ItemNode *listPtr;
        listPtr = m_headPtr;

        //runs while listPtr != null
        if(listPtr != NULL)
        {

                //cycles through the list and sets listPtr to equal to its next value until it reaches the index value
                for(int i = 0; i < index; i++)
                {
                        listPtr = listPtr->next;
                }

                //item is set to equal the value of the address that listyPtr is pointing to
                item = listPtr->value;
                return L_SUCCESS;
        }
        return L_EMPTY;
}

