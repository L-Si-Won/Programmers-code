#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n) {
    string answer = "";
    
    //1,2,4는 각각 3진법의 1,2,0에 사상됨
    //0이 4로 바뀌는 경우, 3진법에서는 한자리 올라가는 것이므로 위의 자리에서 -1해야함
    
    int mod=3;
    int reminder;
    stack<int> sum;
    while(n){
        reminder=n%mod;
        if(reminder==0){
            sum.push(4);
            n=n/mod-1;
        }
        else{
            sum.push(reminder);
            n/=mod;
        }
    }
    while(!sum.empty()){
        answer+=to_string(sum.top());
        sum.pop();
    }
    return answer;
}