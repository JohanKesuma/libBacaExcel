#ifndef MAIN_H
#define MAIN_H

#include "libbacaexcel_global.h"
#include "excel.h"

// create object instance
extern "C" LIBBACAEXCELSHARED_EXPORT Excel *CreateObjectInstance();

// delete object
extern "C" LIBBACAEXCELSHARED_EXPORT void deleteObject(Excel *tableData);

#endif // MAIN_H
