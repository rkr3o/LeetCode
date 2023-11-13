class Solution {
public:
    string sortVowels(string s) {
        set<char>st;
        string temp="";
        for(auto &x : s)
        {
            if(x=='a' || x=='A' || x=='e' || x=='E' || x=='i' || x=='I' || x=='o' || x=='O' || x=='u' || x=='U')
            {
                temp+=x;
            }
        }
        sort(temp.begin(),temp.end());
        int j = 0 ;
        for(auto &x : s)
        {
            if(x=='a' || x=='A' || x=='e' || x=='E' || x=='i' || x=='I' || x=='o' || x=='O' || x=='u' || x=='U')
            {
                x=temp[j];
                j++;
            }
        }
        return s;
    }
};