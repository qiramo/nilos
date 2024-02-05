project("libc")
	kind("Utility")

	files {
		"**.h",
		"**.c"
	}

	filter("files:**.c")
		buildcommands {
			CompileOptions .. "%{file.relpath} -o %{ObjDir}/%{file.basename}.o"
		}

		buildoutputs {
			"%{ObjDir}/%{file.basename}.o"
		}
