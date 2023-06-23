// ELIS
#include <stdio.h> #include <stdlib.h>
int valores[11];
int n = 0;
int ELIS();
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &valores[i]);
    printf("%d\n", ELIS());
    return 0;
}
int ELIS()
{
    int auxiliar[n];
    int maxSub = 0;
    for (int i = 0; i < n; i++)
        auxiliar[i] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (auxiliar[i] < (auxiliar[j] + 1) && valores[i] > valores[j])
                auxiliar[i] = auxiliar[j] + 1;
        }
    }
    for (int i = 0; i < n; i++)
        if (auxiliar[i] > maxSub)
            maxSub = auxiliar[i];
    return maxSub;
}
