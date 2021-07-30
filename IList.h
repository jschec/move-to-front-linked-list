//  Modified from code created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#pragma once

class IList
{
public:
   /** Constructor */
   IList () : traverseCount(0) { }
    
   /** Destroys object and frees memory allocated by object.
    (See C++ Interlude 2) */
   virtual ~IList () { }

   /** Gets the current number of entries in this list.
    @return The integer number of entries currently in the list. */
   virtual int getCurrentSize() const = 0;
   
   /** Sees whether this list is empty.
    @return True if the list is empty, or false if not. */
   virtual bool isEmpty() const = 0;
   
   /** Adds a new entry to this list.
    @post  If successful, newEntry is stored in the list and
       the count of items in the list has increased by 1.
    @param newEntry  The object to be added as a new entry.
    @return  True if addition was successful, or false if not. */
   virtual bool add(int newEntry) = 0;
   
   /** Removes one occurrence of a given entry from this list,
       if possible.
    @post  If successful, anEntry has been removed from th   e list
       and the count of items in the list has decreased by 1.
    @param anEntry  The entry to be removed.
    @return  True if removal was successful, or false if not. */
   virtual bool remove(int anEntry) = 0;
   
   /** Removes all entries from this list.
    @post  List contains no items, and the count of items is 0. */
   virtual void clear() = 0;
   
   /** Tests whether this list contains a given entry.
    @param anEntry  The entry to locate.
    @return  True if list contains anEntry, or false otherwise. */
   virtual bool contains(int anEntry) = 0;
    
   /** Get the count of number of nodes traversed.
    @return  The integer number of nodes traversed since last time the count was reset. */
    virtual int getTraverseCount() const { return traverseCount; }
     
   /** Reset the count of nodes traversed to zero. */
    virtual void resetTraverseCount() { traverseCount = 0; }
    
protected:
    int traverseCount;
}; // end IList

