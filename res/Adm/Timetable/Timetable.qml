import QtQuick 2.0
import QtQuick.Layouts 1.15
import "qrc:/QML/Adm/Timetable/timetableItem_func.js" as Func_items

GridLayout {
    id: _parent
    rows: 2
    columns: 2
    columnSpacing: 0
    rowSpacing: 0
    ListView {
        id: _headerCabinet
        Layout.row: 0
        Layout.column: 1
        Layout.columnSpan: 1
        Layout.rowSpan: 1
        Layout.fillWidth: true
        height: 40
        orientation: Qt.Horizontal
        model: qMCabinet.rowCount()
        delegate:
            Rectangle {
            id: _itemHeaderCabinet
            width: _headerCabinet.width / qMCabinet.rowCount()
            height: _headerCabinet.height
            Text {
                anchors.fill: parent
                text: qMCabinet.data(qMCabinet.index(index, 1))
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

        }

    }
    ListView {
        id: _headerTime
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
        columns: qMCabinet.rowCount()
        rows: settings.countHours()
        Repeater {
            model: qMCabinet.rowCount() * settings.countHours()
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
        anchors.fill: _gridVisible
        flow : GridLayout.TopToBottom
        columnSpacing: 0
        rowSpacing: 0
        columns: qMCabinet.rowCount()
        rows: settings.countSegments()
        Repeater {
            model: qMCabinet.rowCount() * settings.countSegments()
            delegate:
                DropArea {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Rectangle {
                        anchors.fill: parent
                        opacity: 0
                    }
                }
        }
        Component.onCompleted: {
            Func_items.createItems()
        }
    }

    function reloadItems()
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



