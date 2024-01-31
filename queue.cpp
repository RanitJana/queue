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

template <typename t = int>
class QueueLinkedList
{
    struct Node
    {
        t data;
        Node *next;
        Node(t val) : data(val), next(NULL) {}
    } *tail;

public:
    QueueLinkedList()
    {
        tail = nullptr;
    }
    void enqueue(t value)
    {
        Node *newNode = new Node(value);
        if (!tail)
            tail = newNode;
        else
            newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    t dequeue()
    {
        if (tail == NULL)
        {
            cout << "Empty.\n";
            exit(0);
        }
        Node *temp = tail->next;
        if (temp == tail)
            tail = NULL;
        else
            tail->next = temp->next;
        temp->next = NULL;
        t data = temp->data;
        delete temp;
        return data;
    }
    int size()
    {
        int ans = 0;
        if (tail == NULL)
            return 0;
        Node *temp = tail;
        do
        {
            ans++;
            temp = temp->next;
        } while (temp != tail);

        return ans;
    }
    void display()
    {
        if (tail == NULL)
        {
            cout << "Empty.\n";
            return;
        }
        Node *temp = tail->next;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;

        } while (temp != tail->next);

        cout << endl;
    }
};

int main()
{
    QueueLinkedList<int> q;
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