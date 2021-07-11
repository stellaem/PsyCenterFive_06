import QtQuick 2.0
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Rectangle {
    Layout.fillWidth: true
    Layout.fillHeight: true
    ColumnLayout {
        anchors.fill: parent
        spacing: 6
        Rectangle{
            id: _taskHeader
            Layout.fillWidth: true
            implicitHeight: 35

            Text {
                anchors.fill: _taskHeader
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: qsTr("Задания на день")
            }
        }

        ListView {
            id: _listViewTask
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.bottomMargin: 6
            Layout.leftMargin: 6
            snapMode: ListView.SnapToItem
            clip: true

            spacing: 2
            model: 5
            ScrollBar.vertical:  ScrollBar {
                hoverEnabled: true
                active: hovered || pressed
                orientation: Qt.Vertical
                anchors.top: parent.top
                anchors.right: parent.right
                anchors.bottom: parent.bottom
            }
            delegate:
                Rectangle {
                    width: _listViewTask.width - 5
                    height: _textTask.height
                    color: _mouseArea.containsMouse ? "lightgrey" : "white"
                    clip: true
                    Row {
                        Rectangle {
                            height: 8
                            width: 8
                            color: "black"

                        }
                        Text {
                            id: _textTask
                            text: "Господа, реализация намеченных плановых заданий представляет собой интересный эксперимент проверки своевременного выполнения сверхзадачи."
                            width: _listViewTask.width - 25
                            font.pixelSize: 12
                            wrapMode: Text.WordWrap
                        }
                    }
                    MouseArea {
                        id: _mouseArea
                        anchors.fill: parent
                        hoverEnabled: true
                    }
                }
        }
    }
}
