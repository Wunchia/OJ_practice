#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 1. 两数之和
namespace lc1 {
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 数值 -> 下标
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i) {
            int need = target - nums[i];

            // 先找需要的数，避免把当前元素和自己配对
            if (seen.count(need)) {
                return {seen[need], i};
            }

            seen[nums[i]] = i;
        }

        return {}; // 题目保证有答案，实际不会走到这里
    }
};
}

// 3. 无重复字符的最长子串
namespace lc3 {
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 字符 -> 上次出现的下标
        unordered_map<char, int> last;
        int left = 0;
        int answer = 0;

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];

            if (last.count(c)) {
                // left 只能向右移动，不能退回去
                left = max(left, last[c] + 1);
            }

            last[c] = right;
            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};
}

// 20. 有效的括号
namespace lc20 {
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        return st.empty(); // 防止还有未配对的左括号
    }
};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    vector<int> indices = lc1::Solution().twoSum(nums, 9);
    cout << "两数之和: " << indices[0] << ", " << indices[1] << '\n';

    cout << "最长无重复子串: "
         << lc3::Solution().lengthOfLongestSubstring("abcabcbb") << '\n';

    cout << boolalpha;
    cout << "有效的括号: "
         << lc20::Solution().isValid("({[]})") << '\n';
}