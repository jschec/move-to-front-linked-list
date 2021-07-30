/**
 * LinkedList.h
 *
 * Declarations for the "vanilla" LinkedList class, which initializes as an
 * empty list but can be populated with Nodes through the the addition of
 * integer values. Furthermore, the LinkedList class keeps track of traversals
 * of each Node during contains method calls.
 *
 * Joshua Scheck
 * 2020-10-18
 */

#pragma once
#include "IList.h"

/**
 * This struct represents a single node that composes a list ADT
 */
struct Node {
  /** Integer value held by this Node */
  int item;
  /** Reference to the address of the next Node in this LinkedList, otherwise
   * nullptr */
  struct Node *next;
};

/**
 * Represents a vanilla singly Linked List that stores integer values as Nodes
 * and is the subclass of IList
 */
class LinkedList : public IList {
public:
  /**
   * Constructor for this LinkedList class. Initializes an empty LinkedList.
   */
  LinkedList();

  /**
   * Destructor for this LinkedList class that destroys this LinkedList
   * and frees memory allocated by the object.
   *
   * Calls LinkedList::clear() method.
   *
   * @pre     LinkedList must be initialized
   *
   * @post    this LinkedList is empty with all prior Nodes being deallocated
   *          from memory
   */
  ~LinkedList() override;

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
  int getCurrentSize() const override;

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
  bool isEmpty() const override;

  /**
   * Adds a new Node with the specified value to the beginning of this
   * LinkedList. Duplicate integer values are allowed in this LinkedList.
   *
   * @param   newEntry integer value to be added to the beginning of this
   * LinkedList in the form of a Node
   *
   * @pre              LinkedList must be initialized and a valid integer
   * parameter must be provided
   *
   * @post             if successful, the size of this LinkedList increases by
   * 1, which is reflected in class member currentSize. Additionally, the newly
   *                   created Node is now referenced by class member head and
   * previously held Nodes (if any) are shifted down by 1. No change in class
   * state if unsuccessful.
   *
   * @return           true if a new Node is successfully added to the beginning
   * of this LinkedList, false otherwise
   */
  bool add(int newEntry) override;

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
   * @post             if successful, the size of this LinkedList decreases by
   * 1, which is reflected in class member currentSize. Additionally, the first
   * occurance of a Node with the specified value is deallocated from memory and
   * remaining Nodes held by this LinkedList are shifted accordingly. No change
   * in class state if unsuccessful.
   *
   * @return           true if a Node is found with the specified integer value
   * and is removed from this LinkedList, false otherwise
   */
  bool remove(int anEntry) override;

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
  void clear() override;

  /**
   * Determines if the specified integer value is held by a Node in this
   * LinkedList
   *
   * @param   anEntry  the sought integer value held by a Node to be searched
   * for in this LinkedList
   *
   * @pre              LinkedList must be initialized, which will also
   * initialize accessed class members head and traverseCount
   *
   * @post             class member traverseCount is incremented by 1 with each
   * Node traversed in the search for the first occurance of the specified
   *                   integer value (even if not found). No traversals will
   * occur if this LinkedList is empty.
   *
   * @return           true if the specified integer value is contained in
   *                   at least one Node in this LinkedList, false otherwise
   */
  bool contains(int anEntry) override;

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
  int getTraverseCount() const override;

  /**
   * Resets the count of Nodes traversed in this LinkedList
   *
   * @pre  LinkedList must be initialized, which will also initialize
   *       accessed class member traverseCount
   *
   * @post sets class member traverseCount to traverseCount to 0
   */
  void resetTraverseCount() override;

protected:
  /** The current number of Nodes in this LinkedList. */
  int currentSize;
  /** Reference to the address of the first Node in this LinkedList, otherwise
   * nullptr. */
  Node *head;
}; // end LinkedList.h