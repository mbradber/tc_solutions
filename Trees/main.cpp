#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* parent;
    Node* left;
    Node* right;
    
    Node(int value):
    data(value){
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

class Tree{
public:
    Tree();
    void Insert(int value);
    void PrintInOrder();
    void Remove(int value);
    
private:
    void PrintInOrder(Node* root);
    void Remove(Node* root, int value);
    
private:
    Node* m_root;
};

Tree::Tree()
:m_root(NULL){
    
}

void Tree::Insert(int value){
    Node* newNode = new Node(value);
    if(m_root == NULL){
        m_root = newNode;
        return;
    }
    
    Node* tmp = m_root;
    while(true){
        // go right
        if(value > tmp->data){
            if(tmp->right == NULL){
                tmp->right = newNode;
                newNode->parent = tmp;
                break;
            }else{
                tmp = tmp->right;
            }
        }
        // go left
        else{
            if(tmp->left == NULL){
                tmp->left = newNode;
                newNode->parent = tmp;
                break;
            }
            else{
                tmp = tmp->left;
            }
        }
    }
}

void Tree::PrintInOrder(){
    PrintInOrder(m_root);
}

void Tree::PrintInOrder(Node* root){
    if(root == NULL) return;
    
    PrintInOrder(root->left);
    cout << root->data;
    PrintInOrder(root->right);
}

void Tree::Remove(int value){
    Remove(m_root, value);
}

void Tree::Remove(Node* root, int value){
    if(root == NULL) return;
    
    if(root->data == value){
        if(root->right != NULL){
            root->parent->right = root->right;
            root->right->parent = root->parent;
            
            if(root->left != NULL){
                Node* tmp = root->right;
                while(tmp->left != NULL){
                    tmp = tmp->left;
                }
                
                tmp->left = root->left;
                tmp->left->parent = tmp;
            }
        }else if(root->left != NULL){
            root->parent->right = root->left;
            root->left->parent = root->parent;
        }
        
        delete root;
    }else if(value > root->data){
        Remove(root->right, value);
    }else{
        Remove(root->left, value);
    }
}

int main(){
    
    Tree t;
    t.Insert(1);
    t.Insert(0);
    t.Insert(5);
    t.Insert(3);
    t.Insert(7);
    t.Insert(6);
    t.Insert(8);
    t.Insert(2);
    t.Insert(4);
    
    t.PrintInOrder();
    t.Remove(5);
    cout << endl;
    t.PrintInOrder();
    
    
    return 0;
}