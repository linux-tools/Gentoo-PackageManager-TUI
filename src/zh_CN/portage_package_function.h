#ifndef PORTAGE_PACKAGE_FUNCTION_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char package_install_src(char a[255]);//从源码安装软件

char package_install_binary(char a[255]);//安装预编译的软件

char package_search(char a[255]);//软件搜索功能

char package_uninstall(char a[255]);//软件卸载功能

void system_update_src();//从源代码更新系统

void system_update_binary();//使用预编译的软件包软件更新

char package_check(char a[255]);//查看已安装的软件

char repo_add(char a[255]);//添加第三方软件仓库

char repo_enable(char a[255]);//开启第三方或官方软件仓库

char repo_disable(char a[255]);//禁用第三方或官方软件仓库

char repo_remove(char a[255]);//移除第三方或官方软件仓库

void repository_edit_binary();//编辑提供二进制软件包的软件仓库

void repository_edit_src();//编辑提供源代码软件包的软件仓库


#endif