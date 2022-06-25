#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> idx;
    map<string, set<string>> rep;
    
    for(int i=0; i<id_list.size(); i++)
        idx[id_list[i]]=i;
    
    for(int i=0; i<report.size(); i++){
        string s1, s2;
        stringstream(report[i]) >> s1 >> s2;
        rep[s2].insert(s1);
    }

    for(auto it : rep)
        if(it.second.size() >= k)
            for(auto in_it : it.second)
                answer[idx[in_it]]++;
    return answer;
}