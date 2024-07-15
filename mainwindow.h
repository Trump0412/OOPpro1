#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QtDebug>
#include"sqlquerymodel.h"
#include<QTableView>
#include<QMouseEvent>
#include"stutmp.h"
#include"stusql.h"
//#include"statistic.h"
#include<math.h>
#include<QtCharts>
//#include"ui_rank.h"
//#include"ui_statistic.h"

using namespace std;
class  sqlqueryModel;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

//QT_CHARTS_BEGIN_NAMESPACE

//QT_CHARTS_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void refresh();

    void scorecal(int n,double b,double c);

    void getallstu();

    void rankstu();

    void getaverage(int n);

    void getsd(int n);

    void getpassrate(int n);

    QChart* createbarchart() const;

     QChart * createScatterChart() const;
    // void mousePressEvent(QMouseEvent*e) override;
private slots:
    void on_exit_clicked();

    void on_addbut_clicked();

    void on_deletebut_clicked();

    void on_pushButton_clicked();

    void on_find_id_clicked();

    void on_find_name_clicked();

    void on_findbut_clicked();

    void on_back_clicked();

    void on_findbut_2_clicked();

    void on_openfilebut_clicked();

    void on_back_2_clicked();

    void on_searchmul_clicked();

    void on_rankbut_clicked();



    void on_back_rank_clicked();


    void on_writebut_clicked();

    void on_updatebut_clicked();

    void on_add_ok_clicked();

    void on_add_back_clicked();

    void on_analysisbut_clicked();

    void on_back_3_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    int m_count=0;
    stutmp student[100];
    stu stusql[100];
    double m_ave=0;

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;//创建对象
    sqlqueryModel* model;
    QTableView*view;
    bool delete_ok=false;
    bool alreadygetstu=false;
    QString File_Path;
};
#endif // MAINWINDOW_H
