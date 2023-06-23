
#include <stdio.h>
#include <string.h>
#define MAX 1000000

int main()
{
    int t, n, m, i, j, c,count=0;
    char a[MAX];
    scanf("%d", &t);
    for (m = 1; m <= t; m++)
    {
        count = 0;
        scanf("%d", &c); 
            scanf("%s", a);
        for (i = 0; i < c; i++)
        {
            if (a[i] == '.')
            {
                i += 2;
                count++;
            }
        }
        printf("Case %d: %d\n", m, count);
    }
    return 0;
}
