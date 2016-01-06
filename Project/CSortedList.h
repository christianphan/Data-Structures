// ============================================================================
// File: CSortedList.h (Fall 2015)
// ============================================================================
// Header file for the CSortedList class.
// ============================================================================

#ifndef CSORTED_LINKED_LIST_HEADER
#define CSORTED_LINKED_LIST_HEADER

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

// structure for linked list nodes
struct  ItemNode
{
    ListType    value;
    ItemNode    *next;
};


class   CSortedList
{
public:
    // construction and destruction
    CSortedList() : m_headPtr(NULL),  m_numItems(0) {}
    CSortedList(const CSortedList  &object);
    ~CSortedList() { DestroyList(); }

    // member functions
    void       DestroyList();
    void       DispRetVal(const char*  szMessage, LStatus  value) const;
    LStatus    GetItem(int  index, ListType  &item) const;
    int        GetNumItems() const { return m_numItems; }
    LStatus    Insert(const ListType  &newItem);
    bool       IsEmpty() const { return (NULL == m_headPtr); }
    bool       IsFull() const { return false; }
    LStatus    Remove(const ListType  &targetItem);

    // overloaded operators
    CSortedList&    operator=(const CSortedList  &rhs);

private:
    // data members
    ItemNode  *m_headPtr;
    int        m_numItems;
	
    // member functions
    int        CopyList(const CSortedList  &other);
};

#endif  // CSORTED_LINKED_LIST_HEADER


