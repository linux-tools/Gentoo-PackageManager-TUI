# Gentoo-PackageManager

#### Description

Gentoo-PackageManager,a package TUI manager of portage by C programing,is included many useful functions,ranging from checking installed packages,updating system to editing repository.

#### Software Architecture

In terms of source portability,the software theoretically support all architectures.

#### Installation

Install dependencies:
app-eselect/eselect-repository,app-portage/gentoolkit app-admin/sudo

Please execute "emerge --ask app-eselect/eselect-repository app-portage/gentoolkit" to install dependencies.

install:
Please execute "make && make install" to build and install gentoo-packagemanager.
You can remove /usr/bin/gentoo-packagemanager to uninstall.

#### Instructions

Please enter numbers and do not enter strings at random.
Considering that it is used on the server, it temporarily supports English! Chinese follow-up support (please run under X11, wayland or a terminal that supports Chinese for the Chinese version).
Please follow the menu prompts.

#### Introduction to the software interface

the following interface is screenshotted on gnome45:
This is the main page of the software
![Figure 0](images/823e5dbdd6b03d0f55c3900960ef887bdc7c79767b1495900db92746db44013e.png)

This is the package management page
![Figure 1](images/f9cce90da395b82b5a0cea467b83f00e5a4788b8d82c2130bd9b47092e5fb0ec.png)

This is the menu for editing the repository
![Figure 2](images/13c2833c8458bdfbb4136ec176db9c92bb6a58e333f49c21498082ac2c29f3ad.png)

This is the system update interface
![Figure 3](images/ff5d2da03c9b02f1b27c6e4cb74f11f2e11956e6023bed70a0e08ecbf17ec781.png)  
