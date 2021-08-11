# wt-open-server
> we team open server for learn only.

* 编译
    > 每个存在`CMakeLists.txt`的目录都需要如下方式独立编译成可执行文件或库文件

    1. 安装`cmake`编译工具
        * mac: `brew install cmake`
        * arch/manjaro: `sudo pacman -S cmake`
    2. 编译
        * `mkdir build`
        * `cd build`
        * `cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ../`
        * `make`

* 采用`vim`开发并且使用`coc-clangd`作为代码提示可能需要`complile_commands.json`文件，该文件在build目录中，将其拷贝或创建软连接到父目录即可
