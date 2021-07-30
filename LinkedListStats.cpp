// Test program to evaluate linked list performance
// Written 10/4/19 by Michael Stiber
//

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <cassert>

#include "LinkedList.h"
#include "MTFList.h"

using namespace std;

/**
 * Tests LinkedList constructor
 */ 
void testLinkedListConstructor() {
   LinkedList testList;
   assert(testList.getCurrentSize() == 0);
   assert(testList.getTraverseCount() == 0);
   assert(testList.isEmpty() == true);
}

/**
 * Tests add, getCurrentSize and isEmpty methods of LinkedList class
 */ 
void testAddNode() {
   LinkedList testList;
   testList.add(10);
   assert(testList.getCurrentSize() == 1);
   assert(testList.isEmpty() == false);

   testList.add(42);
   assert(testList.getCurrentSize() == 2);
   assert(testList.isEmpty() == false);
}

/**
 * Tests remove method for LinkedList class
 */ 
void testRemoveNode() {
   LinkedList testList;
   testList.add(33);
   testList.add(1);
   testList.add(29);

   // try to remove a Node that doesn't exit
   bool removeResult = testList.remove(99);
   assert(removeResult == false);
   // make sure that failed removal does not change internal counter for size
   assert(testList.getCurrentSize() == 3);

   // remove a Node that does exist in LinkedList
   bool removeResultTwo = testList.remove(33);
   assert(removeResultTwo == true);
   assert(testList.getCurrentSize() == 2);
}

/**
 * Tests clear method of LinkedList class
 */ 
void testClearNodes() {
   LinkedList testList;

   // makes sure that clear works with empty list
   testList.clear();
   assert(testList.getCurrentSize() == 0);

   testList.add(43);
   testList.add(9);
   testList.add(99);

   // make sure that clear works with populated list
   assert(testList.getCurrentSize() == 3);
   testList.clear();
   assert(testList.getCurrentSize() == 0);
   assert(testList.isEmpty() == true);
}

/**
 * Tests contains, getTraverseCount, and resetTraverseCount methods of
 * LinkedList class
 */ 
void testContainsAndTraverseCount() {
   LinkedList testList;
   testList.add(101);
   testList.add(22);
   testList.add(83);

   // tests if contains method goes fully to the end of the list
   testList.contains(33);
   assert(testList.getTraverseCount() == 3);

   // make sure reset method does set traverseCount to 0
   testList.resetTraverseCount();
   assert(testList.getTraverseCount() == 0);

   // tests if contains method reaches the expected position in this
   // list
   testList.contains(22);
   assert(testList.getTraverseCount() == 2);
}

/**
 * Tests overriden contains method of MTFList class
 */ 
void testModifiedContainsAndTraverseCount() {
   MTFList testList;
   testList.add(101);
   testList.add(22);
   testList.add(83);

   // tests if contains method goes fully to the end of the list
   testList.contains(33);
   assert(testList.getTraverseCount() == 3);
   testList.resetTraverseCount();
   assert(testList.getTraverseCount() == 0);

   // tests if move-to-front works
   testList.contains(22);
   assert(testList.getTraverseCount() == 2);
   testList.resetTraverseCount();
   assert(testList.getTraverseCount() == 0);
   testList.contains(22);
   assert(testList.getTraverseCount() == 1);
}

/**
 * A single method with all of the tests used to assess structure
 * and feature requirements of LinkedList and MTFList classes
 */ 
void runAllTests() {
   testLinkedListConstructor();
   testAddNode();
   testRemoveNode();
   testClearNodes();
   testContainsAndTraverseCount();
   testModifiedContainsAndTraverseCount();
}

int main()
{
   // Uncomment next line to run unit and integration tests
   //runAllTests();

   // Alter the following declaration to change the linked list class
   // name.
   LinkedList theList;
   MTFList theOtherList;

   const int numValues = 1000;
   const int numAccesses = 100000;

   // Create a linked list of the numbers 0..numValues-1
   for (int i = numValues - 1; i >= 0; i--)
   {
      theList.add(i);
      theOtherList.add(i);
   }

   // Reset the traversal counter, just in case
   theList.resetTraverseCount();
   theOtherList.resetTraverseCount();

   // Now, access the elements randomly many times
   int theNumber;
   default_random_engine generator;
   uniform_int_distribution<int> uniform(0, numValues - 1);
   normal_distribution<double> normal(numValues / 2.0, numValues / 5.0);

   // As the statistic of comparison, we use a uniform
   // distribution. For sequential search, even a "smart" algorithm
   // shouldn't be able to improve performance.
   for (int i = 0; i < numAccesses; i++)
   {
      // Access a random item by value
      theNumber = uniform(generator);
      assert(theList.contains(theNumber));
      assert(theOtherList.contains(theNumber));
   }

   cout << "LinkedList - Average number of nodes traversed per access (uniform): "
        << theList.getTraverseCount() / double(numAccesses)
        << endl;

   cout << "MTFList - Average number of nodes traversed per access (uniform): "
        << theOtherList.getTraverseCount() / double(numAccesses)
        << endl;

   // Reset the traversal counter.
   theList.resetTraverseCount();
   theOtherList.resetTraverseCount();

   // We use a normal distribution so that some values are accessed
   // much more frequently. It will be peaked around numValues/2 and fall off
   // rapidly above and below. Note that there is some chance of
   // generating a number outside the legal range, so we test and get a
   // new number if that happens (this is because a uniform
   // distribution goes to +/- infinity). A smart algorithm could in
   // principle take advantage of the higher frequency of access of
   // certain items to lower the average access time. On the other hand,
   // without any "smarts", the mean number of nodes traversed should still
   // be the mean of the distribution, the same as for the uniform distribution.
   for (int i = 0; i < numAccesses; i++)
   {
      theNumber = 0;
      do
      {
         theNumber = int(normal(generator));
      } while ((theNumber < 0) || (theNumber >= numValues));

      assert(theList.contains(theNumber));
      assert(theOtherList.contains(theNumber));
   }

   cout << "LinkedList - Average number of nodes traversed per access (normal): "
        << theList.getTraverseCount() / double(numAccesses)
        << endl;

   cout << "MTFList - Average number of nodes traversed per access (normal): "
        << theOtherList.getTraverseCount() / double(numAccesses)
        << endl;

} // end LinkedListStats