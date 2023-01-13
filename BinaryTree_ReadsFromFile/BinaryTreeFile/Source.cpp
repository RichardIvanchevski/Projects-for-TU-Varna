#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert a new node into the binary search tree
void insertNode(TreeNode*& root, int val) {
    if (!root) {
        root = new TreeNode(val);
        return;
    }
    if (val < root->val) {
        insertNode(root->left, val);
    }
    else {
        insertNode(root->right, val);
    }
}

// Function to print the nodes of the binary search tree in-order
void printTree(TreeNode* root) {
    if (!root) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    // Open the text file
    ifstream inputFile("text.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file" << endl;
        return 1;
    }

    // Read the integers from the file and insert them into the binary search tree
    TreeNode* root = NULL;
    int val;
    while (inputFile >> val) {
        insertNode(root, val);
    }

    // Close the file
    inputFile.close();

    // Print the nodes of the binary search tree in ascending order
    printTree(root);
    cout << endl;

    return 0;
}
