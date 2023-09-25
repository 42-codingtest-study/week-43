#include <iostream>
#include <queue>
using namespace std;

// N의 최대 범위 100000
// 데이터가 들어올 때 마다 정렬 필요함
// 우선순위 큐로 문제 풀기

struct compare {
  bool operator()(int op1, int op2) {
    int first = abs(op1);
    int second = abs(op2);

    if (first == second)  // 절대값이 같을 때
      return op1 > op2;   // 음수
    else
      return first > second;
  }
};

int main() {
  int n;
  cin >> n;
  // 우선순위 큐 -> 우선순위가 높은 데이터가 먼저 나오는 것
  priority_queue<int, vector<int>, compare> queue;
  for (int i = 0; i < n; i++) {
    int number;
    cin >> number;

    if (number == 0) {
      if (queue.empty())
        cout << "0\n";  // 배열이 비어 있는 경우인데 절댓값이 가장 작은 값을
                        // 출력하라고 한 경우에는 0을 출력하면 된다
      else {
        cout << queue.top() << "\n";
        queue.pop();
      }
    } else
      queue.push(number);
  }
}