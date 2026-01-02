#include<iostream>
#include<string>
using namespace std;

const int ALPHABET = 26;
 
class Tria
{
private:
    struct triaNode
    {
        triaNode*children[ALPHABET];
        bool isword;

        triaNode()
        {
            isword = false;
            for(int i = 0;i < ALPHABET; i++)
            {
                children[i] = nullptr;
            }
        }
    };
    triaNode* root;
    int charToIndex(char c){return(c - 'a');}
    
   bool isEmptyNode(triaNode* node) 
    {
    if(node->isword) return false; 
    
    for(int i = 0; i < ALPHABET; i++) 
    {
        if(node->children[i] != nullptr) 
        {
            return false;  
        }
    }
    
    return true; 
    }

    bool deleteHelper(triaNode* current, string word, int depth) 
    {
        if(current == nullptr) return false;
        
        if(depth == word.length()) 
        {
            if(!current->isword) return false;
            
            current->isword = false;
            
            return isEmptyNode(current);
        }
        
        int index = charToIndex(word[depth]);
        bool deleteChild = deleteHelper(current->children[index], word, depth + 1);
        
        if(deleteChild) 
        {
            delete current->children[index];
            current->children[index] = nullptr;
            
            return isEmptyNode(current);
        }
        
        return false;
   }
public:
    Tria(){root = new triaNode();}

    void insert(string word)
    {
        triaNode* current = root;

        for(char c : word)
        {
            int index = charToIndex(c);
            if(current->children[index] == nullptr)
            {
                current->children[index] = new triaNode();
            }
            current = current->children[index];
        }
        current->isword = true;
    }
    bool search(string word)
    {
        triaNode* current = root;
        
        for(char c : word)
        {
            int index = charToIndex(c);
            if (current->children[index] == nullptr)
                return false;

            current =current->children[index];
        }
        if(current != nullptr && current->isword)
            return true;
        return false;
    }
 
void deleteWord(string word) 
{
    if(!search(word)) 
    {
        cout << word << "not found!" << endl;
        return;
    }
    
    deleteHelper(root, word, 0);
    cout << word << "deleted." << endl;
}
};
