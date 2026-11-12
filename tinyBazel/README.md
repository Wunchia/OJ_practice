# tinyBazel：从零跑通 Bazel

这是一个不依赖第三方库的 C++ 小项目。请在本目录运行下面的命令。需要 Bazel 7 或更新版本、C++ 编译器，以及用于 `genrule` 的 `tr` 命令（Linux/macOS 常见环境自带）。如果使用 Bazelisk，把下文的 `bazel` 换成 `bazelisk` 即可。首次使用 Bazel 时，工具链或 Bazel 自身可能需要下载。

## 1. 先运行

```bash
cd tinyBazel                 # 如果已经在此目录，跳过这行
bazel version
bazel build //:hello
bazel run //:hello           # Hello, Bazel!
bazel run //:hello -- Alice  # Hello, Alice!
bazel test //:greeting_test  # 运行测试，而不只是编译测试
```

`MODULE.bazel` 标记工作区根目录并声明模块名称。`BUILD.bazel` 把当前目录定义成一个 **包**，其中每条规则定义一个 **目标**。`//:hello` 的 `//` 指工作区根目录，冒号后是目标名。若后来新建 `lib/BUILD.bazel`，该包里的目标就写成 `//lib:目标名`。

## 2. 看懂 BUILD.bazel

| 目标 | 规则 | 输入和依赖 | 作用 |
| --- | --- | --- | --- |
| `//:greeting` | `cc_library` | `greeting.cc`、`greeting.h` | 编译可复用的 C++ 库 |
| `//:hello` | `cc_binary` | `main.cc`、`deps = [":greeting"]` | 链接并生成可执行文件 |
| `//:greeting_test` | `cc_test` | `greeting_test.cc`、同一个库 | 编译并运行测试程序 |
| `//:uppercase_message` | `genrule` | `message.txt`、`tr` 命令 | 生成大写文本文件 |

`name` 是目标名；`srcs` 列实现文件或生成动作的输入；`hdrs` 列库对依赖者提供的头文件；`deps` 列其他规则目标。`":greeting"` 表示同一个包内的 `greeting`。Bazel 根据这些声明建立依赖图：构建 `hello` 会先处理 `greeting`，源文件变更后只重做受影响的动作。

`genrule` 的 `outs` 声明生成文件名；`$(location message.txt)` 展开为该输入文件的执行路径；`$@` 展开为唯一输出文件的路径。它的命令通过 shell 执行，所以本例需要 `tr`。

## 3. 找到编译产物

```bash
bazel build //:hello //:uppercase_message
./bazel-bin/hello
cat bazel-bin/message_upper.txt
bazel build //:greeting                # 单独构建库
ls bazel-bin/libgreeting.a             # 本例 Linux 常见工具链下的静态库
bazel info bazel-bin
bazel info output_base
```

在 Linux/macOS 上，当前目录里的 `bazel-bin` 通常是 Bazel 创建的便捷符号链接，指向真实输出目录。`hello`、`greeting_test`、`message_upper.txt` 等产物都能从这里找到；库文件的具体名字会随平台和工具链变化。`bazel info bazel-bin` 给出其真实路径；不同机器或构建配置下路径可能不同，不要把绝对路径写死。Bazel 的中间文件一般在 `bazel-out/<配置>/` 下，缓存和工作数据在 `bazel info output_base` 给出的目录。测试日志通常可从 `bazel-testlogs/greeting_test/test.log` 查看。

这些输出目录和符号链接由 Bazel 管理，不应提交到 Git；本目录的 `.gitignore` 忽略了便捷链接。

## 4. 常用命令与实验

```bash
bazel build //...                         # 编译工作区所有包里的目标；不会执行测试
bazel test //...                          # 运行所有测试
bazel test --test_output=all //:greeting_test
bazel query 'deps(//:hello)'              # 查看 hello 的传递依赖
bazel query '//...'                        # 列出所有目标
bazel build -c opt //:hello               # 优化构建；与默认配置分开存放
bazel clean                               # 清除当前工作区的构建结果和动作缓存
```

建议先连续运行两次 `bazel build //:hello`，观察第二次复用缓存；再修改 `greeting.cc` 并构建，观察受影响的目标重新构建。`bazel build //:greeting_test` 只编译测试程序，`bazel test //:greeting_test` 才执行它。

## 5. 文件地图

```text
tinyBazel/
├── MODULE.bazel       工作区和模块定义
├── BUILD.bazel        构建规则
├── greeting.h/.cc     库
├── main.cc            可执行程序入口
├── greeting_test.cc   测试程序入口
├── message.txt        genrule 的输入
└── bazel-bin/         构建后出现的便捷链接（非源文件）
```

进一步阅读：[Bazel 官方入门](https://bazel.build/start)、[BUILD 文件概念](https://bazel.build/concepts/build-files)、[C++ 规则](https://bazel.build/reference/be/c-cpp)。
