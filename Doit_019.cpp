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
  int N, K, tmp;
  vector<int> v;
  cin >> N >> K;
  // N개의 정수 입력받기
  while (N--) {
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());  // 벡터를 오름차순으로 정렬
  cout << v[K - 1];          // K번째로 작은 수 출력
}
