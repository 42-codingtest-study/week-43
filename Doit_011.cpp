#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//대놓고 스택 쓰라고 알려줌.
//Yes/No 여부를 스택에 넣다뺐다 하기전에 먼저 알 수 있는지,
// 배열에 저장해 가다가 불가능해지면 그때 NO 출력하고 끝내야 하는지 생각해봄.
// 저장 해놓고 마지막에 출력하자!
int n;
stack<int> s;
//vector<char> ans;
string ans;
int main()
{
  cin>>n;

  int cur = 0;
  //for (int i = 0; i < n; i++)
  while(n--)
  {
    int x;
    cin>>x;
    if (x > cur)
    {
      while(x > cur)  //뽑아야 하는 수가 현재 cur 보다 크면 x까지 push 한다음에 pop
      {
        s.push(++cur);
        ans += '+';
      }
      s.pop();
      ans += '-';
    }
    else
    {
      bool found = false;
      if (!s.empty()) 
      {
        if(x == s.top())  //뽑을 수가 이미 top에 있으면
        {
          found = true;
        }
        s.pop();
        ans += '-';
      }
      if (!found)
      {
        cout<<"NO\n";
        return 0;
      }
    }
    
  }
  for (int i = 0; i < ans.size(); i++)
  {
    cout<<ans[i] << "\n";
  }
    
  return 0;
}