// Heapify Up
// Heapify Down
// Insert
// Delete at specific index (USING BOTH heapifyUp & heapifyDown)

#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int heap[MAX];
int heapSize = 0;
// Heapify Up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
// Heapify Down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;
    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}
// Insert
void insert(int val) {
    if (heapSize == MAX) return;
    heap[heapSize] = val;
    heapifyUp(heapSize);
    heapSize++;
}
// Delete at specific index (USING BOTH heapifyUp & heapifyDown)
void deleteAtIndex(int i) {
    if (i < 0 || i >= heapSize) {
        cout << "Invalid index\n";
        return;
    }
    heap[i] = heap[heapSize - 1];
    heapSize--;
    heapifyUp(i);
    heapifyDown(i);
}

int main() {
    insert(2);
    insert(4);
    insert(6);
    insert(1);
    cout << "Heap: ";
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    int idx;
    cout << "\nEnter index to delete: ";
    cin >> idx;
    deleteAtIndex(idx);
    cout << "Heap after deletion: ";
    for (int i = 0; i < heapSize; i++)
        cout << heap[i] << " ";
    return 0;
}