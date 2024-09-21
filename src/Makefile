CC=gcc
en_US=/usr/bin/genpkg-en
zh_CN=/usr/bin/genpkg-zh
SW=/usr/bin/genpkg-sw
PROGRAM=/usr/bin/genpkg
PACKAGE_FILES=en_US/genpkg-en zh_CN/genpkg-zh genpkg-sw
PACKAGE_NAME=gentoo-packagemanager-tui

genpkg-sw:genpkg-sw.c#依赖项
	$(CC) genpkg-sw.c -Wall -g -o genpkg-sw
all:genpkg-sw
	make -C en_US && make -C zh_CN
zh:
	make -C zh_CN
en:
	make -C en_US

clean_all:
	make -C en_US clean && make -C zh_CN clean && rm -rf package genpkg-sw $(PACKAGE_NAME).tar.gz
clean_excess_files:
	make -C en_US clean_excess_files && make -C zh_CN clean_excess_files
clean_rmpkg:
	rm -rf package
	rm -rf $(PACKAGE_NAME).tar.gz

install_en:
	@make -C en_US install
	@ln -sf $(en_US) $(PROGRAM)
	@clear
	@echo "End installation in three seconds"
	@sleep 3
	@. /etc/profile
install_zh:
	@make -C en_US install
	@install -d /usr/bin/
	@clear
	@echo "三秒钟后结束安装"
	@sleep 3
	@. /etc/profile
install:
	@make -C en_US install && make -C zh_CN install
	@install -d /usr/bin/
	@install -m 0755 genpkg-sw /usr/bin/
	@ln -sf $(en_US) $(PROGRAM)
	@clear
	@echo "您可以使用genpkg-sw命令去更改软件语言!"
	@echo "you can use genpkg-sw to change your language!"
	@sleep 1
	@echo "三秒钟后结束安装"
	@echo "End installation in three seconds"
	@sleep 3
	@. /etc/profile

uninstall:
	@rm -rf $(SW)
	@rm -rf $(PROGRAM)
	@make -C en_US uninstall && make -C zh_CN uninstall

package:
	make -C en_US && make -C zh_CN
	$(CC) genpkg-sw.c -o genpkg-sw
	@mkdir -p package/usr/bin
	@cp -r $(PACKAGE_FILES) package/usr/bin/
	@echo "sudo install -d /usr/bin/ && sudo install -m 0755 usr/bin/genpkg-en /usr/bin/ && sudo install -m 0755 usr/bin/genpkg-zh /usr/bin/ && sudo install -m 0755 usr/bin/genpkg-sw /usr/bin/ && sudo ln -sf /usr/bin/genpkg-en /usr/bin/genpkg" >> package/install.sh
	@echo "sudo rm -rf $(zh_CN) $(en_US) $(SW) $(PROGRAM)" >> package/uninstall.sh
	@chmod 0755 package/install.sh
	@chmod 0755 package/uninstall.sh
	@tar -zcvf $(PACKAGE_NAME).tar.gz package
	@echo Done!
