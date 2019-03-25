#include "main.h"
#include "tabledata.h"

Excel *CreateObjectInstance()
{
    return new TableData();
}

void deleteObject(Excel *math)
{
    delete math;
}
