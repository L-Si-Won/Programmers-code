#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long MIN=1;
    long long MAX=(long long) times[times.size()-1]*n;
    
    while(MIN<=MAX){
        long long MID=(MIN+MAX)/2;
        long long cnt=0;
        
        for(int i=0; i<times.size(); i++)
            cnt+=MID/times[i];
        
        if(cnt<n) MIN=MID+1;
        else{
            if(MID<=MAX) answer=MID;
            MAX=MID-1;
        }
    }
    
    return answer;
}