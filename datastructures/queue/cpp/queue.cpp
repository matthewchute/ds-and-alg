#include "queue.h"

// Desc: Constructor
queue::queue() : size(0), capacity(STARTING_CAPACITY), front(0), back(0) {
    arr = new int[STARTING_CAPACITY];
}

// Desc: Destructor
queue::~queue() {
    delete[] arr;
}

// Desc: Adds new element at the back 
void queue::enqueue(int x) {

    // If size equals capacity: Double capacity 
    if (size == capacity) {

        // create new array
        int * newArr = new int[capacity*2]; 

        // copy over values to new array
        for (unsigned i = 0; i < size; i++){
            newArr[(front + i) % (capacity*2)] = arr[(front + i) % capacity];
            back = (back + 1) % (capacity*2);
        }

        // delete old arr, assign newArr to arr, and double capacity
        delete[] arr;
        arr = newArr;
        capacity *= 2;

    }

    // add new element, update back index, and increment size
    arr[back] = x;
    back = (back + 1) % capacity;
    size++;

}

// Desc: Removes the frontmost element 
void queue::dequeue() {

    // If size is less than a quarter of capacity and half capacity is greater 
    // than or equal to STARTING_CAPACITY: Half capacity
    if(size < (capacity / 4) && (capacity / 2) >= STARTING_CAPACITY) {

        // create new array
        int * newArr = new int[capacity/2];

        // copy over values to new array
        for (unsigned i = 0; i < size; i++){
            newArr[(front + i) % (capacity/2)] = arr[(front + i) % capacity];
            back = (back + 1) % (capacity/2);
        }

        // delete old arr, assign newArr to arr, and half capacity
        delete[] arr;
        arr = newArr;
        capacity /= 2;
    } 

    // update front index and decrement size
    front = (front + 1) % capacity;
    size--;
}

// Desc: Returns a copy of the frontmost element
int queue::peek() const {
    return !isEmpty() ? arr[front] : -9999; 
}

// Desc: Returns true if queue is empty
bool queue::isEmpty() const {
    return size == 0;
}