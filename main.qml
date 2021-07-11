import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

import "qrc:/" as Main

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")



    Component.onCompleted: {
        Main.DiaPrgSelect {    }

    }

}


