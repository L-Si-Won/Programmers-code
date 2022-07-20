#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> day;
    for(int i=0; i<speeds.size(); i++){
        int remain=100-progresses[i];
        if(remain%speeds[i]==0) day.push(remain/speeds[i]);
        else day.push(remain/speeds[i]+1);
    }
    while(!day.empty()){
        int cur=day.front();
        day.pop();
        int cnt=1;
        while(day.front()<=cur){
            day.pop();
            cnt++;
            if(day.empty()) break;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}