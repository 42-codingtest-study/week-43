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
  int N, tmp, idx;
  stack<int> st;  // 인덱스를 저장할 스택
  cin >> N;
  int answer[N], lst[N];  // 결과와 입력 배열 초기화
  memset(lst, 0, sizeof(lst));
  for (int i = 0; i < N; i++) answer[i] = -1;  // 결과 배열을 -1로 초기화
  for (int i = 0; i < N; i++) cin >> lst[i];  // 입력 배열 값 받기

  st.push(0);                    // 스택에 첫 번째 인덱스 푸쉬
  for (int i = 1; i < N; i++) {  // 배열의 두 번째 원소부터 비교 시작
    while (!st.empty() && lst[st.top()] < lst[i]) {
      // 스택이 비어있지 않고
      // 스택의 top 인덱스에 해당하는 원소가 현재 원소보다 작을 동안
      answer[st.top()] = lst[i];  // 현재 원소를 결과 배열에 저장
      st.pop();                   // 스택에서 원소 빼기
    }
    st.push(i);  // 현재 인덱스 스택에 푸쉬
  }
  for (int i = 0; i < N; i++) cout << answer[i] << " ";  // 결과 출력
}
