#include <QCoreApplication>
#include <QtDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlResult>
#include <QSqlRecord>
#include <QSqlField>
#include <QVariant>
#include <bdclass.h>

int main()
{
    QString HN = "192.168.111.12";
    QString DBN = "DBCONTROL";
    QString UN = "postgres";
    QString P = "Tran5ma5t3r";

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(HN);
    db.setDatabaseName(DBN);
    db.setUserName(UN);
    db.setPassword(P);

    if (!db.open())
    {
        qDebug() << QObject::trUtf8("БД не найдена") << db.lastError().text();
        return -1;
    }
    qDebug() << QObject::trUtf8("БД подключена") << db.lastError().text();

    QSqlQuery query;
    query.prepare("SELECT * FROM \"Station\";");
    if(!(query.exec() && query.next()))
    {
        qDebug() << QObject::trUtf8("Error BD query") << db.lastError().text();
    }

    query.seek(0);
        qDebug() << query.value("lat").toString() << endl;


    query.prepare("UPDATE \"Station\" SET caption = 'Хабаровск' WHERE id = '3';");
    query.exec();

//    query.prepare("INSERT INTO \"Station\" VALUES('5','shch','Щелково','54,56564565','110,3423434534','227,453','-3456234,23453456546','3463456,23453434','4536754,345345');");
//    query.exec();

    return 0;
}
