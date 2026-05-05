#include <iostream>
#include <vector>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        int index = haystack.find(needle);

        return index;
    }
};

int main()
{
    std::string haystack1 = "sadbutsad";
    std::string needle1 = "sad";
    std::string haystack2 = "leetcode";
    std::string needle2 = "leeto";
    std::string haystack3 = "hello";
    std::string needle3 = "ll";

    Solution solution;

    int result1 = solution.strStr(haystack1, needle1);
    std::cout << "The result is 1 - " << result1 << '\n';

    int result2 = solution.strStr(haystack2, needle2);
    std::cout << "The result is 2 - " << result2 << '\n';

    int result3 = solution.strStr(haystack3, needle3);
    std::cout << "The result is 3 - " << result3 << '\n';

    return 0;
}
