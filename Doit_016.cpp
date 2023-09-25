#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// swap이 일어나지 않은 루프 찾기 -> 정렬이 완료이다
//  500,000이라 버블로 풀면 시간 초과
//  인덱스 차이 이용하기
int main() {
  int n;
  cin >> n;

  vector<pair<int, int> > vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i].first;
    vec[i].second = i;  // 인덱스 저장
  }
  sort(vec.begin(), vec.end());  // -> sort nlogn(O)
  int max = 0;

  for (int i = 0; i < n; i++) {
    if (max < vec[i].second - i)
      max = vec[i].second - i;  // 정렬 전 인덱스에서 정렬 후 인덱스
  }
  cout << max + 1;
}