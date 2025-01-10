#include <iostream>

int main()
{
    int N{};
    std::cin >> N;
    int t2{1},t1{0},value{};
    int i{1};

    while (i<=N)
    {
        if ( i == 1)
        {
            std::cout << t1 << " ";
            ++i;
        }
        if (i==2)
        {
            std::cout << t2 << " ";
            ++i;
        }
        value = t1+t2;
        if (value > N)
        {
            break;
        }
        std::cout << value << " ";
        t1 = t2;
        t2 = value;
        ++i;
        } 
    return 0;
}