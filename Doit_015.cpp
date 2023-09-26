#include <iostream>

using namespace std;

//1000개의 입력에 시간제한은 1초이기 때문에, O(N^2) 으로 풀어도 시간여유로움.
// 버블정렬로 풀어보장~

int main()
{
  int n;
  int arr[1002];

  cin>>n;
  for (int i = 0; i < n; i++)
    cin>>arr[i];
  
  for (int i = 0; i < n-1; i++)
  {
    for (int j = 0; j < n-1; j++)
    {
      if (arr[j] > arr[j+1])
      {
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout<<arr[i] << "\n";
  return 0;
}