class WordDictionary {
public:
    unordered_map<int,vector<string>>mp;
    WordDictionary() 
    {
    }
    void addWord(string word) 
    {
        int x = word.size();
        mp[x].push_back(word);
    }
    bool equal(string &x , string &s)
    {
           for(int i = 0 ; i < x.size() ; i++)
           {
               if(s[i]=='.')continue;
               if(x[i]!=s[i])return false;
           }
           return true;
    }
    bool search(string word) 
    {
        if(mp.find(word.size())==mp.end())return false;
        for(auto &x : mp[word.size()])
        {
            if(equal(x,word))return true;
        }    

        return false;
    }
};
