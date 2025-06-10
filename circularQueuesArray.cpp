#include <iostream>
using namespace std;

class Queue
{
private:
    static const int max = 5;         // Maximum size of the queue
    int FRONT, REAR;                  // Pointers to front and rear
    int queue_array[max];             // Array to store queue elements

public:
    Queue()
    {
        FRONT = -1;
        REAR = -1;
    }

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

   