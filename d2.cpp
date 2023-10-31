#include <iostream>
#include <vector>
using namespace std;

void arrange(vector<int> &arr1, vector<int> &arr2, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr1[i] > arr1[j]) {
                swap(arr1[i], arr1[j]);
                swap(arr2[i], arr2[j]);
            }
        }
    }
}

int main() {
    vector<int> start = {1, 3, 0, 8};
    vector<int> end = {5, 4, 6, 9};
    int n = start.size();

    arrange(start, end, n);

    int current_start = start[0];
    int current_end = end[0];

    for (int i = 1; i < n; i++) {
        if (start[i] <= current_end) {
            current_end = max(current_end, end[i]);
            
        } else {
            cout << current_start << " " << current_end << endl;
            current_start = start[i];
            current_end = end[i];
        }
    }

    cout << current_start << " " << current_end << endl;

    return 0;
}
