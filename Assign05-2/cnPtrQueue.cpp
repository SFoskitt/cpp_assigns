#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_SP18_A5P2
{
/*
    public:
      typedef std::size_t size_type;
      cnPtrQueue();
      bool empty() const;
      size_type size() const; // returns # of items in queue
      CNode* front();
      void push(CNode* cnPtr);
      void pop();
   private:
      std::stack<CNode*> inStack;
      std::stack<CNode*> outStack;
      size_type numItems;     // # of items in queue
 */

    // constructor, does it need anything special? default args? constructor args list?
    cnPtrQueue::cnPtrQueue()
    {
        std::stack<CNode*> inStack;
        std::stack<CNode*> outStack;
        size_type numItems = 0;
    }

    bool cnPtrQueue::empty() const
    {
        return numItems > 0;
    }

    cnPtrQueue::size_type cnPtrQueue::size() const
    {
         return numItems;
    }

    CNode* cnPtrQueue::front()
    {
        CNode* thing;
        // return a pointer to the front child node
        return thing;
    }

    void cnPtrQueue::push(CNode* cnPtr)
    {
        // stl::push into inStack
        // numItems++;
        return;
    }

    void cnPtrQueue::pop()
    {
        // if (numItems > 0)
            // if (outStack.length = 0)
                // move everything from inStack to outStack
            // stl:: pop
            // numItems--;
        return;
    }
}
