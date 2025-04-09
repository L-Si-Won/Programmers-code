#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    bool flag = false;
    
    s.insert(words[0]);
    for (int i = 1; i < words.size(); i++) {
        if (s.find(words[i]) != s.end() || words[i][0] != words[i - 1][words[i - 1].length() - 1]) {
            if ((i + 1) % n == 0) {
                answer.push_back(n);
                answer.push_back((i + 1) / n);
            } else {
                answer.push_back((i + 1) % n);
                answer.push_back(((i + 1) / n) + 1);
            }
            flag = true;
            break;
        } else {
            s.insert(words[i]);
        }
    }

    if (!flag) {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}
