# src/CMakeLists.txt - 主要源代码构建配置

set(SOURCES
    main.cpp
    b9nativeapp.cpp
    mainwindow.cpp
    logfilemanager.cpp
    myauth.cpp
    OS_Wrapper_Functions.cpp
    QVirtualSerialPort.cpp
    crushbitmap.cpp
    loadingbar.cpp
    helpsystem.cpp
    dlgprintprep.cpp
    dlgcalbuildtable.cpp
    dlgcalprojector.cpp
    dlgcyclesettings.cpp
    dlgmaterialsmanager.cpp
    b9print.cpp
    b9terminal.cpp
    b9printercomm.cpp
    b9projector.cpp
    b9updatemanager.cpp
    b9modelloader.cpp
    b9modelwriter.cpp
    b9matcat.cpp
    b9material.cpp
    b9printermodeldata.cpp
    b9printermodelmanager.cpp
    b9supportstructure.cpp
    b9layout/b9layout.cpp
    b9layout/b9layoutprojectdata.cpp
    b9layout/b9modelinstance.cpp
    b9layout/worldview.cpp
    b9layout/slicecontext.cpp
    b9layout/modeldata.cpp
    b9layout/slice.cpp
    b9layout/loop.cpp
    b9layout/segment.cpp
    b9layout/triangle3d.cpp
    b9layout/sliceset.cpp
    b9layout/geometricfunctions.cpp
    b9layout/SlcExporter.cpp
    b9layout/b9tesselator.cpp
    b9layout/b9verticaltricontainer.cpp
    b9layout/projectdata.cpp
    # b9slice sources
    b9slice/b9slice.cpp
    # b9edit sources
    b9edit/b9edit.cpp
    b9edit/SliceEditView.cpp
    b9edit/DrawingContext.cpp
    b9edit/aboutbox.cpp
    b9edit/floodfill.cpp
    # qextserialport
    qextserialport-1.2beta2/src/qextserialenumerator.cpp
    qextserialport-1.2beta2/src/qextserialport.cpp
    qextserialport-1.2beta2/src/qextserialenumerator_win.cpp
    qextserialport-1.2beta2/src/qextserialport_win.cpp
    qextserialport-1.2beta2/src/qextwineventnotifier_p.cpp
)

set(HEADERS
    b9nativeapp.h
    mainwindow.h
    logfilemanager.h
    b9layout/b9layout.h
    b9layout/worldview.h
    b9layout/slicecontext.h
    b9layout/b9modelinstance.h
    b9layout/modeldata.h
    b9supportstructure.h
    b9layout/slice.h
    b9layout/loop.h
    b9slice/b9slice.h
    b9edit/b9edit.h
    b9print.h
    b9printercomm.h
    b9printermodeldata.h
    b9printermodelmanager.h
    b9terminal.h
    helpsystem.h
    dlgcalbuildtable.h
    dlgcalprojector.h
    dlgcyclesettings.h
    dlgmaterialsmanager.h
    dlgprintprep.h
    b9modelloader.h
    OS_Wrapper_Functions.h
    QVirtualSerialPort.h
    b9projector.h
    b9updatemanager.h
    b9modelwriter.h
    b9matcat.h
    b9material.h
    b9layout/b9layoutprojectdata.h
    b9layout/segment.h
    b9layout/triangle3d.h
    b9layout/sliceset.h
    b9layout/geometricfunctions.h
    b9layout/SlcExporter.h
    b9layout/b9tesselator.h
    b9layout/b9verticaltricontainer.h
    b9layout/projectdata.h
    b9edit/SliceEditView.h
    b9edit/DrawingContext.h
    b9edit/aboutbox.h
    b9edit/floodfill.h
    qextserialport-1.2beta2/src/qextserialport.h
    qextserialport-1.2beta2/src/qextserialenumerator.h
)

set(UI_FILES
    b9edit/aboutbox.ui
    b9edit/b9edit.ui
    b9edit/sliceeditview.ui
    b9layout/b93dmain.ui
    b9layout/dlgslicing.ui
    b9layout/slicedebugwindow.ui
    b9print.ui
    b9slice/b9slice.ui
    b9terminal.ui
    dlgcalbuildtable.ui
    dlgcalprojector.ui
    dlgcyclesettings.ui
    dlgmaterialsmanager.ui
    dlgprintprep.ui
    mainwindow.ui
)

add_executable(B9Creator
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
)

# 添加资源文件（从 resources 目录）
qt_add_resources(B9Creator_RESOURCES
    "../resources/b9creator.qrc"
    "b9edit/b9edit.qrc"
    "b9edit/sliceeditview.qrc"
)
target_sources(B9Creator PRIVATE ${B9Creator_RESOURCES})

# 统一使用关键字签名链接库
target_link_libraries(B9Creator PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Svg
    Qt6::Network
    Qt6::Concurrent
    Qt6::OpenGLWidgets
    setupapi
)

# Windows 特定配置
if(WIN32)
    target_link_libraries(B9Creator
        PRIVATE
            opengl32
    )
    # 添加头文件路径
    target_include_directories(B9Creator PRIVATE
        ${CMAKE_SOURCE_DIR}/src/qextserialport-1.2beta2/src
        ${CMAKE_SOURCE_DIR}/src/openssl/include
    )
endif()

# 设置目标属性
set_target_properties(B9Creator PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
