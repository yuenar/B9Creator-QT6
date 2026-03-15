# PowerShell脚本用于批量更新文件头部注释

function Update-FileHeader {
    param(
        [string]$FilePath,
        [string]$ModuleName,
        [string]$Description
    )
    
    try {
        $content = Get-Content -Path $FilePath -Raw -Encoding UTF8
        
        # 匹配并替换原有的注释块
        $oldPattern = '/\*{15,}.*?\*{15,}/'
        $newHeader = @"
/**************************************************************************
 * Copyright(C),  yuenar2@gmail.com
 * 模块名称:    $ModuleName
 * 文件名:     $(Split-Path $FilePath -Leaf)
 * 模块功能:   $Description
 * 创建者:    owenzhang
 * 创建日期:    2026-03-15
 * 版本号:     V1.0.0
 * 历史记录:
 * 1、修改者:   owenzhang
 *    修改日期: 2026-03-15
 *    修改内容: 迁移到Qt6，更新头部注释格式
 ***************************************************************************/
"@
        
        # 使用正则表达式替换
        $newContent = $content -replace $oldPattern, $newHeader
        
        # 写回文件
        Set-Content -Path $FilePath -Value $newContent -Encoding UTF8
        Write-Host "Updated: $FilePath" -ForegroundColor Green
        return $true
    }
    catch {
        Write-Host "Error updating $FilePath : $_" -ForegroundColor Red
        return $false
    }
}

# 需要更新的文件列表
$filesToUpdate = @(
    # b9layout 模块
    @{Path="src\b9layout\b9layoutprojectdata.h"; Module="b9layout"; Desc="布局项目数据类头文件"},
    @{Path="src\b9layout\b9layoutprojectdata.cpp"; Module="b9layout"; Desc="布局项目数据类实现文件"},
    @{Path="src\b9layout\b9modelinstance.h"; Module="b9layout"; Desc="模型实例类头文件"},
    @{Path="src\b9layout\b9modelinstance.cpp"; Module="b9layout"; Desc="模型实例类实现文件"},
    @{Path="src\b9layout\worldview.h"; Module="b9layout"; Desc="3D视图类头文件"},
    @{Path="src\b9layout\worldview.cpp"; Module="b9layout"; Desc="3D视图类实现文件"},
    @{Path="src\b9layout\modeldata.h"; Module="b9layout"; Desc="模型数据类头文件"},
    @{Path="src\b9layout\modeldata.cpp"; Module="b9layout"; Desc="模型数据类实现文件"},
    @{Path="src\b9layout\slice.h"; Module="b9layout"; Desc="切片类头文件"},
    @{Path="src\b9layout\slice.cpp"; Module="b9layout"; Desc="切片类实现文件"},
    @{Path="src\b9layout\loop.h"; Module="b9layout"; Desc="循环类头文件"},
    @{Path="src\b9layout\loop.cpp"; Module="b9layout"; Desc="循环类实现文件"},
    @{Path="src\b9layout\segment.h"; Module="b9layout"; Desc="分段类头文件"},
    @{Path="src\b9layout\segment.cpp"; Module="b9layout"; Desc="分段类实现文件"},
    @{Path="src\b9layout\triangle3d.h"; Module="b9layout"; Desc="3D三角形类头文件"},
    @{Path="src\b9layout\triangle3d.cpp"; Module="b9layout"; Desc="3D三角形类实现文件"},
    @{Path="src\b9layout\sliceset.h"; Module="b9layout"; Desc="切片集合类头文件"},
    @{Path="src\b9layout\geometricfunctions.h"; Module="b9layout"; Desc="几何函数头文件"},
    @{Path="src\b9layout\geometricfunctions.cpp"; Module="b9layout"; Desc="几何函数实现文件"},
    @{Path="src\b9layout\SlcExporter.h"; Module="b9layout"; Desc="SLC导出类头文件"},
    @{Path="src\b9layout\SlcExporter.cpp"; Module="b9layout"; Desc="SLC导出类实现文件"},
    @{Path="src\b9layout\b9tesselator.h"; Module="b9layout"; Desc="细分器类头文件"},
    @{Path="src\b9layout\b9tesselator.cpp"; Module="b9layout"; Desc="细分器类实现文件"},
    @{Path="src\b9layout\b9verticaltricontainer.h"; Module="b9layout"; Desc="垂直三角形容器类头文件"},
    @{Path="src\b9layout\b9verticaltricontainer.cpp"; Module="b9layout"; Desc="垂直三角形容器类实现文件"},
    @{Path="src\b9layout\projectdata.h"; Module="b9layout"; Desc="项目数据类头文件"},
    @{Path="src\b9layout\projectdata.cpp"; Module="b9layout"; Desc="项目数据类实现文件"},
    
    # b9edit 模块
    @{Path="src\b9edit\b9edit.h"; Module="b9edit"; Desc="编辑器模块头文件"},
    @{Path="src\b9edit\b9edit.cpp"; Module="b9edit"; Desc="编辑器模块实现文件"},
    @{Path="src\b9edit\SliceEditView.h"; Module="b9edit"; Desc="切片编辑视图类头文件"},
    @{Path="src\b9edit\SliceEditView.cpp"; Module="b9edit"; Desc="切片编辑视图类实现文件"},
    @{Path="src\b9edit\DrawingContext.h"; Module="b9edit"; Desc="绘图上下文类头文件"},
    @{Path="src\b9edit\DrawingContext.cpp"; Module="b9edit"; Desc="绘图上下文类实现文件"},
    @{Path="src\b9edit\aboutbox.h"; Module="b9edit"; Desc="关于对话框头文件"},
    @{Path="src\b9edit\aboutbox.cpp"; Module="b9edit"; Desc="关于对话框实现文件"},
    @{Path="src\b9edit\floodfill.h"; Module="b9edit"; Desc="洪水填充算法头文件"},
    @{Path="src\b9edit\floodfill.cpp"; Module="b9edit"; Desc="洪水填充算法实现文件"},
    
    # b9slice 模块
    @{Path="src\b9slice\b9slice.h"; Module="b9slice"; Desc="切片模块头文件"},
    @{Path="src\b9slice\b9slice.cpp"; Module="b9slice"; Desc="切片模块实现文件"},
    
    # 核心模块
    @{Path="src\b9nativeapp.h"; Module="core"; Desc="原生应用程序类头文件"},
    @{Path="src\b9nativeapp.cpp"; Module="core"; Desc="原生应用程序类实现文件"},
    @{Path="src\logfilemanager.h"; Module="core"; Desc="日志文件管理器头文件"},
    @{Path="src\logfilemanager.cpp"; Module="core"; Desc="日志文件管理器实现文件"},
    
    # 工具类
    @{Path="src\OS_GL_Wrapper.h"; Module="utils"; Desc="OpenGL包装器头文件"},
    @{Path="src\OS_GL_Wrapper.cpp"; Module="utils"; Desc="OpenGL包装器实现文件"},
    @{Path="src\OS_Wrapper_Functions.h"; Module="utils"; Desc="操作系统包装函数头文件"},
    @{Path="src\OS_Wrapper_Functions.cpp"; Module="utils"; Desc="操作系统包装函数实现文件"},
    @{Path="src\crushbitmap.h"; Module="utils"; Desc="位图压缩头文件"},
    @{Path="src\crushbitmap.cpp"; Module="utils"; Desc="位图压缩实现文件"},
    @{Path="src\loadingbar.h"; Module="utils"; Desc="加载进度条头文件"},
    @{Path="src\loadingbar.cpp"; Module="utils"; Desc="加载进度条实现文件"},
    
    # 打印相关
    @{Path="src\b9print.h"; Module="print"; Desc="打印功能头文件"},
    @{Path="src\b9print.cpp"; Module="print"; Desc="打印功能实现文件"},
    @{Path="src\b9printercomm.h"; Module="print"; Desc="打印机通信头文件"},
    @{Path="src\b9printercomm.cpp"; Module="print"; Desc="打印机通信实现文件"},
    @{Path="src\b9terminal.h"; Module="print"; Desc="终端头文件"},
    @{Path="src\b9terminal.cpp"; Module="print"; Desc="终端实现文件"},
    @{Path="src\b9projector.h"; Module="print"; Desc="投影仪头文件"},
    @{Path="src\b9projector.cpp"; Module="print"; Desc="投影仪实现文件"},
    
    # 模型处理
    @{Path="src\b9modelwriter.h"; Module="model"; Desc="模型写入器头文件"},
    @{Path="src\b9modelwriter.cpp"; Module="model"; Desc="模型写入器实现文件"},
    
    # 材料管理
    @{Path="src\b9matcat.h"; Module="material"; Desc="材料目录头文件"},
    @{Path="src\b9matcat.cpp"; Module="material"; Desc="材料目录实现文件"},
    @{Path="src\b9material.h"; Module="material"; Desc="材料头文件"},
    @{Path="src\b9material.cpp"; Module="material"; Desc="材料实现文件"},
    @{Path="src\b9printermodeldata.h"; Module="material"; Desc="打印机模型数据头文件"},
    @{Path="src\b9printermodeldata.cpp"; Module="material"; Desc="打印机模型数据实现文件"},
    @{Path="src\b9printermodelmanager.h"; Module="material"; Desc="打印机模型管理器头文件"},
    @{Path="src\b9printermodelmanager.cpp"; Module="material"; Desc="打印机模型管理器实现文件"},
    
    # 对话框
    @{Path="src\dlgcalbuildtable.h"; Module="dialog"; Desc="构建平台校准对话框头文件"},
    @{Path="src\dlgcalbuildtable.cpp"; Module="dialog"; Desc="构建平台校准对话框实现文件"},
    @{Path="src\dlgcalprojector.h"; Module="dialog"; Desc="投影仪校准对话框头文件"},
    @{Path="src\dlgcalprojector.cpp"; Module="dialog"; Desc="投影仪校准对话框实现文件"},
    @{Path="src\dlgcyclesettings.h"; Module="dialog"; Desc="循环设置对话框头文件"},
    @{Path="src\dlgcyclesettings.cpp"; Module="dialog"; Desc="循环设置对话框实现文件"},
    @{Path="src\dlgmaterialsmanager.h"; Module="dialog"; Desc="材料管理器对话框头文件"},
    @{Path="src\dlgmaterialsmanager.cpp"; Module="dialog"; Desc="材料管理器对话框实现文件"},
    @{Path="src\dlgprintprep.h"; Module="dialog"; Desc="打印准备对话框头文件"},
    @{Path="src\dlgprintprep.cpp"; Module="dialog"; Desc="打印准备对话框实现文件"},
    
    # 其他
    @{Path="src\helpsystem.h"; Module="system"; Desc="帮助系统头文件"},
    @{Path="src\helpsystem.cpp"; Module="system"; Desc="帮助系统实现文件"},
    @{Path="src\myauth.h"; Module="auth"; Desc="认证头文件"},
    @{Path="src\myauth.cpp"; Module="auth"; Desc="认证实现文件"},
    @{Path="src\b9updateentry.h"; Module="update"; Desc="更新条目头文件"},
    @{Path="src\b9updateentry.cpp"; Module="update"; Desc="更新条目实现文件"},
    @{Path="src\b9updatemanager.h"; Module="update"; Desc="更新管理器头文件"},
    @{Path="src\b9updatemanager.cpp"; Module="update"; Desc="更新管理器实现文件"}
)

# 执行更新
$successCount = 0
$totalCount = $filesToUpdate.Count

Write-Host "开始批量更新文件头部注释..." -ForegroundColor Cyan
Write-Host "总共需要更新 $totalCount 个文件" -ForegroundColor Yellow

foreach ($file in $filesToUpdate) {
    $fullPath = Join-Path -Path $PSScriptRoot -ChildPath $file.Path
    if (Test-Path $fullPath) {
        if (Update-FileHeader -FilePath $fullPath -ModuleName $file.Module -Description $file.Desc) {
            $successCount++
        }
    }
    else {
        Write-Host "File not found: $fullPath" -ForegroundColor Red
    }
}

Write-Host "`n完成! 成功更新 $successCount/$totalCount 个文件" -ForegroundColor Green
if ($successCount -eq $totalCount) {
    Write-Host "所有文件都已成功更新!" -ForegroundColor Green
} else {
    Write-Host "有 $($totalCount - $successCount) 个文件更新失败" -ForegroundColor Yellow
}
