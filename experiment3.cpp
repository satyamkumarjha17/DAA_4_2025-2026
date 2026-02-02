/*               <---Experiment–3: Stable Attendance Window--->
--Problem Statement
A university maintains an automated log of attendance activities recorded in order.
Each record represents a student being Present (P) or Absent (A).
A stable attendance window is defined as a continuous period in which:
The number of Present and Absent records are equal.

--Input Format
  Integer N — number of attendance records
  N entries representing attendance status
  P → Present
  A → Absent

--Output Format
  Print a single integer: the maximum length of a stable attendance window
  If no such window exists, print 0
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;

    int sum = 0;
    int maxLen = 0;

    mp[0] = -1;

    for (int i = 0; i < N; i++) {

        if (arr[i] == 'P')
            sum += 1;
        else
            sum -= 1;

        if (mp.find(sum) != mp.end()) {

            int len = i - mp[sum];
            maxLen = max(maxLen, len);

        } else {

            mp[sum] = i;
        }
    }

    cout << maxLen << endl;

    return 0;
}
