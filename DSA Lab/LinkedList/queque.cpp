#include <iostream>
using namespace std;

class CircleQueue {
private:
    int frontPos, rearPos, currSize;
    int* queueData;
    int maxSize;

public:
    // Constructor to initialize the queue
    CircleQueue(int capacity) {
        maxSize = capacity;
        queueData = new int[capacity];
        frontPos = 0;
        rearPos = -1;
        currSize = 0;
    }

    // Destructor to free the allocated memory
    ~CircleQueue() {
        delete[] queueData;
    }

    // Check if the queue is full
    bool isQueueFull() const {
        return currSize == maxSize;
    }

    // Check if the queue is empty
    bool isQueueEmpty() const {
        return currSize == 0;
    }

    // Enqueue operation (adding an element to the rear)
    void addToRear(int element) {
        if (isQueueFull()) {
            cout << "Queue is full." << endl;
            return;
        }
        rearPos = (rearPos + 1) % maxSize;
        queueData[rearPos] = element;
        currSize++;
        cout << element << " added to the queue." << endl;
    }

    // Dequeue operation (removing an element from the front)
    int removeFromFront() {
        if (isQueueEmpty()) {
            cout << "Queue is empty. Cannot remove." << endl;
            return -1;
        }
        int removedValue = queueData[frontPos];
        frontPos = (frontPos + 1) % maxSize;
        currSize--;
        cout << removedValue << " removed from the queue." << endl;
        return removedValue;
    }

    // Get the front element of the queue
    int peekFront() const {
        if (isQueueEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return queueData[frontPos];
    }

    // Get the rear element of the queue
    int peekRear() const {
        if (isQueueEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return queueData[rearPos];
    }

    // Display the queue elements
    void showQueue() const {
        if (isQueueEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < currSize; i++) {
            cout << queueData[(frontPos + i) % maxSize] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircleQueue queue(7); // Initialize a queue with capacity 7
    queue.addToRear(1);
    queue.addToRear(2);
    queue.addToRear(3);
    queue.addToRear(4);
    queue.addToRear(5);
    queue.addToRear(6);
    queue.addToRear(7);
    
    queue.showQueue(); // Output the current queue
    
    queue.removeFromFront();
    queue.removeFromFront();
    
    queue.showQueue(); // Output the queue after removing elements
    
    cout << "Front element: " << queue.peekFront() << endl;
    cout << "Rear element: " << queue.peekRear() << endl;
    
    return 0;
}
