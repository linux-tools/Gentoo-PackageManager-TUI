#include<stdio.h>
#include<string.h>
#include "package.h"
#include "function.h"

char _user_input[255];
char _user_choose_editor[255];//string variable
int _choose_1_;
int _choose_2_;
int _choose_3_;
int _choose_4_;  //define users' inputation variable
char _choose_repo_[255];
void manage_package_and_repository(){
    sleep(1);
    cls();
    menu_folk();
    scanf("%d",&_choose_1_);
    getchar();
    while (_choose_1_)
    {
        if (_choose_1_ == 1)
        {
            sleep(1);
            cls();
            check_installed_packages_menu();
            scanf("%s",_user_input);
            getchar();
            package_check(_user_input);
            strcpy(_user_input,"");
            printf("Please input 1 to return:");
            int a;//checking "1" key
            scanf("%d",&a);
            getchar();
            if (a == 1)
            {
                sleep(1);
                cls();
                menu_folk();
                scanf("%d",&_choose_1_);
                getchar();
            }
            else
            {
                printf("Please input 1 to return:");
                scanf("%d",&a);
                getchar();
            }
        }
        else if (_choose_1_ == 2)
        {
            sleep(1);
            cls();
            package_uninstall_menu();
            scanf("%s",_user_input);
            package_uninstall(_user_input);
            strcpy(_user_input,"");
            printf("Please input 1 to return:");
            int a;//checking "1" key
            scanf("%d",&a);
            getchar();
            if (a == 1)
            {
                sleep(1);
                cls();
                menu_folk();
                scanf("%d",&_choose_1_);
                getchar();
            }
            else
            {
                printf("Please input 1 to return:");
                scanf("%d",&a);
                getchar();
            }
        }
        else if (_choose_1_ == 3)
        {
            sleep(1);
            cls();
            package_install_menu();
            scanf("%s",_user_input);
            printf("Please choose a way to install packages on your system:\n\
                1.install from src\n\
                2.install from binary(NOT EVERY PACKAGE CAN BE INSTALL BY BINARY PACKAGE)\n\
                3.return\n\
                Please choose:");
            scanf("%d",&_choose_4_);
            getchar();
            if (_choose_4_ == 1)
            {
                package_install_src(_user_input);
            }
            else if (_choose_4_ == 2)
            {
                package_install_binary(_user_input);
            }
            strcpy(_user_input,"");
            printf("Please input 1 to return:");
            int a;//checking "1" key
            scanf("%d",&a);
            getchar();
            if (a == 1)
            {
                sleep(1);
                cls();
                menu_folk();
                scanf("%d",&_choose_1_);
                getchar();
            }
            else
            {
                printf("Please input 1 to return:");
                scanf("%d",&a);
                getchar();
            }
        }    
        else if (_choose_1_ == 4)
        {
            sleep(1);
            cls();
            printf("Search:");
            scanf("%s",_user_input);
            package_search(_user_input);
            strcpy(_user_input,"");
            printf("Please input 1 to return:");
            int a;//checking "1" key
            scanf("%d",&a);
            getchar();
            if (a == 1)
            {
                sleep(1);
                cls();
                menu_folk();
                scanf("%d",&_choose_1_);
                getchar();
            }
            else
            {
                printf("Please press 1 to return:");
                scanf("%d",&a);
                getchar();
            }
        }
        else if (_choose_1_ == 5)
        {
            repository_manage();
            sleep(1);
            cls();
            menu_folk();
            scanf("%d",&_choose_1_);
            getchar();                    
        }
        else if (_choose_1_ == 6)
        {
            sleep(1);
            cls();
            break;
        }        
        else
        {
            cls();
            menu_folk();
            scanf("%d",&_choose_1_);
            getchar();
        }  
    }
}

void update_system(){
    sleep(1);
    cls();
    update_system_menu();
    scanf("%d",&_choose_2_);
    getchar();
    if (_choose_2_ == 1)
    {
        system_update_src();
        sleep(1);
        cls();
    }
    else if (_choose_2_ == 2)
    {
        system_update_binary();
        sleep(1);
        cls();
    }
    else if (_choose_2_== 3)
    {
        cls();
    }
    else
    {
        cls();
        update_system_menu();
        scanf("%d",&_choose_2_);
        getchar();  
    }
}

void about(){
    cls();
    version();
    printf("Please input 1 to return:");
    int a;//checking "1" key
    scanf("%d",&a);
    getchar();
    while(a)
    {
        if (a == 1)
        {
            cls();
            break;
        }
        else
        {
            printf("Please press 1 to return:");
            scanf("%d",&a);
            getchar();
        }
    }
}

void version(){
    printf("\n\
    *************************************************\n\
    *************************************************\n\
    **Version:2.0-beta-dev2                        **\n\
    **Dependence:gentoolkit,eselect-repository,sudo**\n\
    **Author:Super111                              **\n\
    **Homepage:https://gitee.com/Linux-Tool        **\n\
    *************************************************\n\
    *************************************************\n\
    ");
}

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
}//Packagemanager Menu from the 376 line of the 478 line

void cls(){
    system("clear");
}//clear screen message

void repository_manage(){
    sleep(1);
    cls();
    package_repository_edit_menu();
    scanf("%d",&_choose_3_);
    getchar();
    while (_choose_3_)
    {
        if (_choose_3_ == 1)
        {
            system("eselect editor list");
            printf("Please choose:");
            int b;
            scanf("%d",&b);
            sleep(1);
            editor_choose(b);
            editor_check();
            printf("Returning...\n");
            sleep(1);
            cls();
            package_repository_edit_menu();
            scanf("%d",&_choose_3_);
            getchar();
        }
        else if (_choose_3_ == 2)
        {
            cls();
            repository_edit_src();
            printf("Returning...\n");
            sleep(1);
            cls();
            package_repository_edit_menu();
            scanf("%d",&_choose_3_);
            getchar();
        }
        else if (_choose_3_ == 3)
        {
            cls();
            repository_edit_binary();
            printf("Returning...\n");
            sleep(1);
            cls();
            package_repository_edit_menu();
            scanf("%d",&_choose_3_);
            getchar();
        }
        else if (_choose_3_ == 4)
        {
            cls();
            sleep(1);
            system("eselect repository list");
            printf("Please input 1 to return:");
            int a;//checking "1" key
            scanf("%d",&a);
            getchar();
            if (a == 1)
            {
                sleep(1);
                cls();
                package_repository_edit_menu();
                scanf("%d",&_choose_3_);
                getchar();
            }
            else
            {
                printf("Please press 1 to return:");
                scanf("%d",&a);
                getchar();
            }
        }
        else if (_choose_3_ == 5)
        {
            cls();
            system("eselect repository list");
            printf("Please enter name that you want to enable:");
            scanf("%s",_choose_repo_);
            getchar();
            repo_enable(_choose_repo_);
            printf("Done!\n");
            sleep(2);
            cls();
            package_repository_edit_menu();
            scanf("%d",&_choose_3_);
            getchar();
        }
        else if (_choose_3_ == 6)
        {
            cls();
            system("eselect repository list");
            printf("Please enter name that you want to disable:");
            scanf("%s",_choose_repo_);
            getchar();
            repo_disable(_choose_repo_);
            printf("Done!\n");
            sleep(3);
            cls();
            package_repository_edit_menu();
            scanf("%d",&_choose_3_);
            getchar();
        }
        else if (_choose_3_ == 7)
        {
            cls();
            system("eselect repository list");
            printf("Please enter name that you want to remove:");
            scanf("%s",_choose_repo_);
            getchar();
            repo_remove(_choose_repo_);
            printf("Done!\n");
            sleep(3);
            cls();
            package_repository_edit_menu();
            scanf("%d",&_choose_3_);
            getchar();
            }
            else if (_choose_3_ == 8)
            {
            cls();
            system("eselect repository list");
            printf("\n\
            Please input custom repository that you want to add by your own\n\
            e.g. <name> <sync-type> <sync-uri>\n\
            Please input:");
            scanf("%[^\n]",_choose_repo_);
            getchar();
            repo_add(_choose_repo_);
            printf("Done!\n");
            sleep(1);
            cls();
            package_repository_edit_menu();
            scanf("%d",&_choose_3_);
            getchar();
        }                    
        else if (_choose_3_ == 9)
        {
            sleep(1);
            break;
        }
        else                    
        {
            cls();
            package_repository_edit_menu();
            scanf("%d",&_choose_3_);
            getchar();
            }
    }
}