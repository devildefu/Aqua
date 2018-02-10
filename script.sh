if grub-file --is-x86-multiboot kirid.bin; then
  echo multiboot confirmed
  rm kirid.iso
  cp -f kirid.bin isodir/boot/kirid.bin
  grub-mkrescue -o kirid.iso isodir
else
  echo the file is not multiboot
fi
