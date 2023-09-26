#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
// 문제에서 리스트의 앞에서 빼고 뒤에 넣는 과정이 있기 때문에 스택,큐,디큐 중 디큐를 선택함

int main()
{
  int n;
  // 실제 디큐에 값을 넣어놓고 빼면서 구해야하나 고민하기.
  //  넣어두고 빼는게 직관적으로 쉽기 때문에 일단 디큐를 만들었다.
  cin >> n;
  for (int i = n; i >= 1; i--)
    dq.push_front(i);

  while (dq.size() > 1)
  {
    dq.pop_front();
    if (dq.size() == 1)
    {
      cout << dq.front();
      return 0;
    }
    int top = dq.front();
    dq.pop_front();
    dq.push_back(top);
  }

  return 0;
}