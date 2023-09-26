#include <iostream>

using namespace std;

//예시를 보면 그냥 오름차순으로 정렬하면 되는 문제이다.
// 입력이 1000, 시간 제한이 1초이기 때문에 O(N^2), 선택정렬로 풀었다.

int main()
{
  int n;
  int p[1002];

  cin>>n;
  for (int i = 0; i < n ;i++)
    cin>>p[i];

  for (int i = 0; i < n; i++)   //선택정렬 사용
  {
    int minIdx = i;
    for (int j = i; j < n; j++)
    {
      if (p[minIdx] > p[j])
        minIdx = j;
    }
    int tmp = p[i];
    p[i] = p[minIdx];
    p[minIdx] = tmp;
  }

  int sums[1001];
  sums[0] = 0;
  long long total_sum = 0;  //누적합들의 총합.
  
  for(int i = 1; i <=n; i++)  //누적합을 sums 에 저장해 사람마다 대기하는 시간을 구함.
  {
    sums[i] = sums[i-1];
    sums[i] += p[i- 1];
    total_sum += sums[i];
  }
  cout<<total_sum<<"\n";
  return 0;
}