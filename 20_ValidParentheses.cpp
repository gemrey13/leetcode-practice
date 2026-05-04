#include <iostream>
#include <vector>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::vector<char> paretheses;
        for (char c : s)
        {
            if (c == '{' || c == '[' || c == '(')
            {
                paretheses.emplace_back(c);
            }
            else
            {
                if (paretheses.empty())
                    return false;

                char top = paretheses.back();

                if (c == ')' && top == '(' ||
                    c == ']' && top == '[' ||
                    c == '}' && top == '{')
                {
                    paretheses.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }

        return paretheses.empty();
    }
};

int main()
{
    std::string testCase1 = "()";     // true
    std::string testCase2 = "()[]{}"; // true
    std::string testCase3 = "(]";     // false
    std::string testCase4 = "([])";   // true
    std::string testCase5 = "([)]";   // false
    std::string testCase6 = "]";      // false
    std::string testCase7 = "(){}}{"; // false
    std::string testCase8 = "(])";    // false

    Solution solution;

    bool result1 = solution.isValid(testCase1);
    std::cout << "The result is 1 - " << result1 << '\n'; // true

    bool result2 = solution.isValid(testCase2);
    std::cout << "The result is 2 - " << result2 << '\n'; // true

    bool result3 = solution.isValid(testCase3);
    std::cout << "The result is 3 - " << result3 << '\n'; // true

    bool result4 = solution.isValid(testCase4);
    std::cout << "The result is 4 - " << result4 << '\n'; // true

    bool result5 = solution.isValid(testCase5);
    std::cout << "The result is 5 - " << result5 << '\n'; // true

    bool result6 = solution.isValid(testCase6);
    std::cout << "The result is 6 - " << result6 << '\n'; // true

    bool result7 = solution.isValid(testCase7);
    std::cout << "The result is 7 - " << result7 << '\n';
    ; // false

    bool result8 = solution.isValid(testCase8);
    std::cout << "The result is 8 - " << result8; // false
    return 0;
}

/*
The result is 1 - 1
The result is 2 - 1
The result is 3 - 0
The result is 4 - 1
The result is 5 - 0
The result is 6 - 0
The result is 7 - 0
The result is 8 - 0
*/