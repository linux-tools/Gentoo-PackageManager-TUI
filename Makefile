CC=gcc
en_US=/usr/bin/gentoo-packagemanager-en
zh_CN=/usr/bin/gentoo-packagemanager-zh
SW=/usr/bin/gentoo-packagemanager-sw
PROGRAM=/usr/bin/gentoo-packagemanager
PACKAGE_FILES=en_US/gentoo-packagemanager-en zh_CN/gentoo-packagemanager-zh gentoo-packagemanager-sw install-dependencies.sh
PACKAGE_NAME=gentoo-packagemanager-tui
PACKAGE_INSTALL_SCRIPT=sudo install -d /usr/bin/ && sudo install -m 0755 usr/bin/gentoo-packagemanager-en /usr/bin/ && sudo install -m 0755 usr/bin/gentoo-packagemanager-zh /usr/bin/ && sudo install -m 0755 usr/bin/gentoo-packagemanager-sw /usr/bin/ && sudo ln -sf /usr/bin/gentoo-packagemanager-en /usr/bin/gentoo-packagemanager

gentoo-packagemanager-sw:gentoo-packagemanager-sw.c
	$(CC) gentoo-packagemanager-sw.c -o -Wall gentoo-packagemanager-sw
all:gentoo-packagemanager-sw
	make -C en_US && make -C zh_CN
zh:
	make -C zh_CN
en:
	make -C en_US

clean_all:
	make -C en_US clean && make -C zh_CN clean && rm -rf package gentoo-packagemanager-sw gentoo-packagemanager-tui.tar.gz
clean_excess_files:
	make -C en_US clean_excess_files && make -C zh_CN clean_excess_files
clean_package:
	rm -rf package
	rm -rf $(PACKAGE_NAME).tar.gz

install_en:
	@make -C en_US install && make -C zh_CN install
	@install -d /usr/bin/
	@install -m 0755 gentoo-packagemanager-sw /usr/bin/
	@ln -sf $(en_US) $(SW)
	@clear
	@echo "you can use gentoo-packagemanager-sw to change your language!"
	@sleep 1
	@echo "End installation in ten seconds"
	@sleep 10
	@. /etc/profile
install_zh:
	@make -C en_US install && make -C zh_CN install
	@install -d /usr/bin/
	@install -m 0755 gentoo-packagemanager-sw /usr/bin/
	@ln -sf $(zh_CN) $(SW)
	@clear
	@echo "您可以使用gentoo-packagemanager-sw命令去更改软件语言!"
	@sleep 1
	@echo "十秒钟后结束安装"
	@sleep 10
	@. /etc/profile
uninstall:
	@rm $(SW)
	@rm $(PROGRAM)
	@make -C en_US uninstall && make -C zh_CN uninstall

package:
	make -C en_US && make -C zh_CN
	$(CC) gentoo-packagemanager-sw.c -o gentoo-packagemanager-sw
	mkdir -p package/usr/bin
	cp -r $(PACKAGE_FILES) package/usr/bin/
	echo $(PACKAGE_INSTALL_SCRIPT) >> package/install.sh
	echo "sudo rm -rf $(zh_CN) $(en_US) $(SW) $(PROGRAM)" >> package/uninstall.sh
	chmod 0755 package/install.sh
	tar -zcvf $(PACKAGE_NAME).tar.gz package
