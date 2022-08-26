#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

bool visit[100][100]={0, };
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};

int bfs(vector<vector<int>> arr, int x, int y, int m, int n){
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y]=true;
    int num=arr[x][y];
    
    int cnt=1;
    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                if(visit[nx][ny]==false && arr[nx][ny]==num){
                    visit[nx][ny]=true;
                    q.push({nx, ny});
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(visit, false, sizeof(visit)); //초기화 필수!!!
    
    int area=0;
    int MAX=0;
    vector<int> answer;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(picture[i][j]!=0 && visit[i][j]==false){
                MAX=max(MAX, bfs(picture, i, j, m, n));
                area++;
            }
        }
    }
    
    answer.push_back(area);
    answer.push_back(MAX);
    return answer;
}
