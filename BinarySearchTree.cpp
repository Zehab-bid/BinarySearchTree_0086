#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *leftchild;
    Node *rightchild;

    // Constructor for the node class
    Node()
    {
        leftchild = nullptr; // initialize left child to null
        rightchild = nullptr; // initialize right child to null
    }
};

class Binarytree
{
public:
    Node *ROOT;

    Binarytree()
    {
        ROOT = nullptr; // Initializing ROOT to null
    }

    void insert()
    {
        int x;
        cout << "Masukkan nilai: ";
        cin >> x;

        // Step 1: Allocate memory for the new node
        Node *newNode = new Node();

        // Step 2: Assign value to the data field of new node
        newNode->info = x;

        // Step 3: Make the left and right child of the new node point to NULL
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        // Step 4: Locate the node which will be the parent of the node to be inserted
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);

        // Step 5: If parent is Null (Tree is empty)
        if (parent = nullptr)
        {
            // 5a: Mark the new node as ROOT
            ROOT = newNode;

            // 5b: Exit
            return;
        }

        // Step 6: If the value in the data field of new node is less than thet of parent
        if (x < parent->info)
        {
            // 6a: make the left  child of parent point to the new node
            parent->leftchild = newNode;

            // 6b: exit 
            return;
        }
        
        // Step 7: If the value in the data field of the new node is greater than of the parent
        else if (x > parent->info)
        {
            // 7a: Make the right child of parent point to the new node
            parent->rightchild = newNode;

            // 7B: Exit
            return;
        }
    }

    void search(int element, Node *&parent, Node *&currentNode)
    {
        // This function searches the currentNode of the specified Node as well as the current Node of its parent
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }
};