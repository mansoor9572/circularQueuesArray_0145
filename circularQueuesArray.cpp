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

    void display()
    {
        // Check if queue is empty
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are:\n";

        // Case 1: FRONT is before REAR (normal order)
        if (FRONT <= REAR)
        {
            for (int i = FRONT; i <= REAR; i++)
                cout << queue_array[i] << " ";
        }
        else
        {
            // Case 2: Circular wrap-around
            for (int i = FRONT; i < max; i++)
                cout << queue_array[i] << " ";
            for (int i = 0; i <= REAR; i++)
                cout << queue_array[i] << " ";
        }
        cout << endl;
    }
};

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
