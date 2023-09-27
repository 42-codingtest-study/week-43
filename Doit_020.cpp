#include <iostream>
#include <vector>

using namespace std;
// 병합 정렬 -> O(nlog)

static vector<int> vec;
static vector<int> tmp;

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
    if (tmp[i] <= tmp[j]) {
      vec[k++] = tmp[i++];
    } else {
      vec[k++] = tmp[j++];
    }
  }

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

  merge_sort(1, n);  // 병합 정렬

  for (int i = 1; i <= n; i++) {
    cout << vec[i] << "\n";
  }
}
