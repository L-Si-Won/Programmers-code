#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = -1;

    stack<char> stk;
    stk.push(s[0]);
    for(int i=1; i<s.size(); i++){
        if(stk.empty() || s[i]!=stk.top()) stk.push(s[i]);
        else if(s[i]==stk.top()) stk.pop();
    }
    if(stk.empty()) answer=1;
    else answer=0;
    return answer;
}
