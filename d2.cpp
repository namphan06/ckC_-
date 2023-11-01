#include <iostream>
#include <vector>
using namespace std;

void sortsd(vector<int> &vt1, vector<int> &vt2) {
    for (int i = 0; i < vt1.size(); i++) {
        for (int j = i + 1; j < vt1.size(); j++) {
            if (vt1[i] > vt1[j]) {
                swap(vt1[i], vt1[j]);
                swap(vt2[i], vt2[j]);
            }
        }
    }
}

int main() {
    vector<int> start = {1, 3, 0, 8, 8};
    vector<int> end = {5, 4, 3, 10, 9};
    sortsd(start, end);
    int st = start[0];
    int ed = end[0];
    for (int i = 0; i < start.size() - 1; i++) {
        if (ed < end[i]) {
            ed = end[i];
        }
        if (start[i + 1] > end[i]) {
            cout << "start : " << st << "\t" << "end : " << ed << endl;
            st = start[i + 1];
        }
    }
    cout << "start : " << st << "\t" << "end : " << ed << endl;
    return 0;
}
