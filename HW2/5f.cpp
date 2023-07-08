#include <iostream>
using namespace std;

//* Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return root; // case of empty tree

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // Case 1: no child
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }

            // case 2: 1 child
            // only have right child
            if (root->left == nullptr)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            // only have left child
            else if (root->right == nullptr)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // case 3: 2 childrens
            else
            {
                TreeNode *parent = root;

                // find the min val in the right-sub tree
                TreeNode *successor = root->right;
                // must have left child as it represents the min value
                while (successor->left != nullptr)
                {
                    parent = successor;
                    successor = successor->left;
                }

                root->val = successor->val;
                //delete the left child
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};

int main() { cout << "pass!\n"; }