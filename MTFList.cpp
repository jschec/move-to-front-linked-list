/**
 * MTFList.cpp
 *
 * Implementations for the "move-to-front" linked list variant, MTFList, which
 * is a subclass of LinkedList. MTFList initializes as an empty list just like
 * LinkedList and inherits all of the attributes and methods. However, MTFList
 * overrides the LinkedList:contains(int anEntry) method that leverages the
 * "move-to-front" strategy. Specifically, Nodes with the sought integer values
 * are moved to the front of the initialized MTFList which can introduce
 * efficiency with iterative searching through normally distributed values.
 *
 * Joshua Scheck
 * 2020-10-18
 *
 */

#include "MTFList.h"

/**
 * Overrides LinkedList::contains(int anEntry) method. Similarly determines if
 * the specified integer value is held by a Node in this MTFList, but then moves
 * the found Node to the front of this MTFList
 *
 * @param   anEntry  the sought integer value held by a Node to be searched for
 *                   in this MTFList
 *
 * @pre              MTFList must be initialized, which will also initialize
 *                   accessed class members head and traverseCount
 *
 * @post             class member traverseCount is incremented by 1 with each
 * Node traversed in the search for the first occurance of the specified integer
 * value (even if not found). If the value is found in a Node, that Node is then
 *                   moved up to the front of this MTFList. No traversals will
 * occur if this MTFList is empty.
 *
 * @return           true if the specified integer value is contained in
 *                   at least one Node in this MTFList, false otherwise
 */
bool MTFList::contains(int anEntry) {

  Node *currNode = head;
  Node *prevNode = nullptr;

  // look for specified integer in Nodes in this MTFList
  // if not empty or until the end of the list is reached
  while (currNode != nullptr) {

    // for each operation of looking into a Node, a traversal count
    // is recorded
    traverseCount++;

    if (currNode->item == anEntry) {

      // only make structural modifications to MTFList if the found
      // Node is not at the front of this MTFList
      if (prevNode != nullptr) {
        // have previous Node hold reference to the next Node after
        // current Node in order to splice out currNode
        prevNode->next = currNode->next;

        // found Node is the new front of this MTFList
        currNode->next = head;
        head = currNode;
      }

      return true;
    }

    prevNode = currNode;
    currNode = currNode->next;
  }

  return false;
} // end MTFList.cpp