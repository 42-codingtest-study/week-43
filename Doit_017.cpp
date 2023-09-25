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
  int nums[10], N;
  memset(nums, 0, sizeof(nums));
  cin >> N;
  // N의 각 자리수의 등장 횟수 계산
  while (N >= 10) {
    nums[N % 10]++;  // 마지막 자리수의 등장 횟수 증가
    N /= 10;         // 마지막 자리수 제거
  }
  nums[N]++;  // 마지막 남은 자리수의 등장 횟수 증가
  // 등장 횟수에 따라 내림차순으로 출력
  for (int i = 9; i >= 0; i--)        // 9부터 0까지 순회
    while (nums[i]-- > 0) cout << i;  // 각 숫자를 등장 횟수만큼 출력
}
