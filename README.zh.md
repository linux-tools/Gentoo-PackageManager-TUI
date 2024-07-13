#### 介绍

使用C语言编写的Gentoo TUI 的portage包管理系统前端工具，包括查看已安装软件，更新系统，更改软件仓库等功能

#### 软件架构

软件架构说明
从源码可移植性上来讲，理论上支持全架构

#### 安装教程

安装依赖：app-portage/gentoolkit,app-eselect/select-repository,app-admin/sudo,app-text/tree
执行make、make install 即可，如需卸载，请删除"/usr/bin/gentoo-packagemanager"即可
也可以下载Release上的包解压并执行install.sh来安装，用uninstall.sh来卸载

#### 使用说明

请以输入数字的方式进行操作，切勿随意输入字符串。
考虑到使用在服务器上，故暂时支持英文！中文后续支持（中文版本请在X11,wayland或支持中文的终端下运行）
根据菜单提示进行操作.

#### 关于Portage知识

USE，ACCEPT_KEYWORDS，MASK标签是Gentoo GNU/Linux或"Musl C" Gentoo Linux中的重要部分，可以控制软件包的安装、升级、降级、屏蔽和阻塞操作。(图片来源多来自Gentoo用户论坛，少数来自百度贴吧以及其他来源)

USE：
USE标签可以自定义软件包的功能，这决定了你安装的软件是否可以以二进制形式获取和安装，并决定了你安装的软件包含多少功能。通过添加或删除 USE 标签，可能会增加或减少包的依赖性，而增值会导致包的循环依赖，这会给系统更新带来不必要的麻烦。甚至由于 USE 标记，也可能发生包依赖冲突，从而导致系统更新失败

e.g.

![Figure 0](images/80bdca7261eba11a1413a799eca6bbac368eb85320229d9b4f2069bf80a30ffc.png)  
![Figure 1](images/391035e73226552cf6c4033e95a7229223228f3a02e39b976bd79498cd0b163b.png)  
![Figure 2](images/3c5e46595b3bd2b66f290faf43bca211e89b31b2f33485b58014809c366b1de1.png)  

ACCEPT_KEYWORDS：
安装Gentoo时，选择软件的稳定或不稳定分支时会出现ACCEPT_KEYWORDS=“amd64”或ACCEPT_KEYWORDS=“~amd64”，这决定了系统或软件的更新频率。由于这个原因，一些软件也被阻止了，可以通过手动修改ACCEPT_KEYWORDS来安装被阻止的软件包。

e.g.

![Figure 3](images/4486e250d6cc524899b3f06de31c6eed4bbe4e4cd0967b75ba2637a3349e6694.png)  
![Figure 4](images/c6ee2269ced378ee465bfc4d81fd7c7b879f8c55ddf55630bcde961fb4b0982a.png)  

MASK:
使用 MASK 标签，我们可以锁定一个包的版本或阻止我们不需要的包。但是，对于系统更新来说，这个操作比较危险，需要考虑USE标签带来的依赖问题。包的屏蔽与ACCEPT_KEYWORDS标签有关。

e.g.
![图 6](images/c5092ecccf234c21c49ae706da5e2e5e33be23c6f0630e9dea19b05ac4f81b7b.png)

#### 界面展示

以下界面均在Gentoo gnome45上所截的图

这是软件的主页面:

![图 0](images/823e5dbdd6b03d0f55c3900960ef887bdc7c79767b1495900db92746db44013e.png)

这是软件包管理页面:

![图 1](images/f9cce90da395b82b5a0cea467b83f00e5a4788b8d82c2130bd9b47092e5fb0ec.png)

这是编辑软件仓库的菜单:

![图 2](images/13c2833c8458bdfbb4136ec176db9c92bb6a58e333f49c21498082ac2c29f3ad.png)

这是系统更新界面:

![图 3](images/ff5d2da03c9b02f1b27c6e4cb74f11f2e11956e6023bed70a0e08ecbf17ec781.png)

#### 作者自述

暂无(没有什么好说的) :laughing:
