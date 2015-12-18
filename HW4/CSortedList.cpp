// ============================================================================
// File: CSortedList.cpp (Fall 2015)
// ============================================================================
// This is the implementation file for the list ADT "CSortedList".  This
// particular implementation uses an array to store a list of type
// "ListType" items.
// ============================================================================

#include    <iostream>
using namespace std;
#include    "CSortedList.h"



// ==== CSortedList::CSortedList ============================================
//
// This the default constructor.
//
// Input:
//      Nothing.
//
// Output:
//      Nothing.
//
// ============================================================================

CSortedList::CSortedList()
{
        m_numItems = 0;


}

// ==== CSortedList::CSortedList ============================================
//
// This the copy constructor, which performs a deep copy of the parameter.
//
// Input:
//      otherList   -- a reference to an existing CSortedList object
//
// Output:
//      Nothing.
//
// ============================================================================
CSortedList::CSortedList(const CSortedList& other)
{
        m_currMax = other.m_currMax;
        m_numItems = other.m_numItems;
        m_items = other.m_items;



}


// ==== CSortedList::CopyList =================================================
//
// This function copies the contents of one CSortedList object to another
// CSortedList object.  If the destination object already contains a list, then
// that list is first released.
//
// Input:
//      otherList   -- a const reference to an existing CSortedList object
//
// Output:
//      The total number of items copied from the source object to the
//      destination object.
//
// ============================================================================

int CSortedList::CopyList(const CSortedList &otherList)
{


}


// ==== CSortedList::DestroyList =============================================
//
// This function destroys a list by releasing any memory allocated for the
// list.
//
// Input:  nothing
//
// Output: nothing
//
// ============================================================================

void CSortedList::DestroyList()
{
        delete []m_items;



}

// ==== CSortedList::DispRetVal ===============================================
//
// This function is used for debugging purposes.  If a value of type
// ListReturnCode needs to be displayed to stdout, you can call this function.
//
// Input:
//      szMessage   -- a null-terminated string to display to stdout (e.g., the
//                     name of the function calling this function)
//
//      value       -- the list error code to display
//
// Output:
//      nothing
//
// ============================================================================

void    CSortedList::DispRetVal(const char*  szMessage
                                                    , LStatus  value) const
{
    #ifdef  DEBUG_LIST
    cerr << szMessage << ": ";
    switch (value)
        {
        case   L_FULL:
            cerr << "L_FULL\n";
            break;

        case   L_EMPTY:
            cerr << "L_EMPTY\n";
            break;

        case   L_ERROR:
            cerr << "L_ERROR\n";
            break;
        case   L_SUCCESS:
            cerr << "L_SUCCESS\n";
            break;

        case   L_INVALID_INDEX:
            cerr << "L_INVALID_INDEX\n";
            break;

        case   L_DUPLICATE:
            cerr << "L_DUPLICATE\n";
            break;

        case   L_NOT_EXIST:
            cerr << "L_NOT_EXIST\n";
            break;

        default:
            cerr << "Unrecognized error code\n";
            break;
        }
    #endif  // DEBUG_LIST
}  // end of "CSortedList::DispRetVal"



// ==== CSortedList::GetItem ==================================================
//
// This function fetches the value of a target item from the list.
//
// Input:
//      index   -- the index location for the target item (zero-based).
//
//      item    -- a reference to a ListType object; this argument will
//                 contain the desired item after the function completes
//                 (assuming all goes well)
//
// Output:
//      If all goes well, a value of L_SUCCESS is returned and the target
//      item is assigned to the reference parameter.  Else, an error code is
//      returned.
//
// ============================================================================

LStatus CSortedList::GetItem(int index, ListType &item) const
{
        item = m_items[index];



        return L_SUCCESS;
}


// ==== CSortedList::GetTargetIndex ===========================================
//
// This function determines the proper index location for the "newItem"
// parameter.  The proper index location is one that will maintain an ascending
// sorted order in the list.  If the "newItem" value is already in the list, a
// value of true is returned to alert the caller, otherwise a value of false is
// returned.
//
// NOTE: this function assumes the caller has already determined that there is
//       enough room in the array to add the new item.
//
//
// Input:
//
//      newItem     -- a const reference to the new item to insert into the list
//
//      index       -- the target index location for the new item (zero-based)
//
//
// Output:
//      A value of true if the "newItem" value is already in the list, false if
//      not.
//
// ============================================================================

bool CSortedList::GetTargetIndex(const ListType &newItem, int &index) const
{
        bool returnValue = false;
        for(int index = 0; index < m_numItems ; index++)
        {

                if(newItem == m_items[index])
                {
                        returnValue = true;
                        break;

                }
                else if (newItem < m_items[index])
                {
                        break;

                }

        }
        return returnValue;

}



// ==== CSortedList::Insert ===================================================
//
// This function inserts an item into the list.  If the new item is appended to
// the end of the list, the position of any other list item is unaffected.  If
// the new item is inserted before the last element, all elements after the
// target location are moved towards the back of the array one position to make
// room for the new element.
//
// Input:
//      newItem    -- a const reference to the new item to insert into the list
//
// Output:
//      If all goes well, a value of L_SUCCESS is returned; else, an error
//      code is returned.
//
// ============================================================================

LStatus CSortedList::Insert(const ListType &newItem)
{

        if(m_numItems == 0)
        {
                m_items = new ListType[DEFAULT_LISTSIZE];
                m_currMax = 5;
        }

        int index;
        if (GetTargetIndex(newItem, index) == true)
        {
                DispRetVal("Insert", L_DUPLICATE);
                return L_DUPLICATE;
        }


        if(m_numItems == m_currMax)
        {
                SetListSize(m_numItems);

        }

        for(int i = 0; i < m_numItems; i++)
        {
                if(newItem < m_items[i])
                {
                        MoveItems(i, MOVE_TO_BACK);
                        m_items[i] = newItem;
                        ++m_numItems;
                        return L_SUCCESS;
                }
        }

        m_items[m_numItems] = newItem;
        ++m_numItems;
        return L_SUCCESS;
}



// ==== CSortedList::MoveItems ================================================
//
// This function moves the elements of the list forward or backward one
// position.  If an item is inserted before the last element in the list, the
// "trailing" elements must be moved towards the back of the array one position
// in order to make room for the new list item.  Similarly, if a list item is
// removed from the middle of the list, the trailing elements must be moved
// towards the front of the array one position to fill in the gap left by the
// deleted item.
//
// The caller of this function only needs to indicate the target location where
// an element is being inserted or removed, and the "direction" to move the
// trailing list elements (i.e., towards the front or back of the array).
//
// NOTE: This function assumes that the caller has already verified the
// validity of the index parameter.
//
// Input:
//      targetIndex     -- the index location for the target item (zero-based).
//
//      direction       -- the direction to move the trailing (i.e., those
//                         further down the list) list elements; this parameter
//                         should contain the value MOVE_TO_BACK if an item is
//                         being inserted into the list, or MOVE_TO_FRONT if
//                         the item at targetIndex is being removed from the
//                         list.
//
// Output:
//      If all goes well, a value of L_SUCCESS is returned and the target
//      item is assigned to the reference parameter.  Else, an errorcode is
//      returned.
//
// ============================================================================

int     CSortedList::MoveItems(int  targetIndex, int  direction)
{
    int         destIndex;
    int         increment;
    int         sourceIndex;
    int         totalItemsMoved = 0;

    // initialize the source and destination index values
    if (MOVE_TO_BACK == direction)
        {
        sourceIndex = m_numItems - 1;
        destIndex = m_numItems;
        increment = -1;     // move from higher to lower addresses
        }
    else    // MOVE_TO_FRONT
        {
        sourceIndex = targetIndex + 1;
        destIndex = targetIndex;
        increment = 1;      // move from lower to higher addresses
        }

    // loop and "move" elements
    bool        bContinueLoop = true;
    do  {
        m_items[destIndex] = m_items[sourceIndex];
        destIndex += increment;
        sourceIndex += increment;
        ++totalItemsMoved;

        if (MOVE_TO_BACK == direction)
            {
            if ((sourceIndex < targetIndex)  ||  (destIndex < 1))
                {
                bContinueLoop = false;
                }
            }
        else    // MOVE_TO_FRONT
            {
            if (sourceIndex >= m_numItems)
                {
                bContinueLoop = false;
                }
            }

        }  while (true == bContinueLoop);
    return totalItemsMoved;

}  // end of "CSortedList::MoveItems"



// ==== CSortedList::Remove ===================================================
//
// This function removes an item from the list.  If the target item is at the
// end of the list, the position of any other list item is unaffected.  If the
// target item is before the end of the list, all elements after the target
// location are moved towards the front of the array one position to fill in
// the gap left behind by the deleted item.
//
// Input:
//      targetItem      -- a const reference to the item to remove
//
// Output:
//      If all goes well, a value of L_SUCCESS is returned; else, an error
//      code is returned.
//
// ============================================================================
LStatus CSortedList::Remove(const ListType &targetItem)
{
        if(IsEmpty() == true )
        {
                DispRetVal("Remove", L_EMPTY);
                return L_EMPTY;

        }

        int index;
        if(false == GetTargetIndex(targetItem,index))
        {
                DispRetVal("Remove", L_NOT_EXIST);
                return L_NOT_EXIST;

        }


        for (int i = 0; i < m_numItems; i++)
        {
                if(targetItem == m_items[i])
                {
                        MoveItems(i, MOVE_TO_FRONT);
                }

        }

        --m_numItems;
        return L_SUCCESS;


}


// ==== CSortedList::SetListSize ==============================================
//
// This function is used to manage the allocated size of a list. The input
// parameter indicates the number of elements to allocate for the list. If the
// calling object already contains a list with data, it can be resized to
// either increase or decrease its allocation. If the size of the existing list
// is being decreased, then the trailing items will be truncated.
//
//
// Input:
//      numItems  -- the target number of items in the list
//
// Output:
//      Nothing.
//
// ============================================================================

LStatus CSortedList::SetListSize(int numItems)
{


         if(IsFull() == true)
        {

                ListType * testPtr;
                testPtr = new int[m_currMax  + 1];


                for(int i = 0; i < m_numItems; i++)
                {
                        testPtr[i] = m_items[i];

                }


                DestroyList();
                m_items = new int[m_currMax + 1];

                for(int i = 0; i < m_numItems; i++)
                {
                        m_items[i] = testPtr[i];

                }

                delete []testPtr;
                m_currMax += 1;
                return L_SUCCESS;
        }

        return L_SUCCESS;

}

// ==== CSortedList::operator= ================================================
//
// This is the overloaded assignment operator, copying the parameter's list to
// the calling object.
//
// Input:
//      rhs         -- a reference to a source CSortedList object
//
// Output:
//      A reference to the calling object.
//
// ============================================================================

CSortedList & CSortedList::operator=(const CSortedList &otherList)
{

        m_items = otherList.m_items;

}
