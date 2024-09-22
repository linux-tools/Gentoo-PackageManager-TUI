#ifndef PORTAGE_MANAGE_H//以下操作均存在风险，请慎重操作

void create_floder_in_portage();// 相当于初始化操作，在/etc/portage目录下创建文件夹:/etc/portage/package.use、/etc/portage/package.mask、/etc/portage/package.accept_keywords，便于后续用于更改USE标识，锁包，更换部分软件更新分支等软件高级管理操作

void backup();// 备份操作，备份/etc/portage目录下相关目录:/etc/portage/package.use、/etc/portage/package.mask、/etc/portage/package.accept_keywords，以防损坏

void recover_backup();// 用备份恢复原目录及文件的操作，与备份操作相反，用于恢复/etc/portage/package.use、/etc/portage/package.mask、/etc/portage/package.accept_keywords这三个目录

char edit_USE(char a[255]);// 编辑“/etc/portage/package.use”目录下的相关文件，用来调整部分软件的依赖关系，从而通过特定编译的软件包便于自定义自己的系统

char edit_MASK(char a[255]);// 编辑“/etc/portage/package.mask”目录下的相关文件，屏蔽或启用部分有问题的软件包，从而用来调整部分软件的依赖关系

char edit_ACCEPT(char a[255]);// 编辑“/etc/portage/package.accept_keywords”目录下的相关文件，调整部分软件更新分支，从而启用或关闭一些只能在启用不稳定分支更新的系统才能安装的软件

char create_USE(char a[255]);// 创建“/etc/portage/package.use”目录下的相关文件，作用同上

char create_MASK(char a[255]);// 创建“/etc/portage/package.mask”目录下的相关文件，作用同上

char create_ACCEPT(char a[255]);// 创建“/etc/portage/package.accept_keywords”目录下的相关文件，作用同上

char delete_USE(char a[255]);// 删除“/etc/portage/package.use”目录下的相关文件，作用同上

char delete_MASK(char a[255]);// 删除“/etc/portage/package.mask”目录下的相关文件，作用同上

char delete_ACCEPT(char a[255]);// 删除“/etc/portage/package.accept_keywords”目录下的相关文件，作用同上

#endif