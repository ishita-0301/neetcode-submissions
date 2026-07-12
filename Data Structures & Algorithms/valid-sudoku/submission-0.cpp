class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //pay attention to this data structure
        //use count function of set as finder
        //i/3,j/3 for the given box idx
        //unordered map of pair doesn't work coz pair has no inbuilt hash fn
        vector<unordered_set<char>> rows(9),cols(9);
        vector<unordered_set<char>> box(9);//use int idx = (i / 3) * 3 + (j / 3);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.') continue;
                //if(rows[i].find(board[i][j])||cols[j].find(board[i][j])||box{i/3,j/3}.find(board[i][j]))
                int idx = (i / 3) * 3 + (j / 3);
                if (rows[i].count(board[i][j]) ||
                    cols[j].count(board[i][j]) ||
                    box[idx].count(board[i][j]))
                    return false;
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                box[idx].insert(board[i][j]);
            }
        }
        return true;
    }
};
