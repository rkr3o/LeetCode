class RandomizedSet
{
    public:
        unordered_map<int, int> mp;
    vector<int> v;
    RandomizedSet() {}

    bool insert(int val)
    {
        if (mp.find(val) == mp.end())
        {
            mp[val] = v.size();	//store index
            v.push_back(val);
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (mp.find(val) != mp.end())
        {
            int lastVal = v.back();
            int idx = mp[val];

            v[idx] = lastVal;	// Replace the value at idx with the last value in the vector
            mp[lastVal] = idx;	// Update the index of the last value in the map
            v.pop_back();	// Remove the last value from the vector
            mp.erase(val);	// Erase the value from the map
            return true;
        }
        return false;
    }

    int getRandom()
    {
        int randomIdx = rand() % v.size();
        return v[randomIdx];
    }
};

/**
 *Your RandomizedSet object will be instantiated and called as such:
 *RandomizedSet* obj = new RandomizedSet();
 *bool param_1 = obj->insert(val);
 *bool param_2 = obj->remove(val);
 *int param_3 = obj->getRandom();
 */