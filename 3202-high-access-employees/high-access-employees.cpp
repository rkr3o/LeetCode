
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        unordered_map<string, vector<int>> accessMap;
        // Step 1: Create a map to store access times for each employee
        for (auto x : access_times) {
            accessMap[x[0]].push_back(stoi(x[1]));
        }
        // Step 2: Iterate through the access times for each employee
        //In a 24-hour time format, where times are represented in four digits 
        //(e.g., "1034"), the difference between two times that are exactly one 
        //hour apart would be 100. For example, "1034" and "1134" have a time difference of 100.
        for (auto &[employee, loginTimes] : accessMap) {
            vector<int> time = loginTimes;
            int n = time.size();
            sort(begin(time), end(time));
            for (int i = 0; i < n - 2; i++) {
                if (time[i + 2] < time[i] + 100) {
                    ans.push_back(employee);
                    break;
                }
            }
        }
        return ans;
    }
};