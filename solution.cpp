#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second ? true : false;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;
    
    string temp="";
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0' && s[i]<='9'){
            temp+=s[i];
            if(s[i+1]==',' || s[i+1]=='}'){
                m[stoi(temp)]++;
                temp="";
            }
        }
    }
    
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);
    
    for(int i=0; i<v.size(); i++)
        answer.push_back(v[i].first);
    return answer;
}