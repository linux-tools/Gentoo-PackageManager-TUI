#include<stdio.h>
#include<string.h>
#include "portage_package_function.h"
#include "main_menu.h"
#include "portage_manage.h"

char UserInput[255];
int choose_1;
int choose_2;
int choose_3;
int choose_4;
int choose_5;
int ChooseInPortage;  //define users' inputation variable
char ChooseRepo[255];
char CreateInPortage[255];
char EditInPortage[255];
char DeleteInPortage[255];

void cls(){
    system("clear");
}

void repository_manage(){
    cls();
    package_repository_edit_menu();
    scanf("%d",&choose_3);
    getchar();
    while (choose_3)
    {
        if (choose_3 == 1)
        {
            cls();
            repository_edit_src();
            printf("Returning...\n");
            sleep(1);
            cls();
            package_repository_edit_menu();
            scanf("%d",&choose_3);
            getchar();
        }
        else if (choose_3 == 2)
        {
            cls();
            repository_edit_binary();
            printf("Returning...\n");
            sleep(1);
            cls();
            package_repository_edit_menu();
            scanf("%d",&choose_3);
            getchar();
        }
        else if (choose_3 == 3)
        {
            cls();
            sleep(1);
            system("eselect repository list");
            printf("Please input 1 to return:");
            int key;//checking "1" key
            scanf("%d",&key);
            getchar();
            if (key == 1)
            {
                sleep(1);
                cls();
                package_repository_edit_menu();
                scanf("%d",&choose_3);
                getchar();
            }
            else
            {
                printf("Please press 1 to return:");
                scanf("%d",&key);
                getchar();
            }
        }
        else if (choose_3 == 4)
        {
            cls();
            system("eselect repository list");
            printf("Please enter name that you want to enable:");
            scanf("%s",ChooseRepo);
            getchar();
            repo_enable(ChooseRepo);
            printf("Done!\n");
            strcpy(ChooseRepo,"");
            sleep(2);
            cls();
            package_repository_edit_menu();
            scanf("%d",&choose_3);
            getchar();
        }
        else if (choose_3 == 5)
        {
            cls();
            system("eselect repository list");
            printf("Please enter name that you want to disable:");
            scanf("%s",ChooseRepo);
            getchar();
            repo_disable(ChooseRepo);
            printf("Done!\n");
            strcpy(ChooseRepo,"");
            sleep(3);
            cls();
            package_repository_edit_menu();
            scanf("%d",&choose_3);
            getchar();
        }
        else if (choose_3 == 6)
        {
            cls();
            system("eselect repository list");
            printf("Please enter name that you want to remove:");
            scanf("%s",ChooseRepo);
            getchar();
            repo_remove(ChooseRepo);
            printf("Done!\n");
            strcpy(ChooseRepo,"");
            sleep(3);
            cls();
            package_repository_edit_menu();
            scanf("%d",&choose_3);
            getchar();
            }
        else if (choose_3 == 7)
        {
            cls();
            system("eselect repository list");
            printf("\n\
            Please input custom repository that you want to add by your own\n\
            e.g. <name> <sync-type> <sync-uri>\n\
            Please input:");
            scanf("%[^\n]",ChooseRepo);
            getchar();
            repo_add(ChooseRepo);
            printf("Done!\n");
            sleep(1);
            cls();
            package_repository_edit_menu();
            scanf("%d",&choose_3);
            getchar();
        }
        else if (choose_3 == 8)
        {
            cls();
            system("sudo emerge --sync");
            printf("Done!");
            sleep(1);
            cls();
            package_repository_edit_menu();
            scanf("%d",&choose_3);
            getchar();
        }                    
        else if (choose_3 == 9)
        {
            cls();
            break;
        }
        else                    
        {
            cls();
            package_repository_edit_menu();
            scanf("%d",&choose_3);
            getchar();
        }
    }
}

void advance_of_portage(){
    create_floder_in_portage();
    sleep(1);
    cls();
    portage_manage_menu();
    printf("Please input a number:");
    scanf("%d",&choose_5);
    getchar();
    while (choose_5)
    {
        if (choose_5 == 1)
        {
            cls();
            backup();
            system("tree -lhp $HOME/.portage-tags/backup");
            printf("If you can check the backup content directory, it means that the backup has been successful, otherwise please confirm whether it is in /etc/portage/package.use,/etc/portage/package.accept_keywords,/etc/portage/package.mask has written content or reported to Bug.\n");
            printf("Return after 3 seconds\n");
            sleep(3);
            cls();
            portage_manage_menu();
            printf("Please input a number:");
            scanf("%d",&choose_5);
            getchar();
        }
        else if (choose_5 == 2)
        {
            cls();
            choose_create_file_type_menu_in_portage();
            scanf("%d",&ChooseInPortage);
            getchar();
            while (ChooseInPortage)
            {
                if (ChooseInPortage == 1)
                {
                    printf("Please input a USE file that you want to create:");
                    scanf("%[^\n]",CreateInPortage);
                    getchar();
                    create_USE(CreateInPortage);
                    strcpy(CreateInPortage,"");
                    printf("Returning...\n");
                    sleep(1);
                    break;
                }
                else if (ChooseInPortage == 2)
                {
                    printf("Please input a ACCEPT_KEYWORDS file that you want to create:");
                    scanf("%[^\n]",CreateInPortage);
                    getchar();
                    create_ACCEPT(CreateInPortage);
                    strcpy(CreateInPortage,"");
                    printf("Returning...\n");
                    sleep(1);
                    break;
                }
                else if (ChooseInPortage == 3)
                {
                    printf("Please input MASK file that you want to create:");
                    scanf("%[^\n]",CreateInPortage);
                    getchar();
                    create_MASK(CreateInPortage);
                    strcpy(CreateInPortage,"");
                    printf("Returning...\n");
                    sleep(1);
                    break;
                }
                else
                {
                    cls();
                    choose_create_file_type_menu_in_portage();
                    scanf("%d",&ChooseInPortage);
                    getchar();
                }
            }
            portage_manage_menu();
            printf("Please input a number:");
            scanf("%d",&choose_5);
            getchar();            
        }
        else if (choose_5 == 3)
        {
            cls();
            choose_edit_file_type_menu_in_portage();
            scanf("%d",&ChooseInPortage);
            getchar();
            while (ChooseInPortage)
            {
                if (ChooseInPortage == 1)
                {
                    printf("Please input a USE file that you want to edit:");
                    scanf("%[^\n]",EditInPortage);
                    getchar();
                    edit_USE(EditInPortage);
                    strcpy(EditInPortage,"");
                    printf("Returning...\n");
                    sleep(1);
                    break;
                }
                else if (ChooseInPortage == 2)
                {
                    printf("Please input a ACCEPT_KEYWORDS file that you want to edit:");
                    scanf("%[^\n]",EditInPortage);
                    getchar();
                    edit_ACCEPT(EditInPortage);
                    strcpy(EditInPortage,"");
                    printf("Returning...\n");
                    sleep(1);
                    break;
                }
                else if (ChooseInPortage == 3)
                {
                    printf("Please input MASK file that you want to edit:");
                    scanf("%[^\n]",EditInPortage);
                    getchar();
                    edit_MASK(EditInPortage);
                    strcpy(EditInPortage,"");
                    printf("Returning...\n");
                    sleep(1);
                    break;
                }
                else
                {
                    cls();
                    choose_create_file_type_menu_in_portage();
                    scanf("%d",&ChooseInPortage);
                    getchar();
                }
            }
            portage_manage_menu();
            printf("Please input a number:");
            scanf("%d",&choose_5);
            getchar();
        }
        else if (choose_5 == 4)
        {
            cls();
            choose_delete_file_type_menu_in_portage();
            scanf("%d",&ChooseInPortage);
            getchar();
            while (ChooseInPortage)
            {
                if (ChooseInPortage == 1)
                {
                    printf("Please input a USE file that you want to delete:");
                    scanf("%[^\n]",DeleteInPortage);
                    getchar();
                    delete_USE(DeleteInPortage);
                    strcpy(DeleteInPortage,"");
                    printf("Returning...\n");
                    sleep(1);
                    break;
                }
                else if (ChooseInPortage == 2)
                {
                    printf("Please input a ACCEPT_KEYWORDS file that you want to delete:");
                    scanf("%[^\n]",DeleteInPortage);
                    getchar();
                    delete_ACCEPT(DeleteInPortage);
                    strcpy(DeleteInPortage,"");
                    printf("Returning...\n");
                    sleep(1);
                    break;
                }
                else if (ChooseInPortage == 3)
                {
                    printf("Please input MASK file that you want to delete:");
                    scanf("%[^\n]",DeleteInPortage);
                    getchar();
                    delete_MASK(DeleteInPortage);
                    strcpy(DeleteInPortage,"");
                    printf("Returning...\n");
                    sleep(1);
                    break;
                }
                else
                {
                    cls();
                    choose_create_file_type_menu_in_portage();
                    scanf("%d",&ChooseInPortage);
                    getchar();
                }
            }
            portage_manage_menu();
            printf("Please input a number:");
            scanf("%d",&choose_5);
            getchar();
        }
        else if (choose_5 == 5)
        {
            cls();
            recover_backup();
            system("tree -lhp /etc/portage/package.use /etc/portage/package.accept_keywords /etc/portage/package.mask");
            printf("If you can check the package.use,package.accept_keywords,package.mask content directory, it means that the recovery has been successful, otherwise please confirm whether it is in backup has written content or reported to Bug.\n");
            printf("Return after 3 seconds\n");
            sleep(3);
            cls();
            portage_manage_menu();
            printf("Please input a munber:");
            scanf("%d",&choose_5);
            getchar();
        }
        else if (choose_5 == 6)
        {
            cls();
            break;
        }
        else
        {
            cls();
            portage_manage_menu();
            printf("Please input a number:");
            scanf("%d",&choose_5);
            getchar();
        }  
    }
}

void manage_package_and_repository(){
    cls();
    menu_folk();
    scanf("%d",&choose_1);
    getchar();
    while (choose_1)
    {
        if (choose_1 == 1)
        {
            cls();
            check_installed_packages_menu();
            scanf("%s",UserInput);
            getchar();
            package_check(UserInput);
            strcpy(UserInput,"");
            printf("Please input 1 to return:");
            int key;//checking "1" key
            scanf("%d",&key);
            getchar();
            if (key == 1)
            {
                cls();
                menu_folk();
                scanf("%d",&choose_1);
                getchar();
            }
            else
            {
                printf("Please input 1 to return:");
                scanf("%d",&key);
                getchar();
            }
        }
        else if (choose_1 == 2)
        {
            sleep(1);
            cls();
            package_uninstall_menu();
            scanf("%[^\n]",UserInput);
            getchar();
            if (strcmp(UserInput,"b") != 0 )
            {
                package_uninstall(UserInput);
                strcpy(UserInput,"");
            
                printf("Please input 1 to return:");
                int key;//checking "1" key
                scanf("%d",&key);
                getchar();
                if (key == 1)
                {
                    sleep(1);
                    cls();
                    menu_folk();
                    scanf("%d",&choose_1);
                    getchar();
                }
                else
                {
                    printf("Please input 1 to return:");
                    scanf("%d",&key);
                    getchar();
                }
            }
            else
            {
                sleep(1);
                cls();
                menu_folk();
                scanf("%d",&choose_1);
                getchar();
            }
        }
        else if (choose_1 == 3)
        {
            sleep(1);
            cls();
            package_install_menu();
            scanf("%[^\n]",UserInput);
            getchar();
            if (strcmp(UserInput,"b") != 0)
            {
                printf("\n\
                Please choose a way to install packages on your system:\n\
                1.install from src\n\
                2.install from binary(NOT EVERY PACKAGE CAN BE INSTALL BY BINARY PACKAGE)\n\
                3.return\n\
                Please choose:");
                scanf("%d",&choose_4);
                getchar();
                if (choose_4 == 1)
                {
                    package_install_src(UserInput);
                }
                else if (choose_4 == 2)
                {
                    package_install_binary(UserInput);
                }
                strcpy(UserInput,"");
                printf("Please input 1 to return:");
                int key;//checking "1" key
                scanf("%d",&key);
                getchar();
                if (key == 1)
                {
                    sleep(1);
                    cls();
                    menu_folk();
                    scanf("%d",&choose_1);
                    getchar();
                }
                else
                {
                    printf("Please input 1 to return:");
                    scanf("%d",&key);
                    getchar();
                }
            }
            else
            {
                sleep(1);
                cls();
                menu_folk();
                scanf("%d",&choose_1);
                getchar();
            }
        }    
        else if (choose_1 == 4)
        {
            sleep(1);
            cls();
            printf("Search packages or input b to go back to the previous menu\n\
            Please input:");
            scanf("%s",UserInput);
            if (strcmp(UserInput,"b") != 0)
            {
                package_search(UserInput);
                strcpy(UserInput,"");
                printf("Please input 1 to return:");
                int key;//checking "1" key
                scanf("%d",&key);
                getchar();
                if (key == 1)
                {
                    sleep(1);
                    cls();
                    menu_folk();
                    scanf("%d",&choose_1);
                    getchar();
                }
                else
                {
                    printf("Please press 1 to return:");
                    scanf("%d",&key);
                    getchar();
                }
            }
            else
            {
                cls();
                menu_folk();
                scanf("%d",&choose_1);
                getchar();
            }
        }
        else if (choose_1 == 5)
        {
            repository_manage();
            menu_folk();
            scanf("%d",&choose_1);
            getchar();                    
        }
        else if (choose_1 == 6)
        {
            advance_of_portage();
            menu_folk();
            scanf("%d",&choose_1);
            getchar();
        }
        
        else if (choose_1 == 7)
        {
            cls();
            break;
        }        
        else
        {
            cls();
            menu_folk();
            scanf("%d",&choose_1);
            getchar();
        }  
    }
}

void update_system(){
    sleep(1);
    cls();
    update_system_menu();
    scanf("%d",&choose_2);
    getchar();
    if (choose_2 == 1)
    {
        system_update_src();
        sleep(1);
        cls();
    }
    else if (choose_2 == 2)
    {
        system_update_binary();
        sleep(1);
        cls();
    }
    else if (choose_2== 3)
    {
        cls();
    }
    else
    {
        cls();
        update_system_menu();
        scanf("%d",&choose_2);
        getchar();  
    }
}

void about(){
    cls();
    about_menu();
    printf("Please input 1 to return:");
    int key;//checking "1" key
    scanf("%d",&key);
    getchar();
    while(key)
    {
        if (key == 1)
        {
            cls();
            break;
        }
        else
        {
            printf("Please press 1 to return:");
            scanf("%d",&key);
            getchar();
        }
    }
}