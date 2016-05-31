/*
 * bdlass.h
 *
 *  Created on: 29.02.2016
 *      Author: andrey
 */

#ifndef BDCLASS
#define BDCLASS

class BD {                                         //Объявление класса BD
    QString HostName,                              //IP адрес БД
            DatabaseName,                          //Имя БД
            UserName,                              //Имя пользователя
            Password;                              //Пароль
public:
    QSqlDatabase db;
    QSqlQuery query;

    BD(QString HN, QString DBN, QString UN, QString P) //Конструктор класса
    {
          setParam(HN, DBN, UN, P);
          db = QSqlDatabase::addDatabase("QPSQL");
    }
void setParam(QString HN, QString DBN, QString UN, QString P)  //Установка параметров
    {
        HostName = HN;
        DatabaseName = DBN;
        UserName = UN;
        Password = P;
        HN = db.setHostName;
        DBN = db.setDatabaseName;
        UN = db.setUserName;
        P = db.setPassword;
    }

bool connect()
    {
        return db.open();
        qDebug() << db.lastError().text();
    }

//QString GetValString(QString sql_query, int row, int col)
//{
//    query.exec(sql_query);
//    QString result = "";
//    if(query.seek(row))
//    {
//        result = query.value(col).toString();
//    }
//    else {
//        return result;
//    }

//    return result;
//}

};                                                  //Конец объявления класс BD


#endif // BDCLASS

