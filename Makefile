gentoo-packagemanager-sw:gentoo-packagemanager-sw.c
	gcc gentoo-packagemanager-sw.c -o gentoo-packagemanager-sw
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
	rm -rf gentoo-packagemanager-tui.tar.gz
install:
	make -C en_US install && make -C zh_CN install
	install -d /usr/bin/
	install -m 0755 gentoo-packagemanager-sw /usr/bin/
	ln -sf /usr/bin/gentoo-packagemanager-en /usr/bin/gentoo-packagemanager
	@clear
	@echo "you can use gentoo-packagemanager-sw to change your language!"
	@echo "您可以使用gentoo-packagemanager-sw命令去更改软件语言!"
	@sleep 1
	@echo "End installation in ten seconds"
	@echo "十秒钟后结束安装"
	@sleep 10
	@. /etc/profile
uninstall:
	rm /usr/bin/gentoo-packagemanager-sw
	rm /usr/bin/gentoo-packagemanager
	make -C en_US uninstall && make -C zh_CN uninstall
package:
	make -C en_US && make -C zh_CN
	gcc gentoo-packagemanager-sw.c -o gentoo-packagemanager-sw
	mkdir -p package/usr/bin
	cp -r en_US/gentoo-packagemanager-en zh_CN/gentoo-packagemanager-zh gentoo-packagemanager-sw install-dependencies.sh package/usr/bin/
	echo "sudo install -d /usr/bin/ && sudo install -m 0755 usr/bin/gentoo-packagemanager-en /usr/bin/ && sudo install -m 0755 usr/bin/gentoo-packagemanager-zh /usr/bin/ && sudo install -m 0755 usr/bin/gentoo-packagemanager-sw /usr/bin/ && sudo ln -sf /usr/bin/gentoo-packagemanager-en /usr/bin/gentoo-packagemanager" >> package/install.sh
	echo "sudo rm -rf /usr/bin/gentoo-packagemanager-zh /usr/bin/gentoo-packagemanager-en /usr/bin/gentoo-packagemanager-sw /usr/bin/gentoo-packagemanager" >> package/uninstall.sh
	chmod 0755 package/install.sh
	tar -zcvf gentoo-packagemanager-tui.tar.gz package
