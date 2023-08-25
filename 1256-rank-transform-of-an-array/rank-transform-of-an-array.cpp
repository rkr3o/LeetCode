class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<int>ans=arr;
        sort(arr.begin(),arr.end());
        
        int k = 1 ;
        for(auto x : arr)
        {
            if(mp.find(x)==mp.end())
            {
                mp[x]=k++;
            }
        }
     
        int n = ans.size();
        
        for(int i = 0 ; i < ans.size() ; i++)
        {
            int x = mp[ans[i]];
            ans[i]=x;
        } 
        return ans;
        
    }
};