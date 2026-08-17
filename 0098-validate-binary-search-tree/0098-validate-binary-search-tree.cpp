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
    void inorder(TreeNode* root , int & curr ,int & prev , bool & ans, int & first) 
    {
        if(root!=NULL)
        {
            if(ans==0)return;

            inorder(root->left,curr,prev,ans,first);

            if(ans==0)return;

            prev=curr;
            curr = root->val;
            first++;
            
            if(first>1 && prev>=curr)
            {
                ans=0;
                return;
            }

            inorder(root->right,curr,prev,ans,first);
        }
    }

    bool isValidBST(TreeNode* root) 
    {
        int curr=INT_MIN,prev,first=0;
        bool ans=1;
        inorder(root,curr,prev,ans,first);

        return ans;
    }
};