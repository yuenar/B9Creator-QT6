#!/usr/bin/env python3
import os
import re

def update_header(file_path, module_name, description):
    """更新文件头部注释"""
    try:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        # 查找并替换原有的注释块
        old_pattern = r'/\*{15,}.*?\*{15,}/'
        new_header = f"""/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    {module_name}
 * 文件名:     {os.path.basename(file_path)}
 * 模块功能:   {description}
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/"""
        
        # 替换注释
        new_content = re.sub(old_pattern, new_header, content, flags=re.DOTALL)
        
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(new_content)
        
        print(f"Updated: {file_path}")
        return True
    except Exception as e:
        print(f"Error updating {file_path}: {e}")
        return False

# 文件列表和描述
files_to_update = [
    # b9layout 模块
    ("src/b9layout/b9layout.h", "b9layout", "布局管理模块头文件，定义了B9Layout主窗口类和相关接口"),
    ("src/b9layout/b9layout.cpp", "b9layout", "布局管理模块实现文件，包含B9Layout主窗口类的具体实现"),
    ("src/b9layout/b9layoutprojectdata.h", "b9layout", "布局项目数据类头文件"),
    ("src/b9layout/b9layoutprojectdata.cpp", "b9layout", "布局项目数据类实现文件"),
    ("src/b9layout/b9modelinstance.h", "b9layout", "模型实例类头文件"),
    ("src/b9layout/b9modelinstance.cpp", "b9layout", "模型实例类实现文件"),
    ("src/b9layout/worldview.h", "b9layout", "3D视图类头文件"),
    ("src/b9layout/worldview.cpp", "b9layout", "3D视图类实现文件"),
    ("src/b9layout/slicecontext.h", "b9layout", "切片上下文类头文件"),
    ("src/b9layout/slicecontext.cpp", "b9layout", "切片上下文类实现文件"),
    ("src/b9layout/modeldata.h", "b9layout", "模型数据类头文件"),
    ("src/b9layout/modeldata.cpp", "b9layout", "模型数据类实现文件"),
    ("src/b9layout/slice.h", "b9layout", "切片类头文件"),
    ("src/b9layout/slice.cpp", "b9layout", "切片类实现文件"),
    ("src/b9layout/loop.h", "b9layout", "循环类头文件"),
    ("src/b9layout/loop.cpp", "b9layout", "循环类实现文件"),
    ("src/b9layout/segment.h", "b9layout", "分段类头文件"),
    ("src/b9layout/segment.cpp", "b9layout", "分段类实现文件"),
    ("src/b9layout/triangle3d.h", "b9layout", "3D三角形类头文件"),
    ("src/b9layout/triangle3d.cpp", "b9layout", "3D三角形类实现文件"),
    ("src/b9layout/sliceset.h", "b9layout", "切片集合类头文件"),
    ("src/b9layout/sliceset.cpp", "b9layout", "切片集合类实现文件"),
    ("src/b9layout/geometricfunctions.h", "b9layout", "几何函数头文件"),
    ("src/b9layout/geometricfunctions.cpp", "b9layout", "几何函数实现文件"),
    ("src/b9layout/SlcExporter.h", "b9layout", "SLC导出类头文件"),
    ("src/b9layout/SlcExporter.cpp", "b9layout", "SLC导出类实现文件"),
    ("src/b9layout/b9tesselator.h", "b9layout", "细分器类头文件"),
    ("src/b9layout/b9tesselator.cpp", "b9layout", "细分器类实现文件"),
    ("src/b9layout/b9verticaltricontainer.h", "b9layout", "垂直三角形容器类头文件"),
    ("src/b9layout/b9verticaltricontainer.cpp", "b9layout", "垂直三角形容器类实现文件"),
    ("src/b9layout/projectdata.h", "b9layout", "项目数据类头文件"),
    ("src/b9layout/projectdata.cpp", "b9layout", "项目数据类实现文件"),
    
    # b9edit 模块
    ("src/b9edit/b9edit.h", "b9edit", "编辑器模块头文件"),
    ("src/b9edit/b9edit.cpp", "b9edit", "编辑器模块实现文件"),
    ("src/b9edit/SliceEditView.h", "b9edit", "切片编辑视图类头文件"),
    ("src/b9edit/SliceEditView.cpp", "b9edit", "切片编辑视图类实现文件"),
    ("src/b9edit/DrawingContext.h", "b9edit", "绘图上下文类头文件"),
    ("src/b9edit/DrawingContext.cpp", "b9edit", "绘图上下文类实现文件"),
    ("src/b9edit/aboutbox.h", "b9edit", "关于对话框头文件"),
    ("src/b9edit/aboutbox.cpp", "b9edit", "关于对话框实现文件"),
    ("src/b9edit/floodfill.h", "b9edit", "洪水填充算法头文件"),
    ("src/b9edit/floodfill.cpp", "b9edit", "洪水填充算法实现文件"),
    
    # b9slice 模块
    ("src/b9slice/b9slice.h", "b9slice", "切片模块头文件"),
    ("src/b9slice/b9slice.cpp", "b9slice", "切片模块实现文件"),
    
    # 核心模块
    ("src/mainwindow.h", "core", "主窗口类头文件"),
    ("src/mainwindow.cpp", "core", "主窗口类实现文件"),
    ("src/b9nativeapp.h", "core", "原生应用程序类头文件"),
    ("src/b9nativeapp.cpp", "core", "原生应用程序类实现文件"),
    ("src/logfilemanager.h", "core", "日志文件管理器头文件"),
    ("src/logfilemanager.cpp", "core", "日志文件管理器实现文件"),
    
    # 串口通信
    ("src/QVirtualSerialPort.h", "serial", "虚拟串口头文件"),
    ("src/QVirtualSerialPort.cpp", "serial", "虚拟串口实现文件"),
    
    # 工具类
    ("src/OS_GL_Wrapper.h", "utils", "OpenGL包装器头文件"),
    ("src/OS_GL_Wrapper.cpp", "utils", "OpenGL包装器实现文件"),
    ("src/OS_Wrapper_Functions.h", "utils", "操作系统包装函数头文件"),
    ("src/OS_Wrapper_Functions.cpp", "utils", "操作系统包装函数实现文件"),
    ("src/crushbitmap.h", "utils", "位图压缩头文件"),
    ("src/crushbitmap.cpp", "utils", "位图压缩实现文件"),
    ("src/loadingbar.h", "utils", "加载进度条头文件"),
    ("src/loadingbar.cpp", "utils", "加载进度条实现文件"),
    
    # 打印相关
    ("src/b9print.h", "print", "打印功能头文件"),
    ("src/b9print.cpp", "print", "打印功能实现文件"),
    ("src/b9printercomm.h", "print", "打印机通信头文件"),
    ("src/b9printercomm.cpp", "print", "打印机通信实现文件"),
    ("src/b9terminal.h", "print", "终端头文件"),
    ("src/b9terminal.cpp", "print", "终端实现文件"),
    ("src/b9projector.h", "print", "投影仪头文件"),
    ("src/b9projector.cpp", "print", "投影仪实现文件"),
    
    # 模型处理
    ("src/b9modelloader.h", "model", "模型加载器头文件"),
    ("src/b9modelloader.cpp", "model", "模型加载器实现文件"),
    ("src/b9modelwriter.h", "model", "模型写入器头文件"),
    ("src/b9modelwriter.cpp", "model", "模型写入器实现文件"),
    ("src/b9supportstructure.h", "model", "支撑结构头文件"),
    ("src/b9supportstructure.cpp", "model", "支撑结构实现文件"),
    
    # 材料管理
    ("src/b9matcat.h", "material", "材料目录头文件"),
    ("src/b9matcat.cpp", "material", "材料目录实现文件"),
    ("src/b9material.h", "material", "材料头文件"),
    ("src/b9material.cpp", "material", "材料实现文件"),
    ("src/b9printermodeldata.h", "material", "打印机模型数据头文件"),
    ("src/b9printermodeldata.cpp", "material", "打印机模型数据实现文件"),
    ("src/b9printermodelmanager.h", "material", "打印机模型管理器头文件"),
    ("src/b9printermodelmanager.cpp", "material", "打印机模型管理器实现文件"),
    
    # 对话框
    ("src/dlgcalbuildtable.h", "dialog", "构建平台校准对话框头文件"),
    ("src/dlgcalbuildtable.cpp", "dialog", "构建平台校准对话框实现文件"),
    ("src/dlgcalprojector.h", "dialog", "投影仪校准对话框头文件"),
    ("src/dlgcalprojector.cpp", "dialog", "投影仪校准对话框实现文件"),
    ("src/dlgcyclesettings.h", "dialog", "循环设置对话框头文件"),
    ("src/dlgcyclesettings.cpp", "dialog", "循环设置对话框实现文件"),
    ("src/dlgmaterialsmanager.h", "dialog", "材料管理器对话框头文件"),
    ("src/dlgmaterialsmanager.cpp", "dialog", "材料管理器对话框实现文件"),
    ("src/dlgprintprep.h", "dialog", "打印准备对话框头文件"),
    ("src/dlgprintprep.cpp", "dialog", "打印准备对话框实现文件"),
    
    # 其他
    ("src/helpsystem.h", "system", "帮助系统头文件"),
    ("src/helpsystem.cpp", "system", "帮助系统实现文件"),
    ("src/myauth.h", "auth", "认证头文件"),
    ("src/myauth.cpp", "auth", "认证实现文件"),
    ("src/b9updateentry.h", "update", "更新条目头文件"),
    ("src/b9updateentry.cpp", "update", "更新条目实现文件"),
    ("src/b9updatemanager.h", "update", "更新管理器头文件"),
    ("src/b9updatemanager.cpp", "update", "更新管理器实现文件"),
]

if __name__ == "__main__":
    base_path = "."
    success_count = 0
    total_count = len(files_to_update)
    
    for file_path, module_name, description in files_to_update:
        full_path = os.path.join(base_path, file_path)
        if os.path.exists(full_path):
            if update_header(full_path, module_name, description):
                success_count += 1
        else:
            print(f"File not found: {full_path}")
    
    print(f"\n完成! 成功更新 {success_count}/{total_count} 个文件")
