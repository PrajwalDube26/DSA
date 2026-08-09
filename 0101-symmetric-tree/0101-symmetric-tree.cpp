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
    bool compare(TreeNode* leftn,TreeNode* rightn)
    {
        if((leftn==NULL && rightn!=NULL) ||(leftn!=NULL && rightn==NULL))
        {
            return 0;
        }
        else if(leftn==NULL && rightn==NULL)
        {
            return 1;
        }
        else
        {
            if(leftn->val == rightn->val)
            {
                return compare(leftn->left,rightn->right) && compare(leftn->right,rightn->left);
            }
            else
            {
                return 0;
            }
        }
        
    }

    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 1;
        }
        return compare(root->left,root->right);
    }
};