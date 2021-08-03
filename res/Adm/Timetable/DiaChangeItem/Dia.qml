import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Dialog {
    property var modelPlace: admProperty.getModelPlace()
    property alias _cbHours: _cbHours
    property alias _cbEndHours: _cbEndHours
    property alias _cbMinuts: _cbMinuts
    property alias _cbEndMinuts: _cbEndMinuts
    property alias _cbPlace: _cbPlace
    title: qsTr("Назначте занятие")
    width: 500
    height: 400
    standardButtons:  Dialog.Ok | Dialog.Cancel
    onRejected: { exit }
    contentItem: RowLayout {
        ColumnLayout
        {
            id: _settingsItem
            Text {text: admProperty.getStrDate()}

            RowLayout {
                Text {
                    text: qsTr("Специалист:")
                }
                ComboBox {
                    id: _CbSpec
                    model: admProperty.getModelSpecialist()
                    textRole: "name"
                }
            }
            RowLayout {
                Text {
                    text: qsTr("Начало:")
                }
                ComboBox {
                    id: _cbHours
                    model: settings.getListHours()
                    implicitWidth: 80
                    popup: Popup {
                        y: _cbHours.height
                        width: _cbHours.width
                        height: 200
                        contentItem: ListView {
                            clip: true
                            model: _cbHours.delegateModel
                            ScrollIndicator.vertical: ScrollIndicator { }
                        }
                    }
                }
                ComboBox {
                    id: _cbMinuts
                    model: settings.getListMinuts()
                    currentIndex: 0
                    implicitWidth: 80
                    popup: Popup {
                        y: _cbMinuts.height
                        width: _cbMinuts.width
                        height: 200
                        contentItem: ListView {
                            clip: true
                            model: _cbMinuts.delegateModel
                            ScrollIndicator.vertical: ScrollIndicator { }
                        }
                    }
                }
            }
            RowLayout {
                Text {
                    text: qsTr("Конец:  ")
                }
                ComboBox {
                    id: _cbEndHours
                    model: settings.getListHours()
                    implicitWidth: 80
                    popup: Popup {
                        y: _cbEndHours.height
                        width: _cbEndHours.width
                        height: 200
                        contentItem: ListView {
                            clip: true
                            model: _cbEndHours.delegateModel
                            ScrollIndicator.vertical: ScrollIndicator { }
                        }
                    }
                }
                ComboBox {
                    id: _cbEndMinuts
                    model: settings.getListMinuts()
                    implicitWidth: 80
                    popup: Popup {
                        y: _cbEndMinuts.height
                        width: _cbEndMinuts.width
                        height: 200
                        contentItem: ListView {
                            clip: true
                            model: _cbEndMinuts.delegateModel
                            ScrollIndicator.vertical: ScrollIndicator { }
                        }
                    }
                }
            }
            RowLayout
            {
                Text {text: qsTr("Место\nпроведения:")}
                ComboBox {
                    id:_cbPlace
                    model: modelPlace
                    textRole: "name"
                }
            }

        }
        ColumnLayout
        {
            id: _selectType
            TabBar
            {
                id: _bar
                TabButton
                {
                    text: qsTr("Первичное\nзанятие")
                }

                TabButton
                {
                    text: qsTr("Занятие")
                }
            }
            StackLayout
            {
                currentIndex: _bar.currentIndex
                Item
                {
                    id: _tabPrimary

                }
                Item
                {
                    id: _tabActive
                }
            }
        }
    }
}

