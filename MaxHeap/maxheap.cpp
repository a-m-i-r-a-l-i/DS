#include<iostream>
using namespace std;

class MaxHeap
{
    private:
        int* heap;
        int capacity;
        int size;

        int parent(int i){return( i/2 );}
        int leftChild(int i){return(i * 2); }
        int rightChild(int i){return (( i * 2 ) + 1 );}

        void swap(int& a ,int& b)
        {
            int temp = a;
            a = b;
            b = temp; 
        }

        void heapifyUp(int index)
        {
            while (index > 1 && heap[index] > heap[parent(index)])
            {
                swap(heap[index] , heap[parent(index)]);
                index = parent(index);
            }
            
        }        
        void heapifyDown(int index)
        {
            int largest = index;
            int left = leftChild(index);
            int right = rightChild(index);

            if(left<=size && heap[left] > heap[largest])
                largest = left;


            if(right<=size &&  heap[right] > heap[largest])
                largest = right;

        
            if(largest != index)
            {
                swap(heap[index],heap[largest]);
                heapifyDown(largest);
            }
          
        }

        void resize()
        {
            capacity*=2;
            int*newHeap =new int[capacity];
                for (int i = 1; i <= size; i++)
                {
                    newHeap[i]=heap[i];
                }
            delete[] heap;
            heap =newHeap;
        }
    public:
        MaxHeap(int initialcapacity = 10)
        {
            capacity = initialcapacity;
            size = 0;
            heap = new int[capacity];
        }
        ~MaxHeap(){ delete[] heap;heap = nullptr;}
        bool isEmpty(){return(size == 0);}

        void insert(int value)
        {
            if (size == capacity -1)
            {
                resize();
            }
            size++;
            heap[size]=value;

            heapifyUp(size);
        }
        void extractMax()
        {
            if (isEmpty())
            {
                cout<<"heap is empty";
                return;
            }
            
           int max =heap[1];
           heap[1] = heap[size];
           
           size--;

           if(size>0)
             heapifyDown(1);
           
             cout<<"successfuly"<<endl;
        }
        void getMax()
        {
            if(isEmpty())
            {
                cout<<"heap is empty"<<endl;
                return;
            }
            cout<<"Max: "<<heap[1]<<endl;
        }
        void display()
        {
            for (int i = 1; i <= size; i++)
            {
                cout<<heap[i]<<" ";
            }
            cout<<endl;
        }

};
int main()
{
    MaxHeap heap;
    int choice, value;
    
    while(true) {
        cout << "========== MaxHeap Menu ==========" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Extract max element" << endl;
        cout << "3. Show max element" << endl;
        cout << "4. Display all elements" << endl;
        cout << "5. Check if heap is empty" << endl;
        cout << "6. Exit" << endl;
        cout << "==================================" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        
        switch(choice) 
        {
            case 1: 
            
                cout << "Enter value to insert: ";
                cin >> value;
                heap.insert(value);
                cout <<" inserted successfully." << endl;
                break;
            
            
            case 2: 
                heap.extractMax();
                break;

            case 3: 
                heap.getMax();
                break;

            case 4: 
                cout << "Heap elements:" << endl;
                heap.display();
                break;
            
            case 5: 
                if(heap.isEmpty()) {
                    cout << "Heap is EMPTY." << endl;
                } else {
                    cout << "Heap is NOT EMPTY." << endl;
                }
                break;

            case 6: 
                cout << "Exiting" << endl;
                return 0;
                break;
            
            default: 
                cout << "Invalid choice" << endl;
                break;
        }
    }
}
