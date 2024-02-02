project("kernel")
	kind("Utility")

	files {
		"**.h",
		"**.c"
	}

	filter("files:**.c")
		buildcommands {
			"gcc -c -m32 -nostdlib -ffreestanding -fno-builtin -nostartfiles\\\
			-nodefaultlibs -Wall -Wextra -Werror %{file.relpath}\\\
			-o %{ObjDir}/%{file.basename}.o"
		}

		buildoutputs {
			"%{ObjDir}/%{file.basename}.o"
		}
