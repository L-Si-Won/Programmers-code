#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    
    vector<int> start_t, end_t;
    
    for(int i=0; i<lines.size(); i++){
        int ih, im, is, process;
        lines[i].erase(lines[i].end()-1);
        
        string h, m, s, ms;
        h=lines[i].substr(11,2);
        m=lines[i].substr(14,2);
        s=lines[i].substr(17,2);
        ms=lines[i].substr(20,3);
        process=stod(lines[i].substr(24, 5))*1000;
        
        ih=stoi(h)*3600*1000;
        im=stoi(m)*60*1000;
        is=stoi(s)*1000+stoi(ms);
        
        start_t.push_back(ih+im+is-process+1);
        end_t.push_back(ih+im+is);
    }
    
    for(int i=0; i<lines.size(); i++){
        int cur_t=end_t[i]+1000;
        int temp_answer=1;
        for(int j=i+1; j<lines.size(); j++){
            int next_t=start_t[j];
            if(cur_t>next_t) temp_answer++;
        }
        answer=max(answer, temp_answer);
    }
    
    return answer;
}
