#include <iostream>
#include "CQueue.h"


using namespace std;



int CQueue::Destroy()
{
        int amount = m_list.GetNumItems();
        m_list.DestroyList();
        return amount;
}

void CQueue::Enqueue(const QueueType &newItem)
{
        try
        {
                m_list.Insert(m_list.GetNumItems(), newItem);
        }

        catch(const CListEx &listEx)
        {
                if(L_FULL == listEx.GetExType())
                {
                        throw CQueueEx(Q_FULL);
                }

                else
                {
                        throw CQueueEx(Q_ERROR);
                }
        }
}



void CQueue::Dequeue(QueueType &queueItem)
{
        try
        {
                m_list.GetItem(0,queueItem);
                m_list.Remove(0);
        }

        catch(const CListEx &listEx)
        {
                if(L_EMPTY == listEx.GetExType())
                {
                        throw CQueueEx(Q_EMPTY);
                }
                else
                {
                        throw CQueueEx(Q_ERROR);

                }
        }

}

void CQueue::Dequeue()
{
        QueueType queueItem = 0;
        try
        {
                m_list.GetItem(0,queueItem);
                m_list.Remove(0);
        }

        catch(const CListEx &listEx)
        {
                if(L_EMPTY == listEx.GetExType())
                {
                        throw CQueueEx(Q_EMPTY);
                }

                else
                {
                        throw CQueueEx(Q_ERROR);
                }
        }
}

void CQueue::Retrieve(QueueType &item) const
{
        try
        {
                m_list.GetItem(0,item);
        }
        catch(const CListEx &listEx)
        {
                if(L_EMPTY == listEx.GetExType())
                {
                        throw CQueueEx(Q_EMPTY);
                }
                else
                {
                        throw CQueueEx(Q_ERROR);
                }

        }

}
