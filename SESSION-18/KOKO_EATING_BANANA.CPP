/*                       <<---KOKO_EATING_BANANA--->>


class Solution {
public:
    bool canEat(vector<int>& piles, int h, long long k) {
        long long hours = 0;

        for(int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + k - 1) / k;  
        }

        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long ans = high;
        while(low <= high) {
            long long mid = (low + high) / 2;

            if(canEat(piles, h, mid)) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;   
            }
        }
        return ans;
    }
};
*/