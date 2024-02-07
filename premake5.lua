newoption {
	trigger = "arch",
	description = "Architecture to build nilos for",

	allowed = {
		{"i386"}
	},

	default = "i386"
}

newoption {
	trigger = "mode",
	description = "The mode to build nilos for",

	allowed = {
		{"debug"},
		{"release"}
	},

	default = "debug"
}

BuildDir = _MAIN_SCRIPT_DIR .. "/build/" .. _OPTIONS["mode"]
ObjDir = BuildDir .. "/objects"

local GlobalIncludes =
	"-I" .. _MAIN_SCRIPT_DIR .. "/libc/inc " ..
	"-I" .. _MAIN_SCRIPT_DIR .. "/kernel/inc "

local ConfigOptions = {}
ConfigOptions["debug"] = "-DNILOS_DEBUG=1 "
ConfigOptions["release"] = "-DNILOS_DEBUG=0 "

CompileOptions =
	"gcc -c -m32 -nostdlib -ffreestanding -fno-builtin -fno-stack-protector " ..
	"-nostartfiles -nodefaultlibs -Wall -Wextra -Werror " ..
	GlobalIncludes .. ConfigOptions[_OPTIONS["mode"]]

workspace("nilos")
	location(BuildDir)
	configurations("-")

	os.mkdir(ObjDir)

	include("libc")
	include("kernel")
	include("arch/" .. _OPTIONS["arch"])
