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

  int diff[500002];
  int ans = -1;
  for (int i = 0; i < n; i++)
  {
    diff[i] = i - sorted[i].second; 
    //정렬 완료 후 인덱스와 처음 인덱스의 차이를 구하면, 음수인 것들이 
    //왼쪽으로 이동한 아이들임을 알 수 있음. 그러니 음수 차이를 가진 애들중 가장 큰 값이
    //루프문을 돈 횟수가 된당!
    if (diff[i] <= 0 && abs(diff[i]) > ans) // 음수중 절대값 제일 큰걸 답으로 선택
      ans = abs(diff[i]);
  }
  cout<<ans+1;
  return 0; 
}