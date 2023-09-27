#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long

int main() {
  fast;
  int N, tmp;
  vector<int> v;
  cin >> N;
  // N개의 정수 입력받기
  while (N--) {
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());  // 벡터를 오름차순으로 정렬
  for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";  // 출력
}

//Doti 조금 불편해요ㅋㅋ
