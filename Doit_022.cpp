// #include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;


/*  이거 걍 기수정렬은 배열 만드는순간부터 메모리 초과???? 시|| 발 */
// //n 이 천만, 시간제한 5초 
// // 머지소트로 하면 메모리가 터짐. -> 천만길이 배열이 두개니까.
// // 기수정렬 시도하기 -> 계수정렬은 입력으로 들어오는 숫자의 자릿수가 짧을 때 고려한다.

// int n;
// int arr[10000001];
// priority_queue<int> pq[10];

// int get_digit(int idx, int number)
// {
//   //number 에서 idx 자릿수를 찾아 리턴
//   int divider = pow(10, idx-1); // 12345 에서 3 찾을거면 idx 가 3, diveder 는 1000
//   number %= divider;
//   int divider2 = pow(10, idx);
//   number /= divider2;
//   return number;
// }

// int main()
// {
//   cin>>n;
//   for (int i = 0; i < n; i++)
//     cin>>arr[i];
  
//   for (int i = 1; i <= 5; i++) //10000이 다섯자리
//   {
//     for (int idx = 0; idx < n; idx++)
//     {
//       //n개의 숫자를 1의 자리 부터 시작해 우선순위큐에 넣는 과정 (우선순위큐라 정렬되어있음.)
//       int digit = get_digit(i, arr[idx]); //현재 arr[idx] 숫자의 i번자릿수가 얼만지 구해옴.
//       pq[digit].push(arr[idx]);
//     }

//     int num = 0;
//     for (int idx = 0; idx < 10; idx++) //pq 0부터 9까지
//     {
//       while(!pq[idx].empty()) //큐마다 작은거 순으로 빼서 arr 다시 만듦.
//       {
//         arr[num++] = pq[idx].top();
//         pq[idx].pop();
//       }
//     }
//   }
//   for (int i = n-1; i >= 0; i--)
//     cout<<arr[i] << "\n";
//   return 0;
// } 


//  << 이건 계수정렬로 만든 코드에염>>
#include <stdio.h>

int n;
int arr[10001];
int main()
{
  scanf("%d", &n);
  
  int tmp;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &tmp);
    arr[tmp]++;
  }
  for (int i = 1; i <= 10000; i++)
  {
    int size = arr[i];
    for (int j = 0; j < size; j++)
      printf("%d\n", i);
  }
  return 0;
}