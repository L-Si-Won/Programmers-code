#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(vector<int> numbers) {
    int sum=0;
    bool arr[10];
    memset(arr, false, sizeof(arr));
    for(int i=0; i<10; i++)
        for(int j=0; j<numbers.size(); j++)
            if(numbers[j]==i) arr[i]=true;
    for(int i=0; i<10; i++)
        if(arr[i]==false) sum+=i;
    return sum;
}
