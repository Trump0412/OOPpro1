#include "rank.h"
#include "ui_rank.h"

scoresort::scoresort(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::scoresort)
{
    ui->setupUi(this);
}

scoresort::~scoresort()
{
    delete ui;
}
