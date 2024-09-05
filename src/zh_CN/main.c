#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "portage_package_function.h"//仅管理与gentoo相关的软件操作命令，如emerge命令
#include "main_function.h"//主要函数被存储，一些函数被封装在portage_packagefunction.h中，并且有多个封装
#include "main_menu.h"
int main(){
    int _choose_;
    cls();
    menu_main();
    scanf("%d",&_choose_);
    while (_choose_)
    {
        if (_choose_ == 1)//转到“包管理”子菜单
        {
            manage_package_and_repository();
            menu_main();
            scanf("%d",&_choose_);
            getchar();   
        }
        else if (_choose_ == 2)//转到系统更新选项
        {
            update_system();
            menu_main();
            scanf("%d",&_choose_);
            getchar();
        }
        else if (_choose_ == 3)//检查软件版本
        {
            about();
            menu_main();
            scanf("%d",&_choose_);
            getchar();
        }
        else if (_choose_ == 4)
        {
            cls();
            system("genpkg-sw");
            printf("需要重新启动才能生效...\n");
            sleep(2);
            cls();
            menu_main();
            scanf("%d",&_choose_);
            getchar();
        }
        
        else if (_choose_ == 5)//退出软件
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
            scanf("%d",&_choose_);
            getchar();
        }
    }  
    return 0;
}
//这个main.c文件只包含软件的主要部分，并且有一个函数多重封装