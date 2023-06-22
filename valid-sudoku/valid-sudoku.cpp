class Solution {
public:
    bool check(vector<char>&array)
    {
        unordered_set<int>st;
        for(const auto &x : array)
        {
            if(x!='.' and st.count(x)>0)return false;
            st.insert(x);
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();
        //valid row 
        for(int i = 0 ; i < n ; i++)
        {
            if(!check(board[i]))return false;
        }

        // valid column 
        for(int i = 0 ; i < n ; i++)
        {
            vector<char>column;
            for(int j = 0 ; j < n ;j++)
            {
                column.push_back(board[j][i]);
            }

            if(!check(column))return false;
        }
        // valid each box
        for(int boxRow = 0 ; boxRow < 3 ; boxRow++)
        {
            for(int boxCol  = 0 ; boxCol  < 3 ; boxCol++)
            {
                vector<char>box;
                for(int row = boxRow*3 ; row < (boxRow+1)*3 ; row++)
                {
                   for(int col = boxCol*3 ; col < (1+boxCol)*3 ; col++)
                   {
                          box.push_back(board[row][col]);
                   }
                }
                if(!check(box))return false;
            }
        }
        return true;
    }
};