class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        unordered_set<char> st;
        int cnt = 0;

        for (auto x : chars) mp[x]++;

        for (auto x : chars) st.insert(x);

        for (auto word : words) {
            unordered_map<char, int> mp2;
            bool f = true;

            for (auto y : word) mp2[y]++;

            for (auto y : word) {
                if (mp2[y] > mp[y]) {
                    f = false;
                    break;
                }
            }

            if (f) {
                cnt += word.size();
            }
        }

        return cnt;
    }
};