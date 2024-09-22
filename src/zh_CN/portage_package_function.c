#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
char package_install_src(char a[255]){//Gentoo的软件包安装功能，从源码编译
    char exec_src[255];
    sprintf(exec_src,"sudo emerge --ask %s",a);
    system("clear");
    sleep(1);
    system("clear");
    system(exec_src);
    sleep(1);
    system("clear");
    return 0;
}

char package_install_binary(char a[255]){//Gentoo的软件包安装功能，直接使用二进制包
    char exec_binary[255];
    sprintf(exec_binary,"sudo emerge --ask -g %s",a);
    system("clear");
    sleep(1);
    int b;
    printf("您想运行“getuto”来刷新与二进制包相关的密钥吗？\n\
    1.允许操作\n\
    2.继续安装而不执行getuto\n\
    警告：请不要再次运行它，否则必须删除/etc/portage/gnupg才能重新执行getuto\n\
    恢复安装二进制包的能力，除非您从未运行过getuto来刷新密钥！\n\
    请输入:");
    scanf("%d",&b);
    while(b)
    {
        if (b == 1)
        {
            system("sudo getuto");
            break;
        }
        else if(b == 2)
        {
            printf("continue\n");
            break;
        }
        else
        {
            system("clear");
            printf("您想运行“getuto”来刷新与二进制包相关的密钥吗？\n\
            1.允许操作\n\
            2.继续安装而不执行getuto\n\
            警告：请不要再次运行它，否则必须删除/etc/portage/gnupg才能重新运行getuto\n\
            恢复安装二进制包的能力，除非您从未运行过getuto来刷新密钥！\n\
            请输入:");
            scanf("%d",&b);
        }
    }
    system(exec_binary);
    sleep(1);
    system("clear");
    return 0;
}

char package_search(char a[255]){//Gentoo的软件包搜索功能
    char exec[255];
    sprintf(exec,"emerge -S %s",a);
    system("clear");
    system(exec);
    sleep(2);
    return 0;
}

char package_uninstall(char a[255]){///Gentoo的软件包卸载功能
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
    printf("您想运行“getuto”来刷新与二进制包相关的密钥吗？\n\
    1.允许操作\n\
    2 继续安装而不执行getuto\n\
    警告：请不要再次运行它，否则必须删除/etc/portage/gnupg才能重新运行getuto\n\
    恢复安装二进制包的能力，除非您从未运行过getuto来刷新密钥！\n\
    请输入:");
    scanf("%d",&a);
    while(a)
    {
        if (a == 1)
        {
            system("sudo getuto");
            break;
        }
        else if(a == 2)
        {
            printf("continue\n");
            break;
        }
        else
        {
            system("clear");
            printf("您想运行“getuto”来刷新与二进制包相关的密钥吗？\n\
            1.允许操作\n\
            2.继续安装而不执行getuto\n\
            警告：请不要再次运行它，否则必须删除/etc/portage/gnupg才能重新运行getuto\n\
            恢复安装二进制包的能力，除非您从未运行过getuto来刷新密钥！\n\
            请输入:");
            scanf("%d",&a);
        }
    }
    system("sudo emerge -avuDNg @world");
}//Gentoo的系统包更新功能

char package_check(char a[255]){
    char exec[255];
    sprintf(exec,"equery list %s",a);
    system(exec);
    return 0;
}/*管理已安装的包，参数“a”表示包组*/

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