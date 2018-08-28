#include <stdio.h>
#include <stdlib.h>

bool isHappy(int n) {
    int mod = 0;
    int sum = 0;

    while(n != 1 && n != 4)
    {
        while (n > 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        n = sum;
        sum = 0;
    }

    return n == 1;
}

int main()
{
    bool ret = isHappy(2);
    printf("%d\n", ret);
    return 0;
}
