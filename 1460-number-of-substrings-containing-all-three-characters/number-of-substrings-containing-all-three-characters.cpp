class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0 ;
        unordered_map<char,int>mp;
        for(int right = 0 , left = 0 ; right < n ; right++)
        {
            mp[s[right]]++;
            while(mp.size()==3)
            {
                mp[s[left]]--;
                if(mp[s[left]]==0)mp.erase(s[left]);
                left++;
            }
            cnt+=left;
        }        
        return cnt;
    }
};