#include <iostream>
#include <vector>
#include <algorithm>

struct NumberWithIndex {
    int number;
    int index;
};

bool compare(NumberWithIndex a, NumberWithIndex b) {
    return a.number < b.number;
}

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<NumberWithIndex> numsWithIndices;
    
    for (int i = 0; i < nums.size(); ++i) {
        numsWithIndices.push_back({nums[i], i});
    }
    
    std::sort(numsWithIndices.begin(), numsWithIndices.end(), compare);
    
    int left = 0;
    int right = nums.size() - 1;
    
    while (left < right) {
        int sum = numsWithIndices[left].number + numsWithIndices[right].number;
        if (sum == target) {
            return {numsWithIndices[left].index, numsWithIndices[right].index};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    // If no solution is found, return an empty vector or throw an exception.
    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Output: [" << result[0] << ", " << result[1] << "]\n";
    } else {
        std::cout << "No solution found.\n";
    }

    return 0;
}
