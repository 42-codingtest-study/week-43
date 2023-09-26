#include <iostream>
#include <vector>

using namespace std;

static vector<int> vec;
static vector<int> tmp;
static long cnt = 0;

void merge_sort(int start, int end) {
  if (end - start < 1) return;

  int mid = (start + end) / 2;
  merge_sort(start, mid);
  merge_sort(mid + 1, end);

  for (int i = start; i <= end; i++) tmp[i] = vec[i];

  int k = start;
  int i = start;
  int j = mid + 1;

  while (i <= mid && j <= end) {
    if (tmp[i] > tmp[j]) {
      vec[k] = tmp[j];
      cnt = cnt + (mid - i + 1);  // 이동 거리 계산
      k++;
      j++;
    } else {
      vec[k++] = tmp[i++];
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

  cnt = 0;
  merge_sort(1, n);

  cout << cnt << "\n";

  return 0;
}
