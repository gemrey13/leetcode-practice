#include <iostream>
#include <string>
#include <ranges>
#include <vector>

class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        auto split_view = s | std::views::split(' ');

        std::vector<std::string> trimWords;

        for (const auto word : split_view)
        {
            std::string_view sv{word.begin(), word.end()};

            if (!sv.empty())
            {
                trimWords.emplace_back(sv);
            }
        }
        return trimWords.back().length();
    }
};

int main()
{
    std::string s1 = "Hello World";
    std::string s2 = "   fly me   to   the moon  ";
    std::string s3 = "luffy is still joyboy";

    Solution solution;

    int result1 = solution.lengthOfLastWord(s1);
    std::cout << "The result for test case 1 -> " << result1 << '\n';

    int result2 = solution.lengthOfLastWord(s2);
    std::cout << "The result for test case 2 -> " << result2 << '\n';

    int result3 = solution.lengthOfLastWord(s3);
    std::cout << "The result for test case 3 -> " << result3 << '\n';

    return 0;
}
