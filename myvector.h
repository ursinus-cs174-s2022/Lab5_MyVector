/**
 * This is a vanilla implementation of C++'s STL vector class, which
 * provides a flexible array-like container with constant random access,
 * but which resizes adaptively to accommodate new elements
 * @author You!
 * @param <Item> The type that this container will hold 
 */
#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <string>
using namespace std;



const int DEFAULT_CAPACITY = 10;

template <typename Item> 
class myvector {
    private:
        Item* items; // Underlying array that holds everything
        int N; // size of the vector
        int capacity; // Capacity of the underlying array
        void halveCapacity();
        void doubleCapacity();
    
    public:
        /**
         * Initialize an ArrayList object with a particular 
         * starting capacity
         * @param startSize Initial capacity of the array
         */
        myvector(int startSize);
        /**
         * Initialize an ArrayList object with the underlying array
         * having the default capacity
         */
        myvector();

        /**
         * Clean up the underlying array
         */
        ~myvector();
        
        /**
         * Copy out the elements into a fixed array
         * @return An array holding the elements currently
         *         in this arraylist
         */
        Item* toArray();
        
        /**
         * Clear all of the elements from the arraylist.
         * It's as simple as setting N to be 0!
         */
        void clear() {
            N = 0;
        }
        
        /**
         * Return how many elements are stored in the arraylist
         * @return N
         */
        int size() {
            return N;
        }
        
        /**
         * Put an item at a particular index
         * @param index Index to which to add element
         * @param item Item to add
         * @throws IndexOutOfBoundsException
         */
        void set(int index, Item item);
        
        /**
         * Add an item to the end of the list and update its size
         * @param item Item to add
         */
        void push_back(Item item);
        
        /**
         * Add an item to the middle of the list at a specified index, and
         * move everything to the right of it over by one index.  Be sure
         * to double the capacity if needed
         * @param index The index at which to insert the element
         * @param item The element to insert
         */
        void insert(int index, Item item);
        
        /**
         * Return the element at a particular index
         * 
         * @param index Index of element
         * @return 
         */
        Item at(int index);
        
        /**
         * Return the index of the first occurrence of a particular
         * item, or -1 if the item does not exist in the list
         * @param item Item we're searching for
         * @return Index of the first occurrence of the item, or -1 if
         *         it's not in the list
         */
        int indexOf(Item item);
        
        
        /**
         * Remove an item at a particular index and return it.
         * You should also move everything to the right of this
         * index over one to the left and update the size N.
         * Finally, if the new number of elements being stored is 
         * small enough, you should halve the capacity
         * @param index The index at which to obtain and remove the item
         * @return The item that was removed
         */
        Item remove(int index);
        
        /**
         * Remove the first occurrence of a particular item
         * from the list if it is present and return it
         * @param item The item to remove
         * @return The item if it was found, or null if it was not found
         *         in the list
         */
        Item removeItem(Item item);
        
        string toString();
};


#endif