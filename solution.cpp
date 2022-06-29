#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string num="";
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0' && s[i]<='9') num+=s[i];
        else{
            if(s[i]=='z'){ //0
                num+='0';
                i+=3;
            }
            else if(s[i]=='o'){ //1
                num+='1';
                i+=2;
            }
            else if(s[i]=='t'){ //2, 3
                if(s[i+1]=='w'){
                    num+='2';
                    i+=2;
                }
                else if(s[i+1]=='h'){
                    num+='3';
                    i+=4;
                }
            }
            else if(s[i]=='f'){ //4, 5
                if(s[i+1]=='o'){
                    num+='4';
                    i+=3;
                }
                else if(s[i+1]=='i'){
                    num+='5';
                    i+=3;
                }
            }
            else if(s[i]=='s'){ //6, 7
               if(s[i+1]=='i'){
                    num+='6';
                    i+=2;
                }
                else if(s[i+1]=='e'){
                    num+='7';
                    i+=4;
                }
            }
            else if(s[i]=='e'){ //8
                num+='8';
                i+=4;
            }
            else if(s[i]=='n'){ //9
                num+='9';
                i+=3;
            }
        }
    }
    answer=stoi(num);
    return answer;
}