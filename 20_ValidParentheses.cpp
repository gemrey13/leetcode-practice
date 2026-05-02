#include <iostream>
#include <vector>

class Solution
{
public:
    bool isValid(std::string s)
    {
    }
};

int main()
{
    std::string testCase1 = "()";     // true
    std::string testCase1 = "()[]{}"; // true
    std::string testCase1 = "(]";     // false
    std::string testCase1 = "([])";   // true
    std::string testCase1 = "([)]";   // false

    Solution solution;
    return 0;
}
