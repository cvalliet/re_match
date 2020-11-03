#include <iostream>
#include <regex>
#include <string>

inline bool test_match(const std::string& expression, const std::string& text)
{
    return std::regex_match(text, std::regex(expression));
}

int main(int argc, char * argv[])
{
    if (3 == argc) {
        bool result = test_match(argv[1], argv[2]);

        if (result)
            std::cout << "Match!\n";

        return (result)? EXIT_SUCCESS: EXIT_FAILURE;
    }

    std::cerr <<
        "\n"
        "Usage:\n"
        "\n"
        " re_match <regular expression> <text to evaluate>\n"
        "\n"
        " Check if the regular expression matches with the given text.\n"
        "\n";

    return EXIT_FAILURE;
}
