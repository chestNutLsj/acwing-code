// 数字串的全排列
#include <iostream>
#include <vector>

// 使用描述性注释

// 函数原型声明
void generatePermutations(int n);
void permute(std::vector<int> &nums, int l, int r, std::vector<std::vector<int>> &allPermutations);

int main() {
    int n;
    std::cin >> n;
    generatePermutations(n);
    return 0;
}

// 生成1到n的所有排列并打印
void generatePermutations(int n) {
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    std::vector<std::vector<int>> allPermutations;
    permute(nums, 0, n - 1, allPermutations);

    for (const auto &p : allPermutations) {
        for (int num : p) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

// 使用回溯法生成排列
void permute(std::vector<int> &nums, int l, int r, std::vector<std::vector<int>> &allPermutations) {
    if (l == r) {
        allPermutations.push_back(nums);
    } else {
        for (int i = l; i <= r; i++) {
            std::swap(nums[l], nums[i]);
            permute(nums, l + 1, r, allPermutations);
            std::swap(nums[l], nums[i]); // backtrack
        }
    }
}
