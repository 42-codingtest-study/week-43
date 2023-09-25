#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;
// 시간 제한 2초

int main()
{
    int n;
    cin >> n;

    stack<int> stack;
    vector<char> result;

    int num = 1;
    for (int i = 0; i < n; i++)
    {
        int now;
        cin >> now;
        // 스택이 비어있지 않고 스택에 제일 최근에 들어간 값이 빼야 하는 숫자와 같으면 빼기
        if (num <= now)
        {
            // 현재 수열 값 >= 수 인 경우 수를 ++ 하면서 수를 스택에 넣고
            while (num <= now)
            {
                stack.push(num++);
                result.push_back('+');
            }
            // 수열이 끝나면 숫자 빼기
            stack.pop();
            result.push_back('-');
            // 제일 위에 있는 값이 현재 들어가야 하는 값 보다 크면 ex) 5가 들어가 있는데 빼야 하는 숫자는 3
        }
        else if (!stack.empty() && stack.top() == now)
        {
            stack.pop();
            result.push_back('-');
        }
        else if (!stack.empty() && stack.top() > now) // 세그폴트가 뜸 스택이 비어있는 경우가 있을 수도 있음
        {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n"; // endl 보다 개행 입력이 빠름
    }
    return 0;
}
