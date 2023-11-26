class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        int res;
        vector<int> vv(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==1){
                   vv[j]+=1;
                }
                else{
                    vv[j]=0;
                }
            }
            auto b=vv;//this is the step actually which might be missed
            sort(b.begin(),b.end());
            res=max(res,helper(b));
        }
        return res;
    }
    int helper(vector<int>& heights){
        int n=heights.size();
        stack<int> st;
        vector<int> prevsmaller(n,-1),nextsmaller(n,n);
        for(int i=0;i<n;i++){
            while(st.empty()==false and heights[st.top()]>heights[i]){
                nextsmaller[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(st.empty()==false and heights[st.top()]>heights[i]){
                prevsmaller[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
      
        int area=0;
        for(int i=0;i<=n-1;i++){
            int l=prevsmaller[i];
            int r=nextsmaller[i];
            //cout<<l<<" "<<r<<" "<<heights[i]<<endl;
            //in between l and r we can make a histogram of atleast height: heights[i]
            area=max(area,(r-l-1)*(heights[i]));
        }
        return area;
    }
};