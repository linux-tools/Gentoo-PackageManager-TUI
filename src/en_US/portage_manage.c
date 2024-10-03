#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void create_floder_in_portage(){
    system("cd /etc/portage/package.use && sudo mkdir acct-group dev-lang kde-misc sci-electronics acct-user dev-libs kde-plasma sci-geosciences app-accessibility dev-lisp licenses sci-libs app-admin dev-lua lxde-base sci-mathematics app-alternatives dev-ml lxqt-base sci-misc app-antivirus dev-perl mail-client sci-physics app-arch dev-php mail-filter sci-visualization app-backup dev-python mail-mta scripts app-benchmarks dev-qt mate-base sec-keys app-cdr dev-ruby mate-extra sec-policy app-containers dev-scheme media-fonts app-crypt dev-tcltk media-gfx app-dicts dev-tex media-libs sys-apps app-doc dev-texlive media-plugins sys-auth app-editors dev-util media-radio sys-block app-emacs dev-vcs media-sound sys-boot app-emulation eclass media-tv sys-cluster app-eselect games-action media-video sys-devel app-forensics games-arcade metadata sys-fabric app-i18n games-board net-analyzer sys-firmware app-laptop games-emulation net-dialup sys-fs app-metrics games-engines net-dns sys-kernel app-misc games-fps net-firewall sys-libs app-mobilephone games-kids net-fs sys-power app-office games-misc net-ftp sys-process app-officeext games-mud net-im virtual app-pda games-puzzle net-irc www-apache app-portage games-roguelike net-libs www-apps app-shells games-rpg net-mail www-client app-text games-server net-misc www-misc app-vim games-simulation net-nds www-plugins app-xemacs games-sports net-news www-servers dev-ada games-strategy net-nntp x11-apps dev-build games-util net-p2p x11-base dev-cpp gnome-base net-print x11-drivers dev-db gnome-extra net-proxy x11-libs dev-debug gnustep-apps net-voip x11-misc dev-dotnet gnustep-base net-vpn x11-plugins dev-embedded gnustep-libs net-wireless x11-terms dev-erlang gui-apps perl-core x11-themes dev-games gui-libs profiles x11-wm dev-gap gui-wm sci-astronomy xfce-base dev-go sci-biology xfce-extra dev-haskell kde-apps sci-calculators dev-java kde-frameworks sci-chemistry >/dev/null 2>&1");
    system("cd /etc/portage/package.mask && sudo mkdir acct-group dev-lang kde-misc sci-electronics acct-user dev-libs kde-plasma sci-geosciences app-accessibility dev-lisp licenses sci-libs app-admin dev-lua lxde-base sci-mathematics app-alternatives dev-ml lxqt-base sci-misc app-antivirus dev-perl mail-client sci-physics app-arch dev-php mail-filter sci-visualization app-backup dev-python mail-mta scripts app-benchmarks dev-qt mate-base sec-keys app-cdr dev-ruby mate-extra sec-policy app-containers dev-scheme media-fonts app-crypt dev-tcltk media-gfx app-dicts dev-tex media-libs sys-apps app-doc dev-texlive media-plugins sys-auth app-editors dev-util media-radio sys-block app-emacs dev-vcs media-sound sys-boot app-emulation eclass media-tv sys-cluster app-eselect games-action media-video sys-devel app-forensics games-arcade metadata sys-fabric app-i18n games-board net-analyzer sys-firmware app-laptop games-emulation net-dialup sys-fs app-metrics games-engines net-dns sys-kernel app-misc games-fps net-firewall sys-libs app-mobilephone games-kids net-fs sys-power app-office games-misc net-ftp sys-process app-officeext games-mud net-im virtual app-pda games-puzzle net-irc www-apache app-portage games-roguelike net-libs www-apps app-shells games-rpg net-mail www-client app-text games-server net-misc www-misc app-vim games-simulation net-nds www-plugins app-xemacs games-sports net-news www-servers dev-ada games-strategy net-nntp x11-apps dev-build games-util net-p2p x11-base dev-cpp gnome-base net-print x11-drivers dev-db gnome-extra net-proxy x11-libs dev-debug gnustep-apps net-voip x11-misc dev-dotnet gnustep-base net-vpn x11-plugins dev-embedded gnustep-libs net-wireless x11-terms dev-erlang gui-apps perl-core x11-themes dev-games gui-libs profiles x11-wm dev-gap gui-wm sci-astronomy xfce-base dev-go sci-biology xfce-extra dev-haskell kde-apps sci-calculators dev-java kde-frameworks sci-chemistry >/dev/null 2>&1");
    system("cd /etc/portage/package.accept_keywords && sudo mkdir acct-group dev-lang kde-misc sci-electronics acct-user dev-libs kde-plasma sci-geosciences app-accessibility dev-lisp licenses sci-libs app-admin dev-lua lxde-base sci-mathematics app-alternatives dev-ml lxqt-base sci-misc app-antivirus dev-perl mail-client sci-physics app-arch dev-php mail-filter sci-visualization app-backup dev-python mail-mta scripts app-benchmarks dev-qt mate-base sec-keys app-cdr dev-ruby mate-extra sec-policy app-containers dev-scheme media-fonts app-crypt dev-tcltk media-gfx app-dicts dev-tex media-libs sys-apps app-doc dev-texlive media-plugins sys-auth app-editors dev-util media-radio sys-block app-emacs dev-vcs media-sound sys-boot app-emulation eclass media-tv sys-cluster app-eselect games-action media-video sys-devel app-forensics games-arcade metadata sys-fabric app-i18n games-board net-analyzer sys-firmware app-laptop games-emulation net-dialup sys-fs app-metrics games-engines net-dns sys-kernel app-misc games-fps net-firewall sys-libs app-mobilephone games-kids net-fs sys-power app-office games-misc net-ftp sys-process app-officeext games-mud net-im virtual app-pda games-puzzle net-irc www-apache app-portage games-roguelike net-libs www-apps app-shells games-rpg net-mail www-client app-text games-server net-misc www-misc app-vim games-simulation net-nds www-plugins app-xemacs games-sports net-news www-servers dev-ada games-strategy net-nntp x11-apps dev-build games-util net-p2p x11-base dev-cpp gnome-base net-print x11-drivers dev-db gnome-extra net-proxy x11-libs dev-debug gnustep-apps net-voip x11-misc dev-dotnet gnustep-base net-vpn x11-plugins dev-embedded gnustep-libs net-wireless x11-terms dev-erlang gui-apps perl-core x11-themes dev-games gui-libs profiles x11-wm dev-gap gui-wm sci-astronomy xfce-base dev-go sci-biology xfce-extra dev-haskell kde-apps sci-calculators dev-java kde-frameworks sci-chemistry >/dev/null 2>&1");
}

void backup(){
    system("mkdir $HOME/.portage-tags >/dev/null 2>&1");
    system("mkdir $HOME/.portage-tags/backup >/dev/null 2>&1");
    system("cp -r /etc/portage/package.use /etc/portage/package.mask /etc/portage/package.accept_keywords $HOME/.portage-tags/backup >/dev/null 2>&1");
}

void recover_backup(){
    system("cp -r $HOME/.portage-tags/backup/* /etc/portage/ >/dev/null 2>&1");
}

char edit_USE(char a[255]){
    char exec[255];
    sprintf(exec,"sudo nvim /etc/portage/package.use/%s",a);
    sleep(1);
    system(exec);
    sleep(1);
    system("clear");
    return 0;
}

char edit_MASK(char a[255]){
    char exec[255];
    sprintf(exec,"sudo nvim /etc/portage/package.mask/%s",a);
    sleep(1);
    system(exec);
    sleep(1);
    system("clear");
    return 0;
}

char edit_ACCEPT(char a[255]){
    char exec[255];
    sprintf(exec,"sudo nvim /etc/portage/package.accept_keywords/%s",a);
    sleep(1);
    system("clear");
    system(exec);
    sleep(1);
    system("clear");
    return 0;
} 

char create_USE(char a[255]){
    char exec[255];
    sprintf(exec,"sudo touch /etc/portage/package.use/%s",a);
    sleep(1);
    system(exec);
    sleep(1);
    system("clear");
    return 0;
}

char create_MASK(char a[255]){
    char exec[255];
    sprintf(exec,"sudo touch /etc/portage/package.mask/%s",a);
    sleep(1);
    system(exec);
    sleep(1);
    system("clear");
    return 0;
}

char create_ACCEPT(char a[255]){
    char exec[255];
    sprintf(exec,"sudo touch /etc/portage/package.accept_keywords/%s",a);
    sleep(1);
    system(exec);
    sleep(1);
    system("clear");
    return 0;
}

char delete_USE(char a[255]){
    char exec[255];
    sprintf(exec,"sudo rm /etc/portage/package.use/%s",a);
    sleep(1);
    system("clear");
    system(exec);
    sleep(1);
    system("clear");
    return 0;
}

char delete_MASK(char a[255]){
    char exec[255];
    sprintf(exec,"sudo rm /etc/portage/package.mask/%s",a);
    sleep(1);
    system("clear");
    system(exec);
    sleep(1);
    system("clear");
    return 0;
}

char delete_ACCEPT(char a[255]){
    char exec[255];
    sprintf(exec,"sudo rm /etc/portage/package.accept_keywords/%s",a);
    sleep(1);
    system("clear");
    system(exec);
    sleep(1);
    system("clear");
    return 0;
}

void edit_make_conf(){
    sleep(1);
    system("sudo nvim /etc/portage/make.conf");
    sleep(1);
    system("clear");
}//From line 20 to line 112, including some operations of the portal system