import QtQuick 2.0
import QtQuick.Layouts 1.15

import QtQuick.Controls 1.4
import QtQuick.Controls 2.15

import "qrc:/QML/_widgets/" as Widgets

Rectangle {
    ColumnLayout {
        anchors.fill: parent
        spacing: 6

        ComboBox {
            Layout.topMargin: 6
            id: _selectPeriod
            implicitHeight: 35
            Layout.fillWidth: true
            model: ["День", "Неделя", "Месяц"]
        }



        Calendar {
            id: _calendar
        }
        Widgets.Tasks {
            id: _task

        }

    }
}
