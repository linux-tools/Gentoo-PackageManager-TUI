#ifndef PORTAGE_MANAGE_H

void create_floder_in_portage();

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