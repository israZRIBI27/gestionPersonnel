QT       += core gui
QT += core gui sql
QT       += printsupport
QT       += core gui network
QT       += core gui sql axcontainer printsupport
QT       += core gui sql serialport
QT += printsupport
QT += core gui network
QT += core gui sql axcontainer printsupport
QT       += core gui multimedia multimediawidgets
QT       += sql
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    camera.cpp \
    connection.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    passwordforgot.cpp \
    personnel.cpp \
    register.cpp

HEADERS += \
    camera.h \
    connection.h \
    login.h \
    mainwindow.h \
    passwordforgot.h \
    personnel.h \
    register.h

FORMS += \
    camera.ui \
    login.ui \
    mainwindow.ui \
    passwordforgot.ui \
    recuperMDP.ui \
    recupereMDP.ui \
    register.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
QT += charts

RESOURCES += \
    image.qrc

DISTFILES += \
    Images/Backgroud1.png \
    Images/Backgroud2.png \
    Images/Beneficiaires.png \
    Images/Capture.PNG \
    Images/aide.png \
    Images/charts.png \
    Images/dash.png \
    Images/dashboard.gif \
    Images/emp.png \
    Images/events.png \
    Images/favicon.ico \
    Images/form.gif \
    Images/icon.png \
    Images/icons/rechercher.png \
    Images/icons8-combo-chart.gif \
    Images/list.gif \
    Images/loginpage.png \
    Images/logo.png \
    Images/profile.gif \
    Images/resetpwd.gif \
    Images/rest.png \
    Images/rsz_charts.png \
    icons/122855 (3).png \
    icons/122855 (3).png \
    icons/122855.png \
    icons/2.PNG \
    icons/Capture.PNG \
    icons/close.png \
    icons/icons8-fermer-la-fenêtre-50.png \
    icons/lock_32x32.png \
    icons/mail_32x32.png \
    icons/personel.PNG \
    icons/rocket_48x48.png \
    icons/user_32x32.png
