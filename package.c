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

void menu_main(){
    printf("\n\
    ****************************GENTOO-PACKAGEMANAGER-TUI*************************\n\
    **********************************Welcome-MENU********************************\n\
    ******************************************************************************\n\
    *****----------1.Managing your packages and software repository----------*****\n\
    ******************************************************************************\n\
    *****--------------------------2.Update System---------------------------*****\n\
    ******************************************************************************\n\
    *****------------------------------3.ABOUT-------------------------------*****\n\
    ******************************************************************************\n\
    *****-------------------------------4.EXIT-------------------------------*****\n\
    ******************************************************************************\n\
    ******************************************************************************\n\
    Please input a number:");
}

void menu_folk(){
    printf("\n\
    **********************************Manage Menu*********************************\n\
    ******************************************************************************\n\
    *****--------------------1.Checking installed packages-------------------*****\n\
    ******************************************************************************\n\
    *****--------------------2.Uninstall packages you want-------------------*****\n\
    ******************************************************************************\n\
    *****---------------------3.install packages you want--------------------*****\n\
    ******************************************************************************\n\
    *****----------------4.Searching packages from your repository-----------*****\n\
    ******************************************************************************\n\
    *****----------------------5.Edit package repositories-------------------*****\n\
    ******************************************************************************\n\
    *****-------------------------------6.BACK-------------------------------*****\n\
    ******************************************************************************\n\
    ******************************************************************************\n\
    Please input a number:");
}
//Packagemanager Menu
void check_installed_packages_menu(){
    printf("\n\
    You can enter that you want to search package group\n\
    note:The function is based on 'equery' command. That's the reason why we depend on 'gentoolkit' package\n\
    -----------------------------------------------------\n\
    e.g. you inputed app-misc/*\n\
    you will see these content as follws:\n\
    [IP-] [  ] app-misc/ca-certificates-20240203.3.98:0\n\
    [IP-] [  ] app-misc/editor-wrapper-4-r1:0\n\
    [IP-] [  ] app-misc/fastfetch-2.13.2:0\n\
    [IP-] [  ] app-misc/mime-types-2.1.54:0\n\
    [IP-] [  ] app-misc/pax-utils-1.3.7:0\n\
    -----------------------------------------------------\n\
    you input sudo                                       \n\
    you will see these content as follws:                \n\
    * Searching for sudo ...                             \n\
    [IP-] [  ] app-admin/sudo-1.9.15_p5:0                \n\
    -----------------------------------------------------\n\
    you also can input '*'(including single qutes) to check installed packages on your computer\n\
    -----------------------------------------------------\n\
    Please input:");
}

void update_system_menu(){
    printf("\n\
            Please choose a way to update your system:\n\
            1.install from src\n\
            2.install from binary(NOT EVERY PACKAGE CAN BE INSTALL BY BINARY PACKAGE)\n\
            3.return\n\
            Please choose:");
}

void package_uninstall_menu(){
    printf("\n\
    Please enter a content you want to uninstall\n\
    Please input:");
}

void package_install_menu(){
    printf("\n\
    Please enter a content you want to install\n\
    Please input:");
}

void package_repository_edit_menu(){
    printf("\n\
------------------------------------REPOSITORY-EDIT-MENU-----------------------------------\n\
-------------------------------------------------------------------------------------------\n\
Warning: The second and third operations will very dangerous,I suggest execute 4-8 options \n\
to edit some repository unless you just change mirror to speed up fetching packages and upd\n\
ating system according to your location.Never remove gentoo sources.YOU ARE BE WARNED!     \n\
-------------------------------------------------------------------------------------------\n\
-------------------------------------------------------------------------------------------\n\
******1.change editor(The operation will change the system EDITOR variables)               \n\
******2.edit src repository(directly edit /etc/portage/repos.conf/gentoo.conf)             \n\
******3.edit binary repository(directly edit /etc/portage/binrepos.conf/gentoobinhost.conf)\n\
******4.check usable reposiory                                                             \n\
******5.add and enable third-party repository                                              \n\
******6.disable repository(Both official and third-party repositories are included)        \n\
******7.remove repository(Both official and third-party repositories are included)         \n\
******8.add your own repository(Not on the list of eselect-repository online)              \n\
******9.Back                                                                               \n\
-------------------------------------------------------------------------------------------\n\
-------------------------------------------------------------------------------------------\n\
####Please input:");
}

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

void version(){
    printf("\n\
    Version:1.0-Release-fix1\n\
    Dependence:gentoolkit,eselect-repository,sudo\n\
    Author:Super111\n\
    Homepage:https://gitee.com/Linux-Tool\n\
    ");
}

void cls(){
    system("clear");
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

void panic_1(){//Error area
    printf("\n\
     ************           ***            **         **    *********     ************       ***  \n\
    **************         ** **           **       ****       ***      ****        ****     ***  \n\
    ***         ***       **   **          **      ** **       ***      **            **     ***  \n\
    ***         ***      *********         **     **  **       ***      **                   ***  \n\
    **************      ***********        **    **   **       ***      **                   ***  \n\
    *************      **         **       **   **    **       ***      **                   ***  \n\
    ***               **           **      **  **     **       ***      **            **          \n\
    ***              **             **     ** **      **       ***      ****        ****     ***  \n\
    ***             **               **    ****       **    *********     ************       ***  \n\
    ERROR:1  \n\
    Please enter a valid number instead of a string!!!\n");
    sleep(1);
    printf("The program will be EXIT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    sleep(3);
    system("clear");
}