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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        stack<vector<int>> stk;
        while(!q.empty())
        {
            int qlen=q.size();
            vector<int> level;
            for(int i=0;i<qlen;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node)
                {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(level.size()!=0) stk.push(level);
        }
         while(!stk.empty())
            {
                vector<int> v=stk.top();
                ans.push_back(v);
                stk.pop();
            }
        return ans;
    }
};