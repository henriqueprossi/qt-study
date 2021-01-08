#include <QSqlDatabase>
#include <QSqlQuery>
#include "albumdao.h"
#include "databasemanager.h"

AlbumDao::AlbumDao(QSqlDatabase &database) :
    mDatabase(database)
{

}

void AlbumDao::init() const
{
    if (!mDatabase.tables().contains("albums")) {

    }
}

