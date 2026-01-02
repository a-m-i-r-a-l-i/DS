#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};
class Queue
{
    private:
        Node* Front;
        Node* rear;
    public:

    Queue(){rear = NULL ; Front =NULL;}

    void enqueue(int value)
    {    
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        
        if (isEmpty())
        {
            Front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        Node*temp = Front;
        Front = Front->next;
        delete temp;
        if (Front == NULL)
        {
            rear =NULL;
        }
        
        cout<<"dequeue successfully"<<endl;
    }

    bool isEmpty()
    {
        return(Front==NULL);
    }

    void getFront()
    {
         if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Front: "<<Front->data<<endl;
    }


    void display()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
            Node* current = Front;
            cout<<"front to rear"<<endl;
                while (current !=NULL)
                    {
                        cout<<current->data<<" ";
                        current = current->next;
                    }
            
            cout << endl;
    }


};
int main()
{
  Queue q;
    int choice, value;
    
    while(true)
    {
        cout << "\n========== Queue Menu ==========" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Get Front" << endl;
        cout << "4. Check if empty" << endl;
        cout << "5. Display queue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                cout << "Enqueued successfully." << endl;
                break;
                
            case 2:
                q.dequeue();
                break;
                
            case 3:
                q.getFront();
                break;
                
            case 4:
                if(q.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
                break;
                
            case 5:
                q.display();
                break;
                
            case 6:
                cout << "Exiting " << endl;
                return 0;
                break;
                
            default:
                cout << "Invalid choice" << endl;
        }
    }
    
}
