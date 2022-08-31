#include <iostream>
#include <cmath>
#include <string>
#include <numbers>


bool is_number(const std::string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

bool user_input(int argc, char* argv[], int& num_samples, int& num_bits, bool& cosine)
{
    if (argc < 3 || !is_number(argv[1]) || !is_number(argv[2]))
    {
        return false;
    }
    cosine = false;
    if (argc == 4)
    {
        std::string cosine_arg {argv[3]};
        cosine = cosine_arg == "c";
    }

    num_samples = atoi(argv[1]);
    num_bits = atoi(argv[2]);
    return true;
}


int main(int argc, char *argv[])
{
    int num_samples; int num_bits;
    bool cosine;

    if (!user_input(argc, argv, num_samples, num_bits, cosine))
    {
        std::cout << "Invalid arguments.\n";
        std::cout << "Usage: sintable NUM_SAMPLES BIT-WIDTH [c]\n";
        return 1;
    }

    const auto max_value { (1 << num_bits - 1) - 1};
    const auto interval { 2 * std::numbers::pi / num_samples  };

    for (auto i {0}; i < num_samples; i++)
    {
        auto current_degree { i * interval};
        int current_value { static_cast<int>(sin(current_degree) * max_value)};
        std::cout << current_value;
        if (cosine)
        {
            current_value = cos(current_degree) * max_value;
            std::cout << '\t' << current_value;
        }
        std::cout << '\n';
    }

    return 0;
}
