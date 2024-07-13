#ifndef SQLQUERYMODEL_H
#define SQLQUERYMODEL_H

#include <QSqlQueryModel>

class sqlqueryModel : public QSqlQueryModel
{
public:
    explicit sqlqueryModel(QObject *parent = nullptr);

    bool setData(const QModelIndex &index,const QVariant &value,int role=Qt::EditRole);

    Qt::ItemFlags flags(const QModelIndex &index)const;
private:
    //自定义接口函数
    //更新数据
    void refresh();

    //根据需求定义修改内容的接口
    bool setName(QString uesid,const QString&name);
    bool setCourse1(QString uesid,const QString&course1);
    bool setCourse2(QString uesid,const QString&course1);
    bool setCourse3(QString uesid,const QString&course1);
    bool setCourse4(QString uesid,const QString&course1);
    bool setCourse5(QString uesid,const QString&course1);
    bool setCourse6(QString uesid,const QString&course1);
    bool setCourse7(QString uesid,const QString&course1);
    bool settest(QString uesid,const QString&test);

};

#endif // SQLQUERYMODEL_H
