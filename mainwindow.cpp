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
    db.setDatabaseName("oop05.db");
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
       ui->widget_rank->close();
      ui->widget_ana->close();


      QChartView *chartview;
      chartview=new QChartView(createbarchart());
      ui->horizontalLayout_2->insertWidget(0,chartview);



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
     int i=m_count+1;
     QString addstr="_"+QString::number(i);


     ui->numberedit->setText(addstr);
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
    alreadygetstu=false;
   getallstu();
}


void MainWindow::on_pushButton_clicked()//增加学生的确认
{
    //1.获取ui上的内容
    QString id=ui->idedit->text();
    QString name=ui->nameedit->text();
    QString math=ui->course1dit->text();
    QString physics=ui->course2dit->text();
    QString english=ui->course3dit->text();
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
   // model =new sqlqueryModel;
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

    File_Path=file_path;//保存文件路径

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
    getallstu();
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
        str=QString("      id        name   数理逻辑 集合论 抽象代数 图论 平时综合 期中测试 小论文 期末成绩 总评成绩 ");
        str=str+'\n';
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course1>=in&&stusql[i].s_course1<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"        "+stusql[i].course1+"           "+stusql[i].course2+"           "
                      +stusql[i].course3+"         "+stusql[i].course4+"         "+stusql[i].course5+"            "
                      +stusql[i].course6+"        "+stusql[i].course7+"         "+stusql[i].test0+"           "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 2:
        str=QString("      id        name   数理逻辑 集合论 抽象代数 图论 平时综合 期中测试 小论文 期末成绩 总评成绩 ");
        str=str+'\n';
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course2>=in&&stusql[i].s_course2<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"        "+stusql[i].course1+"           "+stusql[i].course2+"           "
                      +stusql[i].course3+"         "+stusql[i].course4+"         "+stusql[i].course5+"            "
                      +stusql[i].course6+"        "+stusql[i].course7+"         "+stusql[i].test0+"           "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 3:
        str=QString("      id        name   数理逻辑 集合论 抽象代数 图论 平时综合 期中测试 小论文 期末成绩 总评成绩 ");
        str=str+'\n';
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course3>=in&&stusql[i].s_course3<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"        "+stusql[i].course1+"           "+stusql[i].course2+"           "
                      +stusql[i].course3+"         "+stusql[i].course4+"         "+stusql[i].course5+"            "
                      +stusql[i].course6+"        "+stusql[i].course7+"         "+stusql[i].test0+"           "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 4:
        str=QString("      id        name   数理逻辑 集合论 抽象代数 图论 平时综合 期中测试 小论文 期末成绩 总评成绩 ");
        str=str+'\n';
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course4>=in&&stusql[i].s_course4<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"        "+stusql[i].course1+"           "+stusql[i].course2+"           "
                      +stusql[i].course3+"         "+stusql[i].course4+"         "+stusql[i].course5+"            "
                      +stusql[i].course6+"        "+stusql[i].course7+"         "+stusql[i].test0+"           "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 5:
        str=QString("      id        name   数理逻辑 集合论 抽象代数 图论 平时综合 期中测试 小论文 期末成绩 总评成绩 ");
        str=str+'\n';
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course5>=in&&stusql[i].s_course5<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"        "+stusql[i].course1+"           "+stusql[i].course2+"           "
                      +stusql[i].course3+"         "+stusql[i].course4+"         "+stusql[i].course5+"            "
                      +stusql[i].course6+"        "+stusql[i].course7+"         "+stusql[i].test0+"           "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 6:
        str=QString("      id        name   数理逻辑 集合论 抽象代数 图论 平时综合 期中测试 小论文 期末成绩 总评成绩 ");
        str=str+'\n';
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course6>=in&&stusql[i].s_course6<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"        "+stusql[i].course1+"           "+stusql[i].course2+"           "
                      +stusql[i].course3+"         "+stusql[i].course4+"         "+stusql[i].course5+"            "
                      +stusql[i].course6+"        "+stusql[i].course7+"         "+stusql[i].test0+"           "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 7:
        str=QString("      id        name   数理逻辑 集合论 抽象代数 图论 平时综合 期中测试 小论文 期末成绩 总评成绩 ");
        str=str+'\n';
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course7>=in&&stusql[i].s_course7<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"        "+stusql[i].course1+"           "+stusql[i].course2+"           "
                      +stusql[i].course3+"         "+stusql[i].course4+"         "+stusql[i].course5+"            "
                      +stusql[i].course6+"        "+stusql[i].course7+"         "+stusql[i].test0+"           "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 8:
        str=QString("      id        name   数理逻辑 集合论 抽象代数 图论 平时综合 期中测试 小论文 期末成绩 总评成绩 ");
        str=str+'\n';
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].test>=in&&stusql[i].test<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"        "+stusql[i].course1+"           "+stusql[i].course2+"           "
                      +stusql[i].course3+"         "+stusql[i].course4+"         "+stusql[i].course5+"            "
                      +stusql[i].course6+"        "+stusql[i].course7+"         "+stusql[i].test0+"           "+QString::number(stusql[i].final)+'\n';
        }

        break;
    case 9:
        str=QString("      id        name   数理逻辑 集合论 抽象代数 图论 平时综合 期中测试 小论文 期末成绩 总评成绩 ");
        str=str+'\n';
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].final>=in&&stusql[i].final<=ax)
                str=str+stusql[i].s_id+"  "+stusql[i].s_name+"        "+stusql[i].course1+"           "+stusql[i].course2+"           "
                      +stusql[i].course3+"         "+stusql[i].course4+"         "+stusql[i].course5+"            "
                      +stusql[i].course6+"        "+stusql[i].course7+"         "+stusql[i].test0+"           "+QString::number(stusql[i].final)+'\n';
        }

        break;
    default:
        str="该分数段内没有匹配的学生！";
        break;
    }
    ui->textEdit->clear();

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
    ui->textEdit->clear();
    QString str;
    str=QString("      id        name   数理逻辑 集合论 抽象代数 图论 平时综合 期中测试 小论文 期末成绩 总评成绩 ");
    str=str+'\n';

    rankstu();

    for(int i=0;i<m_count;i++)
    {
            str=str+stusql[i].s_id+"  "+stusql[i].s_name+"        "+stusql[i].course1+"           "+stusql[i].course2+"           "
                  +stusql[i].course3+"         "+stusql[i].course4+"         "+stusql[i].course5+"            "
                  +stusql[i].course6+"        "+stusql[i].course7+"         "+stusql[i].test0+"           "+QString::number(stusql[i].final)+'\n';
    }

    ui->textEdit->setText(str);
    ui->widget_main->close();
    ui->widget_gaojichazhao->show();

    ui->widget_add->close();
    ui->widget_find1->close();
    ui->widget_de->close();
    ui->widget_find2->close();
    ui->widget_rank->show();


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


void MainWindow::on_back_rank_clicked()
{
    ui->widget_main->show();
    ui->widget_gaojichazhao->close();

    ui->widget_add->close();
    ui->widget_find1->close();
    ui->widget_de->close();
    ui->widget_find2->close();
    ui->widget_rank->close();
    getallstu();
    refresh();
}

void MainWindow::rankstu()
{
    bool noswap;


    for (int i = 0; i < m_count-1; i++)
    {
        noswap = true;
        for (int j = m_count - 1; j > i; j--)
        {
            if (stusql[j]> stusql[j - 1])
            {
                stu tmp = stusql[j];
                stusql[j] = stusql[j - 1];
                stusql[j - 1] = tmp;
                noswap = false;
            }
        }
        if (noswap)break;
    }
    alreadygetstu=false;//等待之后重新按原顺序排列
}

void MainWindow::getaverage(int n)
{
    double sum=0;
    double ave=0;
    switch(n)
    {
    case 1:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course1;
        }
        ave=sum/m_count;
        ui->aveline->setText(QString::number(ave));

        break;
    case 2:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course2;
        }
        ave=sum/m_count;
        ui->aveline->setText(QString::number(ave));
        break;
    case 3:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course3;
        }
        ave=sum/m_count;
        ui->aveline->setText(QString::number(ave));
        break;
    case 4:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course4;
        }
        ave=sum/m_count;
        ui->aveline->setText(QString::number(ave));
        break;
    case 5:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course5;
        }
        ave=sum/m_count;
        ui->aveline->setText(QString::number(ave));
        break;
    case 6:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course6;
        }
        ave=sum/m_count;
        ui->aveline->setText(QString::number(ave));
        break;
    case 7:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course7;
        }
        ave=sum/m_count;
        ui->aveline->setText(QString::number(ave));
        break;
    case 8:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].test;
        }
        ave=sum/m_count;
        ui->aveline->setText(QString::number(ave));
        break;
    case 9:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].final;
        }
        ave=sum/m_count;
        m_ave=ave;
        ui->aveline->setText(QString::number(ave));
        break;

    }
}

void MainWindow::getsd(int n)
{
    double tmp=0;
    double sum=0;
    double ave=0;
    double sd=0;
    switch(n)
    {
    case 1:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course1;
        }
        ave=sum/m_count;
        for(int i=0;i<m_count;i++)
        {
            tmp+=(stusql[i].s_course1-ave)*(stusql[i].s_course1-ave);
        }

        sd=sqrt(tmp/m_count);
        ui->sdline->setText(QString::number(sd));
        break;
    case 2:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course2;
        }
        ave=sum/m_count;
        for(int i=0;i<m_count;i++)
        {
            tmp+=(stusql[i].s_course2-ave)*(stusql[i].s_course2-ave);
        }

        sd=sqrt(tmp/m_count);
        ui->sdline->setText(QString::number(sd));
        break;
    case 3:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course3;
        }
        ave=sum/m_count;
        for(int i=0;i<m_count;i++)
        {
            tmp+=(stusql[i].s_course3-ave)*(stusql[i].s_course3-ave);
        }

        sd=sqrt(tmp/m_count);
        ui->sdline->setText(QString::number(sd));
        break;
    case 4:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course4;
        }
        ave=sum/m_count;
        for(int i=0;i<m_count;i++)
        {
            tmp+=(stusql[i].s_course4-ave)*(stusql[i].s_course4-ave);
        }

        sd=sqrt(tmp/m_count);
        ui->sdline->setText(QString::number(sd));
        break;
    case 5:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course5;
        }
        ave=sum/m_count;
        for(int i=0;i<m_count;i++)
        {
            tmp+=(stusql[i].s_course5-ave)*(stusql[i].s_course5-ave);
        }

        sd=sqrt(tmp/m_count);
        ui->sdline->setText(QString::number(sd));
        break;
    case 6:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course6;
        }
        ave=sum/m_count;
        for(int i=0;i<m_count;i++)
        {
            tmp+=(stusql[i].s_course6-ave)*(stusql[i].s_course6-ave);
        }

        sd=sqrt(tmp/m_count);
        ui->sdline->setText(QString::number(sd));
        break;
    case 7:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].s_course7;
        }
        ave=sum/m_count;
        for(int i=0;i<m_count;i++)
        {
            tmp+=(stusql[i].s_course7-ave)*(stusql[i].s_course7-ave);
        }

        sd=sqrt(tmp/m_count);
        ui->sdline->setText(QString::number(sd));
        break;
    case 8:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].test;
        }
        ave=sum/m_count;
        for(int i=0;i<m_count;i++)
        {
            tmp+=(stusql[i].test-ave)*(stusql[i].test-ave);
        }

        sd=sqrt(tmp/m_count);
        ui->sdline->setText(QString::number(sd));
        break;
    case 9:
        for(int i=0;i<m_count;i++)
        {
            sum+=stusql[i].final;
        }
        ave=sum/m_count;
        for(int i=0;i<m_count;i++)
        {
            tmp+=(stusql[i].final-ave)*(stusql[i].final-ave);
        }

        sd=sqrt(tmp/m_count);
        ui->sdline->setText(QString::number(sd));
        break;

    }
}

void MainWindow::getpassrate(int n)
{
    double passor=0;
    double passr=0.00;
    double m_count1=QString::number(m_count).toDouble();
    switch(n)
    {
    case 1:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course1>=3)
                passor++;
        }
        passr=passor/m_count1;
        passr=passr*100;
        ui->passrateline->setText(QString::number(passr)+"%");
        break;
    case 2:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course2>=3)
                passor++;
        }
        passr=passor/m_count1;
        passr=passr*100;
        ui->passrateline->setText(QString::number(passr)+"%");
        break;
    case 3:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course3>=3)
                passor++;
        }
        passr=passor/m_count1;
        passr=passr*100;
        ui->passrateline->setText(QString::number(passr)+"%");
        break;
    case 4:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course4>=3)
                passor++;
        }
        passr=passor/m_count1;
        passr=passr*100;
        ui->passrateline->setText(QString::number(passr)+"%");
        break;
    case 5:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course5>=6)
                passor++;
        }
        passr=passor/m_count1;
        passr=passr*100;
        ui->passrateline->setText(QString::number(passr)+"%");
        break;
    case 6:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course6>=6)
                passor++;
        }
        passr=passor/m_count1;
        passr=passr*100;
        ui->passrateline->setText(QString::number(passr)+"%");
        break;
    case 7:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].s_course7>=6)
                passor++;
        }
       // qDebug()<<passor;

        passr=passor/m_count1;
        passr=passr*100;
        ui->passrateline->setText(QString::number(passr)+"%");
        break;
    case 8:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].test>=60)
                passor++;
        }
        passr=passor/m_count1;
        passr=passr*100;
        ui->passrateline->setText(QString::number(passr)+"%");
        break;
    case 9:
        for(int i=0;i<m_count;i++)
        {
            if(stusql[i].final>=60)
                passor++;
        }
        passr=passor/m_count1;
        passr=passr*100;
        ui->passrateline->setText(QString::number(passr)+"%");
        break;

    }
}

QChart *MainWindow::createbarchart() const
{
    QChart *chart = new QChart();
    chart->setTitle("分数段的人数直方图");

    QBarSet *set0 = new QBarSet("本班学生总评成绩");
    //QBarSet *set1 = new QBarSet("B日常开支");
//这里可以设置为for循环统计各分数段学生数目，为方便节约时间故省略
    *set0 << 1 << 11 << 17 << 19 << 25 ;
  //  *set1 << 766 << 435 << 3225 << 1348 << 4883 << 233;


    QBarSeries  *series = new QBarSeries (chart);
    series->append(set0);
   // series->append(set1);


    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "60以下" << "60-70" << "70-80" << "80-90" << "90-100" ;  //保存横坐标字符串的列表
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->axes(Qt::Vertical).first()->setRange(0,30);
    // Add space to label to add space between labels and axis在标签和轴之间加空格
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    //axisY->setLabelFormat("%.2f  ");
     axisY->setLabelFormat("%d  ");

    series->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);  //设置标签显示的位置
    series->setLabelsVisible(true);  //设置数据标签可见

    //设置主题
    chart->setTheme(QChart::ChartThemeBlueCerulean);

    return chart;

}

QChart *MainWindow::createScatterChart() const
{
    // scatter chart
    QChart *chart = new QChart();
    chart->setTitle("以平均分为参照的散点图");

    QScatterSeries *scatterSeries1 = new QScatterSeries(chart);
   // QScatterSeries *scatterSeries2 = new QScatterSeries(chart);

    scatterSeries1->setName("本班学生总评成绩");
    scatterSeries1->setPointLabelsFormat("@yPoint");
  //  scatterSeries1->setPointLabelsVisible();//让它不可见
    scatterSeries1->setMarkerSize(9);

    // scatterSeries2->setName("B店铺接单数");
    // scatterSeries2->setPointLabelsFormat("@yPoint");
    // scatterSeries2->setPointLabelsVisible();
    // scatterSeries2->setMarkerSize(16);

    double value;
    for(int i=0;i<m_count;i++)
    {
        value=stusql[i].final-m_ave;
        scatterSeries1->append(i,value);
        qDebug()<<i<<" "<<value;
    }
    // scatterSeries1->append(0,6);
    // scatterSeries1->append(1,10);
    // scatterSeries1->append(4,12);
    // scatterSeries1->append(6,5);

    // scatterSeries2->append(0,18);
    // scatterSeries2->append(3,13);
    // scatterSeries2->append(5,7);
    // scatterSeries2->append(6,2);
    chart->addSeries(scatterSeries1);
    //chart->addSeries(scatterSeries2);


    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, 75);// x轴范围
    chart->axes(Qt::Vertical).first()->setRange(-40, 40);// y轴范围
    // Add space to label to add space between labels and axis在标签和轴之间加空格
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    axisY->setLabelFormat("%.1f ");

    QValueAxis *axisX = qobject_cast<QValueAxis*>(chart->axes(Qt::Horizontal).first());

    axisY->setLabelFormat("%d ");
 Q_ASSERT(axisX);


    chart->setTheme(QChart::ChartThemeLight);
    return chart;

}


void MainWindow::on_writebut_clicked()
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
            on_writebut_clicked();
            break;
        default:
            return;
            break;
        }

        return;
    }
    //setWindowTitle(file_name);
    opened_file->open(QIODeviceBase::WriteOnly|QIODeviceBase::Text);
    QTextStream fs(opened_file);
   // QString id,name,c1,c2,c3,c4,c5,c6,c7;
   // QString t;
    fs<<QString("      id        name   数理逻辑 集合论 抽象代数 图论 平时综合 期中测试 小论文 期末成绩 总评成绩 ");
    fs<<'\n';
    for(int i=0;i<m_count;i++)
    {
        fs<< stusql[i].s_id<<"  "<<stusql[i].s_name<<"        "<<stusql[i].course1<<"           "<<stusql[i].course2<<"           "
           <<stusql[i].course3<<"         "<<stusql[i].course4<<"         "<<stusql[i].course5<<"            "
           <<stusql[i].course6<<"        "<<stusql[i].course7<<"         "<<stusql[i].test0<<"           "<<stusql[i].final<<'\n';
    }

    opened_file->close();
    QMessageBox::information(this,"successed","成功写入文件");
}


void MainWindow::on_updatebut_clicked()
{
    getallstu();
    QFile *opened_file = new QFile(File_Path);
    opened_file->open(QIODeviceBase::WriteOnly|QIODeviceBase::Text);
    QTextStream fs(opened_file);
    for(int i=0;i<m_count;i++)
    {
        fs<< stusql[i].s_id<<" "<<stusql[i].s_name<<" "<<stusql[i].course1<<" "<<stusql[i].course2<<" "
           <<stusql[i].course3<<" "<<stusql[i].course4<<" "<<stusql[i].course5<<" "
           <<stusql[i].course6<<" "<<stusql[i].course7<<" "<<stusql[i].test0<<'\n';
    }
    fs<<"END";
    opened_file->close();
    QMessageBox::information(this,"successed","成功更新文件");

}


void MainWindow::on_add_ok_clicked()
{
    QString nid=ui->idedit->text();
    nid=nid+ui->numberedit->text();
    QString nname=ui->nameedit->text();
    QString nc1=ui->course1dit->text();
    QString nc2=ui->course2dit->text();
    QString nc3=ui->course3dit->text();
    QString nc4=ui->course4dit->text();
    QString nc5=ui->course5dit->text();
    QString nc6=ui->course6dit->text();
    QString nc7=ui->course7dit->text();
    QString nt=ui->testdit->text();

    stutmp s(nid,nname,nc1,nc2,nc3,nc4,nc5,nc6,nc7,nt);

     QSqlQuery query;

    query.prepare("INSERT INTO stu (id,name,course1,course2,course3,course4,course5,course6,course7,test0,sum ) "
                  "VALUES (:id, :name,:co1,:co2,:co3,:co4,:co5,:co6,:co7,:tt,:ff)");

     // query.addBindValue(nid);
     // query.addBindValue(nname);
     // query.addBindValue(nc1);
     // query.addBindValue(nc2);
     // query.addBindValue(nc3);
     // query.addBindValue(nc4);
     // query.addBindValue(nc5);
     // query.addBindValue(nc6);
     // query.addBindValue(nc7);
     // query.addBindValue(nt);
     query.bindValue(":id", nid);
     query.bindValue(":name", nname);
     query.bindValue(":co1", nc1);
     query.bindValue(":co2", nc2);
     query.bindValue(":co3", nc3);
     query.bindValue(":co4", nc4);
     query.bindValue(":co5", nc5);
     query.bindValue(":co6", nc6);
     query.bindValue(":co7",nc7);
     query.bindValue(":tt", nt);

     query.bindValue(":ff",s.final);


     if(!query.exec())
     {
         qDebug()<<"Error  ADD insert  into data"<<db.lastError();
     }
     else qDebug()<<"ADD chenggong";
     //  sqlInsert.clear();


     // query.exec();

     QMessageBox::information(this,tr("信息提示"),tr("信息录入完毕！"));

    m_count++;

     alreadygetstu=false;
    getallstu();

     on_add_back_clicked();

}


void MainWindow::on_add_back_clicked()
{
    ui->nameedit->clear();
    ui->course1dit->clear();
   ui->course2dit->clear();
    ui->course3dit->clear();
    ui->course4dit->clear();
   ui->course5dit->clear();
   ui->course6dit->clear();
    ui->course7dit->clear();
   ui->testdit->clear();

    ui->widget_main->show();
    ui->widget_gaojichazhao->close();

    ui->widget_add->close();
    ui->widget_find1->close();
    ui->widget_de->close();
    ui->widget_find2->close();
    ui->widget_rank->close();

    refresh();
}


void MainWindow::on_analysisbut_clicked()
{
    getallstu();

    ui->widget_main->close();
    ui->widget_gaojichazhao->close();

    ui->widget_add->close();
    ui->widget_find1->close();
    ui->widget_de->close();
    ui->widget_find2->close();
    ui->widget_rank->close();
    ui->widget_ana->show();

    ui->searchchoice1->addItem("数理逻辑");
    ui->searchchoice1->addItem("集合论");
    ui->searchchoice1->addItem("抽象代数");
    ui->searchchoice1->addItem("图论");
    ui->searchchoice1->addItem("平时综合");
    ui->searchchoice1->addItem("期中测试");
    ui->searchchoice1->addItem("小论文");
    ui->searchchoice1->addItem("期末成绩");
    ui->searchchoice1->addItem("总评成绩");
    ui->searchchoice1->setCurrentText("总评成绩");

    ui->searchchoice2->addItem("数理逻辑");
    ui->searchchoice2->addItem("集合论");
    ui->searchchoice2->addItem("抽象代数");
    ui->searchchoice2->addItem("图论");
    ui->searchchoice2->addItem("平时综合");
    ui->searchchoice2->addItem("期中测试");
    ui->searchchoice2->addItem("小论文");
    ui->searchchoice2->addItem("期末成绩");
    ui->searchchoice2->addItem("总评成绩");
    ui->searchchoice2->setCurrentText("总评成绩");

    ui->searchchoice3->addItem("数理逻辑");
    ui->searchchoice3->addItem("集合论");
    ui->searchchoice3->addItem("抽象代数");
    ui->searchchoice3->addItem("图论");
    ui->searchchoice3->addItem("平时综合");
    ui->searchchoice3->addItem("期中测试");
    ui->searchchoice3->addItem("小论文");
    ui->searchchoice3->addItem("期末成绩");
    ui->searchchoice3->addItem("总评成绩");
    ui->searchchoice3->setCurrentText("总评成绩");

    getaverage(9);

    QChartView *ChartView;
    ChartView=new QChartView(createScatterChart());
    ui->horizontalLayout->insertWidget(0,ChartView);
}


void MainWindow::on_back_3_clicked()
{
    ui->widget_main->show();
    ui->widget_gaojichazhao->close();

    ui->widget_add->close();
    ui->widget_find1->close();
    ui->widget_de->close();
    ui->widget_find2->close();
    ui->widget_rank->close();
    ui->widget_ana->close();
    ui->aveline->clear();
    ui->sdline->clear();
    ui->passrateline->clear();
}


void MainWindow::on_pushButton_1_clicked()
{
    if(ui->searchchoice1->currentText()=="数理逻辑")getaverage(1);
    if(ui->searchchoice1->currentText()=="集合论")  getaverage(2);
    if(ui->searchchoice1->currentText()=="抽象代数")getaverage(3);
    if(ui->searchchoice1->currentText()=="图论")   getaverage(4);
    if(ui->searchchoice1->currentText()=="平时综合")getaverage(5);
    if(ui->searchchoice1->currentText()=="期中测试")getaverage(6);
    if(ui->searchchoice1->currentText()=="小论文")  getaverage(7);
    if(ui->searchchoice1->currentText()=="期末成绩")getaverage(8);
    if(ui->searchchoice1->currentText()=="总评成绩")getaverage(9);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->searchchoice2->currentText()=="数理逻辑")getsd(1);
    if(ui->searchchoice2->currentText()=="集合论")  getsd(2);
    if(ui->searchchoice2->currentText()=="抽象代数")getsd(3);
    if(ui->searchchoice2->currentText()=="图论")   getsd(4);
    if(ui->searchchoice2->currentText()=="平时综合")getsd(5);
    if(ui->searchchoice2->currentText()=="期中测试")getsd(6);
    if(ui->searchchoice2->currentText()=="小论文") getsd(7);
    if(ui->searchchoice2->currentText()=="期末成绩")getsd(8);
    if(ui->searchchoice2->currentText()=="总评成绩")getsd(9);
}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->searchchoice3->currentText()=="数理逻辑")getpassrate(1);
    if(ui->searchchoice3->currentText()=="集合论")  getpassrate(2);
    if(ui->searchchoice3->currentText()=="抽象代数")getpassrate(3);
    if(ui->searchchoice3->currentText()=="图论")   getpassrate(4);
    if(ui->searchchoice3->currentText()=="平时综合")getpassrate(5);
    if(ui->searchchoice3->currentText()=="期中测试")getpassrate(6);
    if(ui->searchchoice3->currentText()=="小论文") getpassrate(7);
    if(ui->searchchoice3->currentText()=="期末成绩")getpassrate(8);
    if(ui->searchchoice3->currentText()=="总评成绩")getpassrate(9);
}

