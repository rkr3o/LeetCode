#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> solve(int n) {
        vector<string> ans;
        if (n == 1) {
            return { "0", "1" };
        }
        
        vector<string> pre = solve(n - 1);
        int x = (int)pre.size();
        for (int i = 0; i < x; ++i) {
            ans.push_back("0" + pre[i]);
        }
        for (int i = x - 1; i >= 0; i--) {
            ans.push_back("1" + pre[i]);
        }

        return ans;
    }

    vector<int> grayCode(int n) {
        vector<int>res(1,0);
        for(int i=0;i<n;i++){
            int size=res.size();
            for(int j=size-1;j>=0;j--){
                res.push_back(res[j]|1<<i);
            }
        }
        return res;
    }
};