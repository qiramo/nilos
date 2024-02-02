project("i386")
	kind("Utility")

	files {
		"**.h",
		"**.c",
		"**.s"
	}

	filter("files:**.c or **.s")
		buildcommands {
			"gcc -c -m32 -nostdlib -ffreestanding -fno-builtin -nostartfiles\\\
			-nodefaultlibs -Wall -Wextra -Werror %{file.relpath}\\\
			-o %{ObjDir}/%{file.basename}.o"
		}

		buildoutputs {
			"%{ObjDir}/%{file.basename}.o"
		}

project("linker")
	kind("Utility")

	files("linker.ld")

	filter("files:linker.ld")
		buildcommands {
			"ld -nostdlib -melf_i386 -T %{file.relpath} -o %{BuildDir}/%{wks.name}.elf\\\
			`ls $$PWD/%{BuildDir}/%{ObjDir}/*`"
		}

		buildoutputs {
			"%{BuildDir}/%{wks.name}.elf"
		}
