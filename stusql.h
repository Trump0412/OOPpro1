#ifndef STUSQL_H
#define STUSQL_H

#include <QObject>
#include<qsqldatabase.h>
#include<QVector>

class stusql :public QObject
{
    Q_OBJECT
public:
    stusql();


};



class stu
{
public:
    QString s_id;
    QString s_name;
    QString s_class;

    QString course1;
    QString course2;
    QString course3;
    QString course4;
    QString course5;
    QString course6;
    QString course7;

    double s_course1;
    double s_course2;
    double s_course3;
    double s_course4;

    double s_course5;
    double s_course6;
    double s_course7;

    QString test0;
    double test;
    double final;

public:
    double getcourse1();
    double getcourse2();
    double getcourse3();
    double getcourse4();
    double getcourse5();
    double getcourse6();
    double getcourse7();
    double gettest();
    double getfinal();


    stu();
    stu(const stu&c);
    stu(QString id, QString name, QString c1, QString c2, QString c3, QString c4, QString c5, QString c6, QString c7, QString t);








};
bool operator>(const stu&a,const stu&b);

#endif // STUSQL_H
