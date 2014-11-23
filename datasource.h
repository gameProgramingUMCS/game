#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QString>

//Typ zrodla danych
enum TypeOfDataSource{
    File,
    Database,
};

//Zrodlo danych zapewnia podstawowe funkcjonalnosci
class DataSource{

public:
    DataSource(TypeOfDataSource type);
    TypeOfDataSource getTypeOfData();

protected:

    TypeOfDataSource getTypeOfData() const;
    QString getPath() const;

private:
    TypeOfDataSource typeOfData;
    QString path;

};

#endif // DATASOURCE_H
