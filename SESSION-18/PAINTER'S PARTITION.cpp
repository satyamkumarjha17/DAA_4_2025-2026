/*                    <<<---PAINTER'S PARTITION GFG  ---<<<
class Solution {
public:
    bool canPaint(vector<int>& arr, int k, int maxTime) {
        int painters = 1;
        long long currSum = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(currSum + arr[i] <= maxTime) {
                currSum += arr[i];
            } else {
                painters++;
                currSum = arr[i];
            }
        }
        return painters <= k;
    }

    int minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = high;

        while(low <= high) {
            long long mid = (low + high) / 2;

            if(canPaint(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};




/* DRY RUN EXAMPLE
Input:
arr = [10, 20, 30, 40]
k = 2
Step 1: Range
low = max = 40
high = sum = 100

Iteration 1
mid = (40 + 100) / 2 = 70
Try max time = 70

Painter 1:
10 + 20 + 30 = 60
Next 40 → exceeds 70

Painter 2:
40
Painters used = 2 RIGHT
So 70 possible

Update:
ans = 70
high = 69

Iteration 2
mid = (40 + 69) / 2 = 54
Try 54
Painter 1:
10 + 20 = 30
+30 → 60 WRONG exceeds

Painter 2:
30
+40 → 70 WRONG

Painter 3:
40

Painters used = 3 WRONG (need ≤2)
So not possible
Update:
low = 55

Iteration 3
mid = (55 + 69) / 2 = 62

Try 62

Painter 1:
10+20+30 = 60
+40 WRONG

Painter 2:
40 RIGHT

Painters used = 2 

Update:
ans = 62
high = 61

Continue...

Final Answer:
60
*/