# MyConfig

我常用的VSCode配置，使用XMake重新构建。

本配置主要针对C/C++的单文件Demo级代码，用于学习和算法竞赛（Competitive Programming）

## 分支解释

Portable: 为了便于部署，该分支不与`XCode SDK`做关联，以保证基本语言特性能正常使用，避免因`XCode`更新造成`Clangd`异常。

Main: 完全还原IDE由`CMake`导出的`compile_commands.json`，尽可能多的支持语言特性。

## 依赖

- XMake
- gcc@13

## 使用方法

如果想生成`Compile_commands.json` 请使用`VSCode`的`Task`功能。

🚧 待完成/Unfinished 🚧

## 部分参考来源

debug.hpp
[Github: sharkdp/dbg-marco](https://github.com/sharkdp/dbg-macro)

Inspired By
[Github: FeignClaims/vscode_cpp_starter](https://github.com/FeignClaims/vscode_cpp_starter)