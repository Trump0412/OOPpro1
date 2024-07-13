#include "sqlquerymodel.h"
#include<QSqlQuery>
#include<QSqlError>
#include<QtDebug>



sqlqueryModel::sqlqueryModel(QObject *parent)
    : QSqlQueryModel{parent}
{}

bool sqlqueryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
//1.判断是否为有效列
    if(index.column()<0||index.column()>10)

    return false;
    //获取id
    QModelIndex primaryindex =QSqlQueryModel::index(index.row(),0);
    QString id=this->data(primaryindex).toString();//获得字段表中的id
   //修改行时将数据清楚
    this->clear();
    bool ok=1;
//根据需求修改列

    if(index.column()==1)
    {
       ok= setName(id,value.toString());

    }
    if(index.column()==2)
    {
        ok=setCourse1(id,value.toString());
    }
    if(index.column()==3)
    {
       ok=setCourse2(id,value.toString());
    }
    if(index.column()==4)
    {
        ok=setCourse3(id,value.toString());
    }
    if(index.column()==5)
    {
        ok=setCourse4(id,value.toString());
    }
    if(index.column()==6)
    {
        ok=setCourse5(id,value.toString());
    }
    if(index.column()==7)
    {
        ok=setCourse6(id,value.toString());
    }
    if(index.column()==8)
    {
        ok=setCourse7(id,value.toString());
    }
    if(index.column()==9)
    {
        ok=settest(id,value.toString());
    }






    //刷新
    refresh();

    return ok;

}

Qt::ItemFlags sqlqueryModel::flags(const QModelIndex &index) const
{
//1.获取单元格当前的编辑状态
    Qt::ItemFlags flag= QSqlQueryModel::flags(index);
//2.给现在有的标志加一个可编辑的标志
flag =flag|Qt::ItemIsEditable  ;
    return flag;
}

void sqlqueryModel::refresh()
{
    //将数据库的数据查询出来转换为model
    this->setQuery("select * from stu");
    this->setHeaderData(0,Qt::Horizontal,"ID");
    this->setHeaderData(1,Qt::Horizontal,"Name");
    this->setHeaderData(2,Qt::Horizontal,"数理逻辑");
    this->setHeaderData(3,Qt::Horizontal,"集合论");
    this->setHeaderData(4,Qt::Horizontal,"抽象代数");
    this->setHeaderData(5,Qt::Horizontal,"图论");
    this->setHeaderData(6,Qt::Horizontal,"平时综合");
    this->setHeaderData(7,Qt::Horizontal,"期中测试");
    this->setHeaderData(8,Qt::Horizontal,"小论文");
    this->setHeaderData(9,Qt::Horizontal,"期末成绩");
     this->setHeaderData(10,Qt::Horizontal,"总分");

}

bool sqlqueryModel::setName(QString uesid, const QString &nname)
{
//相当于刷新的操作
    QSqlQuery query;

    query.prepare("update stu set name=? where id=?");

    query.addBindValue(nname);
    query.addBindValue(uesid);

    return query.exec();
}

bool sqlqueryModel::setCourse1(QString uesid, const QString &course1)
{
    QSqlQuery query;

    query.prepare("update stu set course1=? where id=?");

    query.addBindValue(course1);
    query.addBindValue(uesid);

    return query.exec();
}

bool sqlqueryModel::setCourse2(QString uesid, const QString &course1)
{
    QSqlQuery query;

    query.prepare("update stu set course2=? where id=?");

    query.addBindValue(course1);
    query.addBindValue(uesid);

    return query.exec();
}

bool sqlqueryModel::setCourse3(QString uesid, const QString &course1)
{
    QSqlQuery query;

    query.prepare("update stu set course3=? where id=?");

    query.addBindValue(course1);
    query.addBindValue(uesid);

    return query.exec();
}

bool sqlqueryModel::setCourse4(QString uesid, const QString &course1)
{
    QSqlQuery query;

    query.prepare("update stu set course4=? where id=?");

    query.addBindValue(course1);
    query.addBindValue(uesid);

    return query.exec();
}

bool sqlqueryModel::setCourse5(QString uesid, const QString &course1)
{
    QSqlQuery query;

    query.prepare("update stu set course5=? where id=?");

    query.addBindValue(course1);
    query.addBindValue(uesid);

    return query.exec();
}

bool sqlqueryModel::setCourse6(QString uesid, const QString &course1)
{
    QSqlQuery query;

    query.prepare("update stu set course6=? where id=?");

    query.addBindValue(course1);
    query.addBindValue(uesid);

    return query.exec();
}

bool sqlqueryModel::setCourse7(QString uesid, const QString&course1)
{
    QSqlQuery query;

    query.prepare("update stu set course7=? where id=?");

    query.addBindValue(course1);
    query.addBindValue(uesid);

    return query.exec();
}

bool sqlqueryModel::settest(QString uesid, const QString &test)
{
    QSqlQuery query;

    query.prepare("update stu set test=? where id=?");

    query.addBindValue(test);
    query.addBindValue(uesid);

    return query.exec();
}



