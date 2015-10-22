#!/bin/sh

gcc -static x.c -o x || exit 1
rm x.o

../usr/gen_init_cpio idesc | gzip > initramfs.img

qemu-system-x86_64      --enable-kvm                    \
                        -m 512                          \
                        -kernel ../arch/x86/boot/bzImage\
                        -initrd initramfs.img           \
                        -nographic                      \
                        -append "console=ttyS0" 

# -append init=/bin/sh
