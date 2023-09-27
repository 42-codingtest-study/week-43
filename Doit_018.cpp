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
  vector<int> v;
  cin >> N;
  // N개의 정수 입력받기
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());  // 벡터를 오름차순으로 정렬
  // 각 숫자까지의 누적합을 구하기
  for (int i = 1; i < N; i++) v[i] += v[i - 1];
  // 누적합들의 총합을 구하기
  for (int i = 0; i < N; i++) answer += v[i];
  cout << answer;  // 총합 출력
}
