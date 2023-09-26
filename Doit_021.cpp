#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

vector<ll> arr;  // 입력받을 수를 저장하는 벡터
// ans는 스왑 횟수, sorted는 정렬된 수를 임시로 저장하는 배열
ll ans = 0, sorted[500001];

// 병합 함수. left부터 mid까지와 mid+1부터 right까지 병합
void merge(int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int k = left;

  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      sorted[k] = arr[i];
      i++;
    } else {
      sorted[k] = arr[j];
      ans += j - k;  // 스왑 횟수 증가
      j++;
    }
    k++;
  }

  // 남아있는 요소들을 sorted에 복사
  if (i > mid)
    for (int x = j; x <= right; x++, k++) sorted[k] = arr[x];
  else
    for (int x = i; x <= mid; x++, k++) sorted[k] = arr[x];

  // sorted에서 원래 배열 arr로 복사
  for (int x = left; x <= right; x++) arr[x] = sorted[x];
}

// 병합 정렬 함수. left부터 right까지 정렬
void merge_sort(int left, int right) {
  if (left >= right) return;      // 분할이 불가능하면 리턴
  int mid = (left + right) >> 1;  // 중앙 값을 계산
  merge_sort(left, mid);          // 왼쪽 부분 배열 정렬
  merge_sort(mid + 1, right);     // 오른쪽 부분 배열 정렬
  merge(left, mid, right);        // 병합
}

int main(void) {
  fast;  // 입출력 속도 향상 설정 활성화

  int n, k;
  cin >> n;  // 수의 개수 입력
  for (int i = 0; i < n; i++) {
    cin >> k;
    arr.push_back(k);  // 수 입력
  }

  merge_sort(0, n - 1);  // 병합 정렬 시작
  cout << ans;           // 스왑 횟수 출력

  return 0;
}
