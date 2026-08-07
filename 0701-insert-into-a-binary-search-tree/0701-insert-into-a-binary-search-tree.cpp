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

    void floor_recursive(TreeNode* root, int val,int & ans,TreeNode* & floor)
    {
        TreeNode* temp = root;
        
        if(temp!=NULL)
        {
            if(temp->val > val)
            {
                floor_recursive(root->left,val,ans,floor);
            }
            else if(temp->val < val)
            {
                if(temp->val > ans)
                {
                    ans=temp->val;
                    floor=temp;
                }
                floor_recursive(root->right,val,ans,floor);
            }
        }
        else
        {
            return;
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        int ans=INT_MIN;
        TreeNode* floor=NULL;

        floor_recursive(root,val,ans,floor);
        if(floor==NULL)
        {
            TreeNode* ans= new TreeNode(val);
            ans->right = root;

            return ans;
        }
        TreeNode* temp = floor->right;
        floor->right = new TreeNode(val);

        if(temp == NULL)
        {
            return root;
        }
        else if(temp->val > val)
        {
            floor->right->right = temp;
        }
        else if(temp->val < val)
        {
            floor->right->left = temp;
        }

        return root;
    }
};