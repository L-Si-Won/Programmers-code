#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int open=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            open++;
        }
        else if(s[i]==')'){
            open--;
        }
        if(open<0){
            return false;
            break;
        }
    }
    if(open!=0) return false;
    else return true;
}