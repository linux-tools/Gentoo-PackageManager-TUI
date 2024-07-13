#include<stdio.h>
#include<string.h>
#include "portage_package_function.h"
#include "main_menu.h"
#include "portage_manage.h"

char _user_input[255];
char _user_choose_editor[255];//string variable
int _choose_1_;
int _choose_2_;
int _choose_3_;
int _choose_4_;
int _choose_5_;
int _choose_in_portage_;  //define users' inputation variable
char _choose_repo_[255];
char _create_in_portage[255];
char _edit_in_portage[255];
char _delete_in_portage[255];

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
            strcpy(_choose_repo_,"");
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
            strcpy(_choose_repo_,"");
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
            strcpy(_choose_repo_,"");
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
            cls();
            system("sudo emerge --sync");
            printf("Done!");
            sleep(1);
            cls();
            package_repository_edit_menu();
            scanf("%d",&_choose_3_);
            getchar();
        }                    
        else if (_choose_3_ == 10)
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

void advance_of_portage(){
    sleep(1);
    cls();
    initialization_of_relate_variables();
    portage_manage_menu();
    printf("Please input a number:");
    scanf("%d",&_choose_5_);
    getchar();
    while (_choose_5_)
    {
        if (_choose_5_ == 1)
        {
            cls();
            backup();
            system("tree -lhp $HOME/.portage-tags/backup");
            printf("If you can check the backup content directory, it means that the backup has been successful, otherwise please confirm whether it is in /etc/portage/package.use,/etc/portage/package.accept_keywords,/etc/portage/package.mask has written content or reported to Bug.\n");
            printf("Return after 10 seconds\n");
            sleep(10);
            cls();
            portage_manage_menu();
            printf("Please input a number:");
            scanf("%d",&_choose_5_);
            getchar();
        }
        else if (_choose_5_ == 2)
        {
            sleep(1);
            cls();
            choose_create_file_type_menu_in_portage();
            scanf("%d",&_choose_in_portage_);
            getchar();
            while (_choose_in_portage_)
            {
                if (_choose_in_portage_ == 1)
                {
                    printf("Please input a USE file that you want to create:");
                    scanf("%[^\n]",_create_in_portage);
                    getchar();
                    create_USE(_create_in_portage);
                    strcpy(_create_in_portage,"");
                    printf("Returning...\n");
                    sleep(3);
                    break;
                }
                else if (_choose_in_portage_ == 2)
                {
                    printf("Please input a ACCEPT_KEYWORDS file that you want to create:");
                    scanf("%[^\n]",_create_in_portage);
                    getchar();
                    create_ACCEPT(_create_in_portage);
                    strcpy(_create_in_portage,"");
                    printf("Returning...\n");
                    sleep(3);
                    break;
                }
                else if (_choose_in_portage_ == 3)
                {
                    printf("Please input MASK file that you want to create:");
                    scanf("%[^\n]",_create_in_portage);
                    getchar();
                    create_MASK(_create_in_portage);
                    strcpy(_create_in_portage,"");
                    printf("Returning...\n");
                    sleep(3);
                    break;
                }
                else
                {
                    cls();
                    choose_create_file_type_menu_in_portage();
                    scanf("%d",&_choose_in_portage_);
                    getchar();
                }
            }
            portage_manage_menu();
            printf("Please input a number:");
            scanf("%d",&_choose_5_);
            getchar();            
        }
        else if (_choose_5_ == 3)
        {
            sleep(1);
            cls();
            choose_edit_file_type_menu_in_portage();
            scanf("%d",&_choose_in_portage_);
            getchar();
            while (_choose_in_portage_)
            {
                if (_choose_in_portage_ == 1)
                {
                    printf("Please input a USE file that you want to edit:");
                    scanf("%[^\n]",_edit_in_portage);
                    getchar();
                    edit_USE(_edit_in_portage);
                    strcpy(_edit_in_portage,"");
                    printf("Returning...\n");
                    sleep(3);
                    break;
                }
                else if (_choose_in_portage_ == 2)
                {
                    printf("Please input a ACCEPT_KEYWORDS file that you want to edit:");
                    scanf("%[^\n]",_edit_in_portage);
                    getchar();
                    edit_ACCEPT(_edit_in_portage);
                    strcpy(_edit_in_portage,"");
                    printf("Returning...\n");
                    sleep(3);
                    break;
                }
                else if (_choose_in_portage_ == 3)
                {
                    printf("Please input MASK file that you want to edit:");
                    scanf("%[^\n]",_edit_in_portage);
                    getchar();
                    edit_MASK(_edit_in_portage);
                    strcpy(_edit_in_portage,"");
                    printf("Returning...\n");
                    sleep(3);
                    break;
                }
                else
                {
                    cls();
                    choose_create_file_type_menu_in_portage();
                    scanf("%d",&_choose_in_portage_);
                    getchar();
                }
            }
            portage_manage_menu();
            printf("Please input a number:");
            scanf("%d",&_choose_5_);
            getchar();
        }
        else if (_choose_5_ == 4)
        {
            sleep(1);
            cls();
            choose_delete_file_type_menu_in_portage();
            scanf("%d",&_choose_in_portage_);
            getchar();
            while (_choose_in_portage_)
            {
                if (_choose_in_portage_ == 1)
                {
                    printf("Please input a USE file that you want to delete:");
                    scanf("%[^\n]",_delete_in_portage);
                    getchar();
                    delete_USE(_delete_in_portage);
                    strcpy(_delete_in_portage,"");
                    printf("Returning...\n");
                    sleep(3);
                    break;
                }
                else if (_choose_in_portage_ == 2)
                {
                    printf("Please input a ACCEPT_KEYWORDS file that you want to delete:");
                    scanf("%[^\n]",_delete_in_portage);
                    getchar();
                    delete_ACCEPT(_delete_in_portage);
                    strcpy(_delete_in_portage,"");
                    printf("Returning...\n");
                    sleep(3);
                    break;
                }
                else if (_choose_in_portage_ == 3)
                {
                    printf("Please input MASK file that you want to delete:");
                    scanf("%[^\n]",_delete_in_portage);
                    getchar();
                    delete_MASK(_delete_in_portage);
                    strcpy(_delete_in_portage,"");
                    printf("Returning...\n");
                    sleep(3);
                    break;
                }
                else
                {
                    cls();
                    choose_create_file_type_menu_in_portage();
                    scanf("%d",&_choose_in_portage_);
                    getchar();
                }
            }
            portage_manage_menu();
            printf("Please input a number:");
            scanf("%d",&_choose_5_);
            getchar();
        }
        else if (_choose_5_ == 5)
        {
            cls();
            recover_backup();
            system("tree -lhp $_PORTAGE_USE $_PORTAGE_ACCEPT $_PORTAGE_MASK");
            printf("If you can check the package.use,package.accept_keywords,package.mask content directory, it means that the recovery has been successful, otherwise please confirm whether it is in backup has written content or reported to Bug.\n");
            printf("Return after 10 seconds\n");
            sleep(10);
            cls();
            portage_manage_menu();
            printf("Please input a munber:");
            scanf("%d",&_choose_5_);
            getchar();
        }
        else if (_choose_5_ == 6)
        {
            sleep(1);
            cls();
            break;
        }
        else
        {
            cls();
            portage_manage_menu();
            printf("Please input a number:");
            scanf("%d",&_choose_5_);
            getchar();
        }  
    }
}

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
            scanf("%[^\n]",_user_input);
            getchar();
            if (strcmp(_user_input,"b") != 0 )
            {
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
            else
            {
                sleep(1);
                cls();
                menu_folk();
                scanf("%d",&_choose_1_);
                getchar();
            }
        }
        else if (_choose_1_ == 3)
        {
            sleep(1);
            cls();
            package_install_menu();
            scanf("%[^\n]",_user_input);
            getchar();
            if (strcmp(_user_input,"b") != 0)
            {
                printf("\n\
                Please choose a way to install packages on your system:\n\
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
            else
            {
                sleep(1);
                cls();
                menu_folk();
                scanf("%d",&_choose_1_);
                getchar();
            }
        }    
        else if (_choose_1_ == 4)
        {
            sleep(1);
            cls();
            printf("Search packages or input b to go back to the previous menu\n\
            Please input:");
            scanf("%s",_user_input);
            if (strcmp(_user_input,"b") != 0)
            {
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
            else
            {
                sleep(1);
                cls();
                menu_folk();
                scanf("%d",&_choose_1_);
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
            advance_of_portage();
            menu_folk();
            scanf("%d",&_choose_1_);
            getchar();
        }
        
        else if (_choose_1_ == 7)
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
    printf("\n\
    ******************************************************\n\
    ******************************************************\n\
    **Version:2.0-beta-dev5(Release2.0-RC1)             **\n\
    **Dependence:gentoolkit,eselect-repository,sudo,tree**\n\
    **Author:Super111                                   **\n\
    **Homepage:https://gitee.com/Linux-Tool             **\n\
    ******************************************************\n\
    ******************************************************\n\
    ");
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