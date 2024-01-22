class Solution {
public:
    int countCollisions(string directions) {
        stack<char>st;
        int collide = 0 ;
        int n = directions.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(st.empty())st.push(directions[i]);
            else if(st.top()=='S' and directions[i]=='L')collide++;
            else if(st.top()=='R' and directions[i]=='L')
            {
                st.pop();
                directions[i]='S';
                collide+=2;
                i--;
            }
            else if(st.top()=='R' and directions[i]=='S')
            {
                st.pop();
                directions[i]=='S';
                i--;
                collide++;
            }
            else
            {
                st.push(directions[i]);
            }
        }
        return collide;
    }
};