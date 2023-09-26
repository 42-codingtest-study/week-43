#include <iostream>

using namespace std;

//n 이 1000000000 이지만, 결국 10자리 숫자를 정렬하는 것이기 때문에
//시간복잡도는 고려할 필요가 없다.
// 뭐로 정렬하는지 기억안나서 O(n^2) 의 선택정렬로 해봄.

int main()
{
  string n;
  int arr[11];
  cin>>n;
  for (int i = 0; i < n.size(); i++)
    arr[i] = n[i]-'0';

  for (int i = 0; i < n.size(); i++)
  {
    int maximumIdx = i;
    for (int j = i; j < n.size(); j++)
    {
      if (arr[maximumIdx] < arr[j])
        maximumIdx = j;
    }
    int tmp = arr[i];
    arr[i] = arr[maximumIdx];
    arr[maximumIdx] = tmp;
  }

  for (int i = 0; i < n.size(); i++)
    cout<<arr[i];
  return 0;
}