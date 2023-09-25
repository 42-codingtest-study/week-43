#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

int main() {
  fast;
  int N;
  bool odd = true;  // 홀수번째인지 여부를 저장하는 변수
  cin >> N;
  deque<int> dq;
  for (int i = 1; i <= N; i++)
    dq.push_back(i);  // 1부터 N까지의 숫자를 덱에 넣기

  while (dq.size() != 1) {  // 덱의 크기가 1이 될 때까지 반복
    if (odd)
      dq.pop_front();  // 홀수번째이면 앞에서부터 숫자를 제거
    else {
      dq.push_back(dq.front());  // 짝수번째이면 앞에 있는 숫자를 뒤로 옮기기
      dq.pop_front();  // 그리고 앞에 있는 숫자 제거
    }
    odd = !odd;  // 홀수번째와 짝수번째를 번갈아 가면서 수행
  }
  cout << dq.front();  // 마지막에 남은 숫자 출력
}
