function createItems()
{
    admProperty.getListVCellClass().forEach(function(cellClass, i, arr)
    {

        var item = Qt.createComponent("qrc:/QML/Adm/Timetable/TimetableGrid_Item.qml")
        item.createObject(_gridInvisible,
        {
            'typeName': "_itemClass",
            'idClass': cellClass.id,
            'time': cellClass.timeStart,
            'place': cellClass.place,
            'specialist': cellClass.specialist,
            'listClient': cellClass.listVClient,
            'Layout.row': ( cellClass.timeStart - settings.getStartCenter() ) / ( 60000 * 60 / settings.countCellPerHour() ),
            'Layout.column': findIndexPlace(cellClass),
            'Layout.rowSpan': settings.countCellPerHour() * cellClass.duration / 60 ,
            'Layout.fillHeight': true,
            'Layout.fillWidth': true
        })
    })
}

function findIndexPlace(cellClass)
{
    for (var indexPlace = 0; indexPlace < qMPlace.rowCount(); indexCabinet++)
    {
        if (qMPlace.data(qMPlace.index(indexPlace, 0))  === cellClass.place.id)
        {
            return indexPlace
        }
    }
}









