class Solution {
public:
    unordered_set<int>st;
    int  calc(vector<int>&p1 , vector<int>&p2)
    {
        int x1 = p1[0];
        int x2 = p2[0];
        int y1 = p1[1];
        int y2 = p2[1];
        int dx = x1-x2;
        int dy = y1-y2;
        return dx*dx+dy*dy;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
         //unordered_set<int>st;
         st.insert(calc(p1,p2));
         st.insert(calc(p1,p3));
         st.insert(calc(p1,p4));
         st.insert(calc(p2,p3));
         st.insert(calc(p2,p4));
         st.insert(calc(p3,p4));
         return st.size()==2 and !st.contains(0);
    }
};