#!/bin/sh
cp build/aqua iso/boot/aqua
grub-mkrescue -o aqua.iso iso