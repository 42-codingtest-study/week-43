#include <iostream>
#include <vector>

using namespace std;
// 병합 정렬 -> O(nlog)
// “버블 정렬에서 swap 횟수와 병합정렬에서 원소간의 이동하는 거리는 같다.”
static vector<int> vec;
static vector<int> tmp;
static long cnt = 0;

void merge_sort(int start, int end) {
  if (end - start < 1) return;

  int mid = (start + end) / 2;
  merge_sort(start, mid);
  merge_sort(mid + 1, end);

  for (int i = start; i <= end; i++) tmp[i] = vec[i];  // 복사

  int k = start;
  int i = start;
  int j = mid + 1;

  while (i <= mid && j <= end) {  // 두 그룹 병합 로직 -> 정렬
    if (tmp[i] > tmp[j]) {
      vec[k] = tmp[i];
      cnt = cnt + j - k;  // 이동 거리
      k++;
      j++;
    } else {
      vec[k++] = tmp[j++];
    }
  }
  // 남은 값 넣어주기
  while (i <= mid) vec[k++] = tmp[i++];
  while (j <= end) vec[k++] = tmp[j++];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vec = vector<int>(n + 1, 0);
  tmp = vector<int>(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }

  cnt = 0;
  merge_sort(1, n);  // 병합 정렬

  cout << cnt << "\n";

  //   for (int i = 1; i <= n; i++) {
  // cout << vec[i] << "\n";
  //   }
}
