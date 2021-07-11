import QtQuick 2.0
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "qrc:/QML/Adm/Timetable" as Timetable

Window {
    id: _parent
    width: 800
    height: 600
    GridLayout {
        anchors.fill: parent
        rows: 2
        columns: 2
        rowSpacing: 0
        columnSpacing: 0
        Timetable.Header {
            id: _header
            height: 47
            Layout.fillWidth: true
            Layout.row: 0
            Layout.column: 0
            Layout.columnSpan: 1
            Layout.rowSpan: 1
        }
        Timetable.Timetable {
            id: _timetable
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.row: 1
            Layout.column: 0
            Layout.columnSpan: 1
            Layout.rowSpan: 1
        }
        Timetable.Sidebar {
            id: _sidebar
            width: 250
            Layout.fillHeight: true
            Layout.row: 0
            Layout.column: 1
            Layout.columnSpan: 1
            Layout.rowSpan: 2
        }
    }
}
