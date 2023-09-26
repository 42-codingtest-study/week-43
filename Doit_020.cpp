#include <stdio.h>

#include <string.h>
using namespace std;

// 입력 백만, 시간은 2초기 때문에 O(n^2) 못씀.
//  O(nlogn) 을 사용한다. -> 병합정렬 해볼게용

int n;
int arr[1000002];
int tmp[1000002];

void merge(int start, int mid, int end)
{
  // memcpy(tmp + start, arr + start, (end - start + 1) * sizeof(int));
  // 이거 안하기. tmp 를 전역변수로 만들어 써먹기
  int pointer1 = start;
  int pointer2 = mid + 1;
  int idx = start;

  while (pointer1 <= mid && pointer2 <= end)
  {
    if (arr[pointer1] <= arr[pointer2])
      tmp[idx++] = arr[pointer1++];
    else
      tmp[idx++] = arr[pointer2++];
  }

  if (pointer2 > end) //만약 2번째 포인터가 끝까지 간거면, 포인터1 즉 앞쪽 절반이 남은거니 남은걸 배열 이후에 차곡차곡 넣어준다.
  {
    while (pointer1 <= mid)
      tmp[idx++] = arr[pointer1++];
  }
  else
  {
    while (pointer2 <= end)
      tmp[idx++] = arr[pointer2++];
  }
  for (int i = start; i <= end; i++)
    arr[i] = tmp[i];
}

void mergeSort(int start, int end)
{
  if (start < end)
  {
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, mid, end);
  }
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  mergeSort(0, n - 1);

  for (int i = 0; i < n; i++)
    printf("%d\n", arr[i]);
  
  return 0;
}