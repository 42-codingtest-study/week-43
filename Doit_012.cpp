#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int n;
stack<int> s;
int ans[1000001];
int seq[1000001];
//스택써서 맨 뒤에서부터 내려오면서 현재 stack 의 top 과 지금 보고 있는 인덱스를 확인한다.
//지금 스택의 탑이 지금 인덱스보다 클때가지 pop 해줌


int main()
{
  cin>>n;
  for (int i = 0; i < n; i++)
    cin>>seq[i];
  for (int i = n; i >= 0; i--)
  {
    while( !s.empty() && s.top() <= seq[i])
      s.pop();
    if (s.empty()== true)
      ans[i] = -1;
    else 
      ans[i] = s.top();
    s.push(seq[i]);

  }
  for (int i = 0; i  <n; i++)
    cout<<ans[i] << " ";
  return 0;
}