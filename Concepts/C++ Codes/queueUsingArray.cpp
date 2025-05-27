#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int rear;
    int front;
    int arr[10];

public:
    Queue()
    {
        rear = -1;
        front = -1;

        for (int i = 0; i < 10; i++)
            arr[i] = 0;
    }

    bool isEmpty()
    {
        if (rear == -1 && front == rear)
            return true;
        return false;
    }

    bool isFull()
    {
        if (rear == 9)
            return true;
        return false;
    }

    void enqueue(int val)
    {
        if (isFull())
            cout << "Queue is full";
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        else
            arr[++rear] = val;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return -1;
        }
        int dequeueEle;
        if (rear == front)
        {
            dequeueEle = arr[rear];
            arr[rear] = 0;
            rear = -1;
            front = -1;
        }
        else
        {
            dequeueEle = arr[front];
            arr[front++] = 0;
        }
        return dequeueEle;
    }

    int getSize()
    {
        if (rear == -1)
            return 0;
        return rear - front + 1;
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Queue q;

    int opt;

    do
    {

        cout << "Hello Welcome to Queue Stuff" << endl;
        cout << "1. isEmpty()" << endl;
        cout << "2. isFull()" << endl;
        cout << "3. Enqueque()" << endl;
        cout << "4. Dequeque()" << endl;
        cout << "5. display()" << endl;
        cout << "6. getSize()" << endl;
        cout << "7. Exit" << endl;

        cin >> opt;

        switch (opt)
        {
        case 1:
            if (q.isEmpty())
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {
                cout << "Queue is not Empty" << endl;
            }
            break;
        case 2:
            if (q.isFull())
            {
                cout << "Queue is Full" << endl;
            }
            else
            {
                cout << "Queue has space" << endl;
            }
            break;

        case 3:
            int val;

            if (!q.isFull())
            {
                cout << "Enter the value to enqueue" << endl;
                cin >> val;
                q.enqueue(val);
                cout << "Enqueue success" << endl;
            }
            else
            {
                cout << "The Queue is full" << endl;
            }
            break;

        case 4:
            if (!q.isEmpty())
            {
                int val = q.dequeue();
                cout << "The dequeued val is :" << val << endl;
            }
            else
            {
                cout << "The Queue is Empty" << endl;
            }
            break;

        case 5:
            if (q.isEmpty())
            {
                cout << "The Queue is Empty" << endl;
            }
            else
                q.display();
            break;

        case 6:
            cout << "The size of the Queue: " << q.getSize() << endl;
            break;

        case 7:
            cout << "Good bye!" << endl;
            break;

        default:
            cout << "Enter a Valid Option !" << endl;
            break;
        }

    } while (opt != 7);

    return 0;
}