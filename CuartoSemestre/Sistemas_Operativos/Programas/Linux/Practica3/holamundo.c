#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
int main(){
    int i,j,k,x,s;

    for ( i = 0; i < 5; i++)
    {
        if(fork()==0){
            if (i<5){
                if(fork()==0){
                    if(i<4){
                        if(fork()==0){
                            if(i<3){
                                if(fork()==0){
                                    if(i<2){
                                        if(fork()==0){
                                            if(i<1){
                                                if(fork()==0){
                                                    break;
                                                }
                                            }
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                            break;
                        }

                    }
                    
                    
                    break;
                }
            }
        break;
        }
    }
    while (1);
    


    return 0;
}