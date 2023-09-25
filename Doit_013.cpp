#include <iostream>
#include <queue>
using namespace std;
// 큐 -> 제일 처음에 넣은 데이터가 처음으로 빠져 나옴
// 스택이랑 다르게 프론트 백 접근 가능
int main()
{
    int n;
    cin >> n;

    queue<int> card;
    for (int i = 1; i <= n; i++)
        card.push(i);

    while (card.size() > 1)
    {
        card.pop();
        card.push(card.front());
        card.pop();
    }
    cout << card.front();
}