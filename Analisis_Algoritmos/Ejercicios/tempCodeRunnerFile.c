    int n=3;
    int c=1;

    for (int i = 0; i < n*5; i+=2)
    {
        for (int j = 0; j < 2*n; j++)
        {
            for (int k = j; k < n; k++)
            {

                printf("Valor de K : %d\n",k);
                printf("%d\n",c);
                c++;
            }
            
        }
        
    }