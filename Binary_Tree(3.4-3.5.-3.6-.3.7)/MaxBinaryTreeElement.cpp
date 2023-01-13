#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

// Създаваме нов възел
Node* newNode(int value)
{
    Node* node = new Node;
    node->value = value;
    node->left = node->right = nullptr;
    return node;
}

// Функция за вмъкване на нов възел в двоичното дърво
void insertNode(Node*& root, int value)
{
    if (root == nullptr) {
        root = newNode(value);
        return;
    }

    if (value < root->value)
        insertNode(root->left, value);
    else
        insertNode(root->right, value);
}

// Функция за намиране на най-голямата стойност в дървото
int findMax(Node* root)
{
 
    if (root == nullptr)
        return -1;

    int maxValue = root->value;

    // Намиране на максималната стойност в лявото поддърво
    int leftMax = findMax(root->left);
    if (leftMax > maxValue)
        maxValue = leftMax;

    // Намиране на максималната стойност в дясното поддърво
    int rightMax = findMax(root->right);
    if (rightMax > maxValue)
        maxValue = rightMax;
   
    return maxValue;
}
void increaseTreeValues(Node* root, int increment) {
    if (!root) return; // Ако дървото е празно, спираме до тук.

    root->value += increment; // Increase the value of the root node
    increaseTreeValues(root->left, increment); // Намиране на максималната стойност в лявото поддърво
    increaseTreeValues(root->right, increment); // Increase the values of the right subtree
}
void inOrderTraverse(Node* root) {
    if (!root) return; // If the tree is empty, return

    inOrderTraverse(root->left); // Visit the left subtree
    cout << root->value << " "; // Visit the root node
    inOrderTraverse(root->right); // Visit the right subtree
}
int findTreeDepth(Node* root) {
    if (!root) return 0; // If the tree is empty, return 0

    int leftDepth = findTreeDepth(root->left); // Find the depth of the left subtree
    int rightDepth = findTreeDepth(root->right); // Find the depth of the right subtree

    return max(leftDepth, rightDepth) + 1; // Return the maximum depth of the left and right subtrees plus one for the root node
}

int main()
{
    Node* root = nullptr;

    // Слагаме някакви стойности в двоичното дърво
    insertNode(root, 20); // Вмъкваме стойностите 20 , 10 ,30 , 40 в дървото
    insertNode(root, 10);
    insertNode(root, 30);
    insertNode(root, 40);
    
    
    cout << "The largest value in the binary tree is: " << findMax(root) << endl;
    
   
    cout << "Elements in the binary tree: "; inOrderTraverse(root);
    cout << endl;
    increaseTreeValues(root, 5);
    cout << "Increased all Values by 5:  "; inOrderTraverse(root);
    cout << endl;
    cout << "The depth of the binary tree is: " << findTreeDepth(root) << endl;
}