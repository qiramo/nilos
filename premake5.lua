newoption {
	trigger = "arch",
	description = "Architecture to build nilos for",

	allowed = {
		{"i386"}
	},

	default = "i386"
}

BuildDir = _MAIN_SCRIPT_DIR .. "/build"
ObjDir =	BuildDir .. "/objects"

GlobalIncludes =
	"-I" .. _MAIN_SCRIPT_DIR .. "/libc/inc " ..
	"-I" .. _MAIN_SCRIPT_DIR .. "/kernel/inc "

CompileOptions =
	"gcc -c -m32 -nostdlib -ffreestanding -fno-builtin -fno-stack-protector " ..
	"-nostartfiles -nodefaultlibs -Wall -Wextra -Werror " ..
	GlobalIncludes

workspace("nilos")
	location(BuildDir)
	configurations {
		"Debug"
	}

	os.mkdir(ObjDir)

	include("libc")
	include("kernel")
	include("arch/" .. _OPTIONS["arch"])
