#include <iostream>
#include <vector>
using namespace std;
// 최대 500만개를 정렬한다. N^2은 시간 초과가 예상되므로 nlogn 으로 해결되어야
// 함
// 퀵 정렬

void swap(vector<int> &vec, int s, int e) {
  int tmp = vec[s];
  vec[s] = vec[e];
  vec[e] = tmp;
}

int partition(vector<int> &vec, int s, int e) {
  if (s + 1 == e) {  // 데이터가 두 개인 경우
    if (vec[s] > vec[e]) {
      swap(vec, s, e);  // 정렬
    }
    return e;
  }
  int mid = (s + e) / 2;  // 데이터가 세 개 이상인 경우
  swap(vec, s, mid);  // 첫 번째 데이터와 중간에 위치한 데이터를 교환
  int pivot = vec[s];  // 피벗은 첫 번째 데이터
  int left = s + 1;    // 왼쪽 출발 지점
  int right = e;       // 오른쪽 출발 지점

  while (left <= right) {
    while (left <= e && pivot >= vec[left]) left++;
    while (right >= s + 1 && pivot <= vec[right]) right--;
    if (left <= right) swap(vec, left, right);
  }
  swap(vec, s, right);
  return right;
}

void quickSort(vector<int> &vec, int s, int e, int k) {
  int pivot = partition(vec, s, e);

  if (pivot == k) {
    // cout << vec[pivot] << endl;
    printf("%d\n", vec[pivot]);
    return;
  } else if (pivot > k) {
    quickSort(vec, s, pivot - 1, k);
  } else {
    quickSort(vec, pivot + 1, e, k);
  }
}
int main() {
  //   ios_base::sync_with_stdio(false);
  //   cin.tie(NULL);
  //   cout.tie(NULL);
  int n, k;
  //   cin >> n >> k;
  scanf("%d %d", &n, &k);

  vector<int> vec(n);

  //   for (int i = 0; i < n; i++) cin >> vec[i];
  for (int i = 0; i < n; i++) scanf("%d", &vec[i]);
  quickSort(vec, 0, n - 1, k - 1);
}

// 시간초과...