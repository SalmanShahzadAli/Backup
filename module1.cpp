// this is the first module we are storing reg numbers in a bst.
#include <iostream>
#include <queue>
#include <windows.h>
using namespace std;

class NodeOfBSTRegno
{
public:
    int value;
    NodeOfBSTRegno *left;
    NodeOfBSTRegno *right;

    NodeOfBSTRegno(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTreeRegno
{
public:
    NodeOfBSTRegno *root;

public:
    BinarySearchTreeRegno() { root = nullptr; }
    void destroy(NodeOfBSTRegno *currentNode)
    {
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTreeRegno() { destroy(root); }

    bool insert(int value)
    {
        NodeOfBSTRegno *newNode = new NodeOfBSTRegno(value);

        if (root == nullptr)
        {
            root = newNode;
            return true;
        }
        NodeOfBSTRegno *temp = root;
        while (true)
        {
            if (newNode->value == temp->value)
            {
                return false;
            }
            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }
    // the below function will check if a regno exits or not
    bool containsRegno(int value)
    {
        if (root == nullptr)
            return false;
        NodeOfBSTRegno *temp = root;
        while (temp)
        {
            if (value < temp->value)
            {
                temp = temp->left;
            }
            else if (value > temp->value)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    void BFS()
    {
        NodeOfBSTRegno *currentNode = root;
        queue<NodeOfBSTRegno *> myQueue;
        myQueue.push(currentNode);

        while (myQueue.size() > 0)
        {
            currentNode = myQueue.front();
            myQueue.pop();
            cout <<currentNode->value << endl;
            if (currentNode->left)
            {
                myQueue.push(currentNode->left);
            }
            if (currentNode->right)
            {
                myQueue.push(currentNode->right);
            }
        }
    }

    void DFSPreOrder(NodeOfBSTRegno *currentNode)
    {
        Sleep(500);
        cout <<currentNode->value << endl;
        if (currentNode->left != nullptr)
        {
            DFSPreOrder(currentNode->left);
        }
        if (currentNode->right != nullptr)
        {
            DFSPreOrder(currentNode->right);
        }
    }

    void DFSPreOrder() { DFSPreOrder(root); }

    void DFSPostOrder(NodeOfBSTRegno *currentNode)
    {
        Sleep(500);
        if (currentNode->left != nullptr)
        {
            DFSPostOrder(currentNode->left);
        }
        if (currentNode->right != nullptr)
        {
            DFSPostOrder(currentNode->right);
        }
        cout <<currentNode->value << endl;
    }

    void DFSPostOrder() { DFSPostOrder(root); }

    void DFSInOrder(NodeOfBSTRegno *currentNode)
    {
        Sleep(500);
        if (currentNode->left != nullptr)
        {
            DFSPreOrder(currentNode->left);
        }
        cout << currentNode->value << endl;
        if (currentNode->right != nullptr)
        {
            DFSPreOrder(currentNode->right);
        }
    }

    void DFSInOrder() { DFSInOrder(root); }
};

int main()
{

    BinarySearchTreeRegno *myBST = new BinarySearchTreeRegno();
    // the below code will store 700 regnumbers in the bst.
    int regno = 2023000;
    for (int i = 0; i <= 700; i++)
    {
        myBST->insert(regno + i);
    }
    // the below code will display all of them.
    cout << "Displaying Regno's in Order" << endl;
    myBST->DFSInOrder();
}