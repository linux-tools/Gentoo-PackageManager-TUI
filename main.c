#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "package.h"
char _user_input[255];
char _user_choose_editor[255];//string variable
int _choose_;
int _choose_1_;
int _choose_2_;
int _choose_3_;   //define users' inputation variable
char _choose_repo_[255];

int main(){
    cls();
    menu_main();
    scanf("%d",&_choose_);
    while (_choose_)
    {
        if (_choose_ == 1)
        {
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
                else if (_choose_1_ == 4)
                {
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
                            sleep(3);
                            cls();
                            package_repository_edit_menu();
                            scanf("%d",&_choose_3_);
                            getchar();
                        }
                        else if (_choose_3_ == 2)
                        {
                            repository_edit_src(_user_choose_editor);
                            printf("Returning...\n");
                            sleep(3);
                            cls();
                            package_repository_edit_menu();
                            scanf("%d",&_choose_3_);
                            getchar();
                        }
                        else if (_choose_3_ == 3)
                        {
                            repository_edit_binary(_user_choose_editor);
                            printf("Returning...\n");
                            sleep(3);
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
                            system("eselect repository list");
                            printf("Please enter name that you want to enable:");
                            scanf("%s",_choose_repo_);
                            getchar();
                            repo_enable(_choose_repo_);
                            printf("Done!\n");
                            sleep(3);
                            cls();
                            package_repository_edit_menu();
                            scanf("%d",&_choose_3_);
                            getchar();
                        }
                        else if (_choose_3_ == 6)
                        {
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
                            system("eselect repository list");
                            printf("\n\
                            Please input custom repository that you want to add by your own\n\
                            e.g. <name> <sync-type> <sync-uri>\n\
                            Please input:");
                            scanf("%[^\n]",_choose_repo_);
                            getchar();
                            repo_add(_choose_repo_);
                            printf("Done!\n");
                            sleep(3);
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
                            goto PANIC_1;
                        }
                    }
                    sleep(1);
                    cls();
                    menu_folk();
                    scanf("%d",&_choose_1_);
                    getchar();
                    
                }
                else if (_choose_1_ == 5)
                {
                    sleep(3);
                    cls();
                    break;
                }
                
                else
                {
                    goto PANIC_1;
                }  
            }
        menu_main();
        scanf("%d",&_choose_);
        getchar();   
        }
        else if (_choose_ == 2)
        {
            sleep(1);
            cls();
            update_system_menu();
            scanf("%d",&_choose_2_);
            getchar();
            if (_choose_2_ == 1)
            {
                system_update_src();
                sleep(3);
                cls();
                menu_main();
                scanf("%d",&_choose_);
                getchar();
            }
            else if (_choose_2_ == 2)
            {
                system_update_binary();
                sleep(3);
                cls();
                menu_main();
                scanf("%d",&_choose_);
                getchar();
            }
            else if (_choose_2_== 3)
            {
                cls();
                menu_main();
                scanf("%d",&_choose_);
                getchar();
            }
            else
            {
                goto PANIC_1;   
            }
        }
        else if (_choose_ == 3)
        {
            cls();
            version();
            printf("Please input 1 to return:");
            int a;//checking "1" key
            scanf("%d",&a);
            getchar();
            if (a == 1)
            {
                cls();
                menu_main();
                scanf("%d",&_choose_);
                getchar();
            }
            else
            {
                printf("Please press 1 to return:");
                scanf("%d",&a);
                getchar();
            }
        }
        else if (_choose_ == 4)
        {
            cls();
            printf("See you next time!\n");
            sleep(1);
            break;
        }
        else if (_choose_ == 5)
        {
            goto PANIC_1;
        }
    }  
    return 0;
    PANIC_1: panic_1();//Error area
    }
