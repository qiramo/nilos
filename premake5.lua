newoption {
	trigger = "arch",
	description = "Architecture to build nilos for",

	allowed = {
		{"i386"}
	},

	default = "i386"
}

BuildDir = _MAIN_SCRIPT_DIR .. "/build"
ObjDir =  BuildDir .. "/objects"

workspace("nilos")
	location(BuildDir)
	configurations {
		"Debug"
	}

	os.mkdir(ObjDir)

	include("kernel")
	include("arch/" .. _OPTIONS["arch"])
