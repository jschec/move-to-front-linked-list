/**
 * MTFList.h
 *
 * Declarations for the "move-to-front" linked list variant, MTFList, which is a
 * subclass of LinkedList. MTFList initializes as an empty list just like
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

#pragma once
#include "LinkedList.h"

/**
 * Represents a move-to-front singly Linked List that stores integer values as
 * Nodes and is the subclass of LinkedList
 */
class MTFList : public LinkedList {
public:
  /**
   * Overrides LinkedList::contains(int anEntry) method. Similarly determines if
   * the specified integer value is held by a Node in this MTFList, but then
   * moves the found Node to the front of this MTFList
   *
   * @param   anEntry  the sought integer value held by a Node to be searched
   * for in this MTFList
   *
   * @pre              MTFList must be initialized, which will also initialize
   *                   accessed class members head and traverseCount
   *
   * @post             class member traverseCount is incremented by 1 with each
   * Node traversed in the search for the first occurance of the specified
   * integer value (even if not found). If the value is found in a Node, that
   * Node is then moved up to the front of this MTFList. No traversals will
   * occur if this MTFList is empty.
   *
   * @return           true if the specified integer value is contained in
   *                   at least one Node in this MTFList, false otherwise
   */
  bool contains(int anEntry) override;
}; // end MTFList.h