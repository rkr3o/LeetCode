class Solution {
public:
    long long lcm(int x, int y){
        long long a = x, b = y; 
        return (a* b) / __gcd(a, b); 
    }
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
        // a -> No of elem that are not divisible by div1
        // b -> No of elem that are not divisible by div2
        // c -> No. of elem which are not divible by either of div1/div2
        // if a >= cnt1 && b >= cnt2 && (a + b  - c >= cnt1 + cnt2) should be the conditions for this to exist.

        int low = 1, high = INT_MAX; 
        int ans = INT_MAX; 
        while (low <= high){
            long long mid = low + (high - low) / 2;
            long long a = mid - mid / div1; 
            long long  b = mid - mid / div2; 
            long long c = mid - mid / div1 - mid / div2 + mid / lcm(div1, div2); 
            if (a >= cnt1 && b >= cnt2 && a + b - c >= cnt1 + cnt2){
                ans = mid; 
                high = mid - 1; 
            }
            else{
                low = mid + 1; 
            }
        }
        return ans; 
    }
};