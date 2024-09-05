#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "portage_package_function.h"//Only portage-related software operation commands, such as emerge commands, are managed
#include "main_function.h"//The main function functions are stored, and some functions are encapsulated in portage_package_function.h, and there are multiple encapsulation
#include "main_menu.h"
int main(){
    int _choose_;
    cls();
    menu_main();
    scanf("%d",&_choose_);
    while (_choose_)
    {
        if (_choose_ == 1)//Go to the Package Management submenu
        {
            manage_package_and_repository();
            menu_main();
            scanf("%d",&_choose_);
            getchar();   
        }
        else if (_choose_ == 2)//Go to the System Update option
        {
            update_system();
            menu_main();
            scanf("%d",&_choose_);
            getchar();
        }
        else if (_choose_ == 3)//Check the software version
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
            printf("Need to restart to take effect...\n");
            sleep(2);
            cls();
            menu_main();
            scanf("%d",&_choose_);
            getchar();
        }
        else if (_choose_ == 5)//Exit software
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
//This main.c file contains only the main part of the software, and there is a function multiple encapsulation