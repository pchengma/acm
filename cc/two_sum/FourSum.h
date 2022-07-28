// LeetCode: 18. 4Sum (Medium)
class FourSum {
public:
    vector <vector<int>> fourSum(vector<int> &nums, int target) {

        int i, j, left, right, n = nums.size();

        vector <vector<int>> result;

        if (n < 4 || nums.empty()) {
            return result;
        }

        sort(nums.begin(), nums.end());

        for (i = 0; i < n - 3; i++) {
            long long int target_3 = target - nums[i];

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (j = i + 1; j < n - 2; j++) {
                long long int target_2 = target_3 - nums[j];

                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                if (nums[j + 1] + nums[j + 2] > target_2) {
                    break;
                }

                if (nums[n - 2] + nums[n - 1] < target_2) {
                    continue;
                }

                left = j + 1;
                right = n - 1;
                while (left < right) {
                    int two_sum = nums[left] + nums[right];
                    if (two_sum < target_2) {
                        left++;
                    } else if (two_sum > target_2) {
                        right--;
                    } else {
                        result.push_back(vector < int > {nums[i], nums[j], nums[left], nums[right]});

                        int presentLeft = nums[left], presentRight = nums[right];

                        do {
                            left++;
                        } while (nums[left] == presentLeft && left < right);

                        do {
                            right--;
                        } while (nums[right] == presentRight && left < right);
                    }
                }
            }

        }
        return result;
    }
};