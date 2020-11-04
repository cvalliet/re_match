#include <iostream>
#include <regex>
#include <string>

inline bool test_match(const std::string& expression, const std::string& text)
{
    std::smatch sm;
    
    if (std::regex_match(text, sm, std::regex(expression))) {
        std::cout << "Text matches -> ";

        for (auto s: sm)
            std::cout << "[" << s << "]\n";
        
        return true;
    }
    
    return false;
}

int main(int argc, char * argv[])
{
    if (3 == argc)
        return (test_match(argv[1], argv[2]))? EXIT_SUCCESS: EXIT_FAILURE;

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
