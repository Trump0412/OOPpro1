#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include<QSqlQueryModel>
#include<QTableView>
#include<QMessageBox>
#include"sqlquerymodel.h"
#include"QSqlDatabase"
#include <QTime>
#include <QThread>
//#include<fstream>
#include<QFile>
#include <QFileDialog>
#include <QFileInfo>

//#include<QCloseEvent>

//#include<QSqlTableModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("学生成绩管理系统"));
    //1.根据数据类型链接数据库
    db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("oop04.db");
    //2.打开
    if(!db.open())
    {
        qDebug()<<"open error"<<db.lastError();
    }

    //3.创建表
    QSqlQuery query;
//#if 0
    QString sqlCreatTable=QString("create table stu(id varchar(20),"
                                    "name varchar(20),"
                                    "course1 varchar(10),"
                                   "course2 varchar(10),"
                                    "course3 varchar(10),"
                                    "course4 varchar(10),"
                                    "course5 varchar(10),"
                                    "course6 varchar(10),"
                                    "course7 varchar(10),"
                                    "test0 varchar(10),"
                                    "sum double);");

    if(!query.exec(sqlCreatTable))
    {
        qDebug()<<"create table"<<db.lastError();
    }
//#endif

//#if 0
    //初始化插入
    query.exec("delete from stu");//删除表内内容
#if 0
    for(int i=0;i<m_count;i++)
    {
       QString id=student[i].s_id;
       QString name=student[i].s_name;
       QString co1=student[i].course1;
       QString co2=student[i].course2;
       QString co3=student[i].course3;
       QString co4=student[i].course4;
       QString co5=student[i].course5;
       QString co6=student[i].course6;
       QString co7=student[i].course7;
       double tt=student[i].test;
       double ff=student[i].final;
    QString sqlInsert=QString("insert into stu(id,name,course1,course2,course3,course4,course5,course6,course7,test,sum) "
                                    "values(%1,%2,%3,%4,%5,%6,%7,%8,%9,%10,%11);"
                                    ).arg(id).arg(name).arg(co1).arg(co2).arg(co3).arg(co4).arg(co5).arg(co6).arg(co7).arg(tt).arg(ff);
    if(!query.exec(sqlInsert))
    {
        qDebug()<<"Error insert  into data"<<db.lastError();
    }
    }

    //插入结束
//#endif
    //使用qsqlquerymodel快速查询
    //1.set Qsqlqurymedel duixiang,bing set biaotou
  // QSqlQueryModel*model=new QSqlQueryModel;//未修改过的
    model=new sqlqueryModel;//已经在头文件声明
    //2. run sql
    model->setQuery("select * from stu");//结果集
    //根据需求设置表头
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"Name");
    model->setHeaderData(2,Qt::Horizontal,"数理逻辑");
    model->setHeaderData(3,Qt::Horizontal,"集合论");
    model->setHeaderData(4,Qt::Horizontal,"抽象代数");
    model->setHeaderData(5,Qt::Horizontal,"图论");
    model->setHeaderData(6,Qt::Horizontal,"平时综合");
    model->setHeaderData(7,Qt::Horizontal,"期中测试");
    model->setHeaderData(8,Qt::Horizontal,"小论文");
    model->setHeaderData(9,Qt::Horizontal,"期末成绩");
    model->setHeaderData(10,Qt::Horizontal,"总分");
    //给ui设置一个模型
    view=new QTableView(ui->widget_main);
    view->setFixedSize(QSize(691,511));//设定窗口大小为固定大小

    view->setModel(model);//将数据联动到Ui上

    //将view显示
    view->show();

    //model->setEditStrategy(QSqlTableModel::OnFieldChange);
#endif
    ui->widget_main->show();
    ui->widget_add->close();
    ui->widget_find1->close();
    ui->widget_de->close();
     ui->widget_find2->close();
      ui->widget_gaojichazhao->close();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh()
{
    //2. run sql
    model->setQuery("select id,name,course1,course2,course3,course4,course5,course6,course7,test0,sum from stu");//结果集
    //根据需求设置表头
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"Name");
    model->setHeaderData(2,Qt::Horizontal,"数理逻辑");
    model->setHeaderData(3,Qt::Horizontal,"集合论");
    model->setHeaderData(4,Qt::Horizontal,"抽象代数");
    model->setHeaderData(5,Qt::Horizontal,"图论");
    model->setHeaderData(6,Qt::Horizontal,"平时综合");
    model->setHeaderData(7,Qt::Horizontal,"期中测试");
    model->setHeaderData(8,Qt::Horizontal,"小论文");
    model->setHeaderData(9,Qt::Horizontal,"期末成绩");
    model->setHeaderData(10,Qt::Horizontal,"总分");

    //给ui设置一个模型
    view=new QTableView(ui->widget_main);
    view->setFixedSize(QSize(1011,511));//设定窗口大小为固定大小

    view->setModel(model);//将数据联动到Ui上

    //将view显示
    view->show();
     ui->widget_gaojichazhao->close();
}





void MainWindow::on_exit_clicked()
{
    db.close();


    exit(1);
}


void MainWindow::on_addbut_clicked()
{
    ui->widget_main->close();
      ui->widget_find1->close();
    ui->widget_add->show();
     ui->widget_de->close();

    // //获取选中的行
    // int curRow = view->currentIndex().row();
    // //删除改行
    // model->removeRow(curRow);
    // int ok = QMessageBox::warning(this,QString::fromLocal8Bit("删除当前行"),QString::fromLocal8Bit("你确定删除当前行吗?"),QMessageBox::Yes,QMessageBox::No);
    // //QMessageBox::warning(this,tr("删除当前行"),tr("你确定删除当前行吗?"),QMessageBox::Yes,QMessageBox::No);
    // if(ok==QMessageBox::No)
    // {
    //     model->revertAll();//如果不删除，则撤销
    // }
    // else
    // {
    //     model->submitAll();//否则提交，在数据库中删除该行
    // }

    // ————————————————

    //     版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。

    //             原文链接：https://blog.csdn.net/qq_24127015/article/details/100516198
}


void MainWindow::on_deletebut_clicked()
{
#if 0
    QSqlQuery query;
    int currentrow = view->currentIndex().row();
    model->removeRow(currentrow);
    if(currentrow != -1)//若选中一行
    {
        int ok  =  QMessageBox::warning(this,tr("删除当前行!"),tr("你确定删除当前行吗？"), QMessageBox::Yes,QMessageBox::No);
        //如确认删除
        if(ok == QMessageBox::Yes)
        {
            model->removeRow(currentrow);
            QString name = model->data(model->index(currentrow,0)).toString();//获取姓名
            QString del = "delete from user where name='" + name + "';";
            query.exec(del);
            model->setQuery("select * from user");
            view->setModel(model);
            QMessageBox::information(this, "删除成功", "所选信息删除成功");
        }
    }
    else
        QMessageBox::information(this, "提示", "请选择你要删除的信息行");
#endif




#if 0

     int my_currentrow = view->currentIndex().row();

     QThread::sleep(1);
     //QMessageBox::information(this, "提示", "请选择你要删除的学生");

     //  QThread::sleep(1);
     // my_currentrow = view->currentIndex().row();
     QSqlQuery query;
     // if(my_currentrow!=-1)
     // {


     QString sqldelete;
     int ok  =  QMessageBox::warning(this,tr("删除当前学生!"),tr("你确定删除当前学生吗？"), QMessageBox::Yes,QMessageBox::No);
     //如确认删除
     if(ok == QMessageBox::Yes)
         sqldelete =QString("delete from stu where rowid=%1").arg(my_currentrow);
     else
         QMessageBox::information(this, "提示", "请选择你要删除的学生");
     if(!query.exec(sqldelete))
     {
         qDebug()<<"Error delete  data"<<db.lastError();
     }
     if(query.exec(sqldelete) == false){

         QMessageBox::critical(this,"error","删除学生信息失败");
         ui->lineEdit->clear();
         ui->widget_find1->close();
         ui->widget_main->show();
         ui->widget_add->close();
         refresh();

     }

     else{

         QMessageBox::information(this,"successed","成功删除学生信息");

         refresh();

     }
     // }
     ui->lineEdit->clear();
     ui->widget_find1->close();

#endif
    //1.删除数据库中内容
    QSqlQuery query;
    QString id=ui->lineEdit->text();
    int currentrow = view->currentIndex().row();
    model->removeRow(currentrow);

    if(!id.isEmpty())
  {

    QString sqldelete;
    int ok  =  QMessageBox::warning(this,tr("删除当前学生!"),tr("你确定删除当前学生吗？"), QMessageBox::Yes,QMessageBox::No);
    //如确认删除
    if(ok == QMessageBox::Yes)
        sqldelete =QString("delete from stu where id=%1").arg(id);
    else
        QMessageBox::information(this, "提示", "请选择你要删除的学生");
    if(!query.exec(sqldelete))
    {
        qDebug()<<"Error delete  data"<<db.lastError();
    }
    if(query.exec(sqldelete) == false){

        QMessageBox::critical(this,"error","删除学生信息失败");

    }

    else{

        QMessageBox::information(this,"successed","成功删除学生信息");

        refresh();

    }
    ui->lineEdit->clear();
    ui->widget_find1->close();
    ui->widget_de->close();
   }
   else
    {

         currentrow = view->currentIndex().row();
        model->removeRow(currentrow);
        if(currentrow != -1)//若选中一行
        {
            int ok  =  QMessageBox::warning(this,tr("删除当前行!"),tr("你确定删除当前行吗？"), QMessageBox::Yes,QMessageBox::No);
            //如确认删除
            if(ok == QMessageBox::Yes)
            {
                model->removeRow(currentrow);
                QString did = model->data(model->index(currentrow,0)).toString();//获取id
               // QString del = "delete from user where id='" + did + "';";
               QString  sqldelete2 =QString("delete from stu where id=%1").arg(did);
                query.exec(sqldelete2);
               // model->setQuery("select * from user");
                //view->setModel(model);
                QMessageBox::information(this, "删除成功", "所选信息删除成功");
                refresh();
            }
        }
        else
            QMessageBox::information(this, "提示", "请选择你要删除的信息行");

        ui->lineEdit_2->clear();
        ui->widget_find1->close();
        ui->widget_de->close();
    }

   delete_ok=false;
}


void MainWindow::on_pushButton_clicked()//增加学生的确认
{
    //1.获取ui上的内容
    QString id=ui->idedit->text();
    QString name=ui->nameedit->text();
    QString math=ui->mathedit->text();
    QString physics=ui->physicsedit->text();
    QString english=ui->englishedit->text();
    //2.数据插入到数据库（通过数据库接口的访问）
    QSqlQuery query;

    QString sqlinsert=QString("insert into stu(id ,name,math,physics,english)"
                                "values('%1','%2',%3,%4,%5);").arg(id).arg(name).arg(math.toInt())
                            .arg(physics.toInt())
                            .arg(english.toInt());//占位符，变化数据
    if(!query.exec(sqlinsert))
    {
        qDebug()<<"Error insert into data"<<db.lastError();
    }
    ui->widget_main->show();
    ui->widget_add->close();
     ui->widget_de->close();
    refresh();
}


void MainWindow::on_find_id_clicked()
{


    QString id=ui->lineEdit->text();

    QString did=QString("select id,name,course1,course2,course3,course4,course5,course6,course7,test0,sum from stu where id=%1").arg(id);
    model->setQuery(did);//结果集
    //根据需求设置表头
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"Name");
    model->setHeaderData(2,Qt::Horizontal,"数理逻辑");
    model->setHeaderData(3,Qt::Horizontal,"集合论");
    model->setHeaderData(4,Qt::Horizontal,"抽象代数");
    model->setHeaderData(5,Qt::Horizontal,"图论");
    model->setHeaderData(6,Qt::Horizontal,"平时综合");
    model->setHeaderData(7,Qt::Horizontal,"期中测试");
    model->setHeaderData(8,Qt::Horizontal,"小论文");
    model->setHeaderData(9,Qt::Horizontal,"期末成绩");
    model->setHeaderData(10,Qt::Horizontal,"总分");

    //给ui设置一个模型
    view=new QTableView(ui->widget_main);
    view->setFixedSize(QSize(1011,511));//设定窗口大小为固定大小

    view->setModel(model);//将数据联动到Ui上

    //将view显示
    view->show();
     ui->widget_main->show();
     ui->widget_gaojichazhao->close();

    if(delete_ok)ui->widget_de->show();
}


void MainWindow::on_find_name_clicked()
{


    QString name=ui->lineEdit_2->text();

    QString dname=QString("select id,name,course1,course2,course3,course4,course5,course6,course7,test0,sum from stu where name like '%%1%'").arg(name);
    model->setQuery(dname);//结果集
    //根据需求设置表头
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"Name");
    model->setHeaderData(2,Qt::Horizontal,"数理逻辑");
    model->setHeaderData(3,Qt::Horizontal,"集合论");
    model->setHeaderData(4,Qt::Horizontal,"抽象代数");
    model->setHeaderData(5,Qt::Horizontal,"图论");
    model->setHeaderData(6,Qt::Horizontal,"平时综合");
    model->setHeaderData(7,Qt::Horizontal,"期中测试");
    model->setHeaderData(8,Qt::Horizontal,"小论文");
    model->setHeaderData(9,Qt::Horizontal,"期末成绩");
    model->setHeaderData(10,Qt::Horizontal,"总分");

    //给ui设置一个模型
    view=new QTableView(ui->widget_main);
    view->setFixedSize(QSize(1011,511));//设定窗口大小为固定大小

    view->setModel(model);//将数据联动到Ui上


    //将view显示
    view->show();
    ui->widget_main->show();
    ui->widget_gaojichazhao->close();

    ui->widget_de->show();

     QMessageBox::information(this, "提示", "请选择你要删除的信息行");

    if(delete_ok)ui->widget_de->show();


}


void MainWindow::on_findbut_clicked()
{
    ui->widget_main->show();
    ui->widget_gaojichazhao->close();
    ui->widget_add->close();
    ui->widget_find1->show();
     ui->widget_find2->close();
    ui->widget_de->close();
     delete_ok=true;
}


void MainWindow::on_back_clicked()//返回主界面
{
ui->lineEdit->clear();
ui->lineEdit_2->clear();
    ui->widget_main->show();
ui->widget_gaojichazhao->close();
    ui->widget_add->close();
    ui->widget_find1->close();
    ui->widget_find2->close();
    ui->widget_de->close();
    refresh();
    delete_ok=false;
}


void MainWindow::on_findbut_2_clicked()
{
//第一步和删除的第一步一样
    ui->widget_main->show();
ui->widget_gaojichazhao->close();
    ui->widget_add->close();
    ui->widget_find1->show();
    ui->widget_find2->show();
    ui->widget_de->close();
    ui->searchchoice->addItem("数理逻辑");
     ui->searchchoice->addItem("集合论");
     ui->searchchoice->addItem("抽象代数");
     ui->searchchoice->addItem("图论");
     ui->searchchoice->addItem("平时综合");
      ui->searchchoice->addItem("期中测试");
      ui->searchchoice->addItem("小论文");
       ui->searchchoice->addItem("期末成绩");
      ui->searchchoice->addItem("总评成绩");
    ui->searchchoice->setCurrentText("总评成绩");


}


void MainWindow::on_openfilebut_clicked()
{
    QFileInfo info(QFileDialog::getOpenFileName());
    QString  file_path = info.filePath();
    QString  file_name = info.fileName();
    if(file_path.isEmpty()) return;
    QFile *opened_file = new QFile(file_path);
    if(!opened_file->exists())
    {

        enum QMessageBox::StandardButton ret = QMessageBox::warning(nullptr,"警告","文件不存在",QMessageBox::Retry|QMessageBox::Cancel);
        switch(ret)
        {
        case QMessageBox::Retry:
            on_openfilebut_clicked();
            break;
        default:
            return;
            break;
        }

        return;
    }
    //setWindowTitle(file_name);
    opened_file->open(QIODeviceBase::ReadOnly|QIODeviceBase::Text);
    QTextStream fs(opened_file);
    QString id,name,c1,c2,c3,c4,c5,c6,c7;
   QString t;

    while(!fs.atEnd())
    {
        fs >> id >> name >> c1 >> c2 >> c3>>c4>>c5>>c6>>c7>>t;
        if(id=="END")break;
        stutmp tmp(id,name,c1,c2,c3,c4,c5,c6,c7,t);
        student[m_count]=tmp;
        m_count++;

    }
    qDebug()<<m_count<<student[34].s_name<<" "<<student[35].s_id;
    qDebug()<<student[0].s_id;

    opened_file->close();
#if 0
    //3.创建表
    QSqlQuery query;
    //#if 0
    QString sqlCreatTable=QString("create table stu(id varchar(20),"
                                    "name varchar(20),"
                                    "course1 varchar(10),"
                                    "course2 varchar(10),"
                                    "course3 varchar(10),"
                                    "course4 varchar(10),"
                                    "course5 varchar(10),"
                                    "course6 varchar(10),"
                                    "course7 varchar(10),"
                                    "test double,"
                                    "sum double);");

    if(!query.exec(sqlCreatTable))
    {
        qDebug()<<"create table"<<db.lastError();
    }

#endif
QSqlQuery query;
    //QString sqlInsert;
    //#if 0
    //初始化插入
    //query.exec("delete from stu");//删除表内内容
   for(int i=0;i<m_count;i++)
    {
        // QString id=student[i].s_id;
        // QString name=student[i].s_name;
        // QString co1=student[i].course1;
        // QString co2=student[i].course2;
        // QString co3=student[i].course3;
        // QString co4=student[i].course4;
        // QString co5=student[i].course5;
        // QString co6=student[i].course6;
        // QString co7=student[i].course7;
        // double tt=student[i].test;
        // double ff=student[i].final;
         // sqlInsert=QString("insert into stu(id,name,course1,course2,course3,course4,course5,course6,course7,test,sum) "
         //                            "values(%1,%2,%3,%4,%5,%6,%7,%8,%9,%10,%11);"
         //                            ).arg(student[i].s_id).arg(student[i].s_name).arg(student[i].course1).arg(student[i].course2).arg(student[i].course3).arg(student[i].course4).arg(student[i].course5).arg(student[i].course6).arg(student[i].course7).arg(student[i].test).arg(student[i].final);





    query.prepare("INSERT INTO stu (id,name,course1,course2,course3,course4,course5,course6,course7,test0,sum) VALUES (:id, :name,:co1,:co2,:co3,:co4,:co5,:co6,:co7,:tt,:ff)");
    query.bindValue(":id", student[i].s_id);
    query.bindValue(":name", student[i].s_name);
    query.bindValue(":co1", student[i].course1);
    query.bindValue(":co2", student[i].course2);
    query.bindValue(":co3", student[i].course3);
    query.bindValue(":co4", student[i].course4);
    query.bindValue(":co5", student[i].course5);
    query.bindValue(":co6", student[i].course6);
    query.bindValue(":co7", student[i].course7);
    query.bindValue(":tt", student[i].test0);
    // query.bindValue(":c1", student[i].s_course1);
    // query.bindValue(":c2", student[i].s_course2);
    // query.bindValue(":c3", student[i].s_course3);
    // query.bindValue(":c4", student[i].s_course4);
    // query.bindValue(":c5", student[i].s_course5);
    // query.bindValue(":c6", student[i].s_course6);
    // query.bindValue(":c7", student[i].s_course7);
    // query.bindValue(":dtt", student[i].test);
    query.bindValue(":ff", student[i].final);


    if(!query.exec())
        {
            qDebug()<<"Error insert  into data"<<db.lastError();
        }
         else qDebug()<<"chenggong";
      //  sqlInsert.clear();
    }

    model=new sqlqueryModel;

    refresh();


    ui->widget_main->show();
    ui->widget_add->close();
    ui->widget_find1->close();
    ui->widget_de->close();
    ui->widget_find2->close();
    ui->widget_gaojichazhao->close();
}


void MainWindow::on_back_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->score_min->clear();
    ui->score_max->clear();
    ui->widget_main->show();
    ui->widget_add->close();
    ui->widget_find1->close();
    ui->widget_find2->close();
    ui->widget_de->close();
    ui->widget_gaojichazhao->close();
    refresh();
}




void MainWindow::on_searchmul_clicked()
{
    double min,max;
    min=ui->score_min->text().toDouble();
    max=ui->score_max->text().toDouble();
    //QString subject;

    if(ui->searchchoice->currentText()=="数理逻辑")scorecal(1,min,max);
    if(ui->searchchoice->currentText()=="集合论")scorecal(2,min,max);
    if(ui->searchchoice->currentText()=="抽象代数")scorecal(3,min,max);
    if(ui->searchchoice->currentText()=="图论")scorecal(4,min,max);
    if(ui->searchchoice->currentText()=="平时综合")scorecal(5,min,max);
    if(ui->searchchoice->currentText()=="期中测试")scorecal(6,min,max);
    if(ui->searchchoice->currentText()=="小论文")scorecal(7,min,max);
    if(ui->searchchoice->currentText()=="期末成绩")scorecal(8,min,max);
    if(ui->searchchoice->currentText()=="总评成绩")scorecal(9,min,max);

    //scorecal(subject,min,max);
}
void MainWindow::scorecal(int n,double in,double ax)
{
    QString str;

    switch (n) {
    case 1:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course1>=in&&stusql[i].s_course1<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"  "+stusql[i].course1+"  "+stusql[i].course2+"  "
                      +stusql[i].course3+"  "+stusql[i].course4+"  "+stusql[i].course5+"  "
                      +stusql[i].course6+"  "+stusql[i].course7+"  "+stusql[i].test0+"  "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 2:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course2>=in&&stusql[i].s_course2<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"  "+stusql[i].course1+"  "+stusql[i].course2+"  "
                      +stusql[i].course3+"  "+stusql[i].course4+"  "+stusql[i].course5+"  "
                      +stusql[i].course6+"  "+stusql[i].course7+"  "+stusql[i].test0+"  "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 3:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course3>=in&&stusql[i].s_course3<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"  "+stusql[i].course1+"  "+stusql[i].course2+"  "
                      +stusql[i].course3+"  "+stusql[i].course4+"  "+stusql[i].course5+"  "
                      +stusql[i].course6+"  "+stusql[i].course7+"  "+stusql[i].test0+"  "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 4:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course4>=in&&stusql[i].s_course4<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"  "+stusql[i].course1+"  "+stusql[i].course2+"  "
                      +stusql[i].course3+"  "+stusql[i].course4+"  "+stusql[i].course5+"  "
                      +stusql[i].course6+"  "+stusql[i].course7+"  "+stusql[i].test0+"  "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 5:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course5>=in&&stusql[i].s_course5<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"  "+stusql[i].course1+"  "+stusql[i].course2+"  "
                      +stusql[i].course3+"  "+stusql[i].course4+"  "+stusql[i].course5+"  "
                      +stusql[i].course6+"  "+stusql[i].course7+"  "+stusql[i].test0+"  "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 6:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course6>=in&&stusql[i].s_course6<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"  "+stusql[i].course1+"  "+stusql[i].course2+"  "
                      +stusql[i].course3+"  "+stusql[i].course4+"  "+stusql[i].course5+"  "
                      +stusql[i].course6+"  "+stusql[i].course7+"  "+stusql[i].test0+"  "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 7:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course7>=in&&stusql[i].s_course7<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"  "+stusql[i].course1+"  "+stusql[i].course2+"  "
                      +stusql[i].course3+"  "+stusql[i].course4+"  "+stusql[i].course5+"  "
                      +stusql[i].course6+"  "+stusql[i].course7+"  "+stusql[i].test0+"  "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 8:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].test>=in&&stusql[i].test<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"  "+stusql[i].course1+"  "+stusql[i].course2+"  "
                      +stusql[i].course3+"  "+stusql[i].course4+"  "+stusql[i].course5+"  "
                      +stusql[i].course6+"  "+stusql[i].course7+"  "+stusql[i].test0+"  "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 9:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].final>=in&&stusql[i].final<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"  "+stusql[i].course1+"  "+stusql[i].course2+"  "
                      +stusql[i].course3+"  "+stusql[i].course4+"  "+stusql[i].course5+"  "
                      +stusql[i].course6+"  "+stusql[i].course7+"  "+stusql[i].test0+"  "+QString::number(stusql[i].final)+'\n';
        }

        break;
    default:
        str="该分数段内没有匹配的学生！";
        break;
    }


    ui->textEdit->setText(str);
   ui->widget_main->close();
    ui->widget_gaojichazhao->show();

}

void MainWindow::on_rankbut_clicked()
{
    //  model->setQuery("select * from stu order by sum desc");


    // //给ui设置一个模型
    // view=new QTableView(ui->widget_main);
    // view->setFixedSize(QSize(1011,511));//设定窗口大小为固定大小

    // view->setModel(model);//将数据联动到Ui上

    // //将view显示
    // view->show();
    getallstu();
}

void MainWindow::getallstu()
{
    if(!alreadygetstu)
    {
        QSqlQuery query(db);
    query.exec("select * from stu");
    int i=0;//注意i=1，为了让排序第一个为1
    double tmp=0;//为了算出double类型的成绩
    while(query.next())
    {
        qDebug()<<i;

        stusql[i].s_id=query.value(0).toString();
        stusql[i].s_name=query.value(1).toString();
        stusql[i].course1 =query.value(2).toString();
        stusql[i].course2=query.value(3).toString();
        stusql[i].course3=query.value(4).toString();
        stusql[i].course4=query.value(5).toString();
        stusql[i].course5=query.value(6).toString();
        stusql[i].course6=query.value(7).toString();
        stusql[i].course7=query.value(8).toString();
        stusql[i].test0=query.value(9).toString();
        stusql[i].final=query.value(10).toDouble();
        tmp=stusql[i].getfinal();
        qDebug()<<stusql[i].s_name;
        i++;

    }
    }
    alreadygetstu=true;
}

