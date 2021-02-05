#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include "albumdao.h"

class QSqlDatabase;

const QString DATABASE_FILENAME = "gallery.db";

class DatabaseManager
{
private:
    QSqlDatabase *mDatabase;

public:
    static DatabaseManager& instance();
    ~DatabaseManager();

    const AlbumDao albumDao;

protected:
    DatabaseManager(const QString &path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);
};

#endif // DATABASEMANAGER_H
