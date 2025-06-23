



/**
 *
 * @mainpage Documentation circular Queues
 * @section Introduction 
 * this program from strucutre data
 * this project use structer data ques , implement circular  arrays.
 * @section opreations
 * -en qeue for insert  element  into  qeues 
 * -de qeue for delete element form qeue 
 * -show data / display
 * @section how to use 
 * 1. Insert
 * 2. Delete 
 * 3. Display 
 * 4. Exit 
 * @author 
 *  Name : Mohammed Mansoor Mbdullah Abdo
 *  Nim: 20240140145
 *  class: E 
 * 
 * @copyright Gibran@umy.ac.id(c)2025
 *   
 *  @file circularQueuesArray.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */




#include <iostream>
using namespace std;

/**
 * @class Queue
 * @brief A class to implement a circular queue using an array.
 * 
 * This class provides basic queue operations like insert (enqueue), 
 * remove (dequeue), and display for a fixed-size circular queue.
 */
class Queue
{
private:
    /** @brief The maximum capacity of the queue array. */
    static const int max = 5;
    
    /** @brief Index of the front element in the queue. */
    int FRONT;
    
    /** @brief Index of the rear element in the queue. */
    int REAR;
    
    /** @brief The array to store queue elements. */
    int queue_array[max];

public:
    /**
     * @brief Constructs a new Queue object.
     * 
     * Initializes the queue as empty by setting FRONT and REAR to -1.
     */
    Queue()
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief Destroys the Queue object.
     * 
     * This is a simple destructor. No dynamic memory to deallocate.
     */
    ~Queue() {
        // Destructor
    }

    /**
     * @brief Inserts an element into the rear of the queue (enqueue).
     * 
     * Prompts the user to enter a number and adds it to the queue.
     * Handles queue overflow conditions.
     */
    void insert()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        // Check for overflow condition
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }

        // First element insertion
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else if (REAR == max - 1)     // Wrap around
            REAR = 0;
        else
            REAR = REAR + 1;

        queue_array[REAR] = num;      // Insert element at rear
    }

    /**
     * @brief Removes an element from the front of the queue (dequeue).
     * 
     */
    void remove()
    {
        // Check for underflow condition
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }

        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        // Reset queue if it becomes empty
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else if (FRONT == max - 1)    // Wrap around
            FRONT = 0;
        else
            FRONT = FRONT + 1;        // Move front forward
    }

    /**
     * @brief Displays all elements currently in the queue.
     * 
     */
    void display()
    {
        // Check if queue is empty
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are:\n";

        if (FRONT <= REAR)
        {
            for (int i = FRONT; i <= REAR; i++)
                cout << queue_array[i] << " ";
        }
        else
        {
            for (int i = FRONT; i < max; i++)
                cout << queue_array[i] << " ";
            for (int i = 0; i <= REAR; i++)
                cout << queue_array[i] << " ";
        }
        cout << endl;
    }
};
/**
 * @brief The main entry point for the circular queue program.
 * 
 * This function creates an instance of the Queue class and presents a
 * text-based menu to the user. It continuously prompts the user for
 * an action (insert, remove, display, or exit) and calls the
 * 
 * @return int Returns 0 on successful program termination.
 */
int main()
{

    Queue q;
    char ch;

    while (true)
    {
        cout << "\n=====================\n";
        cout << "Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            q.insert();    // Insert element into queue
            break;
        case '2':
            q.remove();    // Remove element from queue
            break;
        case '3':
            q.display();   // Display all elements in queue
            break;
        case '4':
            return 0;      // Exit the program
        default:
            cout << "Invalid option!!\n";
            break;
        }
    }
}