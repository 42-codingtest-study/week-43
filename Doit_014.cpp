#include <stdio.h>
#include <utility>
#include <queue>
#include <math.h>

using namespace std;

// 그냥 최소값을 pop 시키는 건데, 절댓값이 추가로 있을 때.
int arr[100002];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// 작은순으로 정렬하려고 하는데, c++ 의 greater 는 pair 에서 앞 값이 같으면 second 가 더 작은게 앞으로 오게 정렬됨.
int main()
{
  int n, x;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    int flag = 1;
    scanf("%d", &x);
    if (x != 0)
    {
      if (x < 0)
        flag = -1; // flag 에 음수/양수 구분해 저장
      pq.push(make_pair(abs(x), flag));
    }
    if (x == 0)
    {
      if (pq.empty() == false)
      {
        int value = pq.top().first * pq.top().second; // 출력할 때 다시 +- 를 붙여서 출력해준다.
        printf("%d\n", value);
        pq.pop();
      }
      else
        printf("0\n");
    }
  }
  return 0;
}