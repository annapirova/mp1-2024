#include <stdio.h>
#include <stdlib.h>

int main()
{

    int sum;
    for (sum = 0; sum <= 9 * 3; sum++)
    {
        int a, b;
        for (a = 1; a <= 9; a++)
        {
            if (a > sum) break;
            for (b = 0; b <= 9; b++)
            {
                int c = sum - a - b;
                if (c < 0) break;
                if (c <= 9)
                    printf("%d%d%d  ", a, b, c);
            }
        }
    }

    return 0;
}