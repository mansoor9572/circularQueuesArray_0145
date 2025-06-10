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

        