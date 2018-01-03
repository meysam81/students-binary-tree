QT += core
QT -= gui

TARGET = students-binary-tree
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    student.cpp \
    binarytree.cpp

HEADERS += \
    student.h \
    binarytree.h

