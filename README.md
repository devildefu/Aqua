# Aqua
Operating system made for fun. Use pull requests to help us in developing.

## Compilation

To compile Aqua, you need exactly 3 tools: gcc, nasm and ld, practically 2, bacause ld, in 99.9% cases, goes together with gcc, so it's not a big deal :).
In addition to cmake scripts, we prepared a small `build.sh` script. It'll allow you to compile the kernel regardless of the platform you actually use (csss.. actually no, regardfull, because we **officially** support compiling from Windows and Linux, but don't worry. If you'll success in compiling it on Linux, you'll compile it as well on platform like FreeBSD).
```
$ ./build.sh
```
And now. If you haven't got any errors (warnings don't count of course), you can test it with a virtual machine like qemu (mostly prefered) or if you're really bored, burn it into a pendrive and boot from bios.

## Authors
* **Devourer of Source** (devildefu) - Lead Programmer, Project Manager, Repository Manager
* **Darkei** (dark565) - Main Programmer - [Account](https://github.com/Dark565)
* **Firstbober** - Programmer, Designer - [Account](https://github.com/Firstbober)
