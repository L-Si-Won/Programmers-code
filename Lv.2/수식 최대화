#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(string s) {
    long long answer = 0;
    vector<char> rator; //연산자
    vector<long long> rand; //피연산자
    
    //연산자, 피연산자 구분하기
    string temp="";
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0' && s[i]<='9') temp+=s[i];
        else{
            rand.push_back(stoll(temp));
            rator.push_back(s[i]);
            temp="";
        }
    }
    rand.push_back(stoll(temp));
    
    //최대값 계산
    vector<char> v={'*', '+', '-'};
    do{
        vector<char> temp_rator=rator;
        vector<long long> temp_rand=rand;
        
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<temp_rator.size();){
                if(v[i]==temp_rator[j]){
                    //해당 연산자 계산
                    long long a;
                    if(v[i]=='*') a=temp_rand[j]*temp_rand[j+1];
                    else if(v[i]=='+') a=temp_rand[j]+temp_rand[j+1];
                    else if(v[i]=='-') a=temp_rand[j]-temp_rand[j+1];
                    
                    //피연산자 2개 삭제
                    temp_rand.erase(temp_rand.begin()+j);
                    temp_rand.erase(temp_rand.begin()+j);
                    //연산결과 삽입
                    temp_rand.insert(temp_rand.begin()+j, a);
                    //해당 연산자 삭제
                    temp_rator.erase(temp_rator.begin()+j);
                }
                else j++;
            }
        }
        
        answer=max(answer, abs(temp_rand[0]));
    }while(next_permutation(v.begin(), v.end()));
    
    return answer;
}
