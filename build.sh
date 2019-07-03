#!/bin/sh

# Detect operating system, on whom kernel is going to be compiled
detectHost() {

	case "$(uname -s)" in
		"Msys" | "mingw32" )
			printf "windows"
			;;
		"Linux" )
			printf "linux"
			;;
		* )
			return 1
			;;
	esac
	return 0

}

if ! [ -d build ]; then

	if [[ -n $1 ]]; then
	  	OS="$1"
  	else	
	  	OS="$(detectHost)"
		echo $?
  	fi

	echo "Host OS: $OS"

  	[[ -n $OS && $OS != "windows" ]] && TOOLCHAIN_SUFFIX="-$OS"

  	cmake -H. -Bbuild -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=toolchain-i686-pc${TOOLCHAIN_SUFFIX}.cmake
fi
cmake --build build
