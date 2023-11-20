class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g=-1,p=-1,m=-1,cnt=0;
        int n = travel.size();
        for(int i=1;i<n;i++){
            travel[i]+=travel[i-1];
        }
        for(int i=garbage.size()-1;i>=0;i--){
            cnt += garbage[i].size();
            for(int j = 0;j<garbage[i].size();j++){
                if(garbage[i][j]=='M' && m==-1)m=i;
                if(garbage[i][j]=='P' && p==-1)p=i;
                if(garbage[i][j]=='G' && g==-1)g=i;
            }
        }
        if(m>0)cnt+=travel[m-1];
        if(p>0)cnt+=travel[p-1];
        if(g>0)cnt+=travel[g-1];
        return cnt;
    }
};