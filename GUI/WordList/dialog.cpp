#include "dialog.h"
#include <string>
#include "ui_dialog.h"
#include "calculator.h"
#include <QDebug>
#include <QFileDialog>
#include <cstring>
#include <string>
#include <string.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    cal = new Calculator;

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_cbox_choose_currentIndexChanged(int index)
{
    cal->setWordsMost( index==1?false:true );
}

void Dialog::on_rbtn_circle_clicked(bool checked)
{
    cal->setAllowCircle(checked);
}

void Dialog::on_le_head_textChanged(const QString &arg1)
{
    char* ch;
    QByteArray ba = arg1.toLatin1();
    ch = ba.data();//注意上面和这句话不能合并，why??
    cal->setHeadChar(*ch);
}

void Dialog::on_le_tail_textChanged(const QString &arg1)
{
    char* ch;
    QByteArray ba = arg1.toLatin1();
    ch = ba.data();
    cal->setTailChar(*ch);
}

void Dialog::on_btn_go_clicked()
{
    QString text = ui->te_in->toPlainText();
    QByteArray ba = text.toLatin1();
    char *text_c;
    text_c = ba.data();
    cal->setTextIn(text_c);

    //调用cal的核心功能函数
    cal->core();
	ui->tb_out->setText(cal->getTextOut());

}



void Dialog::on_btn_import_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this,tr("choose file"));
    if(filepath!=NULL){
        QByteArray ba = filepath.toLatin1();
        char *filepath_c;
        filepath_c = ba.data();

        ui->le_path->setText(filepath);
        FILE *fp;
        fopen_s(&fp,filepath_c,"r");

        fseek(fp,0,SEEK_END);
        int filesize = ftell(fp);
        fseek(fp,0,SEEK_SET);

        char *buf = new char[filesize+1];
        int n = fread(buf,1,filesize,fp);
        if(n>0){
            buf[n] = 0;
            ui->te_in->setText(buf);
        }
        delete[] buf;
        fclose(fp);
    }
}

void Dialog::on_btn_export_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("save as"));
    QByteArray ba = filename.toLatin1();
    char *filepath_c;
    filepath_c = ba.data();

    QString text = ui->tb_out->toPlainText();
    QByteArray ba2 = text.toLatin1();
    char *text_c;
    text_c = ba2.data();

    if(filename.length()>0){
        FILE *fp;
        fopen_s(&fp, filepath_c, "w");
        fwrite(text_c,1,text.length(),fp);
    }
}
