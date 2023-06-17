for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 20; j++)
        {
            if(j<10)
                a[i][j]= szBuffer[i][j];
            else
                b[i][j-10]= szBuffer[i][j];
                
        }
        
    }