#include <iostream>

class Solution
{
public:
    bool getRomanValue(char search)
    {
        char romanTable[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

        for (char c : romanTable)
        {
            if (c == search)
            {
                return true;
            }
        }

        return false;
    }

    int romanToInt(std::string s)
    {
        int length = s.length();

        if (length < 1)
            return 0;
        if (length > 15)
            return 0;
        int result = 0;
        for (int i = 0; i < length; i++)
        {
            bool isRoman = getRomanValue(s[i]);

            if (!isRoman)
                return 0;

            switch (s[i])
            {
            case 'V':
                result += 5;
                break;
            case 'L':
                result += 50;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            case 'I':
                if (s[i + 1] == 'V')
                {
                    result += 4;
                    i++;
                }
                else if (s[i + 1] == 'X')
                {
                    result += 9;
                    i++;
                }
                else
                {
                    result += 1;
                }
                break;
            case 'X':
                if (s[i + 1] == 'L')
                {
                    result += 40;
                    i++;
                }
                else if (s[i + 1] == 'C')
                {
                    result += 90;
                    i++;
                }
                else
                {
                    result += 10;
                }
                break;
            case 'C':
                if (s[i + 1] == 'D')
                {
                    result += 400;
                    i++;
                }
                else if (s[i + 1] == 'M')
                {
                    result += 900;
                    i++;
                }
                else
                {
                    result += 100;
                }
                break;
            }
        }
        return result;
    };
};

int main()
{
    Solution solution;
    std::string testCases[] = {"III", "LVIII", "MCMXCIV", "D"};

    int index = 0;
    for (std::string test : testCases) {
        index++;
        int result = solution.romanToInt(test);
        std::cout << "Test case #" << index << std::endl;
        std::cout << test << std::endl;
        std::cout << "Output: " << result << "\n\n";
    }

    return 0;
}


/* 
    int romanToInt(std::string s) {
        int res = 0;
        std::unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for (int i = 0; i < s.size() - 1; i++) {

            // scanning two roman then if the left is less than the right roman it subtract
            if (roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            } else {
                res += roman[s[i]];
            }
        }
                        // this is a last value
        return res + roman[s[s.size() - 1]];        
    }
*/