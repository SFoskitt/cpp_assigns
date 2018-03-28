#include <iostream>
#include <cstdlib>
#include "llcpInt.h"
using namespace std;

int FindListLength(Node* headPtr)
{
   int length = 0;

   while (headPtr != 0)
   {
      ++length;
      headPtr = headPtr->link;
   }

   return length;
}

bool IsSortedUp(Node* headPtr)
{
   if (headPtr == 0 || headPtr->link == 0) // empty or 1-node
      return true;
   while (headPtr->link != 0) // not at last node
   {
      if (headPtr->link->data < headPtr->data)
         return false;
      headPtr = headPtr->link;
   }
   return true;
}

void InsertAsHead(Node*& headPtr, int value)
{
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = headPtr;
   headPtr = newNodePtr;
}

void InsertAsTail(Node*& headPtr, int value)
{
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = 0;
   if (headPtr == 0)
      headPtr = newNodePtr;
   else
   {
      Node *cursor = headPtr;

      while (cursor->link != 0) // not at last node
         cursor = cursor->link;
      cursor->link = newNodePtr;
   }
}

void InsertSortedUp(Node*& headPtr, int value)
{
   Node *precursor = 0,
   *cursor = headPtr;

   while (cursor != 0 && cursor->data < value)
   {
      precursor = cursor;
      cursor = cursor->link;
   }

   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = cursor;
   if (cursor == headPtr)
      headPtr = newNodePtr;
   else
      precursor->link = newNodePtr;
}

bool DelFirstTargetNode(Node*& headPtr, int target)
{
   Node *precursor = 0,
   *cursor = headPtr;

   while (cursor != 0 && cursor->data != target)
   {
      precursor = cursor;
      cursor = cursor->link;
   }
   if (cursor == 0)
   {
      cout << target << " not found." << endl;
      return false;
   }
   if (cursor == headPtr) //OR precursor == 0
      headPtr = headPtr->link;
   else
      precursor->link = cursor->link;
   delete cursor;
   return true;
}

bool DelNodeBefore1stMatch(Node*& headPtr, int target)
{
   if (headPtr == 0 || headPtr->link == 0 || headPtr->data == target) return false;
   Node *cur = headPtr->link, *pre = headPtr, *prepre = 0;
   while (cur != 0 && cur->data != target)
   {
      prepre = pre;
      pre = cur;
      cur = cur->link;
   }
   if (cur == 0) return false;
   if (cur == headPtr->link)
   {
      headPtr = cur;
      delete pre;
   }
   else
   {
      prepre->link = cur;
      delete pre;
   }
   return true;
}

void ShowAll(ostream& outs, Node* headPtr)
{
   while (headPtr != 0)
   {
      outs << headPtr->data << "  ";
      headPtr = headPtr->link;
   }
   outs << endl;
}

void FindMinMax(Node* headPtr, int& minValue, int& maxValue)
{
   if (headPtr == 0)
   {
      cerr << "FindMinMax() attempted on empty list" << endl;
      cerr << "Minimum and maximum values not set" << endl;
   }
   else
   {
      minValue = maxValue = headPtr->data;
      while (headPtr->link != 0)
      {
         headPtr = headPtr->link;
      if (headPtr->data < minValue)
         minValue = headPtr->data;
      else if (headPtr->data > maxValue)
         maxValue = headPtr->data;
      }
   }
}

double FindAverage(Node* headPtr)
{
   if (headPtr == 0)
   {
      cerr << "FindAverage() attempted on empty list" << endl;
      cerr << "An arbitrary zero value is returned" << endl;
      return 0.0;
   }
   else
   {
      int sum = 0,
      count = 0;

      while (headPtr != 0)
      {
         ++count;
         sum += headPtr->data;
         headPtr = headPtr->link;
      }

      return double(sum) / count;
   }
}

void ListClear(Node*& headPtr, int noMsg)
{
   int count = 0;

   Node *cursor = headPtr;
   while (headPtr != 0)
   {
      headPtr = headPtr->link;
      delete cursor;
      cursor = headPtr;
      ++count;
   }
   if (noMsg) return;
   clog << "Dynamic memory for " << count << " nodes freed"
   << endl;
}

void MakeDistinctMirrorPairs(Node*& headPtr)
{
   Node *outerPtr = headPtr,
         *innerPtr = headPtr,
         *thisPtr = headPtr,
         *mirrorPtr = 0;

   int count = 0;
   int length = 0;
   while (thisPtr != 0)
   {
      length++;
      thisPtr = thisPtr->link;
   }

   if (length == 0)
   {
      return;
   }

   if (length == 1)
   {
      Node *newNodePtr = new Node;
      newNodePtr->data = headPtr->data;
      headPtr->link = newNodePtr;
      return;
   }

   while (outerPtr != 0)
   {
      count = 0;
      while (innerPtr != 0)
      {
         Node *nextInner = innerPtr->link;
         if(nextInner->data == outerPtr->data)
         {
            count++;
            if (count == 1)
            {
               // move to the mirror list
               // if mirrorPtr == 0
                  // mirrorPtr = nextInner;  // first node on mirror list
                  // innerPtr->link = nextInner->link;
               // else
                  Node *tmpPtr = mirrorPtr->link;
                  mirrorPtr->link = nextInner;
                  nextInner->link = tmpPtr;
            }

            if (count > 1)
            {
               // delete
//                  innerPtr->link = mirrorPtr->link;
//                  mirrorPtr = innerPtr;
//                  innerPtr->link = nextInner->link;
            }
         }
         innerPtr = innerPtr->link;
      }

      if (count == 0)
      {
//         Node *tmpPtr = mirrorPtr->link;
//         Node *newNodePtr = new Node;
//         newNodePtr->data = outerPtr->data;
//         mirrorPtr->link = newNodePtr;
//         newNodePtr->link = tmpPtr;
      }
      ShowAll(cout, headPtr);
      outerPtr = outerPtr->link;
      innerPtr = outerPtr;
   }
   return;
}

//void MakeDistinctMirrorPairs(Node*& headPtr)
//{
//   Node *outerPtr = headPtr,
//      *innerPtr = headPtr,
//      *mirrorPtr = headPtr,
//      *thisPtr = headPtr;
//
//   int count = 0;
//   int length = 0;
//   while (thisPtr != 0)
//   {
//      length++;
//      if (thisPtr->link == 0)
//         mirrorPtr = thisPtr;
//      thisPtr = thisPtr->link;
//   }
//
//   if (length == 0)
//   {
//      return;
//   }
//
//   if (length == 1)
//   {
//      Node *newNodePtr = new Node;
//      newNodePtr->data = headPtr->data;
//      headPtr->link = newNodePtr;
//      return;
//   }
//
//   while (outerPtr != mirrorPtr)
//   {
//      count = 0;
//      while (innerPtr != mirrorPtr)
//      {
//         Node *nextInner = innerPtr->link;
//         if(outerPtr->data == nextInner->data)
//         {
//            count++;
//            if (count == 1)
//            {
//               if (nextInner == mirrorPtr)
//               {
//                  mirrorPtr = innerPtr;
//                  break;
//               }
//               else
//               {
//                  innerPtr->link = nextInner->link;
//                  Node *tmpPtr = mirrorPtr->link;
//                  mirrorPtr->link = nextInner;
//                  nextInner->link = tmpPtr;
//               }
//            }
//
//            if (count > 1)
//            {
//               if (nextInner == mirrorPtr)
//               {
//                  innerPtr->link = mirrorPtr->link;
//                  mirrorPtr = innerPtr;
//                  break;
//               }
//               else
//               {
//                  innerPtr->link = nextInner->link;
//               }
//            }
//         }
//         innerPtr = innerPtr->link;
//      }
//
//      if (count == 0)
//      {
//         Node *tmpPtr = mirrorPtr->link;
//         Node *newNodePtr = new Node;
//         newNodePtr->data = outerPtr->data;
//         mirrorPtr->link = newNodePtr;
//         newNodePtr->link = tmpPtr;
//      }
//      ShowAll(cout, headPtr);
//      outerPtr = outerPtr->link;
//      innerPtr = outerPtr;
//   }
//   return;
//}
