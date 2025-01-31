#include "mainwindow.h"
#include <QApplication>

#if defined(Q_OS_WIN64)
#include <windows.h>
#include <dbghelp.h> // 添加 Dbghelp 头文件

LONG WINAPI exceptionHandler(EXCEPTION_POINTERS* pExceptionPointers){
    // 创建 Dump 文件
    //路径
//F:\qt6file\qt_Remote_warehouse_management_system\build\Desktop_Qt_6_6_3_MinGW_64_bit-Profile
    QString dumpFileName = "newbug1.dmp";
    HANDLE hDumpFile = CreateFile(dumpFileName.toStdWString().c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (hDumpFile != INVALID_HANDLE_VALUE)
    {
        // 生成Dump文件
        MINIDUMP_EXCEPTION_INFORMATION mdei;
        mdei.ThreadId = GetCurrentThreadId();
        mdei.ExceptionPointers = pExceptionPointers;
        mdei.ClientPointers = TRUE;

        MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &mdei, nullptr, nullptr);
        CloseHandle(hDumpFile);
    }
    return EXCEPTION_EXECUTE_HANDLER;
}

#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

#ifdef QT_NO_DEBUG
    SetUnhandledExceptionFilter(exceptionHandler);      // 安装异常处理程序
#endif


    return a.exec();
}
