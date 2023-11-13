class Solution {
public:
    string sortVowels(string s) 
    {
        unordered_set<char>st={'a','A','e','E','i','I','o','O','u','U'};
        string temp="";
        for(auto &x : s)
        {
            if(st.contains(x)) 
               temp+=x;    
        }
        sort(temp.begin(),temp.end());
        int j = 0 ;
        for(auto &x : s)
        {
             if(st.contains(x))
             {
                  x=temp[j];
                  j++;
             }
        }
        return s;
    }
};