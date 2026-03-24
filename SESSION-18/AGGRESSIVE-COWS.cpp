/*                   <<<---  AGGRESSIVE COWS  --->>>


class Solution {
public:

    bool canPlace(vector<int>& stalls, int k, int dist) {
        int count = 1; 
        int lastPos = stalls[0];

        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - lastPos >= dist) {
                count++;
                lastPos = stalls[i];
            }
            if(count >= k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int low = 0;
        int high = stalls.back() - stalls.front();
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(canPlace(stalls, k, mid)) {
                ans = mid;
                low = mid + 1;  
            } else {
                high = mid - 1; 
            }
        }

        return ans;
    }
};

/* DRY RUN EXAMPLE
 Input:
stalls = [1, 2, 4, 8, 9]
k = 3
Step 1: Sort the stalls
Already sorted:
[1, 2, 4, 8, 9]

Step 2: Define Binary Search Range
low = 0
high = 9 - 1 = 8
We search maximum minimum distance

Iteration 1
mid = (0 + 8) / 2 = 4
Try placing cows with minimum distance = 4
Place cows greedily:
Place first cow at 1
Next stall ≥ 1 + 4 = 5 → place at 8
Next stall ≥ 8 + 4 = 12 → not possible
Only 2 cows placed (need 3)
So distance 4 is not possible

Update:
high = 3

Iteration 2
mid = (0 + 3) / 2 = 1
Try distance = 1
Place at 1
Place at 2 (2-1 ≥1)
Place at 4 (4-2 ≥1)
3 cows placed 
Distance 1 is possible

Update:
ans = 1
low = 2

Iteration 3
mid = (2 + 3) / 2 = 2
Try distance = 2
Place at 1
Next ≥ 3 → place at 4
Next ≥ 6 → place at 8
3 cows placed 
Distance 2 possible

Update:
ans = 2
low = 3

Iteration 4
mid = (3 + 3) / 2 = 3
Try distance = 3
Place at 1
Next ≥ 4 → place at 4
Next ≥ 7 → place at 8
3 cows placed 
Distance 3 possible

Update:
ans = 3
low = 4

Now:
low = 4
high = 3

Loop ends.
Final Answer: 3
*/