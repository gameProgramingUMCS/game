#include "filedatasource.h"

FileDataSource::FileDataSource(TypeOfDataSource type):DataSource(type){

}

FileDataSource::~FileDataSource()
{

}

FileDataSource& FileDataSource::getInstance(){              //Zwraca sinegleton
    static FileDataSource instance(File);
    return instance;
}
