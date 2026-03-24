/*                           <<---Heapify--->>
We need to find the K-th highest score as numbers keep coming. 
Basically we need to maintain the Top K largest numbers seen so far.
The smallest number in this "Top K" group is the K-th highest overall.

So I used a Min-Heap of size K:
1. Min heap keeps the smallest element at the top.
2. If heap has < K elements -> just add the new score.
3. If heap is full (size K) -> compare new score with top (smallest).
   - If new score > top, remove top and add new score.
   - If new score is small, ignore it.
4. If heap size < K output is -1, else output the top element.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int K, N;
    
    cout << "Enter K: ";
    cin >> K;
    cout << "Enter N: ";
    cin >> N;

    
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout << "Enter scores as per you:" << endl;
    for (int i = 0; i < N; i++) {
        int score;
        cin >> score;

        if (minHeap.size() < K) {
            minHeap.push(score);
        } else {
            
            if (score > minHeap.top()) {
                minHeap.pop();
                minHeap.push(score);
            }
        }

        if (minHeap.size() < K) {
            cout << "-1" << endl;
        } else {
            cout << minHeap.top() << endl;
        }
    }

    return 0;
}