#ifndef PORTAGE_MANAGE_H

void create_floder_in_portage();/*Create floders in "/etc/portage/package.use  /etc/portage/package.accept_keyworlds /etc/portage/package.mask" 
to facilitate the management of the software's USE tags,mask logos,and other functions*/

void initialization_of_relate_variables();//Initialize portage-related variables 

void backup();

void recover_backup();

char edit_USE(char a[255]);

char edit_MASK(char a[255]);

char edit_ACCEPT(char a[255]);

char create_USE(char a[255]);

char create_MASK(char a[255]);

char create_ACCEPT(char a[255]);

char delete_USE(char a[255]);

char delete_MASK(char a[255]);

char delete_ACCEPT(char a[255]);

#endif