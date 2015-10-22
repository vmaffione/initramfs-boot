#!/bin/sh

IRATI=/home/vmaffione/git/irati/linux

gcc -static init.c -o init || exit 1

${IRATI}/usr/gen_init_cpio idesc | gzip > initramfs.img

qemu-system-x86_64      --enable-kvm                    \
                        -m 512                          \
                        -kernel ${IRATI}/arch/x86/boot/bzImage\
                        -initrd initramfs.img           \
                        -nographic                      \
                        -append "console=ttyS0" 

# -append init=/bin/sh
