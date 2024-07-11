#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "package.h"
#include "function.h"
int main(){
    int _choose_;
    cls();
    menu_main();
    scanf("%d",&_choose_);
    while (_choose_)
    {
        if (_choose_ == 1)
        {
            manage_package_and_repository();
            menu_main();
            scanf("%d",&_choose_);
            getchar();   
        }
        else if (_choose_ == 2)
        {
            update_system();
            menu_main();
            scanf("%d",&_choose_);
            getchar();
        }
        else if (_choose_ == 3)
        {
            about();
            menu_main();
            scanf("%d",&_choose_);
            getchar();
        }
        else if (_choose_ == 4)
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
