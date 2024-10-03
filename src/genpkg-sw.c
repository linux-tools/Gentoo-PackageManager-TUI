#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void restart();//重启程序(Restart the program)
void restart(){
    pid_t ppid,pid;//获取父进程pid，子进程pid(Get the parent process's pid and child process's pid)
    ppid = getppid();
    pid = getpid();
    printf("The parent pid is %d\n",ppid);
    int rec = fork();//创建子进程(Create child process)
    if (rec == 0)
    {
        execl("/bin/genpkg","genpkg",(char *)NULL);
        kill(ppid,SIGTERM);
    }
    else if(rec > 0)
    {
        wait(NULL);//等待进程结束(Wait for the stopping of process)
        kill(pid,SIGTERM);
    }
    else
    {
        perror("fork()");
        exit(1);
    }
}

int main(){
    printf("\n\
    Please choose your language:\n\
    1.English\n\
    2.Chinese\n\
    Please choose:");
    int choose_Language;
    scanf("%d",&choose_Language);
    while (1)
    {
        if (choose_Language == 1)
        {
            system("sudo ln -sf /usr/bin/genpkg-en /usr/bin/genpkg");
            sleep(1);
            restart();
            sleep(1);
            break;
        }
        else if (choose_Language == 2)
        {
            system("sudo ln -sf /usr/bin/genpkg-zh /usr/bin/genpkg");
            sleep(1);
            restart();
            sleep(1);
            break;
        }
        else
        {
            system("clear");
            printf("\n\
            Please choose your language:\n\
            1.English\n\
            2.Chinese\n\
            Please choose:");
            scanf("%d",&choose_Language);
        }
    }
    return 0;   
}