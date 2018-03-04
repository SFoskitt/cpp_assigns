#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_SP18_A5P2
{
    // constructor, does it need anything special? default args? constructor args list?
    cnPtrQueue::cnPtrQueue()
    {
        std::stack<CNode*> inStack;
        std::stack<CNode*> outStack;
        numItems = 0;
    }

    bool cnPtrQueue::empty() const
    {
        return numItems == 0;
        // return inStack.empty() && outStack.empty();
    }

    cnPtrQueue::size_type cnPtrQueue::size() const
    {
         return numItems;
    }

    CNode* cnPtrQueue::front()
    {
        assert(!empty());
       //assert(!inStack.empty() || !outStack.empty());
        if (outStack.empty())
        {
         while (!inStack.empty())
         {
            outStack.push( inStack.top());
            inStack.pop();
         }
        }
        return outStack.top();
    }

    void cnPtrQueue::push(CNode* cnPtr)
    {
        inStack.push(cnPtr);
        numItems++;
    }

    void cnPtrQueue::pop()
    {
       assert(!empty());
       //assert(!inStack.empty() || !outStack.empty());

        if (outStack.empty())
        {
         while (!inStack.empty())
         {
            outStack.push( inStack.top() );
            inStack.pop();
         }
        }
        outStack.pop();
        numItems--;
    }
}
