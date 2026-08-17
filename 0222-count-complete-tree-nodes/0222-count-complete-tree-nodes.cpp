/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int leftcount(TreeNode* root)
    {
        int count=0;
        while(root!=NULL)
        {
            count++;
            root=root->left;
        }
        return count;
    }

    int rightcount(TreeNode* root)
    {
        int count=0;
        while(root!=NULL)
        {
            count++;
            root=root->right;
        }
        return count;
    }

    int countNodes(TreeNode* root) {
        if(leftcount(root)==rightcount(root))
        {
            return pow(2,leftcount(root)) -1;
        }
        else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};