#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int level = 1;
char const offsets[] = "\t\t\t\t\t\t\t\t";

pid_t Crea_proceso_hijo(int(*child_fn)()) {
    
    fflush(stdout);
    fflush(stderr);

    pid_t child_pid = fork();
    switch(child_pid) {
    case 0: // Proceso hijo
        ++level;
        exit(child_fn());
    case -1: // En caso de que el fork() falle
        abort();
    default: // Proceso padre
        printf("%.*s %u genero a:  %u\n", level, offsets, (unsigned)getpid(), (unsigned)child_pid);
        return child_pid;
    }
}

void Espera_hijo() {
    int wstatus;
    pid_t child_pid = wait(&wstatus);
    if(child_pid == -1)
        abort();
    printf("%.*s %u Fin\n", level, offsets, (unsigned)child_pid);
}
int p21() {return 0;}
int p20() {return 0;}
int p18(){return 0;}
int p15() {return 0;}
int p11() {return 0;}

int p19(){
    Crea_proceso_hijo(p21);
    Espera_hijo();
    return 0;
}

int p16(){
    Crea_proceso_hijo(p19);
    Espera_hijo();
    return 0;
}
int p12(){
    Crea_proceso_hijo(p16);
    Espera_hijo();
    return 0;

}
int p7(){
    Crea_proceso_hijo(p12);
    Espera_hijo();
    return 0;

}
int p2() {
    Crea_proceso_hijo(p7);
    Espera_hijo();
    return 0;
}

int p17(){
    Crea_proceso_hijo(p20);
    Espera_hijo();
    return 0;
}
int p13(){
    Crea_proceso_hijo(p17);
    Espera_hijo();
    return 0;
}
int p8(){
    Crea_proceso_hijo(p13);
    Espera_hijo();
    return 0;
}
int p3() {
    Crea_proceso_hijo(p8);
    Espera_hijo();
    return 0;
}

int p14(){
    Crea_proceso_hijo(p18);
    Espera_hijo();
    return 0;

}
int p9(){
    Crea_proceso_hijo(p14);
    Espera_hijo();
    return 0;

}
int p4() {
    Crea_proceso_hijo(p9);
    Espera_hijo();
    return 0;
}

int p10(){
    Crea_proceso_hijo(p15);
    Espera_hijo();
    return 0;

}
int p5() {
    Crea_proceso_hijo(p10);
    Espera_hijo();
    return 0;
}
int p6(){
    Crea_proceso_hijo(p11);
    Espera_hijo();
    return 0;

}


int p1() {
    printf("%u Comienzo:\n", (unsigned)getpid());
    Crea_proceso_hijo(p2);
    Crea_proceso_hijo(p3);
    Crea_proceso_hijo(p4);
    Crea_proceso_hijo(p5);
    Crea_proceso_hijo(p6);
    Espera_hijo();
    Espera_hijo();
    Espera_hijo();
    Espera_hijo();
    Espera_hijo();
    printf("%u terminated\n", (unsigned)getpid());
    return 0;
} 

int main() {
    return p1();   
}