#include "basicinterface.h"

DataSource& Storable::getDataSource(TypeOfDataSource type){

    if(type == Database){
        return SingletonsProvider::getInstance().getInstanceOfDatabaseDataSource();
    }else if(type == File){
        return SingletonsProvider::getInstance().getInstanceOfFileDataSource();
    }
}
