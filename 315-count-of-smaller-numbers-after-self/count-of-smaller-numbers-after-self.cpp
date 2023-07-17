class Solution {
public:
    void merge(int low ,int mid , int high , vector<int>&count , vector<pair<int,int>>&v)
    {
        int left = low ;
        int right = mid+1;
        vector<pair<int,int>>temp;
        int cnt = 0;
        int k = 0 ;
        while(left<=mid and right<=high)
        {
            if(v[left].first <= v[right].first)
            { 
                count[v[left].second] += cnt;
                temp.push_back({v[left].first,v[left].second});
                left++;
            }
            else
            {
                cnt++;
                temp.push_back({v[right].first,v[right].second});
                right++;
            }
        }
        while(left<=mid)
        {
              count[v[left].second] += cnt;
              temp.push_back({v[left].first,v[left].second});
              left++;
        }
        while(right<=high)
        {
           temp.push_back({v[right].first,v[right].second});
                right++;
        }

        for(int i = low ; i <= high ; i++)
        {
            v[i]=temp[i-low];
        } 
    }
    void mergeSort(int low , int high , vector<int>&count , vector<pair<int,int>>&v)
    {
        if(low>=high)return ;
        int mid = low+(high-low)/2;
        //divide
        mergeSort(low,mid,count,v);
        mergeSort(mid+1,high,count,v);
        //merge them
        merge(low,mid,high,count,v);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>v(n);//prevent from sorting
        for(int i = 0 ; i < n ; i++)
        {
            v[i]={nums[i],i};
        }
        vector<int>count(n,0);
        mergeSort(0,n-1,count,v);
        return count;
    }
};