#include<stdio.h>

void menu_main(){
    printf("\n\
    **********************Gentoo-PackageManager-TUI*******************\n\
    *******************************欢迎菜单***************************\n\
    ******************************************************************\n\
    *****---------------1.管理您的软件包和软件存储库-------------*****\n\
    ******************************************************************\n\
    *****-------------------------2.更新系统---------------------*****\n\
    ******************************************************************\n\
    *****---------------------------3.关于-----------------------*****\n\
    ******************************************************************\n\
    *****---------------------------4.语言-----------------------*****\n\
    ******************************************************************\n\
    *****---------------------------5.退出-----------------------*****\n\
    ******************************************************************\n\
    ******************************************************************\n\
    请输入一个数字:");
}

void menu_folk(){
    printf("\n\
    ************************************管理菜单**********************************\n\
    ******************************************************************************\n\
    *****-------------------------1.查看已安装的软件包-----------------------*****\n\
    ******************************************************************************\n\
    *****--------------------------2.卸载所需的软件包------------------------*****\n\
    ******************************************************************************\n\
    *****--------------------------3.安装所需的软件包------------------------*****\n\
    ******************************************************************************\n\
    *****------------------------4.从存储库中搜索软件包----------------------*****\n\
    ******************************************************************************\n\
    *****--------------------------5.管理软件包存储库------------------------*****\n\
    ******************************************************************************\n\
    *****--------------------------6.Portage的高级选项-----------------------*****\n\
    ******************************************************************************\n\
    *****-------------------------------7.返回-------------------------------*****\n\
    ******************************************************************************\n\
    ******************************************************************************\n\
    请输入一个数字:");
}

void check_installed_packages_menu(){
    printf("\n\
    您可以输入要搜索包组\n\
    注意：该函数基于“equery”命令。这就是我们依赖“gentoolkit”包的原因\n\
    -----------------------------------------------------\n\
    例如：您输入了'app-misc/*'\n\
    您将看到以下内容:\n\
    [IP-] [  ] app-misc/ca-certificates-20240203.3.98:0\n\
    [IP-] [  ] app-misc/editor-wrapper-4-r1:0\n\
    [IP-] [  ] app-misc/fastfetch-2.13.2:0\n\
    [IP-] [  ] app-misc/mime-types-2.1.54:0\n\
    [IP-] [  ] app-misc/pax-utils-1.3.7:0\n\
    -----------------------------------------------------\n\
    您输入'sudo'                                         \n\
    您将看到以下内容:                                     \n\
    * Searching for sudo ...                             \n\
    [IP-] [  ] app-admin/sudo-1.9.15_p5:0                \n\
    -----------------------------------------------------\n\
    您还可以输入'*'（包括单个qute）来检查计算机上已安装的软件包\n\
    -----------------------------------------------------\n\
    Please input:");
}

void update_system_menu(){
    printf("\n\
        请选择一种更新系统的方式:\n\
        1.从源代码安装\n\
        2.从二进制安装（并非每个包都可以通过二进制包安装）\n\
        3.返回\n\
        请选择:");
}

void package_uninstall_menu(){
    printf("\n\
    请输入要卸载的内容\n\
    或输入b返回上一菜单\n\
    请输入:");
}

void package_install_menu(){
    printf("\n\
    请输入要安装的内容\n\
    或输入b返回上一菜单\n\
    请输入：");
}

void package_repository_edit_menu(){
    printf("\n\
--------------------------------------仓库管理菜单------------------------------------------\n\
-------------------------------------------------------------------------------------------\n\
警告：第1项和第2项操作将非常危险，我建议执行3-7个选项去编辑一些存储库，除非您只是更改镜像以加快获 \n\
取包和更新根据您的位置调整软件包获取速度。切勿删除gentoo源。你被警告了！                         \n\
-------------------------------------------------------------------------------------------\n\
-------------------------------------------------------------------------------------------\n\
******1.编辑src存储库（直接编辑/etc/portage/rerepos.conf/gentoo.conf）                       \n\
******2.编辑二进制存储库（直接编辑/etc/portage/binrepos.conf/gentoobinhost.conf）            \n\
******3.检查可用仓库                                                                        \n\
******4.添加并启用第三方存储库                                                               \n\
******5.禁用存储库（包括官方和第三方存储库）                                                  \n\
******6.禁用存储库（包括官方和第三方存储库）                                                  \n\
******7.添加您自己的存储库（不在在线eselect-repository存储库列表中）                           \n\
******8.同步所有存储库                                                               \n\
******9.返回                                                                              \n\
-------------------------------------------------------------------------------------------\n\
-------------------------------------------------------------------------------------------\n\
####请输入:");
}

void portage_manage_menu(){
    printf("\n\
    *******************************Portage高级选项菜单****************************\n\
    ******************************************************************************\n\
    *****------------------1.备份 USE,ACCEPT_KEYWORDS,MASK tags--------------*****\n\
    ******************************************************************************\n\
    *****------------------2.创建 USE,ACCEPT_KEYWORDS,MASK tags--------------*****\n\
    ******************************************************************************\n\
    *****------------------3.编辑 USE,ACCEPT_KEYWORDS,MASK tags--------------*****\n\
    ******************************************************************************\n\
    *****------------------4.删除 USE,ACCEPT_KEYWORDS,MASK tags--------------*****\n\
    ******************************************************************************\n\
    *****------------------5.恢复 USE,ACCEPT_KEYWORDS,MASK tags--------------*****\n\
    ******************************************************************************\n\
    *****-------------------------------6.返回-------------------------------*****\n\
    ******************************************************************************\n\
    ******************************************************************************\n\
    ");
}

void choose_create_file_type_menu_in_portage(){
    printf("\n\
    请选择要创建的文件类型:\n\
    1.USE\n\
    2.ACCEPT_KEYWORDS\n\
    3.MASK\n\
    请选择:");
}

void choose_edit_file_type_menu_in_portage(){
    printf("\n\
    请选择要编辑的文件类型:\n\
    1.USE\n\
    2.ACCEPT_KEYWORDS\n\
    3.MASK\n\
    请选择:");
}

void choose_delete_file_type_menu_in_portage(){
    printf("\n\
    请选择要删除的文件类型:\n\
    1.USE\n\
    2.ACCEPT_KEYWORDS\n\
    3.MASK\n\
    请选择:");
}

//Packagemanager Menu