#include <iostream>

int main(void)
{
    int numTope;
    int i;
    int num;

    numTope = 0;
    i = 0;
    num = 0;
    std::cin >> numTope;
    while (i <= numTope)
    {
        num = num + i;
        i++;
    }
    std::cout << num << std::endl;
    return 0;
}