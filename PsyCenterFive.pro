QT += quick quickcontrols2 sql

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        WindowAdm/admproperty.cpp \
        engine.cpp \
        main.cpp \
        models/modelclient.cpp \
        models/modelplace.cpp \
        models/modelspecialist.cpp \
        models/modeltasks.cpp \
        objects/cellclass.cpp \
        objects/note.cpp \
        objects/place.cpp \
        objects/qualification.cpp \
        objects/recommendation.cpp \
        objects/request.cpp \
        persons/administrator.cpp \
        persons/client.cpp \
        persons/specialist.cpp \
        settings/settings.cpp \
        translator.cpp

RESOURCES += \
    res/resources.qrc

TRANSLATIONS += \
    PsyCenterFive_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    WindowAdm/admproperty.h \
    engine.h \
    models/modelclient.h \
    models/modelplace.h \
    models/modelspecialist.h \
    models/modeltasks.h \
    objects/cellclass.h \
    objects/note.h \
    objects/place.h \
    objects/qualification.h \
    objects/recommendation.h \
    objects/request.h \
    persons/administrator.h \
    persons/client.h \
    persons/specialist.h \
    settings/settings.h \
    translator.h
