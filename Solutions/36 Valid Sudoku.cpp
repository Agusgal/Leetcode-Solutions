#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        //Each element of the arrays represent a row, col, or subgrid
        unordered_set<char> rowSet[9];
        unordered_set<char> columnSet[9];
        unordered_set<char> boxSet[9];

        for(int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++){

                if (board[row][col] == '.'){
                    continue;
                }

                char value = board[row][col];
                int boxId = (row/3) * 3 + (col/3);

                if (rowSet[row].count(value) || columnSet[col].count(value) || boxSet[boxId].count(value))
                {
                    return false;
                }

                rowSet[row].insert(value);
                columnSet[col].insert(value);
                boxSet[boxId].insert(value);
            }
        }
        return true;
    }
};