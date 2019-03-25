#ifndef TABLEDATA_H
#define TABLEDATA_H

#include "excel.h"

#include <QStandardItemModel>

class TableData : public Excel
{
public:
    TableData();
    ~TableData() override;
    void parseDocument(const QString &fileName) override;
    QStandardItemModel *getItemModel() override;
    void saveAs(const QString &fileName) override;
};

#endif // TABLEDATA_H
