// ============================================================================
// File: CSimpleList.cpp (Fall 2015)
// ============================================================================
// This is the implementation file for the list ADT "CSimpleList".  This
// particular implementation uses an array to store a list of type
// "ListType" items.
// ============================================================================

#include    <iostream>
using namespace std;
#include    "CSortedList.h"



// ==== CSimpleList::DispRetVal ===============================================
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

}  // end of "CSimpleList::DispRetVal"



// ==== CSimpleList::GetItem ==============================================
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

LStatus  CSortedList::GetListItem(int  index, ListType  &item) const
{
    // if the list is empty, return an error cocde
    if (true == IsEmpty())
        {
        DispRetVal("GetItem", L_EMPTY);
        return L_EMPTY;
        }

    // if the target location is not within appropriate list boundaries (i.e.,
    // 0 to m_numItems-1), return an error code
    if ((index < 0)  ||  (index > (m_numItems - 1)))
        {
        DispRetVal("GetItem", L_INVALID_INDEX);
        return L_INVALID_INDEX;
        }

    // initialize the reference parameter and return
    item = m_items[index];
    return L_SUCCESS;

}  // end of "CSimpleList::GetItem"



// ==== CSimpleList::Insert ===============================================
//
// This function inserts an item into the list.  If the new item is appended to
// the end of the list, the position of any other list item is unaffected.  If
// the new item is inserted before the last element, all elements after the
// target location are moved towards the back of the array one position to make
// room for the new element.
//
// Input:
//      index       -- the target index location for the new item (zero-based).
//
//      newItem     -- a const reference to the new item to insert into the list
//
// Output:
//      If all goes well, a value of L_SUCCESS is returned; else, an error
//      code is returned.
//
// ============================================================================

LStatus  CSortedList::InsertItem(const ListType &newItem)
{
    // if the list is already full, return an error code
    if (true == IsFull())
        {
        DispRetVal("Insert", L_FULL);
        return L_FULL;
        }


    //checks if there is a duplicate already in the list
    if(GetTargetIndex(newItem, m_numItems) == true)
        {

                DispRetVal("IndertItem", L_DUPLICATE);
                return L_DUPLICATE;
        }

    //checks if new item is less than the numbers already in the list. If it is it will be added to the spot
   //where the index is and the current number in that index will be moved back one place.
    for(int i = 0; i < MAX_ITEMS; i++)
    {
        if(newItem < m_items[i])
        {
                MoveListItems(i, MOVE_TO_BACK);
                m_items[i] = newItem;
                ++m_numItems;
                return L_SUCCESS;
        }

    }



    //adds number to the end if the number is larger than all numbers in the array list
    m_items[m_numItems] = newItem;
    ++m_numItems;
    return L_SUCCESS;

}  // end of "CSimpleList::Insert"



// ==== CSimpleList::MoveItems ============================================
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

int     CSortedList::MoveListItems(int  targetIndex, int  direction)
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

}  // end of "CSimpleList::MoveItems"



// ==== CSimpleList::Remove ===============================================
//
// This function removes an item from the list.  If the target item is at the
// end of the list, the position of any other list item is unaffected.  If the
// target item is before the end of the list, all elements after the target
// location are moved towards the front of the array one position to fill in
// the gap left behind by the deleted item.
//
// Input:
//      index       -- the index location for the target item (zero-based).
//
// Output:
//      If all goes well, a value of L_SUCCESS is returned; else, an error
//      code is returned.
//
// ============================================================================

LStatus  CSortedList::RemoveItem(const ListType &targetItem)
{
    // if the list is empty, return an error cocde
    if (true == IsEmpty())
        {
        DispRetVal("Remove", L_EMPTY);
        return L_EMPTY;
        }

    //checks if the number is in the list. If it isn't it will return not exist error
    if(GetTargetIndex(targetItem, m_numItems) != true)
        {
                DispRetVal("RemoveItem", L_NOT_EXIST);
                return L_NOT_EXIST;

        }

    //find the target item, and moves it to the front to be deleted from the list
    for (int i = 0; i < MAX_ITEMS; i++)
        {

                if(targetItem == m_items[i])
                {
                        MoveListItems(i, MOVE_TO_FRONT);

                }
        }

    --m_numItems;
    return L_SUCCESS;

}  // end of "CSortedeList::Remove"




//determines where if an item is in a list. If it isn't where it belongs
bool CSortedList::GetTargetIndex(const ListType &newItem, int &targetIndex) const
{
        for(int i = 0; i < targetIndex; i++)
        {
                if(m_items[i] == newItem)
                {
                        return true;
                }
        }
       return false;




}

