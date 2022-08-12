#include <string>
#include <iostream>

using namespace std;

bool check(string s){ //올바른 괄호 문자열인지 판단
    int open=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            open++;
        }
        else if(s[i]==')'){
            open--;
        }
        if(open<0) return false;
    }
    return true;
}

string solve(string p){
    //1
    if(p=="") return p;
    
    //2
    string u="", v="";
    int open=0;
    u+=p[0];
    if(u=="(") open++;
    else open--;
    for(int i=1; i<p.length(); i++){
        if(p[i]=='('){
            open++;
            u+=p[i];
        }
        else if(p[i]==')'){
            open--;
            u+=p[i];
        }
        if(open==0) break;
    }
    v=p;
    v.erase(v.begin(), v.begin()+u.length());
    
    //3
    if(check(u)) return u+solve(v);
    
    //4
    else{
        string emp="(";
        emp+=solve(v)+")";
        u=u.substr(1, u.length()-2);
        for(int i=0; i<u.length(); i++){
            if(u[i]=='(') emp+=')';
            else emp+='(';
        }
        return emp;
    }
}

string solution(string p) {
    if(check(p)) return p;
    return solve(p);
}















