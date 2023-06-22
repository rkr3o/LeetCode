class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Validate Rows
        for (int row = 0; row < 9; row++) {
            if (!isValidSet(board[row])) {
                return false;
            }
        }

        // Validate Columns
        for (int col = 0; col < 9; col++) {
            vector<char> column;
            for (int row = 0; row < 9; row++) {
                column.push_back(board[row][col]);
            }
            if (!isValidSet(column)) {
                return false;
            }
        }

        // Validate Sub-boxes
        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                vector<char> subBox;
                for (int row = boxRow * 3; row < (boxRow + 1) * 3; row++) {
                    for (int col = boxCol * 3; col < (boxCol + 1) * 3; col++) {
                        subBox.push_back(board[row][col]);
                    }
                }
                if (!isValidSet(subBox)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool isValidSet(const vector<char>& digits) {
        unordered_set<char> digitSet;
        for (char digit : digits) {
            if (digit != '.' && digitSet.count(digit) > 0) {
                return false;
            }
            digitSet.insert(digit);
        }
        return true;
    }
};
