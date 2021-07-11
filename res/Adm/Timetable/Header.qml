import QtQuick 2.0
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Rectangle {
    id: _parent
    RowLayout {
        anchors.fill: parent
        spacing: 6
        RowLayout {
            id: _title
            implicitHeight: 35
            spacing: 0
            Rectangle {
                width: 35
                Image {
                    width: 25
                    height: 25
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    source: "qrc:/Image/icons/menu.png"
                }
            }

            Text {
                text: qsTr("Расписание")
                font.pixelSize: 20
            }
        }
        ComboBox {
            id: _selectSp
            width: 100
            implicitHeight: 35
            model: ["Общее", "Попкова С.Е."]

        }
        TextField {
            id: _search
            implicitHeight: 35
            Layout.fillWidth: true
            Layout.rightMargin: 6
        }
    }
}

