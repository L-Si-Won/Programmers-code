#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    for(int i=1; i<=s.length()/2; i++){
        string temp="", some=s.substr(0, i);
        int cnt=1;
        for(int j=i; j<s.length(); j+=i){
            if(some==s.substr(j, i)) cnt++;
            else{
                if(cnt>1) temp+=to_string(cnt);
                temp+=some;
                some=s.substr(j, i);
                cnt=1;
            }
        }
        if(cnt>1) temp+=to_string(cnt);
        temp+=some;
        answer=min(answer, (int)temp.length());
    }
    return answer;
}
