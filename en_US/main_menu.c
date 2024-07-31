#include<stdio.h>

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
    *****----------------------1.View installed packages---------------------*****\n\
    ******************************************************************************\n\
    *****--------------------2.Uninstall packages you want-------------------*****\n\
    ******************************************************************************\n\
    *****---------------------3.install packages you want--------------------*****\n\
    ******************************************************************************\n\
    *****---------------4.Searching packages from your repository------------*****\n\
    ******************************************************************************\n\
    *****--------------------5.Manage package repositories-------------------*****\n\
    ******************************************************************************\n\
    *****--------------------6.Advanced options of Portage-------------------*****\n\
    ******************************************************************************\n\
    *****-------------------------------7.BACK-------------------------------*****\n\
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
    Please enter your content you want to uninstall\n\
    or input b to go back to the previous menu\n\
    Please input:");
}

void package_install_menu(){
    printf("\n\
    Please enter your content you want to install\n\
    or input b to go back to the previous menu\n\
    Please input:");
}

void package_repository_edit_menu(){
    printf("\n\
---------------------------------REPOSITORY-MANAGE-MENU------------------------------------\n\
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
******9.sync all repository                                                                \n\
******10.Back                                                                              \n\
-------------------------------------------------------------------------------------------\n\
-------------------------------------------------------------------------------------------\n\
####Please input:");
}

void portage_manage_menu(){
    printf("\n\
    *************************Advanced options Menu of Portage*********************\n\
    ******************************************************************************\n\
    *****-----------------1.backup USE,ACCEPT_KEYWORDS,MASK tags-------------*****\n\
    ******************************************************************************\n\
    *****-----------------2.create USE,ACCEPT_KEYWORDS,MASK tags-------------*****\n\
    ******************************************************************************\n\
    *****------------------3.edit USE,ACCEPT_KEYWORDS,MASK tags--------------*****\n\
    ******************************************************************************\n\
    *****-----------------4.delete USE,ACCEPT_KEYWORDS,MASK tags-------------*****\n\
    ******************************************************************************\n\
    *****-----------------5.recover USE,ACCEPT_KEYWORDS,MASK tags------------*****\n\
    ******************************************************************************\n\
    *****-------------------------------6.BACK-------------------------------*****\n\
    ******************************************************************************\n\
    ******************************************************************************\n\
    ");
}

void choose_create_file_type_menu_in_portage(){
    printf("\n\
    Please select the type of file you want to create:\n\
    1.USE\n\
    2.ACCEPT_KEYWORDS\n\
    3.MASK\n\
    Please choose:");
}

void choose_edit_file_type_menu_in_portage(){
    printf("\n\
    Please select the type of file you want to edit:\n\
    1.USE\n\
    2.ACCEPT_KEYWORDS\n\
    3.MASK\n\
    Please choose:");
}

void choose_delete_file_type_menu_in_portage(){
    printf("\n\
    Please select the type of file you want to delete:\n\
    1.USE\n\
    2.ACCEPT_KEYWORDS\n\
    3.MASK\n\
    Please choose:");
}

//Packagemanager Menu