/**
 * LinkedList.cpp
 *
 * Implementations for the "vanilla" LinkedList class, which initializes as an
 * empty list but can be populated with Nodes through the the addition of
 * integer values. Furthermore, the LinkedList class keeps track of traversals
 * of each Node during contains method calls.
 *
 * Joshua Scheck
 * 2020-10-18
 */

#include "LinkedList.h"
#include <iostream>

/**
 * Constructor for this LinkedList class. Initializes an empty LinkedList.
 */
LinkedList::LinkedList() {
  currentSize = 0;
  head = nullptr;
}

/**
 * Destructor for this LinkedList class that destroys this LinkedList
 * and frees memory allocated by the object.
 *
 * Calls LinkedList::clear method.
 *
 * @pre     LinkedList must be initialized
 *
 * @post    this LinkedList is empty with all prior Nodes being deallocated
 *          from memory
 */
LinkedList::~LinkedList() {
   clear(); 
}

/**
 * Retrieves the current number of Nodes in this LinkedList
 *
 * @pre     LinkedList must be initialized, which will also initialize
 *          the retrieved class member currentSize
 *
 * @post    state of this LinkedList does not change
 *
 * @return  the number of Nodes in this LinkedList
 */
int LinkedList::getCurrentSize() const { 
   return currentSize; 
}

/**
 * Determines if the number of Nodes in this list is zero
 *
 * @pre     LinkedList must be initialized, which will also initialize
 *          the retrieved class member head
 *
 * @post    state of this LinkedList does not change
 *
 * @return  true if the number of Nodes in this LinkedList
 *          is zero, false otherwise
 */
bool LinkedList::isEmpty() const {
  // check if there is no reference to a starting Node
  if (head == nullptr) {
    // assume that this LinkedList is empty if no starting Node
    return true;
  }
  
  return false;
}

/**
 * Adds a new Node with the specified value to the beginning of this LinkedList.
 * Duplicate integer values are allowed in this LinkedList.
 *
 * @param   newEntry integer value to be added to the beginning of this
 * LinkedList in the form of a Node
 *
 * @pre              LinkedList must be initialized and a valid integer
 * parameter must be provided
 *
 * @post             if successful, the size of this LinkedList increases by 1,
 * which is reflected in class member currentSize. Additionally, the newly
 *                   created Node is now referenced by class member head and
 * previously held Nodes (if any) are shifted down by 1. No change in class
 * state if unsuccessful.
 *
 * @return           true if a new Node is successfully added to the beginning
 * of this LinkedList, false otherwise
 */
bool LinkedList::add(int newEntry) {
  try {
    Node *newNode = new Node;
    newNode->item = newEntry;
    // place list of Nodes currently in this LinkedList after newly created Node
    newNode->next = head;
    // newly created Node is the new front of this LinkedList
    head = newNode;
    currentSize++;
    return true;
  }
  // inability to allocate memory will throw a std::bad_allac error
  // which will be caught and signals a lack of success
  catch (std::bad_alloc &exc) {
    return false;
  }
}

/**
 * Removes the first occurrence of a Node containing the specified integer
 * from this LinkedList
 *
 * @param   anEntry  the sought integer value held by a Node to be removed
 *                   from this LinkedList
 *
 * @pre              LinkedList must be initialized and a valid integer
 * parameter must be provided
 *
 * @post             if successful, the size of this LinkedList decreases by 1,
 *                   which is reflected in class member currentSize.
 * Additionally, the first occurance of a Node with the specified value is
 *                   deallocated from memory and remaining Nodes held by this
 * LinkedList are shifted accordingly. No change in class state if unsuccessful.
 *
 * @return           true if a Node is found with the specified integer value
 * and is removed from this LinkedList, false otherwise
 */
bool LinkedList::remove(int anEntry) {

  Node *currNode = LinkedList::head;
  Node *prevNode = nullptr;

  while (currNode != nullptr) {
    if (currNode->item == anEntry) {
      Node *nextNode = currNode->next;
      // deallocate memory from removed Node and recalculate size
      // of this LinkedList
      delete currNode;
      currNode = nullptr;
      currentSize--;

      // after memory deallocation, replace currNode address to the
      // address of the next Node in this LinkedList.
      prevNode->next = nextNode;
      return true;
    }

    prevNode = currNode;
    currNode = currNode->next;
  }

  return false;
}

/**
 * Removes all entries from this list by sequentially deallocating memory
 * from each Node existing in this list
 *
 * @pre     LinkedList must be initialized, which will also initialize
 *          manipulated class members head and currentSize
 *
 * @post    this LinkedList will have no Nodes (is empty) and class member
 *          currentCount will be set to 0
 */
void LinkedList::clear() {
  Node *currNode = head;
  Node *nextNode = nullptr;

  // deallocate memory from Nodes in this LinkedList if not empty
  while (currNode != nullptr) {
    // obtains the reference for the next node to avoid dangling pointers
    nextNode = currNode->next;
    // deallocate memory from currentNode in freestore
    delete currNode;
    currNode = nullptr;
    // move to the next Node in this LinkedList
    currNode = nextNode;
  }

  // reset this LinkedList to starting conditions (empty list)
  head = nullptr;
  currentSize = 0;
}

/**
 * Determines if the specified integer value is held by a Node in this
 * LinkedList
 *
 * @param   anEntry  the sought integer value held by a Node to be searched for
 * in this LinkedList
 *
 * @pre              LinkedList must be initialized, which will also initialize
 *                   accessed class members head and traverseCount
 *
 * @post             class member traverseCount is incremented by 1 with each
 * Node traversed in the search for the first occurance of the specified integer
 * value (even if not found). No traversals will occur if this LinkedList is
 * empty.
 *
 * @return           true if the specified integer value is contained in
 *                   at least one Node in this LinkedList, false otherwise
 */
bool LinkedList::contains(int anEntry) {
  Node *currNode = head;

  // look for specified integer in Nodes in this LinkedList
  // if not empty or until the end of the list is reached
  while (currNode != nullptr) {
    // for each operation of looking into a Node, a traversal count
    // is recorded
    traverseCount++;

    if (currNode->item == anEntry) {
      return true;
    }

    currNode = currNode->next;
  }

  // returns false if this LinkedList is empty or if
  // end is reached without finding specified integer value
  return false;
}

/**
 * Retrieves the number of nodes traversed since the last time the count was
 * reset in this LinkedList.
 *
 * @pre     LinkedList must be initialized, which will also initialize
 *          retrieved class member traverseCount
 *
 * @post    state of this LinkedList does not change
 *
 * @return  the number of Nodes traversed
 */
int LinkedList::getTraverseCount() const { return traverseCount; }

/**
 * Resets the count of Nodes traversed in this LinkedList
 *
 * @pre  LinkedList must be initialized, which will also initialize
 *       accessed class member traverseCount
 *
 * @post sets class member traverseCount to traverseCount to 0
 */
void LinkedList::resetTraverseCount() {
  traverseCount = 0;
} // end LinkedList.cpp