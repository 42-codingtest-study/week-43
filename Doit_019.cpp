#include <stdio.h>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSelect(vector<int>& arr, int low, int high, int k) {
    while (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        }
        else if (pivotIndex > k - 1) {
            high = pivotIndex - 1;
        }
        else {
            low = pivotIndex + 1;
        }
    }

    return -1; // Error case, should not reach here
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int kthSmallest = quickSelect(arr, 0, n - 1, k);
    printf("%d\n", kthSmallest);

    return 0;
}
