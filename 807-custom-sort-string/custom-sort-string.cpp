class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(int i = 0 ; i < order.size() ; i++)
        {
            mp[order[i]]=i;
        }
        unordered_map<char,int>mp2;
        for(auto x : s)
           mp2[x]++;
        string temp="";
        
        for(auto &x : order)
        {
            int freq = mp2[x];
            while(freq--)
            {
                temp+=x;
                mp2[x]--;
                if(mp2[x]==0)mp2.erase(x);
            }
        }
        for(auto &[x,y] : mp2){
             while(y--)
             {
                 temp+=x;
             }
        }
        return temp;
    }
};