

# B9Creator™ 3D打印控制软件 | B9Creator™ 3D Printing Control Software

## 🌐 语言切换 | Language Switch

| 🇨🇳 中文版本 | 🇺🇸 English Version |
|-------------|-------------------|
| [点击查看中文内容](#-中文版本) | [Click for English](#-english-version) |

---

# 🇨🇳 中文版本

## 📋 项目简介

B9Creator™是一个开源的3D打印机固件和控制软件，原本基于QT4.8，现已成功迁移到Qt6。该软件为B9Creator™高分辨率DLP/树脂3D打印机提供完整的控制界面。

### 🎯 软件特点
- **高精度**: 支持高分辨率DLP/树脂3D打印
- **跨平台**: 完全支持Windows、macOS、Linux系统
- **开源**: 基于GNU GPL v3.0许可证开源
- **易用**: 直观的用户界面和完整的打印流程

## 🚀 版本信息

- **当前版本**: Qt6.6.x迁移版本
- **原始版本**: 基于QT4.8
- **最后更新**: 2026-03-15
- **维护者**: owenzhang (yuenar2@gmail.com)

## 📜 历史变更记录

### 2026-03-15 - Qt6迁移版本 (owenzhang)
- 🆕 **重大升级**: 从Qt4.8成功迁移到Qt6.x
- 📝 **代码注释**: 全面添加中文代码注释，提高可维护性
- 🔧 **代码优化**: 改进代码结构和性能
- 🏗️ **模块化**: 重新设计模块架构和接口
- 📚 **文档完善**: 更新项目文档和使用指南

### 2015-10-19 - 注释优化版本 (yuenar2@gmail.com)
- 📝 **注释改进**: 更改几乎全部注释，方便国人阅读
- 🖥️ **界面**: 界面未做汉化，保持原版英文界面
- ⚠️ **已知问题**: 
  - Windows平台下编译通过后，无法正常切片
  - Linux/macOS下预设支撑无法正常加载

### 2015-09-24 - 首次上传版本 (yuenar2@gmail.com)
- 🎉 **初始发布**: 基于QT4.8的开源版本迁移到Qt5.6
- 🖥️ **平台支持**: 测试支持win7-10/OSX10.10.1-10.11/openSUSE13.2/Ubuntu
- 📦 **功能完整**: 包含完整的3D打印控制功能

## 🖥️ 支持平台

### Windows
- ✅ Windows 7 (SP1+)
- ✅ Windows 8/8.1
- ✅ Windows 10/11
- ✅ 支持Visual Studio 2019+编译

### macOS
- ✅ macOS 10.10.1 (Yosemite) 及以上
- ✅ 支持Xcode 12+编译
- ✅ Intel和Apple Silicon (M1/M2)支持

### Linux
- ✅ Ubuntu 16.04 LTS 及以上
- ✅ openSUSE 13.2 及以上
- ✅ Debian 9+ 及其他发行版
- ✅ 支持GCC 7+和Clang 8+编译

## 📚 项目特性

### 🎯 核心功能
- **3D模型布局**: 
  - 支持多模型同时导入和编辑
  - 智能自动排列和手动调整
  - 模型旋转、缩放、移动操作
  - 支撑结构生成和编辑

- **切片引擎**:
  - 高效的模型切片算法
  - 可调节的层厚度和曝光参数
  - 支撑自动生成和手动编辑
  - 切片预览和优化

- **打印控制**:
  - 完整的打印流程管理
  - 实时打印状态监控
  - 打印参数调节和保存
  - 错误检测和处理

- **文件格式**:
  - 支持STL、OBJ等常见3D模型格式
  - B9专用项目文件格式(.b9layout)
  - SLC切片文件导出
  - 打印作业文件(.b9j)支持

### 🔄 技术更新
- **Qt6迁移**: 
  - 从Qt4.8完全迁移到Qt6.x
  - 现代化的UI组件和交互
  - 改进的信号槽机制
  - 更好的跨平台兼容性

- **中文注释**: 
  - 所有核心文件添加详细中文注释
  - 统一的注释格式和风格
  - 详细的函数和类说明
  - 业务逻辑和算法解释

- **代码优化**: 
  - 改进的内存管理
  - 优化的算法性能
  - 更好的错误处理
  - 线程安全改进

- **模块化设计**: 
  - 清晰的模块划分
  - 标准化的接口设计
  - 松耦合的组件架构
  - 易于扩展和维护

## 📁 项目结构

```
B9Creator-QT5.X/
├── src/                          # 源代码目录
│   ├── b9layout/                 # 布局模块 - 3D模型布局和项目数据管理
│   │   ├── projectdata.h/cpp     # 项目数据管理 - 文件读写、项目状态维护
│   │   ├── b9tesselator.h/cpp    # 三角剖分 - OpenGL三角剖分算法
│   │   ├── SlcExporter.h/cpp     # SLC文件导出 - 标准切片格式导出
│   │   ├── b9verticaltricontainer.h/cpp  # 垂直三角形容器 - Z轴分层优化
│   │   ├── b9layout.h/cpp        # 主布局类 - 布局核心逻辑
│   │   ├── loop.h/cpp             # 循环数据处理
│   │   ├── triangle3d.h/cpp      # 3D三角形数据结构
│   │   └── geometricfunctions.h/cpp # 几何计算函数
│   ├── b9edit/                   # 编辑模块 - 切片编辑和图形处理
│   │   ├── SliceEditView.h/cpp   # 切片编辑视图 - 可视化编辑界面
│   │   ├── floodfill.h/cpp       # 洪水填充算法 - 区域填充操作
│   │   ├── DrawingContext.h/cpp  # 绘制上下文 - 图形渲染管理
│   │   ├── sliceeditview.ui       # Qt Designer界面文件
│   │   └── ...                   # 其他编辑相关文件
│   ├── b9print/                  # 打印模块 - 打印控制和监控
│   │   ├── b9print.h/cpp         # 打印控制核心 - 打印流程管理
│   │   └── ...                   # 其他打印相关文件
│   ├── b9terminal/               # 终端模块 - 打印机通信
│   │   ├── b9terminal.h/cpp      # 打印机终端控制
│   │   └── ...                   # 其他终端相关文件
│   ├── b9projector/              # 投影模块 - 投影控制
│   │   ├── b9projector.h/cpp     # 投影机控制
│   │   └── ...                   # 其他投影相关文件
│   ├── mainwindow.h/cpp          # 主窗口 - 应用程序主界面
│   ├── main.cpp                  # 程序入口
│   └── ...                       # 其他核心文件
├── resources/                    # 资源文件目录
│   ├── icons/                    # 图标资源
│   ├── images/                   # 图片资源
│   ├── ui/                       # UI文件
│   └── ...                       # 其他资源
├── docs/                         # 文档目录
│   ├── api/                      # API文档
│   ├── userguide/                # 用户指南
│   └── ...                       # 其他文档
├── build/                        # 构建输出目录
├── CMakeLists.txt                # CMake构建配置
├── README.md                     # 项目说明文档
├── LICENSE                       # 许可证文件
└── ...                           # 其他配置文件
```

## 🔧 编译说明

### 📋 环境要求

#### 必需组件
- **Qt6**: Qt6.2 或更高版本
- **CMake**: 3.16 或更高版本  
- **编译器**: C++17 兼容编译器
  - Windows: Visual Studio 2019+ 或 MinGW-w64 8+
  - macOS: Xcode 12+ 或 Clang 8+
  - Linux: GCC 7+ 或 Clang 8+

#### 可选组件
- **OpenGL**: 用于3D渲染和三角剖分
- **Git**: 用于版本控制和源码获取
- **Python**: 用于构建脚本和工具

### 🏗️ 编译步骤

#### Windows (Visual Studio)
```cmd
# 1. 安装Qt6和Visual Studio 2019+
# 2. 克隆项目
git clone [项目地址]
cd B9Creator-QT5.X

# 3. 创建构建目录
mkdir build
cd build

# 4. 配置CMake
cmake .. -G "Visual Studio 16 2019" -A x64

# 5. 编译
cmake --build . --config Release

# 6. 运行
cd Release
B9Creator.exe
```

#### macOS (Xcode)
```bash
# 1. 安装Qt6和Xcode
# 2. 克隆项目
git clone [项目地址]
cd B9Creator-QT5.X

# 3. 创建构建目录
mkdir build && cd build

# 4. 配置CMake
cmake .. -G Xcode

# 5. 编译
cmake --build . --config Release

# 6. 运行
open B9Creator.app
```

#### Linux (GCC)
```bash
# 1. 安装依赖
sudo apt-get install qt6-base-dev cmake build-essential

# 2. 克隆项目
git clone [项目地址]
cd B9Creator-QT5.X

# 3. 创建构建目录
mkdir build && cd build

# 4. 配置CMake
cmake .. -DCMAKE_BUILD_TYPE=Release

# 5. 编译
make -j$(nproc)

# 6. 运行
./B9Creator
```

### ⚠️ 编译注意事项

#### Windows平台
- 确保Qt6环境变量正确设置
- 可能需要安装Visual C++ Redistributable
- 某些功能可能需要管理员权限

#### macOS平台  
- 确保Xcode命令行工具已安装
- 可能需要禁用Gatekeeper以运行未签名应用
- Apple Silicon Mac需要使用arm64版本的Qt6

#### Linux平台
- 确保OpenGL驱动程序正确安装
- 可能需要安装额外的Qt6模块
- 某些发行版可能需要调整库路径

## 📖 模块详细说明

### b9layout模块 - 布局管理核心

#### projectdata (项目数据管理)
- **功能**: 负责项目文件的读写、项目状态维护和数据管理
- **主要类**: `ProjectData`
- **核心功能**:
  - 项目文件(.b9layout)的读取和保存
  - 模型实例管理和布局数据
  - 打印参数和设置管理
  - 项目修改状态跟踪
- **文件格式**: 支持版本13和14的布局文件格式
- **数据结构**: 包含模型列表、分辨率、像素尺寸、构建空间等

#### b9tesselator (三角剖分)
- **功能**: OpenGL三角剖分算法，用于模型网格处理
- **主要类**: `B9Tesselator`
- **核心功能**:
  - 2D多边形三角剖分
  - OpenGL回调函数处理
  - 顶点数据管理和优化
  - 内存管理和错误处理
- **算法**: 基于GLU三角剖分器
- **应用**: 用于模型切片和支撑生成

#### SlcExporter (SLC文件导出)
- **功能**: 标准SLC格式文件导出
- **主要类**: `SlcExporter`
- **核心功能**:
  - SLC文件头信息写入
  - 切片数据和边界导出
  - 单位转换和坐标处理
  - 二进制文件格式处理
- **文件格式**: 支持SLC 2.0标准
- **应用**: 与其他3D打印软件的兼容性

#### b9verticaltricontainer (垂直三角形容器)
- **功能**: Z轴分层三角形容器，优化三角形处理
- **主要类**: `B9VerticalTriContainer`
- **核心功能**:
  - 按Z轴范围管理三角形
  - 三角形适合性判断
  - 容器链表结构管理
  - 空间索引优化
- **算法**: 垂直空间分割
- **应用**: 提高切片算法效率

### b9edit模块 - 编辑和图形处理

#### SliceEditView (切片编辑视图)
- **功能**: 切片编辑的可视化界面
- **主要类**: `SliceEditView`
- **核心功能**:
  - 切片图像显示和编辑
  - 支撑结构编辑
  - 绘图工具和操作
  - 实时预览和更新
- **界面**: 基于Qt Designer的UI文件
- **交互**: 鼠标和键盘事件处理

#### floodfill (洪水填充算法)
- **功能**: 区域填充算法实现
- **主要类**: 洪水填充相关类
- **核心功能**:
  - 种子填充算法
  - 区域检测和标记
  - 边界处理和优化
  - 多种填充策略支持
- **算法**: 扫描线填充和递归填充
- **应用**: 支撑生成和区域选择

#### DrawingContext (绘制上下文)
- **功能**: 图形渲染管理和绘制操作
- **主要类**: `DrawingContext`
- **核心功能**:
  - 2D图形绘制接口
  - 绘制状态管理
  - 图形对象操作
  - 渲染优化
- **图形**: 支持线条、多边形、文本等
- **应用**: 切片预览和编辑界面

### b9print模块 - 打印控制

#### b9print (打印控制核心)
- **功能**: 3D打印流程管理和控制
- **主要类**: `B9Print`
- **核心功能**:
  - 打印任务管理
  - 打印参数控制
  - 实时状态监控
  - 错误处理和恢复
- **通信**: 与打印机硬件通信
- **流程**: 从切片到打印的完整流程

## 🌟 主要改进详情

### Qt6迁移优化
- **信号槽语法**: 从Qt4的`SIGNAL()`/`SLOT()`宏更新到Qt6的函数指针语法
- **UI组件**: 使用Qt6的现代化UI组件，提升用户体验
- **线程安全**: 改进多线程处理，提高稳定性
- **模块依赖**: 优化模块间依赖关系，减少耦合
- **内存管理**: 使用Qt6的智能指针和现代C++特性
- **事件处理**: 更新事件处理机制，提高响应性能

### 代码质量提升
- **完整中文注释**: 
  - 所有核心.h和.cpp文件添加详细中文注释
  - 统一的注释格式：`// 注释内容` 或 `/* 注释内容 */`
  - 包含函数功能、参数说明、返回值、注意事项
  - 业务逻辑和算法的详细解释

- **统一代码风格**:
  - 规范化命名约定（驼峰命名法）
  - 统一的缩进和格式
  - 一致的括号和空格使用
  - 标准化的头文件包含顺序

- **文档完善**:
  - 详细的模块功能说明
  - 完整的API文档
  - 清晰的架构设计文档
  - 用户使用指南

- **可读性增强**:
  - 清晰的代码结构和逻辑
  - 合理的函数分解和模块化
  - 丰富的注释和说明
  - 一致的错误处理模式

### 功能增强
- **性能优化**:
  - 改进的算法复杂度
  - 优化的内存使用
  - 更快的数据处理速度
  - 减少的启动时间

- **错误处理**:
  - 完善的异常处理机制
  - 详细的错误日志
  - 用户友好的错误提示
  - 自动恢复和重试机制

- **兼容性**:
  - 更好的文件格式兼容性
  - 向后兼容旧版本文件
  - 跨平台一致性
  - 硬件兼容性改进

- **用户体验**:
  - 改进的界面交互
  - 更直观的操作流程
  - 实时反馈和提示
  - 可定制的设置选项

## 🤝 贡献指南

### 🎯 如何贡献

我们欢迎所有形式的贡献！无论是代码、文档、bug报告还是功能建议。

#### 🐛 报告问题
- 使用GitHub Issues报告bug
- 提供详细的复现步骤
- 包含系统信息和错误日志
- 添加相关截图或视频

#### 💡 功能建议
- 在Issues中描述新功能需求
- 说明使用场景和预期效果
- 讨论实现方案和技术细节

#### 🔧 代码贡献
1. **Fork项目**: 点击GitHub右上角的Fork按钮
2. **克隆仓库**: `git clone [你的fork地址]`
3. **创建分支**: `git checkout -b feature/AmazingFeature`
4. **编写代码**: 遵循项目的代码规范
5. **测试验证**: 确保功能正常且不破坏现有功能
6. **提交更改**: `git commit -m 'Add some AmazingFeature'`
7. **推送分支**: `git push origin feature/AmazingFeature`
8. **创建PR**: 在GitHub上创建Pull Request

#### � 文档改进
- 修正文档中的错误
- 添加缺失的说明
- 改进示例代码
- 翻译文档到其他语言

### 📋 提交规范

#### 提交信息格式
```
<类型>(<范围>): <描述>

[可选的正文]

[可选的脚注]
```

#### 类型说明
- `feat`: 新功能
- `fix`: 修复bug
- `docs`: 文档更新
- `style`: 代码格式调整
- `refactor`: 代码重构
- `test`: 测试相关
- `chore`: 构建过程或辅助工具的变动

#### 示例
```
feat(ui): 添加打印进度显示功能

- 在主界面添加实时进度条
- 显示剩余时间和完成百分比
- 支持暂停和恢复操作

Closes #123
```

### 🔍 代码审查

所有代码贡献都需要通过代码审查：

#### 审查要点
- ✅ 代码符合项目规范
- ✅ 功能正确且完整
- ✅ 包含适当的测试
- ✅ 文档已更新
- ✅ 性能影响可接受
- ✅ 安全性考虑充分

#### 审查流程
1. 创建Pull Request
2. 自动化测试运行
3. 维护者人工审查
4. 反馈和修改
5. 合并到主分支

## � 许可证

本项目基于 **GNU General Public License v3.0** 许可证开源。

### 📜 许可证要点

#### ✅ 你可以：
- **使用**: 自由使用软件用于任何目的
- **修改**: 修改源代码以满足你的需求
- **分发**: 分发原始或修改后的版本
- **私用**: 用于个人或商业项目

#### ⚠️ 你必须：
- **保留声明**: 保留原始版权和许可证声明
- **说明变更**: 明确标注对原始代码的修改
- **开源修改**: 如果分发修改版本，必须使用相同许可证
- **提供源码**: 确保用户能获取源代码

#### ❌ 你不能：
- **承担责任**: 作者不承担任何担保责任
- **商标使用**: 不能使用项目商标进行商业推广

### 📋 许可证全文

完整的许可证文本请参见项目根目录的 [LICENSE](LICENSE) 文件。

## 📞 联系方式

### 👥 项目团队

#### 当前维护者
- **owenzhang** - 主要维护者和Qt6迁移负责人
  - 📧 Email: yuenar2@gmail.com
  - 🎯 负责内容: 代码维护、功能开发、社区管理

#### 原始贡献者
- **yuenar2@gmail.com** - 项目创始人和早期维护者
  - 🎯 贡献: 初始开源发布、中文注释优化

### 🌐 官方渠道

#### 项目主页
- **官方网站**: http://b9creator.com/
- **GitHub仓库**: [项目GitHub地址]
- **文档站点**: [文档网站地址]

#### 社区交流
- **技术讨论**: [论坛地址]
- **问题反馈**: [GitHub Issues]
- **功能建议**: [GitHub Discussions]

### 📧 商业联系

如需商业合作、技术支持或定制开发，请通过以下方式联系：

- **商务合作**: business@b9creator.com
- **技术支持**: support@b9creator.com
- **媒体咨询**: media@b9creator.com

### 🕐 支持时间

- **技术支持**: 工作日 9:00-18:00 (UTC+8)
- **社区响应**: 通常在24小时内回复
- **紧急问题**: 标记为urgent的issue会优先处理

## 🙏 致谢

### 🌟 特别感谢

#### 原始开发团队
感谢B9Creations, LLC提供的优秀基础代码和持续支持：
- **核心架构设计**: 为项目奠定了坚实的技术基础
- **硬件集成**: 实现了与B9Creator™打印机的完美配合
- **算法优化**: 提供了高效的切片和打印算法

#### 社区贡献者
感谢所有为项目做出贡献的开发者和用户：
- **代码贡献**: 提交代码、修复bug、开发新功能
- **测试反馈**: 报告问题、提供测试结果、改进建议
- **文档完善**: 编写文档、翻译内容、制作教程
- **社区支持**: 帮助新手、分享经验、推广项目

### 📚 技术致谢

#### 开源项目
本项目依赖和借鉴了以下优秀的开源项目：
- **Qt框架**: 跨平台GUI开发框架
- **OpenGL**: 3D图形渲染标准
- **CMake**: 跨平台构建系统
- **STL**: C++标准模板库

#### 技术标准
- **SLC格式**: 3D打印切片文件标准
- **STL格式**: 3D模型文件标准
- **GNU GPL**: 开源软件许可证标准

### 🎁 赞助支持

如果您觉得本项目有用，欢迎通过以下方式支持：

#### 💰 资金支持
- **GitHub Sponsors**: 通过GitHub赞助项目
- **Patreon**: 月度支持计划
- **一次性捐赠**: PayPal或其他支付方式

#### 🤝 技术支持
- **代码贡献**: 提交代码和功能改进
- **文档编写**: 完善用户文档和API文档
- **测试验证**: 帮助测试新功能和修复bug

#### 📢 推广宣传
- **社交媒体**: 分享项目到社交平台
- **技术博客**: 撰写使用教程和评测
- **社区活动**: 参与相关技术会议和活动

## 🔮 未来规划

### 📅 发展路线图

#### 短期目标 (3-6个月)
- ✅ **Qt6迁移完成**: 完全迁移到Qt6.x
- ✅ **中文注释完善**: 所有核心文件添加中文注释
- 🔄 **性能优化**: 改进切片和渲染性能
- 🔄 **UI改进**: 现代化用户界面设计
- 🔄 **文档完善**: 完整的用户和开发文档

#### 中期目标 (6-12个月)
- 🎯 **新功能开发**: 
  - 高级支撑生成算法
  - 实时切片预览
  - 批量打印管理
  - 云端项目同步
- 🎯 **兼容性提升**:
  - 更多3D打印机支持
  - 更多文件格式支持
  - 移动端应用开发
- 🎯 **性能优化**:
  - 多线程切片引擎
  - GPU加速渲染
  - 内存使用优化

#### 长期目标 (1-2年)
- 🚀 **生态系统建设**:
  - 插件系统开发
  - 第三方工具集成
  - 开放API平台
- 🚀 **智能化发展**:
  - AI辅助支撑生成
  - 自动参数优化
  - 智能错误检测
- 🚀 **商业化发展**:
  - 企业版功能
  - 技术支持服务
  - 培训和认证

### 🎯 技术愿景

#### 架构演进
- **微服务化**: 将单体应用拆分为微服务架构
- **云原生**: 支持容器化部署和云端运行
- **跨平台**: 扩展到Web、移动端等更多平台

#### 技术创新
- **AI集成**: 集成机器学习和人工智能技术
- **实时协作**: 支持多用户实时协作编辑
- **虚拟现实**: 支持VR/AR技术的3D预览和编辑

#### 社区建设
- **开发者生态**: 建立活跃的开发者社区
- **用户社区**: 建立用户交流和支持平台
- **教育推广**: 推广3D打印技术和开源文化

---

## 📌 重要声明

### ⚠️ 免责声明

**本软件按"原样"提供，不提供任何明示或暗示的担保。**

#### 使用风险
- 使用本软件的风险由用户自行承担
- 开发团队不对任何直接或间接损失负责
- 建议在生产环境使用前进行充分测试

#### 责任限制
- 软件可能存在缺陷和错误
- 功能可能随时变更或中断
- 不保证服务的持续可用性

### 🔒 隐私保护

#### 数据收集
- 本软件不收集用户个人信息
- 使用数据仅用于功能改进
- 不会向第三方分享用户数据

#### 数据安全
- 项目文件存储在本地
- 网络通信采用加密传输
- 定期更新安全补丁

### 📜 版权声明

© 2011-2012 B9Creations, LLC 
© 2015-2026 yuenar2@gmail.com

保留所有权利。

---

**感谢您选择B9Creator™开源3D打印软件！**

🎉 **开始您的3D打印之旅吧！** 🎉

---

# 🇺🇸 English Version

# B9Creator™ 3D Printing Control Software

## 📋 Project Overview

B9Creator™ is an open-source 3D printer firmware and control software, originally based on Qt4.8, now successfully migrated to Qt6. This software provides a complete control interface for the B9Creator™ high-resolution DLP/resin 3D printer.

### 🎯 Software Features
- **High Precision**: Support for high-resolution DLP/resin 3D printing
- **Cross-Platform**: Full support for Windows, macOS, Linux systems
- **Open Source**: Based on GNU GPL v3.0 license
- **User-Friendly**: Intuitive user interface and complete printing workflow

## 🚀 Version Information

- **Current Version**: Qt6.x Migration Version
- **Original Version**: Based on Qt4.8
- **Last Update**: 2026-03-15
- **Maintainer**: owenzhang (yuenar2@gmail.com)

## 📜 Change History

### 2026-03-15 - Qt6 Migration Version (owenzhang)
- 🆕 **Major Upgrade**: Successfully migrated from Qt4.8 to Qt6.x
- 📝 **Code Comments**: Added comprehensive Chinese code comments for improved maintainability
- 🔧 **Code Optimization**: Improved code structure and performance
- 🏗️ **Modularization**: Redesigned module architecture and interfaces
- 📚 **Documentation**: Updated project documentation and user guides

### 2015-10-19 - Comment Optimization Version (yuenar2@gmail.com)
- 📝 **Comment Improvements**: Updated almost all comments for Chinese users
- 🖥️ **Interface**: Interface remained in English, no localization
- ⚠️ **Known Issues**: 
  - Normal slicing not working after compilation on Windows platform
  - Default support loading issues on Linux/macOS

### 2015-09-24 - First Upload Version (yuenar2@gmail.com)
- 🎉 **Initial Release**: Open source version based on Qt4.8, migrated to Qt5.6
- 🖥️ **Platform Support**: Tested on win7-10/OSX10.10.1-10.11/openSUSE13.2/Ubuntu
- 📦 **Complete Features**: Full 3D printing control functionality

## 🖥️ Supported Platforms

### Windows
- ✅ Windows 7 (SP1+)
- ✅ Windows 8/8.1
- ✅ Windows 10/11
- ✅ Visual Studio 2019+ compilation support

### macOS
- ✅ macOS 10.10.1 (Yosemite) and above
- ✅ Xcode 12+ compilation support
- ✅ Intel and Apple Silicon (M1/M2) support

### Linux
- ✅ Ubuntu 16.04 LTS and above
- ✅ openSUSE 13.2 and above
- ✅ Debian 9+ and other distributions
- ✅ GCC 7+ and Clang 8+ compilation support

## 📚 Project Features

### 🎯 Core Features
- **3D Model Layout**: 
  - Support for multiple model import and editing
  - Intelligent auto-arrangement and manual adjustment
  - Model rotation, scaling, and movement operations
  - Support structure generation and editing

- **Slicing Engine**:
  - Efficient model slicing algorithms
  - Adjustable layer thickness and exposure parameters
  - Automatic support generation and manual editing
  - Slice preview and optimization

- **Print Control**:
  - Complete printing workflow management
  - Real-time printing status monitoring
  - Print parameter adjustment and saving
  - Error detection and handling

- **File Formats**:
  - Support for STL, OBJ and other common 3D model formats
  - B9 proprietary project file format (.b9layout)
  - SLC slice file export
  - Print job file (.b9j) support

### 🔄 Technical Updates
- **Qt6 Migration**: 
  - Complete migration from Qt4.8 to Qt6.x
  - Modernized UI components and interactions
  - Improved signal-slot mechanism
  - Better cross-platform compatibility

- **Chinese Comments**: 
  - Detailed Chinese comments added to all core files
  - Unified comment format and style
  - Detailed function and class descriptions
  - Business logic and algorithm explanations

- **Code Optimization**: 
  - Improved memory management
  - Optimized algorithm performance
  - Better error handling
  - Thread safety improvements

- **Modular Design**: 
  - Clear module division
  - Standardized interface design
  - Loose-coupled component architecture
  - Easy to extend and maintain

## 📁 Project Structure

```
B9Creator-QT5.X/
├── src/                          # Source code directory
│   ├── b9layout/                 # Layout module - 3D model layout and project data management
│   │   ├── projectdata.h/cpp     # Project data management - File I/O, project state maintenance
│   │   ├── b9tesselator.h/cpp    # Triangulation - OpenGL triangulation algorithms
│   │   ├── SlcExporter.h/cpp     # SLC file export - Standard slice format export
│   │   ├── b9verticaltricontainer.h/cpp  # Vertical triangle container - Z-axis layering optimization
│   │   ├── b9layout.h/cpp        # Main layout class - Layout core logic
│   │   ├── loop.h/cpp             # Loop data processing
│   │   ├── triangle3d.h/cpp      # 3D triangle data structure
│   │   └── geometricfunctions.h/cpp # Geometric calculation functions
│   ├── b9edit/                   # Edit module - Slice editing and graphics processing
│   │   ├── SliceEditView.h/cpp   # Slice edit view - Visual editing interface
│   │   ├── floodfill.h/cpp       # Flood fill algorithm - Region fill operations
│   │   ├── DrawingContext.h/cpp  # Drawing context - Graphics rendering management
│   │   ├── sliceeditview.ui       # Qt Designer interface file
│   │   └── ...                   # Other edit-related files
│   ├── b9print/                  # Print module - Print control and monitoring
│   │   ├── b9print.h/cpp         # Print control core - Print workflow management
│   │   └── ...                   # Other print-related files
│   ├── b9terminal/               # Terminal module - Printer communication
│   │   ├── b9terminal.h/cpp      # Printer terminal control
│   │   └── ...                   # Other terminal-related files
│   ├── b9projector/              # Projector module - Projection control
│   │   ├── b9projector.h/cpp     # Projector control
│   │   └── ...                   # Other projector-related files
│   ├── mainwindow.h/cpp          # Main window - Application main interface
│   ├── main.cpp                  # Program entry point
│   └── ...                       # Other core files
├── resources/                    # Resource files directory
│   ├── icons/                    # Icon resources
│   ├── images/                   # Image resources
│   ├── ui/                       # UI files
│   └── ...                       # Other resources
├── docs/                         # Documentation directory
│   ├── api/                      # API documentation
│   ├── userguide/                # User guide
│   └── ...                       # Other documentation
├── build/                        # Build output directory
├── CMakeLists.txt                # CMake build configuration
├── README.md                     # Project documentation
├── LICENSE                       # License file
└── ...                           # Other configuration files
```

## 🔧 Build Instructions

### 📋 Environment Requirements

#### Required Components
- **Qt6**: Qt6.2 or higher version
- **CMake**: 3.16 or higher version  
- **Compiler**: C++17 compatible compiler
  - Windows: Visual Studio 2019+ or MinGW-w64 8+
  - macOS: Xcode 12+ or Clang 8+
  - Linux: GCC 7+ or Clang 8+

#### Optional Components
- **OpenGL**: For 3D rendering and triangulation
- **Git**: For version control and source code retrieval
- **Python**: For build scripts and tools

### 🏗️ Build Steps

#### Windows (Visual Studio)
```cmd
# 1. Install Qt6 and Visual Studio 2019+
# 2. Clone project
git clone [repository-url]
cd B9Creator-QT5.X

# 3. Create build directory
mkdir build
cd build

# 4. Configure CMake
cmake .. -G "Visual Studio 16 2019" -A x64

# 5. Build
cmake --build . --config Release

# 6. Run
cd Release
B9Creator.exe
```

#### macOS (Xcode)
```bash
# 1. Install Qt6 and Xcode
# 2. Clone project
git clone [repository-url]
cd B9Creator-QT5.X

# 3. Create build directory
mkdir build && cd build

# 4. Configure CMake
cmake .. -G Xcode

# 5. Build
cmake --build . --config Release

# 6. Run
open B9Creator.app
```

#### Linux (GCC)
```bash
# 1. Install dependencies
sudo apt-get install qt6-base-dev cmake build-essential

# 2. Clone project
git clone [repository-url]
cd B9Creator-QT5.X

# 3. Create build directory
mkdir build && cd build

# 4. Configure CMake
cmake .. -DCMAKE_BUILD_TYPE=Release

# 5. Build
make -j$(nproc)

# 6. Run
./B9Creator
```

### ⚠️ Build Notes

#### Windows Platform
- Ensure Qt6 environment variables are correctly set
- May need to install Visual C++ Redistributable
- Some features may require administrator privileges

#### macOS Platform  
- Ensure Xcode command line tools are installed
- May need to disable Gatekeeper to run unsigned applications
- Apple Silicon Macs need arm64 version of Qt6

#### Linux Platform
- Ensure OpenGL drivers are properly installed
- May need to install additional Qt6 modules
- Some distributions may require library path adjustments

## 📖 Module Details

### b9layout Module - Layout Management Core

#### projectdata (Project Data Management)
- **Function**: Responsible for project file I/O, project state maintenance, and data management
- **Main Class**: `ProjectData`
- **Core Features**:
  - Project file (.b9layout) reading and saving
  - Model instance management and layout data
  - Print parameters and settings management
  - Project modification state tracking
- **File Format**: Support for version 13 and 14 layout file formats
- **Data Structure**: Contains model list, resolution, pixel size, build space, etc.

#### b9tesselator (Triangulation)
- **Function**: OpenGL triangulation algorithm for model mesh processing
- **Main Class**: `B9Tesselator`
- **Core Features**:
  - 2D polygon triangulation
  - OpenGL callback function handling
  - Vertex data management and optimization
  - Memory management and error handling
- **Algorithm**: Based on GLU triangulator
- **Application**: Used for model slicing and support generation

#### SlcExporter (SLC File Export)
- **Function**: Standard SLC format file export
- **Main Class**: `SlcExporter`
- **Core Features**:
  - SLC file header information writing
  - Slice data and boundary export
  - Unit conversion and coordinate processing
  - Binary file format handling
- **File Format**: Support for SLC 2.0 standard
- **Application**: Compatibility with other 3D printing software

#### b9verticaltricontainer (Vertical Triangle Container)
- **Function**: Z-axis layered triangle container for optimized triangle processing
- **Main Class**: `B9VerticalTriContainer`
- **Core Features**:
  - Triangle management by Z-axis range
  - Triangle fitness determination
  - Container linked list structure management
  - Spatial indexing optimization
- **Algorithm**: Vertical space partitioning
- **Application**: Improves slicing algorithm efficiency

### b9edit Module - Editing and Graphics Processing

#### SliceEditView (Slice Edit View)
- **Function**: Visual interface for slice editing
- **Main Class**: `SliceEditView`
- **Core Features**:
  - Slice image display and editing
  - Support structure editing
  - Drawing tools and operations
  - Real-time preview and updates
- **Interface**: Based on Qt Designer UI files
- **Interaction**: Mouse and keyboard event handling

#### floodfill (Flood Fill Algorithm)
- **Function**: Region fill algorithm implementation
- **Main Class**: Flood fill related classes
- **Core Features**:
  - Seed fill algorithm
  - Region detection and marking
  - Boundary processing and optimization
  - Multiple fill strategy support
- **Algorithm**: Scanline fill and recursive fill
- **Application**: Support generation and region selection

#### DrawingContext (Drawing Context)
- **Function**: Graphics rendering management and drawing operations
- **Main Class**: `DrawingContext`
- **Core Features**:
  - 2D graphics drawing interface
  - Drawing state management
  - Graphics object operations
  - Rendering optimization
- **Graphics**: Support for lines, polygons, text, etc.
- **Application**: Slice preview and editing interface

### b9print Module - Print Control

#### b9print (Print Control Core)
- **Function**: 3D printing workflow management and control
- **Main Class**: `B9Print`
- **Core Features**:
  - Print job management
  - Print parameter control
  - Real-time status monitoring
  - Error handling and recovery
- **Communication**: Communication with printer hardware
- **Workflow**: Complete process from slicing to printing

## 🌟 Major Improvements Details

### Qt6 Migration Optimization
- **Signal-Slot Syntax**: Updated from Qt4 `SIGNAL()`/`SLOT()` macros to Qt6 function pointer syntax
- **UI Components**: Using Qt6 modernized UI components for improved user experience
- **Thread Safety**: Improved multi-threading handling for better stability
- **Module Dependencies**: Optimized inter-module dependencies, reduced coupling
- **Memory Management**: Using Qt6 smart pointers and modern C++ features
- **Event Handling**: Updated event handling mechanism for improved response performance

### Code Quality Enhancement
- **Complete Chinese Comments**: 
  - Detailed Chinese comments added to all core .h and .cpp files
  - Unified comment format: `// comment content` or `/* comment content */`
  - Function functionality, parameter descriptions, return values, notes included
  - Detailed business logic and algorithm explanations

- **Unified Code Style**:
  - Standardized naming conventions (camelCase)
  - Unified indentation and formatting
  - Consistent bracket and space usage
  - Standardized header file include order

- **Documentation Improvement**:
  - Detailed module functionality descriptions
  - Complete API documentation
  - Clear architecture design documentation
  - User usage guides

- **Readability Enhancement**:
  - Clear code structure and logic
  - Reasonable function decomposition and modularization
  - Rich comments and explanations
  - Consistent error handling patterns

### Feature Enhancement
- **Performance Optimization**:
  - Improved algorithm complexity
  - Optimized memory usage
  - Faster data processing speed
  - Reduced startup time

- **Error Handling**:
  - Comprehensive exception handling mechanisms
  - Detailed error logging
  - User-friendly error messages
  - Automatic recovery and retry mechanisms

- **Compatibility**:
  - Better file format compatibility
  - Backward compatibility with old version files
  - Cross-platform consistency
  - Hardware compatibility improvements

- **User Experience**:
  - Improved interface interactions
  - More intuitive operation workflow
  - Real-time feedback and prompts
  - Customizable setting options

## 🤝 Contributing Guidelines

### 🎯 How to Contribute

We welcome all forms of contributions! Whether it's code, documentation, bug reports, or feature suggestions.

#### 🐛 Reporting Issues
- Use GitHub Issues to report bugs
- Provide detailed reproduction steps
- Include system information and error logs
- Add relevant screenshots or videos

#### 💡 Feature Suggestions
- Describe new feature requirements in Issues
- Explain use cases and expected effects
- Discuss implementation solutions and technical details

#### 🔧 Code Contributions
1. **Fork Project**: Click the Fork button in the top right of GitHub
2. **Clone Repository**: `git clone [your-fork-url]`
3. **Create Branch**: `git checkout -b feature/AmazingFeature`
4. **Write Code**: Follow project coding standards
5. **Test Verification**: Ensure functionality works and doesn't break existing features
6. **Submit Changes**: `git commit -m 'Add some AmazingFeature'`
7. **Push Branch**: `git push origin feature/AmazingFeature`
8. **Create PR**: Create Pull Request on GitHub

#### 📝 Documentation Improvements
- Correct errors in documentation
- Add missing explanations
- Improve example code
- Translate documentation to other languages

### 📋 Submission Guidelines

#### Commit Message Format
```
<type>(<scope>): <description>

[optional body]

[optional footer]
```

#### Type Description
- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation update
- `style`: Code format adjustment
- `refactor`: Code refactoring
- `test`: Test related
- `chore`: Build process or auxiliary tool changes

#### Example
```
feat(ui): Add print progress display feature

- Add real-time progress bar in main interface
- Display remaining time and completion percentage
- Support pause and resume operations

Closes #123
```

### 🔍 Code Review

All code contributions require code review:

#### Review Points
- ✅ Code meets project standards
- ✅ Functionality is correct and complete
- ✅ Includes appropriate tests
- ✅ Documentation is updated
- ✅ Performance impact is acceptable
- ✅ Security considerations are adequate

#### Review Process
1. Create Pull Request
2. Automated tests run
3. Maintainer manual review
4. Feedback and modifications
5. Merge to main branch

## 📄 License

This project is open source under the **GNU General Public License v3.0** license.

### 📜 License Key Points

#### ✅ You Can:
- **Use**: Freely use software for any purpose
- **Modify**: Modify source code to meet your needs
- **Distribute**: Distribute original or modified versions
- **Private Use**: Use for personal or commercial projects

#### ⚠️ You Must:
- **Retain Notice**: Keep original copyright and license notices
- **State Changes**: Clearly mark modifications to original code
- **Open Source Changes**: If distributing modified versions, must use same license
- **Provide Source**: Ensure users can obtain source code

#### ❌ You Cannot:
- **Assume Liability**: Authors assume no warranty liability
- **Trademark Use**: Cannot use project trademarks for commercial promotion

### 📋 Full License Text

For the complete license text, please see the [LICENSE](LICENSE) file in the project root directory.

## 📞 Contact Information

### 👥 Project Team

#### Current Maintainer
- **owenzhang** - Primary maintainer and Qt6 migration lead
  - 📧 Email: yuenar2@gmail.com
  - 🎯 Responsibilities: Code maintenance, feature development, community management

#### Original Contributors
- **yuenar2@gmail.com** - Project founder and early maintainer
  - 🎯 Contributions: Initial open source release, Chinese comment optimization

### 🌐 Official Channels

#### Project Homepage
- **Official Website**: http://b9creator.com/
- **GitHub Repository**: [Project GitHub URL]
- **Documentation Site**: [Documentation website URL]

#### Community Communication
- **Technical Discussion**: [Forum URL]
- **Issue Reporting**: [GitHub Issues]
- **Feature Suggestions**: [GitHub Discussions]

### 📧 Business Contact

For business cooperation, technical support, or custom development, please contact:

- **Business Cooperation**: business@b9creator.com
- **Technical Support**: support@b9creator.com
- **Media Inquiries**: media@b9creator.com

### 🕐 Support Hours

- **Technical Support**: Weekdays 9:00-18:00 (UTC+8)
- **Community Response**: Usually within 24 hours
- **Urgent Issues**: Issues marked as urgent will be prioritized

## 🙏 Acknowledgments

### 🌟 Special Thanks

#### Original Development Team
Thanks to B9Creations, LLC for providing excellent foundation code and continued support:
- **Core Architecture Design**: Laid solid technical foundation for the project
- **Hardware Integration**: Achieved perfect compatibility with B9Creator™ printers
- **Algorithm Optimization**: Provided efficient slicing and printing algorithms

#### Community Contributors
Thanks to all developers and users who contributed to the project:
- **Code Contributions**: Submit code, fix bugs, develop new features
- **Testing Feedback**: Report issues, provide test results, improvement suggestions
- **Documentation**: Write documentation, translate content, create tutorials
- **Community Support**: Help newcomers, share experiences, promote project

### 📚 Technical Acknowledgments

#### Open Source Projects
This project relies on and learns from the following excellent open source projects:
- **Qt Framework**: Cross-platform GUI development framework
- **OpenGL**: 3D graphics rendering standard
- **CMake**: Cross-platform build system
- **STL**: C++ Standard Template Library

#### Technical Standards
- **SLC Format**: 3D printing slice file standard
- **STL Format**: 3D model file standard
- **GNU GPL**: Open source software license standard

## 🔮 Future Plans

### 📅 Development Roadmap

#### Short-term Goals (3-6 months)
- ✅ **Qt6 Migration Complete**: Fully migrate to Qt6.x
- ✅ **Chinese Comments Complete**: Add Chinese comments to all core files
- 🔄 **Performance Optimization**: Improve slicing and rendering performance
- 🔄 **UI Improvements**: Modernized user interface design
- 🔄 **Documentation**: Complete user and developer documentation

#### Mid-term Goals (6-12 months)
- 🎯 **New Feature Development**: 
  - Advanced support generation algorithms
  - Real-time slice preview
  - Batch print management
  - Cloud project synchronization
- 🎯 **Compatibility Enhancement**:
  - More 3D printer support
  - More file format support
  - Mobile application development
- 🎯 **Performance Optimization**:
  - Multi-threaded slicing engine
  - GPU-accelerated rendering
  - Memory usage optimization

#### Long-term Goals (1-2 years)
- 🚀 **Ecosystem Development**:
  - Plugin system development
  - Third-party tool integration
  - Open API platform
- 🚀 **Intelligent Development**:
  - AI-assisted support generation
  - Automatic parameter optimization
  - Intelligent error detection
- 🚀 **Commercial Development**:
  - Enterprise version features
  - Technical support services
  - Training and certification

### 🎯 Technical Vision

#### Architecture Evolution
- **Microservices**: Split monolithic application into microservices architecture
- **Cloud Native**: Support containerized deployment and cloud operation
- **Cross-Platform**: Expand to Web, mobile, and other platforms

#### Technical Innovation
- **AI Integration**: Integrate machine learning and artificial intelligence technologies
- **Real-time Collaboration**: Support multi-user real-time collaborative editing
- **Virtual Reality**: Support VR/AR technology for 3D preview and editing

#### Community Building
- **Developer Ecosystem**: Build active developer community
- **User Community**: Build user communication and support platform
- **Education Promotion**: Promote 3D printing technology and open source culture

---

## 📌 Important Notice

### ⚠️ Disclaimer

**This software is provided "as is" without any express or implied warranties.**

#### Usage Risks
- Users assume all risks when using this software
- Development team is not responsible for any direct or indirect losses
- Recommend thorough testing before production use

#### Liability Limitations
- Software may have defects and errors
- Features may change or be discontinued at any time
- No guarantee of continuous service availability

### 🔒 Privacy Protection

#### Data Collection
- This software does not collect user personal information
- Usage data is only used for feature improvement
- User data will not be shared with third parties

#### Data Security
- Project files are stored locally
- Network communication uses encrypted transmission
- Regular security patch updates

### 📜 Copyright Notice

© 2011-2012 B9Creations, LLC 
© 2015-2026 yuenar2@gmail.com

All rights reserved.

---

**Thank you for choosing B9Creator™ open source 3D printing software!**

🎉 **Start your 3D printing journey now!** 🎉

