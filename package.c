#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

char package_install_src(char a[255]){//Gentoo's packages installation founction
    char exec_src[255];
    sprintf(exec_src,("sudo emerge --ask %s"),a);
    system("clear");
    sleep(1);
    system("clear");
    system(exec_src);
    sleep(1);
    system("clear");
    return 0;
}

char package_install_binary(char a[255]){//Gentoo's packages installation founction
    char exec_binary[255];
    sprintf(exec_binary,"sudo emerge --ask -g %s",a);
    system("clear");
    sleep(1);
    printf("Do you want to run 'getuto' to refresh the binary package related keys?\n\
    Please input 1 to permit the operate or input other number to continue.\n\
    Warning: Please don't run it again or you must delete /etc/portage/gnupg to rerun getuto\n\
    to recover the ability to install binary packages unless you had never run getuto tu refresh keys!\n\
    Please input:");
    int b;
    scanf("%d",&b);
    if (b == 1)
    {
        system("sudo getuto");
    }
    else if (b == 2)
    {
        printf("continue\n");
    }
    system(exec_binary);
    sleep(1);
    system("clear");
    return 0;
}

char package_search(char a[255]){//Gentoo's packages searching founction
    char exec[255];
    sprintf(exec,"emerge -S %s",a);
    system("clear");
    system(exec);
    sleep(2);
    system("clear");
    return 0;
}

char package_uninstall(char a[255]){//Gentoo's package uninstallation founction
    char exec[255];
    sprintf(exec,"sudo emerge -acv %s",a);
    system("clear");
    system(exec);
    sleep(2);
    system("clear");
    return 0;
}

void system_update_src(){
    system("sudo emerge -avuDN @world");
}
void system_update_binary(){
    int a;
    printf("Do you want to run 'getuto' to refresh the binary package related keys?\n\
    Please input 1 to permit the operate or input other number to continue.\n\
    Warning: Please don't run it again or you must delete /etc/portage/gnupg to rerun getuto\n\
    to recover the ability to install binary packages unless you had never run getuto tu refresh keys!\n\
    Please input:");
    scanf("%d",&a);
    if (a == 1)
    {
        system("sudo getuto");
    }
    else if(a == 2)
    {
        printf("continue\n");
    }
    system("sudo emerge -avuDNg @world");
}//Gentoo's system packages update function

char package_check(char a[255]){
    char exec[255];
    sprintf(exec,"equery list %s",a);
    system(exec);
    return 0;
}/*Managing installed packages and parameter "a" represent package group*/

void repository_edit_binary(){
    char exec[255];
    sprintf(exec,"sudo $EDITOR /etc/portage/binrepos.conf/gentoobinhost.conf");
    system(exec);
}

void repository_edit_src(){
    char exec[255];
    sprintf(exec,"sudo $EDITOR /etc/portage/repos.conf/gentoo.conf");
    system(exec);
}

char repo_add(char a[255]){
    char exec[255];
    printf("Adding...");
    sprintf(exec,"sudo eselect repository add %s",a);
    system(exec);
    strcpy(exec,"");
    return 0;
}

char repo_enable(char a[255]){
    char exec[255];
    printf("Enabling...");
    sprintf(exec,"sudo eselect repository enable %s",a);
    system(exec);
    strcpy(exec,"");
    return 0;
}

char repo_disable(char a[255]){
    char exec[255];
    printf("Disabling...");
    sprintf(exec,"sudo eselect repository disable %s",a);
    system(exec);
    strcpy(exec,"");
    return 0;
}

char repo_remove(char a[255]){
    char exec[255];
    printf("Removing...");
    sprintf(exec,"sudo eselect repository remove %s",a);
    system(exec);
    strcpy(exec,"");
    return 0;
}

int editor_choose(int a){
    char exec[255];
    sprintf(exec,"sudo eselect editor set %d && . /etc/profile",a);
    system(exec);
    return 0;
}

void editor_check()
{
    system("echo $EDITOR");
}