function createItems()
{
        listVCellClass.forEach(function(cellClass, i, arr)
    {

        var item = Qt.createComponent("qrc:/QML/administration/timetableGrid_Item.qml")
        item.createObject(_gridInvisible,
        {
            'typeName': "_itemClass",
            'idClass': cellClass.id,
            'time': cellClass.timeStart,
            'cabinet': cellClass.cabinet,
            'specialist': cellClass.specialist,
            'listClient': cellClass.listVClient,
            'Layout.row': ( cellClass.timeStart - settings.getStartCenter() ) / ( 60000 * 60 / settings.countCellPerHour() ),
            'Layout.column': findIndexCabinet(cellClass),
            'Layout.rowSpan': settings.countCellPerHour() * cellClass.duration / 60 ,
            'Layout.fillHeight': true,
            'Layout.fillWidth': true,

        })
    })
}

function findIndexCabinet(cellClass)
{
    for (var indexCabinet = 0; indexCabinet < qMCabinet.rowCount(); indexCabinet++)
    {
        if (qMCabinet.data(qMCabinet.index(indexCabinet, 0))  === cellClass.cabinet.id)
        {
            return indexCabinet
        }
    }
}









