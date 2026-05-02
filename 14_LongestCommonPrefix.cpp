#include <iostream>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        if (strs.empty()) return "";

        std::string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0){ 
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }

        }

        return prefix;
    }
};

int main()
{
    std::vector<std::string> testCases1 = {"flower", "flow", "flight", "flpp"};
    std::vector<std::string> testCases2 = {"dog", "racecar", "car"};

    Solution solution;


    std::cout << "Result 1: ";
    std::cout << solution.longestCommonPrefix(testCases1) << std::endl;
    std::cout << "Result 2: ";
    std::cout << solution.longestCommonPrefix(testCases2) << std::endl;

    return 0;
}
