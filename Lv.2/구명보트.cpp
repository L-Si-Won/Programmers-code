#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, idx = 0;
    
    sort(people.begin(), people.end());
    
    for (int i = people.size() - 1; i >= 0; i--) {
        if (idx > i) {
            break;
        }

        int sum = people[i];
        
        for (int j = idx; j < i; j++) {
            if (sum + people[j] <= limit) {
                sum += people[j];
                idx++;
                break;
            } else {
                break;
            }
        }

        answer++;
    }
    
    return answer;
}
