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
using namespace std;
class  sqlqueryModel;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void refresh();
    void scorecal(int n,double b,double c);
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

    void getallstu();

private:
    int m_count=0;
    stutmp student[100];
    stu stusql[100];

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;//创建对象
    sqlqueryModel* model;
    QTableView*view;
    bool delete_ok=false;
    bool alreadygetstu=false;
};
#endif // MAINWINDOW_H
