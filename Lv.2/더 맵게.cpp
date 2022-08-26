#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q(scoville.begin(), scoville.end());
    while(q.top()<K && q.size()>1){
        int first=q.top(); q.pop();
        int second=q.top(); q.pop();
        q.push(second*2+first);
        answer++;
    }
    if(q.top()<K) answer=-1;
    return answer;
}
