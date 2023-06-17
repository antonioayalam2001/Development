#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
int main(){
    int i,j,k,x,s;

    for ( i = 0; i <5; i++)
    {
        if(fork()==0){
            if(i==0){
                for(j=0;j<5;j++){
                    if(fork()!=0)break;
                }
            }

            else if(i==1){
                for(j=0;j<4;j++){
                    if(fork()!=0)break;
                }
            }

            else if(i==2){
                for(j=0;j<3;j++){
                    if(fork()!=0)break;
                }
            }

            else if(i==3){
                for(j=0;j<2;j++){
                    if(fork()!=0)break;
                }
            }

            else if (i==4){
                for(j=0;j<1;j++){
                    if(fork()!=0)break;
                }
            }
            
        break;
        }
    }
    
    while (1);
    return 0;
}