#include <stdio.h>

int main(){
    int fd[2];  
    pipe(fd);  //Crea el pipe
    int pid = fork(); //Fork

    if(pid == 0){ //Proceso hijo
        close(STDIN_FILENO);
        dup(fd[0]); 
        close(fd[1]);
        execlp("wc","wc","-l",NULL);

    }else{ //Proceso padre
        close(STDOUT_FILENO);
        dup(fd[1]);   
        close(fd[0]);
        execlp("ls","ls",NULL);
    }
    return 0;
}