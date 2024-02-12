 
class Solution {
public:
    int cnt = 0 ;
    vector<int> solve(TreeNode* root , int dist ){
        if(root==NULL)return {};
        if(root->left==0 and root->right==0) return{1};
        vector<int>left = solve(root->left,dist);
        vector<int>right = solve(root->right,dist);
        vector<int>res;
        for(auto x : left)
        {
            for(auto y : right)
            {
                if(x+y <=dist)cnt++;
            }
        }
        for(auto x : left)
            res.push_back(x+1);
        for(auto x : right)
            res.push_back(x+1);
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        solve(root,distance);
        return cnt;
    }
};