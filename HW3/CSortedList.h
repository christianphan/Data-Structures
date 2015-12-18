// ============================================================================
// File: CSortedList.h (Fall 2015)
// ============================================================================
// Header file for the CSortedList class.
// ============================================================================

#ifndef CSORTED_LIST_HEADER
#define CSORTED_LIST_HEADER

// enable this #define symbol to see debug output
#define DEBUG_LIST

// type definitions
typedef int     ListType;
enum    LStatus  { L_FULL
                  , L_EMPTY
                  , L_ERROR
                  , L_SUCCESS
                  , L_INVALID_INDEX
                  , L_DUPLICATE
                  , L_NOT_EXIST
                };


// constants
const   int     MAX_ITEMS = 5;
const   int     MOVE_TO_BACK = 0;
const   int     MOVE_TO_FRONT  = 1;

class   CSortedList
{
public:
    // constructor and destructor
    CSortedList() : m_numItems(0) {}
    ~CSortedList() { DestroyList(); }

    // member functions
    LStatus    DestroyList()
                        { m_numItems = 0; return L_SUCCESS; }
    void       DispRetVal(const char*  szMessage, LStatus  value) const;
    LStatus    GetListItem(int  index, ListType  &item) const;
    int        GetNumItems() const { return (m_numItems); }
    LStatus    InsertItem(const ListType  &newItem);
    bool       IsEmpty() const { return (0 == m_numItems); }
    bool       IsFull() const { return (MAX_ITEMS == m_numItems); }
    LStatus    RemoveItem(const ListType  &targetItem);

private:
    // data members
    int        m_numItems;
    ListType   m_items[MAX_ITEMS];

    // member functions
    bool       GetTargetIndex(const ListType  &newItem
                                   , int  &targetIndex) const;
    int        MoveListItems(int  targetIndex, int  direction);
};

#endif  // CSORTED_LIST_HEADER


