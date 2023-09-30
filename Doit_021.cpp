#include <stdio.h>
#include <string.h>
using namespace std;

int n;
int arr[500002];
int tmp[500002];
long long cnt = 0;
//n이 오십만, 시간제한은 1초라 버블정렬하면 초과가 난다.
//그럼 버블 안하고도 스왑이 몇번일어났는지 알아야한다는건데
//병합정렬에서 스왑하는 횟수랑 버블정렬에서 스왑ㅅ횟수가 같다
//병합정렬에서 값 뒤바꿀때 cnt++ 해주자ㅋㅋ

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
    else {
      tmp[idx++] = arr[pointer2++];
      cnt += pointer2 - idx;
    }
      
  }
  if (pointer2 > end)
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
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n ; i++)
    scanf("%d", &arr[i]);
  mergeSort(0, n-1);
  printf("%lld\n", cnt);
  return 0;
}