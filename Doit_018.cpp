#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// ATM
int main() {
  int n, sum = 0;
  cin >> n;

  vector<int> time(n, 0);
  for (int i = 0; i < n; i++) cin >> time[i];

  // 삽입 정렬 - 오름차순 정렬일 때 시간의 합이 가장 짧다
  int temp;
  for (int i = 0; i < n - 1; i++) {
    int j = i;
    while (time[j] > time[j + 1]) {
      temp = time[j];
      time[j] = time[j + 1];
      time[j + 1] = temp;
      j--;
    }
  }

  // 시간의 합 구하기
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) sum += time[j];
  }

  cout << sum << endl;

  return 0;
}
