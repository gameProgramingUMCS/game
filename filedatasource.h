#ifndef FILEDATASOURCE_H
#define FILEDATASOURCE_H

#include "datasource.h"

//Klasa plikowego zrodla danych zwraca singelton
class FileDataSource: public DataSource{

public:
    static FileDataSource& getInstance();       //Zwraca sinegleton

private:
    FileDataSource(TypeOfDataSource type);
    virtual ~FileDataSource();
};

#endif // FILEDATASOURCE_H
