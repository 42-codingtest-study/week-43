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
  while (N--) {
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
}
