#include <unordered_map>
#include <vector>
#include <random>

class RandomizedCollection {
public:
    unordered_map<int,int>mp;
    vector<int>v;
    RandomizedCollection(){

    }
    bool insert(int x) {
       if(mp[x]==0)
         {
            mp[x]++; 
            v.push_back(x);
            return true;   
         }
         else if(mp[x]>0)
         {
            mp[x]++; 
            v.push_back(x);
            return false;   
         }
         return false;
    }

    bool remove(int x) {
         if(mp[x]>0)
         { 
             auto it = find(v.begin(),v.end(),x);
             v.erase(it);
             mp[x]--;
             return true; 
 
         }
         return false;
    }
    int getRandom() {
         int randomIdx = rand() % v.size();
         return v[randomIdx];
    }
};
