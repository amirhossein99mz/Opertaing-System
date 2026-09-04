#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int last=-1;
int last_last= -1;
int finish=0;

void signal_handler(int sig){
    
    if(sig==last && last == last_last)finish=1;

    else {last_last = last; last=sig;}

}

int main(int argc,char *argv[]){

    char cmd[100];

    if(signal(SIGUSR1,signal_handler())==SIG_ERR ||  signal(SIGUSR2,signal_handler())==SIG_ERR )exit(-1);
   
    if(!fork()){
        pid_t pid1=getpid();
        while(1){
            sleep(1);
            kill(getppid(),SIGUSR1);
        }
    }
    else{
    
        if(!fork()){
            pid_t pid2=getpid();
            while(1){
                sleep(1);
                kill(getppid(),SIGUSR2);

            }

        }

    }

    while(1){
   
       pause();

       if(finish){
         
           sprintf(cmd,"kill -9 %d",pid1)
           system(cmd);

           sprintf(cmd,"kill -9 %d",pid2)
           system(cmd);

           exit(0);

       }



    }

}




int main(int argc,char *argv[]){

    int fd[2];char line[N];

    if(pipe(fd)==-1)exit(-1);

    if(fork()){

       close(fd[0]);

       while(1){
       
           scanf("%s",line);
           write(fd[1],line,(sizeof(line)+1)*sizeof(char));
           close(fd[1]);
       }

    else{

        close(fd[1]);
 
        while(1){
       
           read(fd[0],line,N);
           printf("%s",line);
           close(fd[0]);
       }


     }

    }

}
