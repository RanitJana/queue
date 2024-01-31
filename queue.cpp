#include <bits/stdc++.h>
using namespace std;

// queue using array
template <class t = int>
class QueueArray
{
    t *a;
    int capacity;
    int front, rear;

public:
    QueueArray(int n)
    {
        capacity = n;
        a = new t[n];
        front = rear = -1;
    }
    void enqueue(t value)
    {
        if (rear == capacity - 1)
        {
            cout << "Queue is full.\n";
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        a[++rear] = value;
    }
    t dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Empty.\n";
            exit(0);
        }
        return a[front++];
    }

    int size()
    {
        return front == -1 || front > rear ? 0 : rear - front + 1;
    }
    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Empty.\n";
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    QueueArray<int> q(4);
    while (1)
    {
        int value;
        cin >> value;
        if (value == 1)
        {
            cout << "Enter data";
            int data;
            cin >> data;
            q.enqueue(data);
        }
        else
        {
            cout << q.dequeue() << endl;
        }
        q.display();
    }
    return 0;
}