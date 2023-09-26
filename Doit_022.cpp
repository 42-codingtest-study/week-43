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
  int N, tmp, arr[10001];  // N은 숫자의 개수, tmp는 입력받은 숫자를 임시 저장,
                           // arr는 각 숫자의 빈도수를 저장
  memset(arr, 0, sizeof(arr));  // arr 배열 0으로 초기화

  cin >> N;  // 숫자의 개수 입력받기
  for (int i = 0; i < N; i++) {
    cin >> tmp;  // 숫자 하나씩 입력받기
    arr[tmp]++;  // 입력받은 숫자의 빈도수 증가
  }
  for (int i = 0; i < 10001; i++)            // 0부터 10000까지 순회
    while (arr[i]-- > 0) cout << i << "\n";  // 각 숫자를 그 빈도수만큼 출력
}
