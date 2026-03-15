# B9Creator Qt6 项目源代码结构说明

## 项目概述

B9Creator是一个基于Qt6的3D打印机控制软件，用于控制B9Creator系列3D打印机的切片、布局、打印等功能。

## 目录结构

```
src/
├── b9edit/                    # 编辑器模块
│   ├── b9edit.h             # 编辑器主窗口头文件
│   ├── b9edit.cpp           # 编辑器主窗口实现
│   ├── DrawingContext.h     # 绘图上下文头文件
│   ├── SliceEditView.h     # 切片编辑视图头文件
│   ├── aboutbox.h         # 关于对话框头文件
│   └── floodfill.h        # 洪水填充头文件
│
├── b9layout/                   # 布局管理模块
│   ├── b9layout.h             # 布局主窗口头文件
│   ├── b9layout.cpp           # 布局主窗口实现
│   ├── b9layoutprojectdata.h  # 布局项目数据头文件
│   ├── b9layoutprojectdata.cpp  # 布局项目数据实现
│   ├── worldview.h            # 3D视图头文件
│   ├── worldview.cpp           # 3D视图实现
│   ├── b9modelinstance.h     # 模型实例头文件
│   ├── b9modelinstance.cpp     # 模型实例实现
│   ├── slicecontext.h         # 切片上下文头文件
│   ├── slicecontext.cpp       # 切片上下文实现
│   ├── sliceset.h            # 切片集合头文件
│   ├── sliceset.cpp           # 切片集合实现
│   ├── slice.h               # 切片类头文件
│   ├── slice.cpp              # 切片类实现
│   ├── loop.h                # 循环类头文件
│   ├── loop.cpp               # 循环类实现
│   ├── segment.h             # 分段类头文件
│   ├── segment.cpp            # 分段类实现
│   ├── geometricfunctions.h   # 几何函数头文件
│   ├── geometricfunctions.cpp # 几何函数实现
│   ├── triangle3d.h          # 3D三角形头文件
│   ├── triangle3d.cpp         # 3D三角形实现
│   ├── modeldata.h           # 模型数据头文件
│   ├── modeldata.cpp          # 模型数据实现
│   ├── SlcExporter.h         # SLC导出器头文件
│   └── b9tesselator.h       # 细分器头文件
│
├── b9slice/                    # 切片模块
│   ├── b9slice.h             # 切片主窗口头文件
│   └── b9slice.cpp           # 切片主窗口实现
│
├── b9matcat.cpp                # 材料目录实现
├── b9matcat.h                 # 材料目录头文件
│
├── b9material.cpp              # 材料类实现
├── b9material.h                # 材料类头文件
│
├── b9modelloader.cpp            # 模型加载器实现
├── b9modelloader.h             # 模型加载器头文件
│
├── b9modelwriter.cpp            # 模型写入器实现
├── b9modelwriter.h             # 模型写入器头文件
│
├── b9supportstructure.cpp     # 支撑结构实现
├── b9supportstructure.h       # 支撑结构头文件
│
├── b9print.cpp                # 打印功能实现
├── b9print.h                 # 打印功能头文件
│
├── b9printercomm.cpp           # 打印机通信实现
├── b9printercomm.h           # 打印机通信头文件
│
├── b9printermodeldata.cpp      # 打印机模型数据实现
├── b9printermodeldata.h       # 打印机模型数据头文件
│
├── b9printermodelmanager.cpp   # 打印机模型管理器实现
├── b9printermodelmanager.h     # 打印机模型管理器头文件
│
├── b9projector.cpp            # 投影仪控制实现
├── b9projector.h             # 投影仪控制头文件
│
├── b9terminal.cpp              # 终端控制实现
├── b9terminal.h              # 终端控制头文件
│
├── b9updatemanager.cpp         # 更新管理器实现
├── b9updatemanager.h          # 更新管理器头文件
├── b9updateentry.h            # 更新条目头文件
│
├── crushbitmap.cpp             # 位图压缩实现
├── crushbitmap.h              # 位图压缩头文件
│
├── dlgcalbuildtable.cpp       # 构建平台校准对话框实现
├── dlgcalbuildtable.h         # 构建平台校准对话框头文件
│
├── dlgcalprojector.cpp        # 投影仪校准对话框实现
├── dlgcalprojector.h          # 投影仪校准对话框头文件
│
├── dlgcyclesettings.cpp        # 循环设置对话框实现
├── dlgcyclesettings.h          # 循环设置对话框头文件
│
├── dlgmaterialsmanager.cpp     # 材料管理器对话框实现
├── dlgmaterialsmanager.h       # 材料管理器对话框头文件
│
├── dlgprintprep.cpp            # 打印准备对话框实现
├── dlgprintprep.h             # 打印准备对话框头文件
│
├── helpsystem.cpp             # 帮助系统实现
├── helpsystem.h              # 帮助系统头文件
│
├── loadingbar.cpp             # 加载进度条实现
├── loadingbar.h              # 加载进度条头文件
│
├── logfilemanager.cpp          # 日志文件管理器实现
├── logfilemanager.h           # 日志文件管理器头文件
│
├── main.cpp                  # 主程序入口
├── mainwindow.cpp             # 主窗口实现
├── mainwindow.h              # 主窗口头文件
│
├── myauth.cpp                 # 认证系统实现
├── myauth.h                 # 认证系统头文件
│
├── screensaverwaker.cpp        # 屏幕保护唤醒器实现
├── screensaverwaker.h          # 屏幕保护唤醒器头文件
│
├── OS_Wrapper_Functions.cpp     # 操作系统包装函数实现
├── OS_Wrapper_Functions.h      # 操作系统包装函数头文件
│
├── OS_GL_Wrapper.h           # OpenGL包装器头文件
│
├── QVirtualSerialPort.cpp       # 虚拟串口实现
├── QVirtualSerialPort.h        # 虚拟串口头文件
│
└── qextserialport-1.2beta2/ # QextSerialPort第三方库
    ├── qextserialport.pro       # QextSerialPort库配置
    ├── common.pri               # QextSerialPort通用配置
    └── src/
        ├── qextserialport.pri   # QextSerialPort源文件配置
        └── [其他源文件]
```

## 主要模块说明

### 1. 核心模块 (core/)

#### 主程序入口
- **main.cpp / mainwindow.h**: 应用程序主入口和主窗口
- **b9nativeapp.h**: 原生应用程序类

#### 操作系统包装
- **OS_Wrapper_Functions.cpp / OS_Wrapper_Functions.h**: 跨平台兼容性函数
- **OS_GL_Wrapper.h**: OpenGL相关包装函数

### 2. 布局管理模块 (b9layout/)

#### 3D布局和模型处理
- **b9layout.h / b9layout.cpp**: 布局管理主窗口
- **b9layoutprojectdata.h / b9layoutprojectdata.cpp**: 布局项目数据管理
- **worldview.h / worldview.cpp**: 3D视图显示
- **b9modelinstance.h / b9modelinstance.cpp**: 3D模型实例管理
- **slicecontext.h / slicecontext.cpp**: 切片上下文管理
- **sliceset.h / sliceset.cpp**: 切片集合管理
- **slice.h / slice.cpp**: 单个切片处理
- **loop.h / loop.cpp**: 切片循环处理
- **segment.h / segment.cpp**: 切片分段处理
- **geometricfunctions.h / geometricfunctions.cpp**: 几何计算函数
- **triangle3d.h / triangle3d.cpp**: 3D三角形数据结构
- **SlcExporter.h**: SLC格式导出器
- **b9tesselator.h**: 细分算法

### 3. 切片模块 (b9slice/)

#### 切片编辑器
- **b9slice.h / b9slice.cpp**: 切片编辑主窗口

### 4. 编辑器模块 (b9edit/)

#### 切片编辑功能
- **b9edit.h / b9edit.cpp**: 切片编辑器主窗口
- **DrawingContext.h**: 绘图上下文
- **SliceEditView.h**: 切片编辑视图
- **aboutbox.h**: 关于对话框
- **floodfill.h**: 洪水填充算法

### 5. 模型处理模块

#### 模型加载和写入
- **b9modelloader.h / b9modelloader.cpp**: STL模型加载器
- **b9modelwriter.h / b9modelwriter.cpp**: 模型数据写入器

#### 支撑结构
- **b9supportstructure.h / b9supportstructure.cpp**: 3D打印支撑结构生成

### 6. 材料管理模块

#### 材料目录和材料
- **b9matcat.h / b9matcat.cpp**: 材料目录管理
- **b9material.h / b9material.cpp**: 单个材料定义

### 7. 打印控制模块

#### 打印功能和通信
- **b9print.h / b9print.cpp**: 打印控制主窗口
- **b9printercomm.h / b9printercomm.cpp**: 打印机串口通信
- **b9projector.h / b9projector.cpp**: 投影仪控制
- **b9printermodeldata.h / b9printermodeldata.cpp**: 打印机模型数据
- **b9printermodelmanager.h / b9printermodelmanager.cpp**: 打印机模型管理

### 8. 系统工具模块

#### 更新和帮助
- **b9updatemanager.h / b9updatemanager.cpp**: 软件更新管理
- **b9updateentry.h**: 更新条目定义
- **helpsystem.h / helpsystem.cpp**: 帮助系统

#### 工具类
- **crushbitmap.h / crushbitmap.cpp**: 位图压缩处理
- **loadingbar.h / loadingbar.cpp**: 加载进度条
- **logfilemanager.h / logfilemanager.cpp**: 日志文件管理
- **screensaverwaker.h / screensaverwaker.cpp**: 屏幕保护

#### 认证和安全
- **myauth.h / myauth.cpp**: 用户认证系统

### 9. 第三方库

#### QextSerialPort库
- **qextserialport-1.2beta2/**: 跨平台串口通信库
  - qextserialport.pro: 库主配置文件
  - common.pri: 通用配置
  - qextserialport.pri: 源文件配置
  - src/: 源代码文件

## 技术架构

### 核心技术栈
- **Qt6**: 主要GUI框架和窗口系统
- **OpenGL**: 3D渲染和图形显示
- **C++11**: 现代C++标准
- **CMake**: 构建系统

### 设计模式
- **MVC架构**: 模型-视图-控制器分离
- **信号槽机制**: Qt事件驱动编程
- **插件化设计**: QextSerialPort作为第三方库集成

## 编译和构建

### 构建系统
- 使用CMake作为主要构建系统
- 支持Qt6的模块化编译
- 跨平台兼容性（Windows/Linux）

### 依赖管理
- Qt6核心模块
- OpenGL图形库
- 网络通信库
- 串口通信库（QextSerialPort）

## 开发规范

### 代码风格
- 统一的头部注释格式
- Qt编码规范
- 模块化设计
- 接口和实现分离

### 文件命名规范
- 头文件：`.h`后缀
- 实现文件：`.cpp`后缀
- 配置文件：`.pro`和`.pri`后缀
- UI文件：`.ui`后缀

## 版本信息

- **当前版本**: Qt6迁移版本
- **构建工具**: CMake 3.15+
- **目标平台**: Windows 10/11, Linux

## 注意事项

1. **Qt6兼容性**: 所有代码已适配Qt6 API
2. **模块化**: 清晰的模块边界，便于维护
3. **跨平台**: 使用条件编译处理平台差异
4. **第三方库**: QextSerialPort作为独立子模块

## 联系信息

- **项目维护**: B9Creator Qt6版本
- **技术支持**: Qt6和C++11标准
- **文档更新**: 随代码变更同步更新

---

*最后更新: 2026-03-15*
*维护者: owenzhang*
