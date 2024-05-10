set_policy("check.auto_ignore_flags", false)
add_rules("plugin.compile_commands.autoupdate")
set_languages("cxx20")
set_config("toolchain","gcc")
set_config("cxx", "/opt/homebrew/bin/g++-14")
set_config("ld", "/opt/homebrew/bin/g++-14")

-- ref: The -isystem and -idirafter options also mark the directory as a system directory, 
-- 所以当系统头文件报错时，可以尝试-isystem选项

target("structure_only")
    -- 常规参数
    add_defines("LOCAL")
    set_kind("static")
    add_includedirs("dependency/include")
    add_files("**.c")   
    add_files("**.cc")  
    add_files("**.cpp") 
    add_files("**.cxx") 

    -- 对MacOSX平台进行特殊处理，添加Xcode SDK路径
    if is_plat("macosx") then
        local sdk_path,err = "",""
        on_load(function (target)
            sdk_path,err = os.iorunv("xcrun", {"--sdk", "macosx","--show-sdk-path"})
            if (err and #err > 0) or #sdk_path == 0 then
                raise("Failed to get MacOS SDK path: " .. err)
            end
            target:add("cxflags","-arch arm64", "-isysroot " .. sdk_path)
            target:add("ldflags","-arch arm64", "-isysroot " .. sdk_path)
        end)
    end