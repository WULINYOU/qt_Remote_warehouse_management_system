#include "mainwindow.h"
#include <QApplication>
#include <QDir>

#if defined(Q_OS_WIN64)
#include <windows.h>
#include <dbghelp.h> // 添加 Dbghelp 头文件

// 定义Dump文件保存路径
QString getDumpFilePath() {
    // 使用相对路径或绝对路径，确保路径存在
    QDir dumpDir("F:/qt6file/qt_Remote_warehouse_management_system/build/Desktop_Qt_6_6_3_MinGW_64_bit-Profile");
    if (!dumpDir.exists()) {
        dumpDir.mkpath(".");
    }
    return dumpDir.absoluteFilePath("newbug1.dmp");
}

LONG WINAPI exceptionHandler(EXCEPTION_POINTERS* pExceptionPointers) {
    QString dumpFileName = getDumpFilePath();
    HANDLE hDumpFile = CreateFile(dumpFileName.toStdWString().c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (hDumpFile != INVALID_HANDLE_VALUE) {
        MINIDUMP_EXCEPTION_INFORMATION mdei;
        mdei.ThreadId = GetCurrentThreadId();
        mdei.ExceptionPointers = pExceptionPointers;
        mdei.ClientPointers = TRUE;

        MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &mdei, nullptr, nullptr);
        CloseHandle(hDumpFile);
    } else {
        qDebug() << "Failed to create dump file:" << dumpFileName;
    }
    return EXCEPTION_EXECUTE_HANDLER;
}

#endif

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

#ifdef QT_NO_DEBUG
    SetUnhandledExceptionFilter(exceptionHandler);      // 安装异常处理程序
#endif

    return a.exec();
}
