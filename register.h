#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include "ui_register.h"

namespace Ui {
class registerDialog;
}

class registerDialog: public QDialog
{
    Q_OBJECT

public:
    explicit registerDialog(QWidget *parent = nullptr);
    ~registerDialog();

private:
    Ui::registerDialog *ui;
private slots:
    void on_btn_confirm_clicked();
    void on_btn_back_clicked();
};

#endif // REGISTER_H
