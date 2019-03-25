#include "tabledata.h"
#include "xlsxdocument.h"

TableData::TableData()
{
    tableModel = new QStandardItemModel();
}

TableData::~TableData()
{
    delete tableModel;
}

void TableData::parseDocument(const QString &fileName)
{
    // kosongkan data
    tableModel->clear();

    QXlsx::Document document(fileName);
    int columnCount = document.dimension().columnCount();

    for (int i = 1; i <= document.dimension().rowCount(); ++i) {
            if (i == 1) {
                // make table header
                for (int j = 1; j <= columnCount; ++j) {
                    tableModel->setHorizontalHeaderItem(j - 1, new QStandardItem(document.read(i, j).toString()));
                }
            } else {
                QList<QStandardItem *> rowData;
                for (int j = 1; j <= columnCount; ++j) {
                    rowData << new QStandardItem(document.read(i, j).toString());
                }
                tableModel->appendRow(rowData);
            }
        }
}

QStandardItemModel *TableData::getItemModel()
{
    return tableModel;
}

void TableData::saveAs(const QString &fileName)
{
    QXlsx::Document document;

    for (int i = 1; i <= tableModel->rowCount(); ++i) {
        for (int j = 1; j <= tableModel->columnCount(); ++j) {
            document.write(i, j, tableModel->index(i - 1, j - 1).data());
        }
    }
    document.saveAs(fileName);
}
