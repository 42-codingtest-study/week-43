#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

int main() {
  fast;
  // pair<int, bool>로 구성된 최소 힙
  priority_queue<pair<int, bool>, vector<pair<int, bool> >,
                 greater<pair<int, bool> > >
      pq;
  pair<int, bool> element;  // <절대값, 원래 값의 부호>를 저장할 변수
  int N, tmp;
  cin >> N;

  while (N--) {  // N번의 연산을 수행
    cin >> tmp;  // 값 입력받기
    // 원소를 추가할 때, 절대값과 원래 값의 부호를 pair에 저장
    element = make_pair(tmp < 0 ? -1 * tmp : tmp, tmp >= 0);
    if (tmp == 0) {  // 입력받은 값이 0인 경우
      if (pq.empty())
        cout << "0\n";  // 큐가 비어있으면 0 출력
      else {
        // 큐에서 절대값이 가장 작은 값을 출력하고 제거
        cout << (pq.top().second ? pq.top().first : -1 * (pq.top().first))
             << "\n";
        pq.pop();
      }
    } else
      pq.push(element);  // 0이 아닌 경우, 값 추가
  }
}
