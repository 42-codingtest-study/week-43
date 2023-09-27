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

int main() {
  fast;
  int N, tmp, answer = 0;
  vector<pair<int, int> > v;  // <값, 원래 인덱스>를 저장할 벡터
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> tmp;
    v.push_back(
        make_pair(tmp, i));  // 값과 원래 인덱스를 pair로 저장해 벡터에 삽입
  }
  sort(v.begin(), v.end());  // 값에 대해 오름차순 정렬
  // 정렬 후의 인덱스와 원래 인덱스의 차이의 최댓값 찾기
  for (int i = 0; i < N; i++) answer = max(answer, v[i].second - i);
  cout << answer + 1;  // 최대 차이 + 1 출력
}
