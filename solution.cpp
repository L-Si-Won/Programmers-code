#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> state;
    map<string, string> user;
    
    for(int i=0; i<record.size(); i++){
        stringstream ss(record[i]);
        string str[3];
        string token;
        int idx=0;
        while(ss >> token) str[idx++]=token;
        
        if(str[0]=="Enter"){
            state.push_back("님이 들어왔습니다.");
            user[str[1]]=str[2];
            answer.push_back(str[1]);
        }
        else if(str[0]=="Leave"){
            state.push_back("님이 나갔습니다.");
            answer.push_back(str[1]);
        }
        else if(str[0]=="Change"){
            user[str[1]]=str[2];
        }
    }
    for(int i=0; i<answer.size(); i++)
        answer[i]=user[answer[i]]+state[i];

    return answer;
}