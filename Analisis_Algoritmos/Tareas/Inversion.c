#include <stdio.h>

#define sz 500000
#define inf 1000000000
long a[sz + 2], left[sz + 2], right[sz + 2];
long long cnt;

void merge(long inicio, long mid, long fin)
{
    long i, j, k, ind1, ind2;

    for (i = inicio, ind1 = 1; i <= mid; i++)
    {
        left[ind1++] = a[i];
    }
    left[ind1] = inf;

    for (i = mid + 1, ind2 = 1; i <= fin; i++)
    {
        right[ind2++] = a[i];
    }
    right[ind2] = inf;

    i = j = 1;

    for (k = inicio; k <= fin; k++)
    {
        if (left[i] > right[j])
        {
            cnt += ind1 - i;
            a[k] = right[j];
            j++;
        }
        else
        {
            a[k] = left[i];
            i++;
        }
    }
}

void mergeSort(long inicio, long fin)
{
    if (inicio < fin)
    {
        long mid = (inicio + fin) / 2;
        mergeSort(inicio, mid);
        mergeSort(mid + 1, fin);
        merge(inicio, mid, fin);
    }
}

int main()
{
    // t : Numero de pruebas que se van a realizar
    // n : Variable para la insercion de numeros
    // i : Variable que maneja el ciclo dentro del while
    long i, n, t;

    scanf("%ld", &t);
    while (t--)
    {
        scanf("%ld", &n);
        for (i = 1; i <= n; i++)
        {
            scanf("%ld", &a[i]);
        }
        cnt = 0;
        mergeSort(1, n);
        printf("%lld\n", cnt);
    }

    return 0;
}