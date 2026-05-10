#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long

signed main(){
    int N, S; cin >> N >> S;
    vector<int> arr(N);
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 1'000'000'000'000'000'000;
    for (int i = 0; i < N; i++){
        int rest_student = N - i; // 현재 학생을 포함하여 남은 학생
        int t = rest_student * arr[i];
        if (t < S){ // 공부 시간이 부족
            S -= arr[i]; // 현재 학생은 최대한 공부함.
        }
        else{
            ans = (S - 1) / rest_student + 1; // 남은 공부 시간에 대해 남은 학생들이 몇 시간을 공부해야하는가?
            break;
        }
    }
    cout << ans;
    return 0;
}
