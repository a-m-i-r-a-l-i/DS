#include<iostream>
using namespace std;

class AvlTree
{
private:    
    struct AvlNode
    {
        int data;
        AvlNode* left;
        AvlNode* right;
        int height;
        AvlNode(int value)
            {
                data = value;
                left = right = nullptr;
                height = 1;
            }
    };
    AvlNode* root;
    
    int max(int a,int b) {return( (a > b) ? a : b );}

    int height(AvlNode* node)
    {
        if(node == nullptr) return 0;
        return node->height;
    }

    int getBalance(AvlNode* node)
    {
        if(node == nullptr ) return 0;
        return ( height(node->left) - height(node->right) );
    }
    void updateHeight(AvlNode* node)
    {
        if(node == nullptr) return;
        node->height = 1 + max(height(node->left) , height(node->right));
    }

    AvlNode*rightRotate(AvlNode* y)
    {
        AvlNode* x = y->left;
        AvlNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AvlNode*leftRotate(AvlNode* x)
    {
        AvlNode* y = x->right;
        AvlNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }
    AvlNode*insertHelper(AvlNode* node , int value)
    {
        if(node == nullptr) return (new AvlNode(value));

        if(value < node->data) node->left = insertHelper(node->left, value);

        else if(value> node->data) node->right = insertHelper(node->right , value);

        else return node;

        updateHeight(node);

        int balance = getBalance(node);

        if(balance > 1)
        {
            if(value < node->left->data) return rightRotate(node);

            else 
            {
                node->left = leftRotate(node->left);
                return rightRotate(node); 
            }
        }

        if(balance < -1)
        {
            if( value > node->right->data) return leftRotate(node);
            
            else 
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    bool searchHelper(AvlNode* node , int value)
    {
        if(node == nullptr) return false;
        if(value == node->data) return true;
        else if (value < node->data) return searchHelper(node->left , value);
        else return searchHelper(node->right , value);
    }

    void inorder(AvlNode* node)
    {
        if(node ==nullptr) return;

        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }

    AvlNode* minValueNode(AvlNode* node) 
    {
        AvlNode* current = node;
        while(current->left != nullptr)
            current = current->left;
        return current;
    }

    AvlNode* removeHelper(AvlNode* node ,int value)
    {
        if(node == nullptr)
            return node;
        
        if(value < node->data) 
            node->left = removeHelper(node->left , value );

        else if(value > node->data) 
            node->right = removeHelper(node->right , value);
        else
        {
            if(node->left == nullptr || node->right == nullptr )
            {
            AvlNode* temp = node->left ? node->left : node->right;

            if (temp == nullptr) 
            {
                temp = node;
                node = nullptr;
            } 
            else 
            {
                *node = *temp; 
            }
            
            delete temp;

            }

            else
            {
                AvlNode* temp = minValueNode(node->right);
                node->data =temp->data;
                node->right = removeHelper(node->right , temp->data);
            }
        }
        if(node == nullptr)
            return node;
        
        updateHeight(node);

        int balance = getBalance(node);

        if(balance > 1)
        {
            if(getBalance(node->left) >= 0)
                return rightRotate(node);
            else 
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        else if(balance < -1)
        {
            if(getBalance(node->right) <= 0)
            {
                return leftRotate(node);
            }
            else
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }
public:
    AvlTree()
    {
        root = nullptr;
    }


    void insert(int value)
    {
        root = insertHelper(root ,value);
    }


    void remove(int value)  
    {
        if(!search(value)) 
        {
            cout << value << " not found!" << endl;
            return;
        }
        root = removeHelper(root, value);
        cout << value << " removed." << endl;
    }    


    bool search(int value)
    { 
        return(searchHelper(root,value));
    }


    void display()
    {
        cout<<"AVL Tree:";
        inorder(root);cout<<endl;
    }
};
