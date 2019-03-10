#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "calculator.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_cbox_choose_currentIndexChanged(int index);

    void on_rbtn_circle_clicked(bool checked);

    void on_le_head_textChanged(const QString &arg1);

    void on_le_tail_textChanged(const QString &arg1);

    void on_btn_go_clicked();

    void on_btn_import_clicked();

    void on_btn_export_clicked();

private:
    Ui::Dialog *ui;
    Calculator *cal;
};

#endif // DIALOG_H
