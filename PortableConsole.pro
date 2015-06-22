#-------------------------------------------------
# File: PortableConsole.pro
# Created on: 2015-06-22
# Copyright (C) 2015 DCS Computing GmbH
#-------------------------------------------------
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PortableConsole

TEMPLATE = app

INCLUDEPATH += View\
		Utils\
		Model\
		Controller

SOURCES += main.cpp

include(View/View.pri)
include(Utils/Utils.pri)
include(Model/Model.pri)
include(Controller/Controller.pri)




