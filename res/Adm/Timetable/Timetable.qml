import QtQuick 2.0
import QtQuick.Layouts 1.15
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.15
import Objects 1.0
import "qrc:/QML/Adm/Timetable/timetableItem_func.js" as Func_items

import "qrc:/QML/Adm/Timetable" as Timetable
import "qrc:/QML/Adm/Timetable/DiaChangeItem" as DiaChange

GridLayout {
    property alias _gridInvisible: _gridInvisible
    property var modelPlace: admProperty.getModelPlace()
    id: _parent
    rows: 2
    columns: 2
    columnSpacing: 0
    rowSpacing: 0
    ListView {
        id: _headerCabinet
        interactive: false
        Layout.row: 0
        Layout.column: 1
        Layout.columnSpan: 1
        Layout.rowSpan: 1
        Layout.fillWidth: true
        height: 40
        orientation: Qt.Horizontal
        model: modelPlace
        delegate:
            Rectangle {
            id: _itemHeaderCabinet
            width: _headerCabinet.width / modelPlace.rowCount()
            height: _headerCabinet.height
            Text {
                anchors.fill: parent
                text: name
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
    ListView {
        id: _headerTime
        interactive: false
        Layout.row: 1
        Layout.column: 0
        Layout.columnSpan: 1
        Layout.rowSpan: 1
        width: 100
        Layout.fillHeight: true
        model: settings.countHours()
        delegate: Rectangle {
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
                id: _hdText
                anchors.fill: parent
                font.pixelSize: 20
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                text: settings.getListTime()[index * settings.countCellPerHour()].toLocaleTimeString("hh:mm")
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
        columns: modelPlace.rowCount()
        rows: settings.countHours()
        Repeater {
            model: modelPlace.rowCount() * settings.countHours()
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
    MouseArea {
        id: _mAreaGridInvzible
        property var rememberColor: []
        Layout.row: 1
        Layout.column: 1
        Layout.columnSpan: 1
        Layout.rowSpan: 1
        Layout.fillWidth: true
        Layout.fillHeight: true
        acceptedButtons: Qt.RightButton
        hoverEnabled : true
        onClicked: _contextMenu.popup()

        GridLayout {
            id : _gridInvisible
            anchors.fill: parent
            flow : GridLayout.TopToBottom
            columnSpacing: 0
            rowSpacing: 0
            columns: modelPlace.rowCount()
            rows: settings.countSegments()
            Repeater {
                model: modelPlace.rowCount() * settings.countSegments()
                delegate:
                    DropArea {
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }
            }
        }
        Menu {
            id: _contextMenu
            width: 100
            MenuItem {
                text: qsTr("Добавить запись")
                onClicked:
                {
                    var x = _mAreaGridInvzible.mouseX
                    var y = _mAreaGridInvzible.mouseY
                    _diaChangeItem.mX = x
                    _diaChangeItem.mY = y
                    _diaChangeItem._cbHours.currentIndex = _headerTime.indexAt(0, y)
                    _diaChangeItem._cbEndHours.currentIndex = _headerTime.indexAt(0, y) + 1
                    _diaChangeItem._cbPlace.currentIndex =  _headerCabinet.indexAt(x, 0)

                    _diaChangeItem.open()

                }
            }
        }
        DiaChange.Dia {
            id: _diaChangeItem
            property int mX: 0
            property int mY: 0
            property var cell: CellClass{};
            x: mX > _mAreaGridInvzible.x + _mAreaGridInvzible.width - width ? mX - width : mX
            y: mY > _mAreaGridInvzible.y + _mAreaGridInvzible.height - height ? mY - height : mY
            onAccepted: {
                cell.id = 1;
                cell.recordCell();
            }
            onRejected: {exit}
        }
    }
}














































