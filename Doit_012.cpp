#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 시간 제한 1초

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n);
    vector<int> result(n, -1);
    stack<int> stack;
    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    // cout << numbers.size();
    stack.push(0);
    for (int i = 1; i < numbers.size(); i++)
    {
        // 스택이 비어있지 않고 스택에 제일 마지막 값이 비교할 값보다 작을 때
        while (!stack.empty() && numbers[stack.top()] < numbers[i])
        {
            // int index = stack.top();
            result[stack.top()] = numbers[i];
            stack.pop();
        }
        stack.push(i);
    }
    while (!stack.empty())
    {
        result[stack.top()] = -1;
        stack.pop();
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}