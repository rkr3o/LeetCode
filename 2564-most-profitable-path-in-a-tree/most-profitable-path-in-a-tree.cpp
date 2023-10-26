class Solution {
public:
    int cross_time(int cur,int p,vector<int>v[],vector<int>&c,int bob){
        if(cur==bob) return c[cur]=0;
        for(auto i:v[cur]){
            if(i==p) continue;
            int time=cross_time(i,cur,v,c,bob);
            if(time!=-1) return c[cur]=1+time;
        }
        return -1;
    }
    
    void dfs(int alice,int p,vector<int>&a,vector<int>&c,vector<int>v[],int
             cur_sum,int cur_time,int&ans){
        // cout<<alice<<" "<<p<<" "<<cur_sum<<" "<<cur_time<<" "<<ans<<"   ";
        if(cur_time<c[alice]) cur_sum+=a[alice];
        else if(cur_time==c[alice]) cur_sum+=a[alice]/2;
        // cout<<cur_sum<<" "<<cur_time<<"\n";
        if(v[alice].size()==1 && alice) ans=max(ans,cur_sum);
        for(auto i:v[alice]){
            if(i==p) continue;
            dfs(i,alice,a,c,v,cur_sum,cur_time+1,ans);
        }
        return;
    }
    
    int mostProfitablePath(vector<vector<int>>& e,int b,vector<int>& a){
        int n=a.size();
        vector<int>v[n];
        for(auto i:e){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        vector<int>cross_time_bob(n,1e6);    
        cross_time(0,-1,v,cross_time_bob,b);
        // for(auto i:cross_time_bob) cout<<i<<' '; cout<<'\n';
        int ans=-2e9;
        dfs(0,-1,a,cross_time_bob,v,0,0,ans);
        return ans;
    }
};