#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

int main() {
  fast;
  int n, m, i = 1;
  stack<int> st;
  bool ans = true;
  string answer = "";
  cin >> n;
  while (n--) {
    cin >> m;
    // 스택의 맨 위 값. 하나도 없다면 0
    int topOfStack = st.empty() == true ? 0 : st.top();
    if (topOfStack < m) {
      // 입력되는 값보다 스택의 윗 값이 작다면 값을 추가한다.
      while (i <= m) {
        st.push(i);
        answer += "+\n";
        if (i == m) {
          st.pop();
          answer += "-\n";
        }
        i++;
      }
      // 스택의 윗값이 입력값과 같다면 빼준다
    } else if (topOfStack == m) {
      st.pop();
      answer += "-\n";
      // 조건에 맞지 않을 경우
    } else
      ans = false;
  }
  ans ? cout << answer : cout << "NO";
}
