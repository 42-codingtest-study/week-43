#include <algorithm>
#include <iostream>
#include <vector>

// 선택 정렬O(N^2)
// 10자리
// 배열의 크기가 최대 10인 정렬 문제라 단순하게 구현이 가능한 선택 정렬 사용
// 선택 정렬이란, N-1번부터 1번까지의 자리에 대하여 해당 자리에 넣어야 하는
// 원소를 선택하는 알고리즘이다.
using namespace std;

int main() {
  string n;
  cin >> n;

  vector<int> vec(n.size());

  for (int i = 0; i < n.size(); i++) {
    vec[i] = n[i] - '0';
  }

  //   for (int i = 0; i < vec.size(); i++) {
  //     cout << vec[i] << std::endl;
  //   }

  int idx = 0;
  for (int i = 0; i < vec.size(); i++) {
    idx = i;
    for (int j = i + 1; j < vec.size(); j++) {  // 1 3 2 4
      if (vec[idx] < vec[j]) idx = j;  // 내림 차순일 때 최대값
    }

    int temp = vec[idx];
    vec[idx] = vec[i];
    vec[i] = temp;
  }

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
  }
  cout << "\n";
}