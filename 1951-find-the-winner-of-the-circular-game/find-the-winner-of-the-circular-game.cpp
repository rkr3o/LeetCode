class Solution {
public:
    int findTheWinner(int n, int k) {
         queue<int>q;
         for(int i = 1 ; i<= n ; i++)
         {
             q.push(i);
         }
         while(true)
         {
             if(q.size()==1)return q.front();
             for(int i = 0 ; i < k-1 ; i++)
             {
                 int x = q.front();
                 q.pop();
                 q.push(x);
             }
             q.pop();
         }
         return 0;
    }
};