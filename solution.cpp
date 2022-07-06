#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;

    char fs[8]={'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    int fac8=40320; //8!
    
    while(fac8--){
        bool truth=true;
        for(int i=0; i<n; i++){
            char f1=data[i][0];
            char f2=data[i][2];
            char con=data[i][3];
            int num=data[i][4]-'0';
            
            int idx1, idx2;
            for(int j=0; j<8; j++){
                if(fs[j]==f1) idx1=j;
                if(fs[j]==f2) idx2=j;
            }
            
            if(con=='='){
                if(abs(idx1-idx2)!=num+1) truth=false;
            }
            else if(con=='<'){
                if(abs(idx1-idx2)>=num+1) truth=false;
            }
            else if(con=='>'){
                if(abs(idx1-idx2)<=num+1) truth=false;
            }
        }
        if(truth==true) answer++;
        next_permutation(fs, fs+8);
    }
    return answer;
}