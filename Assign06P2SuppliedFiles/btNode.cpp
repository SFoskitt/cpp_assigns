#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

bool bst_insert(btNode* bst_root, int insVal)
{
  while(bst_root->left && bst_root->right)
  {
    //if(bst_node-> data > bst_root->data)
      if(insVal > bst_root->data)
      {
         if(bst_root->right != 0)
         {
            // go to the right
            bst_root = bst_root->right;
         }
         else
         {
            btNode* tmp = 0;
            tmp->data = insVal;
            bst_root->right = tmp;
            return true;
         }
      }

      if(insVal < bst_root->data)
      {
         if(bst_root->left != 0)
         {
            bst_root = bst_root->left;
         }
         else
         {
            btNode* tmp = 0;
            tmp->data = insVal;
            bst_root->left = tmp;
            return true;
         }
      }
  }
  return false;  // node could not be added to tree (maybe a duplicate value?)
}

bool bst_remove(btNode* bst_root, int anInt)
{
  // FIRST FIND THE THING! Use the while loop above to find the correct node to remove
  // case 1
    //
  // case 2
    //
  return false; // thing is not found
}

bool bst_remove_max(btNode* bst_root)
{
  return true;
}
