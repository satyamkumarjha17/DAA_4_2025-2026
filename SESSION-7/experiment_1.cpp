#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;


long long operations = 0;
int maxDepth = 0;

void complexRec(int n, int depth) {
    maxDepth = max(maxDepth, depth);

    if (n <= 2) return;

    int p = n;
    while (p > 0) {
        for (int i = 0; i < n; i++) {
            operations++;
        }
        p = p / 2;
    }

    for (int i = 0; i < n; i++) {
        operations++;
    }

    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {
    cout<<"Recurrence Relation: 3T(n/2) + O(nlogn)"<<endl;
    cout<<"Time Complexity: O(n^log(3)) = O(n^1.58)"<<endl;
    vector<int> inputs = {100, 200, 400, 800};

    for (int n : inputs) {
        operations = 0;
        maxDepth = 0;

        auto start = high_resolution_clock::now();
        complexRec(n, 1);
        auto end = high_resolution_clock::now();

        auto timeTaken = duration_cast<milliseconds>(end - start).count();

        cout << "n = " << n << endl;
        cout << "Operations = " << operations << endl;
        cout << "Recursion Depth = " << maxDepth << endl;
        cout << "Time Taken = " << timeTaken << " ms" << endl;
        
    }

    
    
}
/*sample output:
    Recurrence Relation: 3T(n/2) + O(nlogn)
Time Complexity: O(n^log(3)) = O(n^1.58)
n = 100
Operations = 8951
Recursion Depth = 7
Time Taken = 0 ms
n = 200
Operations = 28653
Recursion Depth = 8
Time Taken = 0 ms
n = 400
Operations = 89959
Recursion Depth = 9
Time Taken = 0 ms
n = 800
Operations = 278677
Recursion Depth = 10
Time Taken = 0 ms*/