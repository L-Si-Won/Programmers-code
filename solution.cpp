#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
bool visit[5][5];

bool dfs(int x, int y, vector<string> v, int cnt){
    if(cnt==3) return true;
    
    if(cnt>0 && v[x][y]=='P') return false;
    
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<5 && ny<5){
            if(visit[nx][ny]==false){
                if(v[nx][ny]!='X'){
                    visit[nx][ny]=true;
                    if(dfs(nx, ny, v, cnt+1)==false) return false;
                    visit[nx][ny]=false;
                }
            }
        }
    }
    return true;
}

int solve(vector<string> v){
    memset(visit, false, sizeof(visit));
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(v[i][j]=='P'){
                visit[i][j]=true;
                if(dfs(i, j, v, 0)==false) return 0;
                visit[i][j]=false;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0; i<5; i++)
        answer.push_back(solve(places[i]));
    return answer;
}