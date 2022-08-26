#include <numeric>

using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    answer=(long long)w*(long long)h-(w+h-gcd(w, h));
    return answer;
}
