#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "portage_package_repo_function.h"//仅管理与gentoo相关的软件操作命令，如emerge命令
#include "main_function.h"//主要函数被存储，一些函数被封装在portage_packagefunction.h中，并且有多个封装
#include "main_menu.h"
int main(){
    int choose_main = 0;
    int *p1/*choose_main 的地址*/ = &choose_main;
    cls();
    menu_main();
    scanf("%d",p1);
    while (choose_main)
    {
        if (choose_main == 1)//转到“包管理”子菜单
        {
            manage_package_and_repository();//来自main_function.h
            menu_main();//来自main_menu.h
            scanf("%d",&choose_main);
            getchar();   
        }
        else if (choose_main == 2)//转到系统更新选项
        {
            update_system();//来自main_function.h
            menu_main();
            scanf("%d",p1);
            getchar();
        }
        else if (choose_main == 3)//检查软件版本
        {
            about();//来自main_function.h
            menu_main();
            scanf("%d",p1);
            getchar();
        }
        else if (choose_main == 4)
        {
            cls();//来自main_function.h
            system("genpkg-sw");
            break;
        }
        
        else if (choose_main == 5)//退出软件
        {
            cls();
            printf("See you next time!\n");
            sleep(1);
            break;
        }
        else
        {
            cls();
            menu_main();
            scanf("%d",p1);
            getchar();
        }
    }  
    return 0;
}
//这个main.c文件只包含软件的主要部分，并且有一个函数多重封装