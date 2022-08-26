#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    bool right=false;
    if(hand=="right") right=true;
    
    int pad[4][3]={{1,2,3},
                   {4,5,6},
                   {7,8,9},
                   {'*',0,'#'}};
    pair<int, int> L={3,0};
    pair<int, int> R={3,2};
    
    for(int i=0; i<numbers.size(); i++){
        pair<int, int> n;
        for(int j=0; j<4; j++)
            for(int k=0; k<3; k++)
                if(numbers[i]==pad[j][k]) n={j, k};
        
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]==7){
            L=n;
            answer+="L";
        }
        else if(numbers[i]==3 || numbers[i]==6 || numbers[i]==9){
            R=n;
            answer+="R";
        }
        else{
            int l_dis=abs(L.first-n.first)+abs(L.second-n.second);
            int r_dis=abs(R.first-n.first)+abs(R.second-n.second);
            if(l_dis<r_dis){
                L=n;
                answer+="L";
            }
            else if(l_dis>r_dis){
                R=n;
                answer+="R";
            }
            else if(l_dis==r_dis){
                if(right==true){
                    R=n;
                    answer+="R";
                }
                else if(right==false){
                    L=n;
                    answer+="L";
                }
            }
        }
    }
    return answer;
}
