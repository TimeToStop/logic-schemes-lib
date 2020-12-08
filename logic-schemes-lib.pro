TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        src/components/data.cpp \
        src/components/datain.cpp \
        src/components/dataout.cpp \
        src/components/signal.cpp \
        src/elements/and.cpp \
        src/elements/andnot.cpp \
        src/elements/buffer.cpp \
        src/elements/element.cpp \
        src/elements/logicelement.cpp \
        src/elements/monophaseelement.cpp \
        src/elements/multiphaseelement.cpp \
        src/elements/not.cpp \
        src/elements/or.cpp \
        src/elements/ornot.cpp \
        src/schemes/connectionmanager.cpp \
        src/schemes/elementcontainter.cpp \
        src/schemes/lifespan.cpp \
        src/schemes/schema.cpp \
        src/userinput/printer.cpp \
        src/userinput/userinput.cpp

HEADERS += \
    single_include.hpp \
    src/components/data.h \
    src/components/datain.h \
    src/components/dataout.h \
    src/components/signal.h \
    src/elements/and.h \
    src/elements/andnot.h \
    src/elements/buffer.h \
    src/elements/element.h \
    src/elements/logicelement.h \
    src/elements/monophaseelement.h \
    src/elements/multiphaseelement.h \
    src/elements/not.h \
    src/elements/or.h \
    src/elements/ornot.h \
    src/schemes/connectionmanager.h \
    src/schemes/elementcontainter.h \
    src/schemes/lifespan.h \
    src/schemes/schema.h \
    src/userinput/printer.h \
    src/userinput/userinput.h

DISTFILES += \
    .gitignore \
    readme.md
