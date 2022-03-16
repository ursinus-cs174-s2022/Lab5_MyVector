/**
 * This is a vanilla implementation of C++'s STL vector class, which
 * provides a flexible array-like container with constant random access,
 * but which resizes adaptively to accommodate new elements
 * @author You!
 * @param <Item> The type that this container will hold 
 */
#include "myvector.h"
#include <string>
#include <sstream>
#include <exception>
using namespace std;


/**
 * Initialize an ArrayList object with a particular 
 * starting capacity
 * @param startSize Initial capacity of the array
 */
template <typename Item>
myvector<Item>::myvector(int startSize) {
    items = new Item[startSize];
    N = 0;
    capacity = startSize;
}
/**
 * Initialize an ArrayList object with the underlying array
 * having the default capacity
 */
template <typename Item> 
myvector<Item>::myvector() {
    items = new Item[DEFAULT_CAPACITY];
    N = 0;
    capacity = DEFAULT_CAPACITY;
}

/**
 * Clean up the underlying array
 */
template <typename Item> 
myvector<Item>::~myvector() {
    delete[] items;
}

/**
 * Double the capacity of the underlying array by creating
 * a new underlying array and copying everything over that 
 * was there before up to N
 */
template <typename Item> 
void myvector<Item>::doubleCapacity() {
    // TODO: Fill this in
}

/**
 * Halve the capacity of the array that holds the elements
 * @throws bad_alloc if half of the current size wouldn't be
 *         enough to hold the elements that are there
 */
template <typename Item> 
void myvector<Item>::halveCapacity() {
    int newSize = capacity/3;
    if (newSize < N) {
        __throw_bad_alloc();
    }
    Item* newItems = new Item[newSize];
    for (int i = 0; i < N; i++) {
        newItems[i] = items[i];
    }
    delete[] items;
    items = newItems;
    capacity = newSize;
}

/**
 * Copy out the elements into a fixed array
 * @return An array holding the elements currently
 *         in this arraylist
 */
template <typename Item> 
Item* myvector<Item>::toArray() {
    Item* ret = new Item[N];
    for (int i = 0; i < N; i++) {
        ret[i] = items[i];
    }
    return ret;
}

/**
 * Put an item at a particular index
 * @param index Index to which to add element
 * @param item Item to add
 * @throws runtime_error for out of bounds
 */
template <typename Item> 
void myvector<Item>::set(int index, Item item) {
    if (index < 0 || index >= N) {
        __throw_runtime_error("Out of bounds error in set");
    }
    items[index] = item;
}

/**
 * Add an item to the end of the list and update its size
 * TODO: Update this so that if there isn't enough space
 * in the underlying array, that it doubles the capacity of 
 * the array first (hint: use your doubleCapacity() method to do this)
 * @param item Item to add
 */
template <typename Item> 
void myvector<Item>::add(Item item) {
    // TODO: Update this so that it doubles the capacity of the
    // underlying array if it's run out of space, so that there
    // is always enough room to add an element
    if (N < capacity) {
        items[N] = item;
        N++;
    }
    else {
        __throw_runtime_error("Ran out of space!");
    }
}

/**
 * Add an item to the middle of the list at a specified index, and
 * move everything to the right of it over by one index.  Be sure
 * to double the capacity if needed
 * @param index The index at which to insert the element
 * @param item The element to insert
 */
template <typename Item> 
void myvector<Item>::add(int index, Item item) {
    if (index < 0 || index > N) {
        __throw_runtime_error("Out of bounds error in add");
    }
    // TODO: Fill this in
}

/**
 * Return the element at a particular index
 * 
 * @param index Index of element
 * @return 
 */
template <typename Item> 
Item myvector<Item>::at(int index) {
    if (index < 0 || index >= N) {
        __throw_runtime_error("Out of bounds error in at");
    }
    return items[index];
}

/**
 * Return the index of the first occurrence of a particular
 * item, or -1 if the item does not exist in the list
 * @param item Item we're searching for
 * @return Index of the first occurrence of the item, or -1 if
 *         it's not in the list
 */
template <typename Item> 
int myvector<Item>::indexOf(Item item) {
    int index = -1;
    bool found = false;
    for (int i = 0; i < N && !found; i++) {
        if (items[i] == item) {
            index = i;
            found = true;
        }
    }
    return index;
}


/**
 * Remove an item at a particular index and return it.
 * You should also move everything to the right of this
 * index over one to the left and update the size N.
 * Finally, if the new number of elements being stored is 
 * small enough, you should halve the capacity
 * @param index The index at which to obtain and remove the item
 * @return The item that was removed
 */
template <typename Item> 
Item myvector<Item>::remove(int index) {
    Item ret;
    // TODO: Fill this in
    return ret;
}

/**
 * Remove the first occurrence of a particular item
 * from the list if it is present and return it
 * (HINT: Make use of the indexOf method and the overloaded version of
 *        remove above that takes an index so you don't have to 
 *        rewrite so much code)
 * @param item The item to remove
 * @return The item if it was found, or null if it was not found
 *         in the list
 */
template <typename Item> 
Item myvector<Item>::removeItem(Item item) {
    Item ret;
    // TODO: Fill this in
    return ret;
}

template <typename Item> 
string myvector<Item>::toString() {
    stringstream ret;
    ret << "[";
    for (int i = 0; i < N; i++) {
        ret << items[i];
        if (i < N-1) {
            ret << ", ";
        }
    }
    ret << "]";
    return ret.str();
}
