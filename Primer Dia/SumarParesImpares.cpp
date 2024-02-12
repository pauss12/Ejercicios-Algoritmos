#include <iostream>

int main(void)
{
    int numTope;
    int i;
    int num;

    numTope = 0;
    num = 0;
    i = 0;
    std::cin >> numTope;
    if (numTope % 2 == 0)
    {
        while (i <= numTope)
        {
            num = num + i;
            i = i + 2;
        }
    }
    else if (numTope % 2 != 0)
    {
        i = 1;
        while (i <= numTope)
        {
            num = num + i;
            i = i + 2;
        }
    }
    std::cout << num << std::endl;
    return 0;
}