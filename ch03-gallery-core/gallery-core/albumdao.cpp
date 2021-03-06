#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QStringList>
#include "albumdao.h"
#include "album.h"
#include "databasemanager.h"

AlbumDao::AlbumDao(QSqlDatabase &database) :
    mDatabase(database)
{

}

void AlbumDao::init() const
{
    if (!mDatabase.tables().contains("albums")) {
        QSqlQuery query(mDatabase);
        bool success = query.exec("CREATE TABLE albums (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
        Q_ASSERT(success);
        // TODO: check QSqlQuery::lastError()
    }
}

void AlbumDao::addAlbum(Album &album) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO albums (name) VALUES (:name)");
    query.bindValue(":name", album.name());
    query.exec();
    album.setId(query.lastInsertId().toInt());

}

