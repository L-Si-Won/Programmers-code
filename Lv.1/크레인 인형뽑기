#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s; //바구니
    
    for(int i=0; i<moves.size(); i++){
        int grap=moves[i]-1; //뽑는 열
        if(board[board.size()-1][grap]==0) continue;
        
        int doll;
        for(int j=0; j<board.size(); j++){
            if(board[j][grap]!=0){
                doll=board[j][grap];
                board[j][grap]=0;
                break;
            }
        }
        
        if(s.size()==0) s.push(doll);
        else{
            if(s.top()==doll){
                s.pop();
                answer+=2;
            }
            else s.push(doll);
        }
    }
    
    return answer;
}
