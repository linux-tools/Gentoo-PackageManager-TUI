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
Considering that it is used on the server, it temporarily supports English! Chinese follow-up support (please run under X11, wayland or a terminal that supports Chinese for the Chinese version)
