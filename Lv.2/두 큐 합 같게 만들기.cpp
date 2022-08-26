#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer=0;
    vector<int>temp_queue1=queue1;
    vector<int>temp_queue2=queue2;
    
    //각 큐의 합
    long long sum1=0, sum2=0;
    for(int i=0; i<queue1.size(); i++)
        sum1+=queue1[i];
    for(int i=0; i<queue2.size(); i++)
        sum2+=queue2[i];
    
    //모든 수의 합이 홀수이면
    if((sum1+sum2)&2!=0){
        answer=-1;
        return answer;
    }
    
    int size1=queue1.size();
    
    int pop1=0, pop2=0; //각 큐에서 pop한 횟수
    
    while(1){
        if(sum1==sum2) break;
        else if(sum1>sum2){
            sum1-=queue1[pop1];
            sum2+=queue1[pop1];
            queue2.push_back(queue1[pop1]);
            queue1[pop1]=0;
            pop1++;
        }
        else if(sum1<sum2){
            sum1+=queue2[pop2];
            sum2-=queue2[pop2];
            queue1.push_back(queue2[pop2]);
            queue2[pop2]=0;
            pop2++;
        }
        
        if(queue1.size()>size1*3){
            answer=-1;
            break;
        }
        
        answer++;
    }
    
    return answer;
}
