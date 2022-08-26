#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int bfs(int n, vector<int> v[]){
    queue<pair<int, int>> q; //노드번호, 거리
    bool visit[20001]={false};
    int dis[20001];
    
    for(int i=1; i<n+1; i++) dis[i]=2e9;
    dis[1]=0;
    visit[1]=true;
    q.push({1, 0});
    
    while(!q.empty()){
        int cur_num=q.front().first;
        int cur_dis=q.front().second;
        q.pop();
        
        for(int i=0; i<v[cur_num].size(); i++){
            int next=v[cur_num][i];
            if(visit[next]==false || dis[next]>cur_dis+1){ //거리비교에서 = 빼야됨
                visit[next]=true;
                dis[next]=cur_dis+1;
                q.push({next, cur_dis+1});
            }
        }
    }
    int MAX=dis[2];
    for(int i=3; i<n+1; i++) MAX=max(MAX, dis[i]);
    int sol=0;
    for(int i=2; i<n+1; i++)
        if(dis[i]==MAX) sol++;
    return sol;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> v[20001];
    for(int i=0; i<edge.size(); i++){
        int a=edge[i][0];
        int b=edge[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
        
    }
    answer=bfs(n, v);
    
    return answer;
}
