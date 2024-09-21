# Gentoo-PackageManager

#### Description

Gentoo-PackageManager,a package TUI(Text User Interface) manager of portage by C programing,is included many useful functions,ranging from checking installed packages,updating system to editing repository.

#### Software Architecture

In terms of source portability,the software theoretically support all architectures.Only support Gentoo GNU/Linux

#### Installation

Install dependencies:
app-eselect/eselect-repository,app-portage/gentoolkit,app-admin/sudo,app-text/tree,app-editors/neovim

Please execute "emerge --ask app-eselect/eselect-repository app-portage/gentoolkit app-admin/sudo,app-text/tree,app-editors/neovim" to install dependencies.

install:
Download the package on the Release and unzip it and run the install.sh to install it, and use the uninstall.sh to uninstall 😃 it

Install from source code: This operation is risky, and the compiled program may be problematic, please be cautious 😕

Compilation Options: 
Run "make all" to compile everything

Run "make zh" to compile only the Chinese version

Run "make en" to compile only the English version (not recommended 😕)

Run "make package" to package the software as a "tar.gz" file

 Installation && Uninstallation Options: 
 
 Run ”make install_en“ install the English version
 
 Run the "make install_zh" install the Chinese version ("make zh && install_zh", "make en && make install_en" will make the language switching option unavailable!! 😟 )
 
 Run the make install command to install the dual-language version, the default selection of Chinese

make uninstall:You know the command that used to uninstall the software

Cleaning Options:

make clean_all:Clean all the files

make clean_excess_files:Clean the files produced by the C compiler,such as ".o" file

make clean_rmpkg:delete the packaged file(tar.gz file)

#### Instructions

Please enter numbers and do not enter strings at random.
Considering that it is used on the server, it temporarily supports English! Chinese follow-up support (please run under X11, wayland or a terminal that supports Chinese for the Chinese version).
Please follow the menu prompts.

#### About Portage knowledges

USE,ACCEPT_KEYWORDS,MASK tags are important part in Gentoo GNU/Linux or Musl C  version of the Gentoo Linux that can control package installing,upgrading,downgrading,masking and blocking operations.(Most of the images come from Gentoo user forums, and a few come from Baidu Tieba and other sources)

USE:
USE tags can customize the features of packages,which determines whether the software you install can be acquired and installed in binary form and determines how many features are included in the software you install. By adding or removing USE tags, the dependencies of the package may be increased or reduced, and the value appreciation will lead to the circular dependency of the package, which will bring unnecessary trouble to the system update.Even package dependency conflicts can occur due to USE tags, causing system updates to fail

e.g.

![Figure 0](images/80bdca7261eba11a1413a799eca6bbac368eb85320229d9b4f2069bf80a30ffc.png)  
![Figure 1](images/391035e73226552cf6c4033e95a7229223228f3a02e39b976bd79498cd0b163b.png)  
![Figure 2](images/3c5e46595b3bd2b66f290faf43bca211e89b31b2f33485b58014809c366b1de1.png)  

ACCEPT_KEYWORDS:
When installing Gentoo, ACCEPT_KEYWORDS="amd64" or ACCEPT_KEYWORDS="~amd64" will appear when selecting a stable or unstable branch of the software, which decide how often the system or software is updated. Some software is also blocked for this reason, and it is possible to install the blocked package by manually modifying the ACCEPT_KEYWORDS.

e.g.

![Figure 3](images/4486e250d6cc524899b3f06de31c6eed4bbe4e4cd0967b75ba2637a3349e6694.png)  
![Figure 4](images/c6ee2269ced378ee465bfc4d81fd7c7b879f8c55ddf55630bcde961fb4b0982a.png)  

MASK:
With the MASK tag,we can lock the version of a package or block packages that we don't need. However, for system updates, this operation is more dangerous, and you need to consider the dependency problems caused by USE tags.The masking of packages is related to ACCEPT_KEYWORDS tags.

e.g.
![Figure 5](images/c5092ecccf234c21c49ae706da5e2e5e33be23c6f0630e9dea19b05ac4f81b7b.png)  

#### Introduction to the software interface

the following interface is screenshotted on gnome45:

![Figure 6](images/888ad94d96e1dd525cb553229b9610e21cf7b1cde81d71657b0584ec047dc4f6.png)  

![Figure 7](images/4571f69f63226806978ea6ba413a32a48ef2e68fe527538b30457f2c2ff6cc94.png)  

![Figure 8](images/d33ec84f368e6e052634b3447ae2cf365b7d367dcd319c47a14b86be1d63771c.png)  

![Figure 9](images/36a5047f45da11e8265ea5cc6c70fe4a42b79b2a1d14d0447b81b54e6d0a906b.png)  

![Figure 10](images/f466783ebc0fbb1bb0154fca3e508bd6fa19c241de294f738e9f628d99a79bd4.png)  

![Figure 11](images/045204cea7fe0045d331b51f837308b6cb3c427d70aa47e5734608469eb379a5.png)

#### Author's statement

None :laughing:
