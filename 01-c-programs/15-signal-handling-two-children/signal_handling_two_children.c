//Signal Handling with Two Child Processes : 
//General context: Parent receives signals from two children and stops them after 3 same signals in a row.

#include <stdio.h> // printf() , input/output
#include <stding.h>
#include <stdlib.h> // exit(),rand()
#include <signal.h> // kill(), signal(), SIGUSR1, SIGUSR2
#include <sys/type.h> // pid_t pid1,pid2;
#include <sys/wait.h> //wait(),pause(),waitpid(),waitppid()
#include <undistd.h> //fork(),sleep(),getppid(),exec()

int last_sig = -1;
int last_last_sig = -1;
int finish = 0;

void sig_handler(int sig){
    if(sig==last_last_sig ==last_sig)finish=1;
    else{   - A : becones A - and enter B  : [A B]
        last_last_sig =last_sig; 
        last_sig = sig;  
    }
}

int main(int argc,char *argv[]){
    
    char cmd[100];
    pid_t pid1,pid2;
    
    if((signal(SIGUSR1,sig_handler())==SIG_ERR) || (signal(SIGUSR2,sig_handler())==SIG_ERR)){
        printf("Error initialization signal handler");
        exit(-1);
    }


    pid1 = fork();

    if(!pid1()){
        while(1){
            sleep(rand()%2);//pid1 wait random 0,1 seconds
            kill(getppid(),SIGUSR1);//pid1 sends SIGUSR1 to the parent
        }
    } 

    else{
 
        pid2 = fork();

        if(!pid2()){
            while(1){
                sleep(rand()%3);//pid2 wait random 0,1,2 seconds
                kill(getppid(),SIGUSR2);//pid2 sends SIGUSR2 to the parent
            }
        } 
    }

    while(1){

        pause();//parent sleeps until a signal arrives
        if(finish){
            sprintf(cmd,"kill -9 %d",pid1);system(cmd);
            sprintf(cmd,"kill -9 %d",pid2);system(cmd);
            exit(0);//parent terminates successfully

        }

    }

}
