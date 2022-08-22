#include <iostream>

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << "Arg[" << i + 1 << "] = " << argv[i] << '\n';
    }

    return 0;
}
