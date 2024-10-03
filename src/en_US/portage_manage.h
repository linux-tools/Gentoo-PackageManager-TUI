#ifndef PORTAGE_MANAGE_H//The following operations carry risks, please proceed with caution

void create_floder_in_portage();//Equivalent to an initialization operation, create folders in the /etc/portage directory:/etc/portage/package.use,/etc/portage/package.mask,/etc/portage/package.accept_keywords, which are easy to use for later software advanced management operations such as changing the USE identifier, locking packages, replacing some software update branches, etc

void backup();//Backup operation

void recover_backup();//The operation of restoring the original directory and files through backup

char edit_USE(char a[255]);//Edit the relevant files in the "/etc/portage/package.use" directory to adjust the dependency relationships of some software, making it easier to customize your own system through specific compiled software packages

char edit_MASK(char a[255]);//Edit the relevant files in the "/etc/portage/package.mask" directory, block or enable some problematic software packages, and use them to adjust the dependency relationships of some software

char edit_ACCEPT(char a[255]);//Edit the relevant files in the "/etc/portage/package.accept_keywords" directory, adjust some software update branches, and enable or disable some software that can only be installed on systems with unstable branch updates enabled

char create_USE(char a[255]);//Create relevant files in the directory "/etc/portage/package.use", with the same function as above

char create_MASK(char a[255]);//Create relevant files in the directory "/etc/portal/package.mask", with the same function as above

char create_ACCEPT(char a[255]);//Create relevant files in the directory "/etc/portal/package.accept_keywords", with the same function as above

char delete_USE(char a[255]);//Delete the relevant files in the "/etc/portal/package.use" directory, with the same function as above

char delete_MASK(char a[255]);//Delete the relevant files in the "/etc/portal/package.mask" directory, with the same function as above

char delete_ACCEPT(char a[255]);//Delete the relevant files in the "/etc/portal/package.accept_keywords" directory, with the same function as above

char edit_make_conf();//Edit "/etc/portage/make.conf"

#endif