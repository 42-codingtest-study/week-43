#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n; // 1000
    cin >> n;
    int tmp;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> vec[i];
        // vec.push_back(number);
        // cout << vec[i];
    }
    // for (int i = 0; i < n; i++)
    //     cout << vec[i] << "\n";

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                tmp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << vec[i] << "\n";
}
