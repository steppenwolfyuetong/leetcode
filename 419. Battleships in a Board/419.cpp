/*
 * At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
 */


class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty() || board.front().empty())
            return 0;

        int rt = 0;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == '.')
                    continue;
                if(j > 0 && board[i][j-1] == 'X')
                    continue;
                if(i > 0 && board[i-1][j] == 'X')
                    continue;
                rt++;
            }
        }
        return rt;
    }
};

int main()
{
}
