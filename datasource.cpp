#include "datasource.h"
#include "singletonsprovider.h"
#include <QDir>

DataSource::DataSource(TypeOfDataSource type){
    this->typeOfData = type;
    path = QDir::root().path();

    if(type == File){
        path.append(QDir::separator()).append("FilesTank2");
        QDir tmpDir = QDir(path);

        if(!tmpDir.exists()){   //Jesli katalog nie istnieje
            tmpDir.mkpath(".");
        }

    }else if(type == Database){
        path.append(QDir::separator()).append("DatabaseTank2");
        QDir tmpDir = QDir(path);

        if(!tmpDir.exists()){   //Jesli katalog nie istnieje
            tmpDir.mkpath(".");
        }

    }
}

TypeOfDataSource DataSource::getTypeOfData(){
    return this->typeOfData;
}

AppInformation &DataSource::getAppInformation(){
    return SingletonsProvider::getInstance().getInstanceOfAppInformation();
}

TypeOfDataSource DataSource::getTypeOfData() const{
    return typeOfData;
}

QString DataSource::getPath() const{
    return path;
}
