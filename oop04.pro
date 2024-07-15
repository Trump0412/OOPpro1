QT       += core gui sql
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    sqlquerymodel.cpp \
    stusql.cpp \
    stutmp.cpp

HEADERS += \
    mainwindow.h \
    sqlquerymodel.h \
    stusql.h \
    stutmp.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    19DE - 副本.txt \
    19DE .txt \
    19DE .txt \
    19DE1 .txt \
    19DE1 .txt \
    19DE1 .txt \
    19DE1 .txt \
    19DE1 .txt \
    19DE1 .txt \
    19DE1 .txt \
    19DE1 .txt \
    19DE1 .txt \
    rank0.txt \
    readme.txt \
    stu.txt
