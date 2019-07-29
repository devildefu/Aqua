# Aqua {#mainpage}
Operating system made for fun. Use pull requests to help us in developing.

# Preparation

To compile Aqua, you need exactly:
* Cross Compiler (GNU GCC)
* Binutils (readelf, objdump, etc.)
* Netwide Assembler
* CMake

CMake and nasm can be installed using package manager on Linux, *BSD or macOS (if homebrew is installed).
When it comes to the cross-compiler, there are two ways to do it.
1. manual compilation. This is the most recommended method, because then you can be sure that it is the right version.
2. Download from the repository. Some distributions have a cross-compiler in the repository, e.g. Arch Linux.

Recommended versions:
* GNU GCC - 8.2.0
* Binutils - 2.32
* Netwide Assembler - 2.13.02
* CMake - 3.10.2

Newer versions should also work, but these versions are recommended.

For the first way to compile a cross compiler you will find [here](https://wiki.osdev.org/GCC_Cross-Compiler#Preparing_for_the_build)

On Windows the best and easiest method is to use Windows Subsystem for Linux, but unfortunately it is only for Windows 10.
On older versions (7, 8.x) we recommend using a Cygwin.

## Compilation

In addition to cmake scripts, we prepared a small `build.sh` script. 
```
$ ./build.sh
```
And now. If you haven't got any errors (warnings don't count of course), you can test it with a virtual machine like qemu (mostly prefered) or if you're really bored, burn it into a pendrive and boot from bios.

## Authors
* **Devourer of Source** (devildefu) - Lead Programmer, Project Manager, Repository Manager
* **Darkei** (dark565) - Programmer - [Account](https://github.com/Dark565)
* **Firstbober** - Programmer, Designer - [Account](https://github.com/Firstbober)
