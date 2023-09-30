#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>

using namespace std;
//n이 오십만, 시간초는 2초이기 때문에, 곧대로 버블 정렬을 갈기면 시간초과가 남.
// i 는 swap 이 일어나지 않을 때 까지 돈 횟수를 뜻함.
// 그니까 모두 정렬이 되었다는 거..-> 안쪽 for 가 몇번 수행되었는가
// 정렬이 끝날 때까지 스왑이 일어난 큰 루프는 몇번 일어났는가

int n;
int arr[500002];
pair<int,int> sorted[500002];
int main()
{
  cin>>n;
  for (int i = 0; i < n; i++){
    cin>>arr[i];
    sorted[i].first = arr[i];
    sorted[i].second = i;
  }
    
  sort(sorted, sorted + n); //pair 에 <값, 인덱스> 를 담아 정렬.

  int ans = -1;
  for (int i = 0; i < n; i++) ans = ans > sorted[i].second - i ? ans : sorted[i].second - i;
// 또는 max 함수 사용
  for (int i = 0; i < n; i++) ans = max(ans, sorted[i].second - i);
  cout<<ans+1;
  return 0; 
}