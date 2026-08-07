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
    void insert(TreeNode* root, int val) 
    {
        TreeNode* temp=root;

        if(temp!=NULL)
        {
            if(temp->val < val)
            {
                if(temp->right == NULL)
                {
                    temp->right = new TreeNode(val);
                    return;
                }
                else
                {
                    insertIntoBST(root->right,val);
                }
                
            }
            else if(temp->val > val)
            {
                if(temp->left == NULL)
                {
                    temp->left = new TreeNode(val);
                    return;
                }
                else
                {
                    insertIntoBST(root->left,val);
                }
            }
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root == NULL)
        {
            return new TreeNode(val);
        }
        
        insert(root,val);

        return root;
    }
};