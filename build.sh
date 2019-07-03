#!/bin/sh

# Detect operating system, on whom kernel is going to be compiled


ERROR=$'\033'"[1;31mError"$'\033'"[m"

checkDependency() {
	PROG_FULLNAME="${ARCH_SUFFIX}-elf-$1"
	if ! type -P "${PROG_FULLNAME}" >/dev/null; then
		printf "${ERROR}: '${PROG_FULLNAME}' not found. If you use "${ARCH_SUFFIX}" system with elf as an executable format, then you should create symlinks to gcc and ld in your PATH  with "${ARCH_SUFFIX}-elf-" before each link's name.\n"
		exit 1
	fi
}

cmakePrepareBuild() {
	cmake -H. -Bbuild -G "Ninja" -DCMAKE_TOOLCHAIN_FILE="$1"
}

if ! [ -d build ]; then

	[[ -n $1 ]] && TOOLCHAIN_TARGET="$1" || TOOLCHAIN_TARGET="i686-pc"


	ARCH_SUFFIX="${TOOLCHAIN_TARGET%-*}"

	checkDependency gcc
	checkDependency ld

	TOOLCHAIN="toolchain-${TOOLCHAIN_TARGET}"

  	if ! cmakePrepareBuild "${TOOLCHAIN}.cmake"; then
		printf "${ERROR}: Cannot prepare cmake build cache. Trying workaround toolchain..\n"
		cat "${TOOLCHAIN}" | sed 's/set(LINKER/set(CMAKE_LINKER/' > "${TOOLCHAIN}-workaround.cmake" # Workaround is needed, because sometimes cmake leaves LINKER variable empty
													    # and CMAKE_LINKER is a solution and vice versa.

		if ! cmakePrepareBuild "${TOOLCHAIN}-workaround.cmake"; then
			printf "${ERROR}: Oops. Cannot prepare a build.\n"
			rm "${TOOLCHAIN}-workaround.cmake"
			exit 1
		fi
	fi

fi
cmake --build build
