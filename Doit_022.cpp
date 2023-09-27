#include <iostream>
#include <vector>
using namespace std;
// 기수 정렬은 값을 비교하지 않는 정렬임
// 기수 정렬은 자릿수를 기준으로 정렬하는 방법
// 시간 복잡도는 O(kn)이다. k는 자릿수

// 계수 정렬은 기수 정렬의 일종이다.
// 계수 정렬은 자릿수가 아닌 값 자체를 비교한다.
// 시간 복잡도는 O(n+k)이다. k는 값의 범위

// 시간 초과는 cin, cout을 고쳐서 해결함
int main() {
  int n;
  //   cin >> n;
  scanf("%d", &n);
  //   int count[10001] = {0};
  vector<int> count(10001, 0);
  int num;

  for (int i = 0; i < n; i++) {
    // cin >> num;
    scanf("%d", &num);
    count[num]++;
  }
  for (int i = 0; i <= 10000; i++) {
    if (count[i] != 0) {
      for (int j = 0; j < count[i]; j++) {
        // cout << i << "\n";
        printf("%d\n", i);
      }
    }
  }
}