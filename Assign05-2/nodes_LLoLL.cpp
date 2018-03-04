#include "nodes_LLoLL.h"
#include "cnPtrQueue.h"
#include <iostream>
using namespace std;

namespace CS3358_SP18_A5P2
{
   void Destroy_cList(CNode*& cListHead)
   {
      int count = 0;
      CNode* cNodePtr = cListHead;
      while (cListHead != 0)
      {
         cListHead = cListHead->link;
         delete cNodePtr;
         cNodePtr = cListHead;
         ++count;
      }
      cout << "Dynamic memory for " << count << " CNodes freed \n" << endl;
   }

   void Destroy_pList(PNode*& pListHead)
   {
      int count = 0;
      PNode* pNodePtr = pListHead;
      while (pListHead != 0)
      {
         pListHead = pListHead->link;
         Destroy_cList(pNodePtr->data);
         delete pNodePtr;
         pNodePtr = pListHead;
         ++count;
      }
      cout << "Dynamic memory for " << count << " PNodes freed \n" << endl;
   }

   // do depth-first traversal and print data
   void ShowAll_DF(PNode* pListHead, ostream& outs)
   {
      while (pListHead != 0)
      {
         CNode* cListHead = pListHead->data;
         while (cListHead != 0)
         {
            outs << cListHead->data << " ";
            cListHead = cListHead->link;
         }
         pListHead = pListHead->link;
      }
   }

   void ShowAll_BF(PNode* pListHead, ostream& outs)
   {
      if (pListHead == 0) return;

      cnPtrQueue bf_queue = cnPtrQueue();

      while (pListHead != 0)
      {
         if (pListHead->data != 0)
         {
            bf_queue.push(pListHead->data);
         }
         pListHead = pListHead->link;
      }

      while (!bf_queue.empty())
      {
         CNode* thing = bf_queue.front();
         bf_queue.pop();
         outs << thing->data << " ";
         if(thing->link)
         {
            bf_queue.push(thing->link);
         }
      }

//      for (int i = 0; i < 5; i++)
//      {
//         CNode* tmpPtr = 0;
//         bf_queue.push(tmpPtr);
//      }
//
//      for (int j = 0; j < 5; j++)
//      {
//         outs << "front: ", bf_queue.front();
//         bf_queue.pop();
//      }
   }
}
