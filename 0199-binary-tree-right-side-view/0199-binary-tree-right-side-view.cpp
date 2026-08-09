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
    void right_view_by_dfs(TreeNode* root,int level,vector<int>& ans)
    {
        if(root!=NULL)
        {
            if(level == ans.size())
            {
                ans.push_back(root->val);
            }
            
            right_view_by_dfs(root->right,level+1,ans);
            right_view_by_dfs(root->left,level+1,ans);
        }
    }

    vector<int> rightSideView(TreeNode* root)
    {
        vector<int>ans;
        right_view_by_dfs(root,0,ans);
        return ans;
    }
};