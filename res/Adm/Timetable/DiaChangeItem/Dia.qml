import QtQuick 2.15
import QtQuick.Layouts 1.15



import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3



Dialog {

    title: qsTr("Назначте занятие")

    standardButtons:  Dialog.Ok | Dialog.Cancel
    onRejected: { exit }
    ColumnLayout {
        anchors.fill: parent
        TabBar {
            id: _bar
            TabButton {
                text: qsTr("Группа")
            }
            TabButton {
                text: qsTr("Первичное \nзанятие")
            }
            TabButton {
                text: qsTr("Занятие")
            }
        }
        StackLayout {
        currentIndex: _bar.currentIndex
            RowLayout {
                id: _tabGroup
                Text {
                    text: admProperty.getStrDate()
                }
                RowLayout {
                    Text {
                        text: qsTr("Время:  ")
                    }
                    ComboBox {
                        model: settings.getListHours()
                    }
                    ComboBox {

                    }

                }


            }
            Item {
                id: _tabPrimary
                Text {
                    text: admProperty.getStrDate()
                }
            }
            Item {
                id: _tabActive
                Text {
                    text: admProperty.getStrDate()
                }
            }
        }

    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
