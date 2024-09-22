#!/usr/bin/bash
echo "Install package dependences"
sleep 1
sudo emerge --ask app-eselect/eselect-repository app-portage/gentoolkit app-admin/sudo app-text/tree app-editors/neovim
