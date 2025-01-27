QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4):
QT += widgets
QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO
CONFIG += c++17

LIBS += -ldbghelp
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_LFLAGS_RELEASE = -mthreads -W
QMAKE_CXXFLAGS_RELEASE += -g

CONFIG(release, debug|release) {
    MY_POST_LINK_COMMAND = F:\\qt_Remote_warehouse_management_system\\cv2pdb.exe $$OUT_PWD F:\\qt6file\\qt_Remote_warehouse_management_system\\release
    QMAKE_POST_LINK += $${MY_POST_LINK_COMMAND}
}

SOURCES += \
    add_record.cpp \
    add_storage.cpp \
    confirmdeletedialog.cpp \
    delete_record.cpp \
    lessen_storage.cpp \
    main.cpp \
    mainwindow.cpp \
    manage.cpp \
    registec.cpp \
    update_record.cpp

HEADERS += \
    add_record.h \
    add_storage.h \
    confirmdeletedialog.h \
    delete_record.h \
    lessen_storage.h \
    mainwindow.h \
    manage.h \
    registec.h \
    update_record.h

FORMS += \
    add_record.ui \
    add_storage.ui \
    confirmdeletedialog.ui \
    delete_record.ui \
    lessen_storage.ui \
    mainwindow.ui \
    manage.ui \
    registec.ui \
    update_record.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
