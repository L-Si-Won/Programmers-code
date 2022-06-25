#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i=0; i<new_id.length(); i++)
        if(new_id[i]>='A' && new_id[i]<='Z')
            new_id[i]=new_id[i]+32;
    for(int i=0; i<new_id.length(); i++)
        if(!(new_id[i]>='a' && new_id[i]<='z') && !(new_id[i]>='0' && new_id[i]<='9') && new_id[i]!='-' && new_id[i]!='_' && new_id[i]!='.')
            new_id.erase(new_id.begin()+(i--));
    for(int i=0; i<new_id.length()-1; i++)
        if(new_id[i]=='.')
            while(new_id[i+1]=='.')
                new_id.erase(new_id.begin()+i+1);
    if(new_id[0]=='.') new_id.erase(new_id.begin());
    if(new_id[new_id.length()-1]=='.') new_id.erase(new_id.end()-1);
    if(new_id=="") new_id="a";
    if(new_id.length()>15)
        while(new_id.length()>15) new_id.erase(new_id.begin()+15);
    if(new_id[new_id.length()-1]=='.') new_id.erase(new_id.end()-1);
    if(new_id.length()<3)
        while(new_id.length()<3)
            new_id+=new_id[new_id.length()-1];
    
            
    answer=new_id;
    return answer;
}