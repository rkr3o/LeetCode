//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long v[], int n)
{
        long long  maxi = 0;
        int left = 0 , right = n-1 ;
        while(left<=right)
        {
            maxi = max(maxi , min(v[left], v[right]) * (right - left));
            if (v[left] < v[right])left++;
            else right--;
        }
      return maxi;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends