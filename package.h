#ifndef PACKAGE_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char package_install_src(char a[255]);//Gentoo's packages installation founction

char package_install_binary(char a[255]);//Gentoo's packages installation founction

char package_search(char a[255]);//Gentoo's packages searching founction

char package_uninstall(char a[255]);//Gentoo's package uninstallation founction

void system_update_src();

void system_update_binary();//Gentoo's system packages update function

char package_check(char a[255]);/*Managing installed packages and parameter "a" represent package group*/

char repo_add(char a[255]);

char repo_enable(char a[255]);

char repo_disable(char a[255]);

char repo_remove(char a[255]);

void menu_main();

void menu_folk();

void check_installed_packages_menu();

void update_system_menu();

void package_uninstall_menu();

void package_install_menu();

void package_repository_edit_menu();//Packagemanager Menu

void repository_edit_binary();

void repository_edit_src();

void version();

void cls();

int editor_choose(int a);

void editor_check();

void panic_1();//Error area

#endif