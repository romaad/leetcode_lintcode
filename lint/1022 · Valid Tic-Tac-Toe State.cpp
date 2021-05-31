class Solution {
public:
    /**
     * @param board: the given board
     * @return: True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game
     */
    bool validTicTacToe(vector<string> &board) {
        // Write your code
        int xcnt = 0, ocnt = 0;
        int winCnt = 0;
        for(int i = 0 ; i < 3 ; i++) {
            int rowSame = 0, colSame = 0;
            if(board[i][0] == 'X') {
                xcnt ++;
            } else if(board[i][0]=='O') {
                ocnt++;
            }
            for(int j = 1 ; j <3 ; j++) {
                if ( board[i][j] =='X' || board[i][j] == 'O') {
                    if(board[i][j] == 'X') {
                        xcnt ++;
                    } else if(board[i][j]=='O') {
                        ocnt++;
                    }
                    if(board[i][j] == board[i][j-1]) {
                        rowSame++;
                    }
                    if(board[j][i] == board[j-1][i]) {
                        colSame++;
                    }
                }

            }
            winCnt += (rowSame == 2? 1 : 0) + (colSame == 2? 1 : 0);
        }
        if((xcnt != ocnt  && xcnt != ocnt+1 )|| winCnt > 1) return false;
        if(board[0][0] == 'X' || board[0][0] == 'O') {
            winCnt += ((board[0][0] ==board[1][1] && board[1][1] == board[2][2]) ? 1: 0);
        }
        if(board[0][2] == 'X' || board[0][2] == 'O') {
            winCnt += ((board[0][2] ==board[1][1] && board[1][1] == board[2][0]) ? 1: 0);
        }
        return winCnt < 2 && ((winCnt == 0) || winCnt == 1 && xcnt == ocnt+1);

    }
};
