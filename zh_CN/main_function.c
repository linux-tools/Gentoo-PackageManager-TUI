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
            printf("请选择:");
            int b;
            scanf("%d",&b);
            sleep(1);
            editor_choose(b);
            editor_check();
            printf("返回中...\n");
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
            printf("返回中...\n");
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
            printf("返回中...\n");
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
                printf("请按1返回:");
                scanf("%d",&a);
                getchar();
            }
        }
        else if (_choose_3_ == 5)
        {
            cls();
            system("eselect repository list");
            printf("请输入要禁用的名称:");
            scanf("%s",_choose_repo_);
            getchar();
            repo_enable(_choose_repo_);
            printf("完成!\n");
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
            printf("请输入要禁用的名称:");
            scanf("%s",_choose_repo_);
            getchar();
            repo_disable(_choose_repo_);
            printf("完成!\n");
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
            printf("请输入要删除的名称:");
            scanf("%s",_choose_repo_);
            getchar();
            repo_remove(_choose_repo_);
            printf("完成!\n");
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
            请输入您要自己添加的自定义存储库。\n\
            例子：<仓库名称> <同步方式（可决定你的URI地址）> <仓库的URI>\n\
            请输入:");
            scanf("%[^\n]",_choose_repo_);
            getchar();
            repo_add(_choose_repo_);
            printf("完成!\n");
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
            printf("完成!");
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
    portage_manage_menu();
    printf("请输入一个数字:");
    scanf("%d",&_choose_5_);
    getchar();
    while (_choose_5_)
    {
        if (_choose_5_ == 1)
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
                    printf("请输入要创建的USE文件:");
                    scanf("%[^\n]",_create_in_portage);
                    getchar();
                    create_USE(_create_in_portage);
                    strcpy(_create_in_portage,"");
                    printf("返回中...\n");
                    sleep(1);
                    break;
                }
                else if (_choose_in_portage_ == 2)
                {
                    printf("请输入要创建的ACCEPT_KEYWORDS文件:");
                    scanf("%[^\n]",_create_in_portage);
                    getchar();
                    create_ACCEPT(_create_in_portage);
                    strcpy(_create_in_portage,"");
                    printf("返回中...\n");
                    sleep(1);
                    break;
                }
                else if (_choose_in_portage_ == 3)
                {
                    printf("请输入要创建的MASK文件:");
                    scanf("%[^\n]",_create_in_portage);
                    getchar();
                    create_MASK(_create_in_portage);
                    strcpy(_create_in_portage,"");
                    printf("返回中...\n");
                    sleep(1);
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
            printf("请输入一个数字:");
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
                    printf("请输入要编辑的USE文件:");
                    scanf("%[^\n]",_edit_in_portage);
                    getchar();
                    edit_USE(_edit_in_portage);
                    strcpy(_edit_in_portage,"");
                    printf("返回中...\n");
                    sleep(1);
                    break;
                }
                else if (_choose_in_portage_ == 2)
                {
                    printf("请输入要编辑的ACCEPT_KEYWORDS文件:");
                    scanf("%[^\n]",_edit_in_portage);
                    getchar();
                    edit_ACCEPT(_edit_in_portage);
                    strcpy(_edit_in_portage,"");
                    printf("返回中...\n");
                    sleep(1);
                    break;
                }
                else if (_choose_in_portage_ == 3)
                {
                    printf("请输入要编辑的MASK文件:");
                    scanf("%[^\n]",_edit_in_portage);
                    getchar();
                    edit_MASK(_edit_in_portage);
                    strcpy(_edit_in_portage,"");
                    printf("返回中...\n");
                    sleep(1);
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
            printf("请输入一个数字:");
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
                    printf("请输入要删除的USE文件:");
                    scanf("%[^\n]",_delete_in_portage);
                    getchar();
                    delete_USE(_delete_in_portage);
                    strcpy(_delete_in_portage,"");
                    printf("返回中\n");
                    sleep(1);
                    break;
                }
                else if (_choose_in_portage_ == 2)
                {
                    printf("请输入要删除的ACCEPT_KEYWORDS文件:");
                    scanf("%[^\n]",_delete_in_portage);
                    getchar();
                    delete_ACCEPT(_delete_in_portage);
                    strcpy(_delete_in_portage,"");
                    printf("返回中...\n");
                    sleep(1);
                    break;
                }
                else if (_choose_in_portage_ == 3)
                {
                    printf("请输入要删除的MASK文件:");
                    scanf("%[^\n]",_delete_in_portage);
                    getchar();
                    delete_MASK(_delete_in_portage);
                    strcpy(_delete_in_portage,"");
                    printf("返回中...\n");
                    sleep(1);
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
            printf("请输入一个数字:");
            scanf("%d",&_choose_5_);
            getchar();
        }
        else if (_choose_5_ == 5)
        {
            cls();
            recover_backup();
            system("tree -lhp $_PORTAGE_USE $_PORTAGE_ACCEPT $_PORTAGE_MASK");
            printf("如果您可以检查package.use、package.eccept_keywords、package.mask内容目录，则表示恢复已成功，否则请确认备份中是否有写入内容或报告Bug。\n");
            printf("10秒后返回\n");
            sleep(10);
            cls();
            portage_manage_menu();
            printf("请输入一个数字:");
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
            printf("请输入一个数字:");
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
            printf("请输入1返回:");
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
                printf("请输入1返回:");
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
            
                printf("请输入1返回:");
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
                    printf("请输入1返回:");
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
                请选择一种在您的系统上安装软件包的方法：\n\
                1.从src安装\n\
                2.从二进制安装（并非每个包都可以通过二进制包安装）\n\
                3.返回\n\
                请选择：");
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
                printf("请输入1返回:");
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
                    printf("请输入1返回:");
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
            printf("搜索包或输入b返回上一菜单\n\
                    请输入：");
            scanf("%s",_user_input);
            if (strcmp(_user_input,"b") != 0)
            {
                package_search(_user_input);
                strcpy(_user_input,"");
                printf("请输入1返回:");
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
                    printf("请输入1返回:");
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
    **版本:v3.0-beta-dev1                                **\n\
    **软件依赖:gentoolkit,eselect-repository,sudo,tree   **\n\
    **作者:Super111                                      **\n\
    **作者主页:https://gitee.com/Linux-Tool              **\n\
    ******************************************************\n\
    ******************************************************\n\
    ");
    printf("请输入1返回:");
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
            printf("请输入1返回:");
            scanf("%d",&a);
            getchar();
        }
    }
}