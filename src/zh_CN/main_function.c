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
int ChooseInPortage;  //定义用户的输入变量
char ChooseRepo[255];
char CreateInPortage[255];
char EditInPortage[255];
char DeleteInPortage[255];

void cls(){
    system("clear");
}

void repository_manage(){
    sleep(1);//此为main_function.h中该函数的内容
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
            printf("返回中...\n");
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
            printf("返回中...\n");
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
            int key;//检查“1”键
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
                printf("请按1返回:");
                scanf("%d",&key);
                getchar();
            }
        }
        else if (choose_3 == 4)
        {
            cls();
            system("eselect repository list");
            printf("请输入要启用的名称:");
            scanf("%s",ChooseRepo);
            getchar();
            repo_enable(ChooseRepo);
            printf("完成!\n");
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
            printf("请输入要禁用的名称:");
            scanf("%s",ChooseRepo);
            getchar();
            repo_disable(ChooseRepo);
            printf("完成!\n");
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
            printf("请输入要删除的名称:");
            scanf("%s",ChooseRepo);
            getchar();
            repo_remove(ChooseRepo);
            printf("完成!\n");
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
            请输入您要自己添加的自定义存储库。\n\
            例子：<仓库名称> <同步方式（可决定你的URI地址）> <仓库的URI>\n\
            请输入:");
            scanf("%[^\n]",ChooseRepo);
            getchar();
            repo_add(ChooseRepo);
            printf("完成!\n");
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
            printf("完成!");
            sleep(1);
            cls();
            package_repository_edit_menu();
            scanf("%d",&choose_3);
            getchar();
        }                    
        else if (choose_3 == 9)
        {
            sleep(1);
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

void advance_of_portage(){//从169到387行的自定义函数来源于portage_manage.h
    create_floder_in_portage();
    sleep(1);
    cls();
    portage_manage_menu();
    printf("请输入一个数字:");
    scanf("%d",&choose_5);
    getchar();
    while (choose_5)
    {
        if (choose_5 == 1)
        {
            cls();
            backup();
            system("tree -lhp $HOME/.portage-tags/backup");
            printf("如果您可以检查备份内容目录，则表示备份已成功，否则请确认它是否在/etc/portage/package.use、/etc/portage-package.eccept_keywords、/etc/portage/package.mask中已写入内容或向Bug报告。\n");
            printf("3秒后返回\n");
            sleep(3);
            cls();
            portage_manage_menu();
            printf("请输入一个数字:");
            scanf("%d",&choose_5);
            getchar();
        }
        else if (choose_5 == 2)
        {
            sleep(1);
            cls();
            choose_create_file_type_menu_in_portage();
            scanf("%d",&ChooseInPortage);
            getchar();
            while (ChooseInPortage)
            {
                if (ChooseInPortage == 1)
                {
                    printf("请输入要创建的USE文件:");
                    scanf("%[^\n]",CreateInPortage);
                    getchar();
                    create_USE(CreateInPortage);
                    strcpy(CreateInPortage,"");
                    printf("返回中...\n");
                    sleep(1);
                    break;
                }
                else if (ChooseInPortage == 2)
                {
                    printf("请输入要创建的ACCEPT_KEYWORDS文件:");
                    scanf("%[^\n]",CreateInPortage);
                    getchar();
                    create_ACCEPT(CreateInPortage);
                    strcpy(CreateInPortage,"");
                    printf("返回中...\n");
                    sleep(1);
                    break;
                }
                else if (ChooseInPortage == 3)
                {
                    printf("请输入要创建的MASK文件:");
                    scanf("%[^\n]",CreateInPortage);
                    getchar();
                    create_MASK(CreateInPortage);
                    strcpy(CreateInPortage,"");
                    printf("返回中...\n");
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
            printf("请输入一个数字:");
            scanf("%d",&choose_5);
            getchar();            
        }
        else if (choose_5 == 3)
        {
            sleep(1);
            cls();
            choose_edit_file_type_menu_in_portage();
            scanf("%d",&ChooseInPortage);
            getchar();
            while (ChooseInPortage)
            {
                if (ChooseInPortage == 1)
                {
                    printf("请输入要编辑的USE文件:");
                    scanf("%[^\n]",EditInPortage);
                    getchar();
                    edit_USE(EditInPortage);
                    strcpy(EditInPortage,"");
                    printf("返回中...\n");
                    sleep(1);
                    break;
                }
                else if (ChooseInPortage == 2)
                {
                    printf("请输入要编辑的ACCEPT_KEYWORDS文件:");
                    scanf("%[^\n]",EditInPortage);
                    getchar();
                    edit_ACCEPT(EditInPortage);
                    strcpy(EditInPortage,"");
                    printf("返回中...\n");
                    sleep(1);
                    break;
                }
                else if (ChooseInPortage == 3)
                {
                    printf("请输入要编辑的MASK文件:");
                    scanf("%[^\n]",EditInPortage);
                    getchar();
                    edit_MASK(EditInPortage);
                    strcpy(EditInPortage,"");
                    printf("返回中...\n");
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
            printf("请输入一个数字:");
            scanf("%d",&choose_5);
            getchar();
        }
        else if (choose_5 == 4)
        {
            sleep(1);
            cls();
            choose_delete_file_type_menu_in_portage();
            scanf("%d",&ChooseInPortage);
            getchar();
            while (ChooseInPortage)
            {
                if (ChooseInPortage == 1)
                {
                    printf("请输入要删除的USE文件:");
                    scanf("%[^\n]",DeleteInPortage);
                    getchar();
                    delete_USE(DeleteInPortage);
                    strcpy(DeleteInPortage,"");
                    printf("返回中\n");
                    sleep(1);
                    break;
                }
                else if (ChooseInPortage == 2)
                {
                    printf("请输入要删除的ACCEPT_KEYWORDS文件:");
                    scanf("%[^\n]",DeleteInPortage);
                    getchar();
                    delete_ACCEPT(DeleteInPortage);
                    strcpy(DeleteInPortage,"");
                    printf("返回中...\n");
                    sleep(1);
                    break;
                }
                else if (ChooseInPortage == 3)
                {
                    printf("请输入要删除的MASK文件:");
                    scanf("%[^\n]",DeleteInPortage);
                    getchar();
                    delete_MASK(DeleteInPortage);
                    strcpy(DeleteInPortage,"");
                    printf("返回中...\n");
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
            printf("请输入一个数字:");
            scanf("%d",&choose_5);
            getchar();
        }
        else if (choose_5 == 5)
        {
            cls();
            recover_backup();
            system("tree -lhp /etc/portage/package.use /etc/portage/package.accept_keywords /etc/portage/package.mask");
            printf("如果您可以检查package.use、package.eccept_keywords、package.mask内容目录，则表示恢复已成功，否则请确认备份中是否有写入内容或报告Bug。\n");
            printf("3秒后返回\n");
            sleep(3);
            cls();
            portage_manage_menu();
            printf("请输入一个数字:");
            scanf("%d",&choose_5);
            getchar();
        }
        else if (choose_5 == 6)
        {
            sleep(1);
            cls();
            break;
        }
        else
        {
            cls();
            portage_manage_menu();
            printf("请输入一个数字:");
            scanf("%d",&choose_5);
            getchar();
        }  
    }
}

void manage_package_and_repository(){//此为main_function.h中该函数的内容
    sleep(1);
    cls();
    menu_folk();
    scanf("%d",&choose_1);
    getchar();
    while (choose_1)
    {
        if (choose_1 == 1)
        {
            sleep(1);
            cls();
            check_installed_packages_menu();
            scanf("%s",UserInput);
            getchar();
            package_check(UserInput);
            strcpy(UserInput,"");
            printf("请输入1返回:");
            int key;//检查“1”键
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
                printf("请输入1返回:");
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
            
                printf("请输入1返回:");
                int key;//检查“1”键
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
                    printf("请输入1返回:");
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
                请选择一种在您的系统上安装软件包的方法：\n\
                1.从src安装\n\
                2.从二进制安装（并非每个包都可以通过二进制包安装）\n\
                3.返回\n\
                请选择：");
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
                printf("请输入1返回:");
                int key;//检查“1”键
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
                    printf("请输入1返回:");
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
            printf("搜索包或输入b返回上一菜单\n\
                    请输入：");
            scanf("%s",UserInput);
            if (strcmp(UserInput,"b") != 0)
            {
                package_search(UserInput);
                strcpy(UserInput,"");
                printf("请输入1返回:");
                int key;//检查“1”键
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
                    printf("请输入1返回:");
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
        else if (choose_1 == 5)
        {
            repository_manage();
            sleep(1);
            cls();
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
            sleep(1);
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
    printf("\n\
    ******************************************************\n\
    ******************************************************\n\
    **版本:v3.0-RC1                                      **\n\
    **软件依赖:gentoolkit,eselect-repository,sudo,tree   **\n\
    **作者:Super111                                      **\n\
    **作者主页:https://gitee.com/Linux-Tool              **\n\
    ******************************************************\n\
    ******************************************************\n\
    ");
    printf("请输入1返回:");
    int key;//检查“1”键
    scanf("%d",&key);
    getchar();
    while(1)
    {
        if (key == 1)
        {
            cls();
            break;
        }
        else
        {
            printf("请输入1返回:");
            scanf("%d",&key);
            getchar();
        }
    }
}