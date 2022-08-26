#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero=0;
    for(int i=0; i<6; i++)
        if(lottos[i]==0) zero++;
    int same=0;
    for(int i=0; i<6; i++)
        for(int j=0; j<6; j++)
            if(lottos[i]==win_nums[j]) same++;

    answer.push_back(min(6, 7-same-zero));
    answer.push_back(min(6, 7-same));
    return answer;
}
