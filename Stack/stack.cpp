#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
    private:
        Node *top;
    public:
    Stack()
    {
        top = NULL ;
    }


    void push(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;    
    }


    void pop()
    {
        if (isEmpty())
        {
            cout<<"stack is empty.";
            return;
        }
        Node*temp = top;
        top = top->next;
        delete temp;
        cout << "Element popped successfully." << endl;
    }


    bool isEmpty()
    {
        return(top == NULL);
    }


    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty No top element." << endl;
            return;
        }
        cout<<"top element:"<<top->data;
    }


    void display()
    {
        if (isEmpty())
        {
            cout<<"stack is empty"<<endl;
            return;
        }
        Node*display = top;
        cout<<"top to bottom"<<endl;
        while (display != NULL)
        {
            cout<< display->data <<" ";
            display = display->next;
        }
        cout<<endl;
    }
    ~Stack() 
    {
    while(!isEmpty()) {
        pop();
    }
}

};

int main()
{
    Stack stack;
    int a;
    while (true)
    {
        
    
    
    cout<<"========stack======="<<endl;
    cout<<"1-posh"<<endl;
    cout<<"2-pop"<<endl;
    cout<<"3-isEmpty"<<endl;
    cout<<"4-peek"<<endl;
    cout<<"5-display"<<endl;
    cout<<"6-Exit"<<endl;
    cout<<"choise:"<<endl;
    cin>>a;
     switch(a)
        {
            case 1:
                cout<<"Enter the num"<<endl;
                int b; 
                cin>>b;
                stack.push(b);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                cout << "Stack is " << (stack.isEmpty() ? "empty" : "not empty") << endl;
                break;

            case 4:
                stack.peek();
                break;

            case 5:
                stack.display();
                break;

            case 6:
                cout<<"Exiting";
                return 0 ;
                break;

            default:
                cout<<"Invalid choice;"<<endl;
                break;
        }
  }
}
