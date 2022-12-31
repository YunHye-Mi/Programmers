#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> pick;
    for(auto it:moves){
        for(auto i = 0; i < board.size(); i++){
            if(board[i][it-1] != 0){
                if(!pick.empty() && board[i][it - 1] == pick.top()){
                    pick.pop();
                    answer += 2;
                }
                else{
                    pick.push(board[i][it-1]);
                }
                board[i][it-1] = 0;
                break;
            }
        }
    }

    return answer;
}