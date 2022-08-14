#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    //소문자로 통일
    for(int i=0; i<str1.size(); i++)
        if(str1[i]>='A' && str1[i]<='Z') str1[i]+=32;
    for(int i=0; i<str2.size(); i++)
        if(str2[i]>='A' && str2[i]<='Z') str2[i]+=32;
    
    //문자 나누기
    unordered_set<string> str;
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    
    for(int i=0; i<str1.size()-1; i++){
        if((str1[i]>='a' && str1[i]<='z') && (str1[i+1]>='a' && str1[i+1]<='z')){
            string temp=str1.substr(i, 2);
            m1[temp]++;
            str.insert(temp);
        }
    }
    for(int i=0; i<str2.size()-1; i++){
        if((str2[i]>='a' && str2[i]<='z') && (str2[i+1]>='a' && str2[i+1]<='z')){
            string temp=str2.substr(i, 2);
            m2[temp]++;
            str.insert(temp);
        }
    }
    
    //자카드 유사도 계산
    int sum=0; //합집합 크기
    int same=0; //교집합 크기
    for(auto iter:str){
        sum+=max(m1[iter], m2[iter]);
        same+=min(m1[iter], m2[iter]);
    }
    
    if(sum==0 && same==0) return 65536;
    
    return 65536*same/sum;
}