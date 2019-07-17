#!/bin/sh
cp build/kernel/aqua iso/boot/aqua
grub-mkrescue -o iso/aqua.iso iso