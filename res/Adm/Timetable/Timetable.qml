import QtQuick 2.0
import QtQuick.Layouts 1.15
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.15

import "qrc:/QML/Adm/Timetable/timetableItem_func.js" as Func_items

import "qrc:/QML/Adm/Timetable" as Timetable
import "qrc:/QML/Adm/Timetable/DiaChangeItem" as DiaChange


GridLayout {
    id: _parent
    rows: 2
    columns: 2
    columnSpacing: 0
    rowSpacing: 0
    ListView {
        z: 2
        id: _headerCabinet
        interactive: false
        Layout.row: 0
        Layout.column: 1
        Layout.columnSpan: 1
        Layout.rowSpan: 1
        Layout.fillWidth: true
        height: 40
        orientation: Qt.Horizontal
        model: qMPlace.rowCount()
        delegate:
            Rectangle {
            id: _itemHeaderCabinet
            width: _headerCabinet.width / qMPlace.rowCount()
            height: _headerCabinet.height
            Text {
                anchors.fill: parent
                text: qMPlace.data(qMPlace.index(index, 1))
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

        }

    }
    ListView {
        z: 2
        id: _headerTime
        interactive: false
        Layout.row: 1
        Layout.column: 0
        Layout.columnSpan: 1
        Layout.rowSpan: 1
        width: 100
        Layout.fillHeight: true
        model: settings.countHours()
        delegate:
            Rectangle {
            width: _headerTime.width
            height: _headerTime.height / settings.countCellPerHour()
                Rectangle {
                    visible: index + 1  === settings.countHours() ? false : true
                    height: 1
                    color:  'black'
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                }
                Text {
                    anchors.fill: parent
                    font.pixelSize: 20
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                    text:  settings.getListTime()[index * settings.countCellPerHour()].toLocaleTimeString("hh:mm")
                }
        }
    }
    GridLayout {
        id : _gridVisible

        Layout.row: 1
        Layout.column: 1
        Layout.columnSpan: 1
        Layout.rowSpan: 1
        Layout.fillWidth: true
        Layout.fillHeight: true
        flow : GridLayout.TopToBottom
        columnSpacing: 0
        rowSpacing: 0
        columns: qMPlace.rowCount()
        rows: settings.countHours()
        Repeater {
            model: qMPlace.rowCount() * settings.countHours()
            delegate:
                Rectangle {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color:Math.floor(index / settings.countHours())  % 2 ? "white" : "silver"
                    Rectangle {
                        visible: (index + 1) % settings.countHours()  ===  0 ? false : true
                        height: 1
                        color: "black"
                        anchors.bottom: parent.bottom
                        anchors.left: parent.left
                        anchors.right: parent.right
                    }
            }

        }
    }
    GridLayout {
        id : _gridInvisible
        Layout.row: 1
        Layout.column: 1
        Layout.columnSpan: 1
        Layout.rowSpan: 1
        Layout.fillWidth: true
        Layout.fillHeight: true
        flow : GridLayout.TopToBottom
        columnSpacing: 0
        rowSpacing: 0
        columns: qMPlace.rowCount()
        rows: settings.countSegments()
        z: 2
        Repeater {
            model: qMPlace.rowCount() * settings.countSegments()
            delegate:
                DropArea {
                    objectName: index
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    MouseArea {
                        anchors.fill: parent
                        Menu {
                            id: _contextMenu
                            width: 100
                            MenuItem { text: qsTr("Добавить запись") }
                                 // BUG: !!! убрать огромное количество menu
                        }
                        DiaChange.Dia { // BUG: !!! убрать огромное количество диалогов
                            id: _diaChangeItem
                        }
                        acceptedButtons: Qt.LeftButton | Qt.RightButton
                        hoverEnabled : true
                        onClicked: (mouse) => mouse.button & Qt.RightButton ? _contextMenu.popup() : null
                        onDoubleClicked:  _diaChangeItem.open()
                    }
                }
        }
        Component.onCompleted: {
            Func_items.createItems()
        }
    }

    function reloadItems(date)
    {

        for (var i in _gridInvisible.data){
            if(_gridInvisible.data[i].typeName === '_itemClass')
            {
                _gridInvisible.data[i].destroy()
            }
        }
        Func_items.createItems()
    }
}






