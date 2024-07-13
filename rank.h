#ifndef RANK_H
#define RANK_H

#include <QDialog>

namespace Ui {
class scoresort;
}

class scoresort : public QDialog
{
    Q_OBJECT

public:
    explicit scoresort(QWidget *parent = nullptr);
    ~scoresort();

private:
    Ui::scoresort *ui;
};

#endif // RANK_H
