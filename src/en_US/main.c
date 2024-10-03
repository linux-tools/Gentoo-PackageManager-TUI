#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "portage_package_repo_function.h"//Only portage-related software operation commands, such as emerge commands, are managed
#include "main_function.h"//The main function functions are stored, and some functions are encapsulated in portage_package_function.h, and there are multiple encapsulation
#include "main_menu.h"
int main(){
    int choose_main;
    int *p1/*choose_main address*/ = &choose_main;
    cls();
    menu_main();
    scanf("%d",p1);
    while (choose_main)
    {
        if (choose_main == 1)//Go to the Package Management submenu
        {
            manage_package_and_repository();
            menu_main();
            scanf("%d",p1);
            getchar();   
        }
        else if (choose_main == 2)//Go to the System Update option
        {
            update_system();
            menu_main();
            scanf("%d",p1);
            getchar();
        }
        else if (choose_main == 3)//Check the software version
        {
            about();
            menu_main();
            scanf("%d",p1);
            getchar();
        }
        else if (choose_main == 4)
        {
            cls();
            system("genpkg-sw");
            break;
        }
        else if (choose_main == 5)//Exit software
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
//This main.c file contains only the main part of the software, and there is a function multiple encapsulation