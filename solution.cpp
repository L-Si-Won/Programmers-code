#include <string>
#include <vector>

using namespace std;

int solve(int rows, int columns, vector<int> queries, int arr[100][100]){
    pair<int, int> lu={queries[0]-1, queries[1]-1}; //행, 열
    pair<int, int> rd={queries[2]-1, queries[3]-1};
    int temp=arr[lu.first][lu.second];
    int MIN=temp;
    
    for(int i=lu.first; i<rd.first; i++){ //좌
        MIN=min(MIN, arr[i][lu.second]);
        arr[i][lu.second]=arr[i+1][lu.second];
    }
    
    for(int i=lu.second; i<rd.second; i++){ //하
        MIN=min(MIN, arr[rd.first][i]);
        arr[rd.first][i]=arr[rd.first][i+1];
    }
    
    for(int i=rd.first; i>lu.first; i--){ //우
        MIN=min(MIN, arr[i][rd.second]);
        arr[i][rd.second]=arr[i-1][rd.second];
    }
    
    for(int i=rd.second; i>lu.second; i--){ //상
        MIN=min(MIN, arr[lu.first][i]);
        arr[lu.first][i]=arr[lu.first][i-1];
    }
    
    arr[lu.first][lu.second+1]=temp;
        
    return MIN;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int arr[100][100];
    int num=1;
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            arr[i][j]=num++;
    for(int i=0; i<queries.size(); i++)
        answer.push_back(solve(rows, columns, queries[i], arr));
    
    return answer;
}