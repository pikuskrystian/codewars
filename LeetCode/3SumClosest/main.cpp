class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];  // Initialize with the first three elements

        // Step 2: Iterate through the array
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            // Step 3: Use two pointers to find the closest sum
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // Update closestSum if the current sum is closer to the target
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                // Move pointers based on the comparison with the target
                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    // If the sum matches the target exactly, return it
                    return currentSum;
                }
            }
        }

        return closestSum;
    }
};

