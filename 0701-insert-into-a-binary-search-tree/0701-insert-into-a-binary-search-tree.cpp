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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        int ans=INT_MAX;
        TreeNode* temp = root;
        TreeNode* ceil=NULL;
        
        while(temp!=NULL)
        {
            if(temp->val > val)
            {
                if(temp->val < ans)
                {
                    ans = temp->val;
                    ceil = temp;
                }
                temp =temp->left;
            }
            else if(temp->val < val)
            {
                temp =temp->right;
            }
            
        }
        
        if(ceil == NULL)
        {
            TreeNode* ans= new TreeNode(val);
            ans->left = root;
            return ans;
        }

        TreeNode* temp2 = ceil->left;
        ceil->left = new TreeNode(val);
        
        if(temp2==NULL)
        {
            return root;
        }
        else if(temp2->val > val)
        {
            ceil->left->right = temp2;
        }
        else if(temp2->val < val)
        {
            ceil->left->left = temp2;
        }
        
        return root;
    }
};