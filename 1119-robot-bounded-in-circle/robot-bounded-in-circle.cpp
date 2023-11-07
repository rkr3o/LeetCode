class Solution {
public:
    bool isRobotBounded(string s) {
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        int d = 0 , x =0 , y = 0 ;
        for(int i = 0; i < s.size() ; i++)
        {
             if(s[i]=='L')
             {
                 //i = (i+1) % 4 will turn right
                 d = (d+1)%4;
             }
             else if(s[i]=='R')
             {
                 //i = (i+3) % 4 will turn left
                 d = (d+3)%4;
             }
             else
             {
                 x = x+drow[d];
                 y = y+dcol[d];
             }
        }
        return x==0 and y==0 || d!=0;
    }
};