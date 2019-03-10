/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *le_path;
    QPushButton *btn_import;
    QTextEdit *te_in;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QComboBox *cbox_choose;
    QRadioButton *rbtn_circle;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *le_head;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *le_tail;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_export;
    QTextBrowser *tb_out;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_go;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(705, 361);
        verticalLayout_5 = new QVBoxLayout(Dialog);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        le_path = new QLineEdit(Dialog);
        le_path->setObjectName(QString::fromUtf8("le_path"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_path->sizePolicy().hasHeightForWidth());
        le_path->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(10);
        le_path->setFont(font);

        horizontalLayout_3->addWidget(le_path);

        btn_import = new QPushButton(Dialog);
        btn_import->setObjectName(QString::fromUtf8("btn_import"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        btn_import->setFont(font1);

        horizontalLayout_3->addWidget(btn_import);


        verticalLayout_3->addLayout(horizontalLayout_3);

        te_in = new QTextEdit(Dialog);
        te_in->setObjectName(QString::fromUtf8("te_in"));
        te_in->setMinimumSize(QSize(250, 250));
        te_in->setMaximumSize(QSize(250, 250));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(12);
        te_in->setFont(font2);

        verticalLayout_3->addWidget(te_in);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        cbox_choose = new QComboBox(Dialog);
        cbox_choose->addItem(QString());
        cbox_choose->addItem(QString());
        cbox_choose->setObjectName(QString::fromUtf8("cbox_choose"));
        cbox_choose->setFont(font1);
        cbox_choose->setEditable(false);

        verticalLayout->addWidget(cbox_choose);

        rbtn_circle = new QRadioButton(Dialog);
        rbtn_circle->setObjectName(QString::fromUtf8("rbtn_circle"));
        rbtn_circle->setFont(font1);

        verticalLayout->addWidget(rbtn_circle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        le_head = new QLineEdit(Dialog);
        le_head->setObjectName(QString::fromUtf8("le_head"));
        le_head->setMinimumSize(QSize(40, 0));
        le_head->setMaximumSize(QSize(40, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(13);
        le_head->setFont(font3);
        le_head->setMaxLength(1);

        horizontalLayout->addWidget(le_head);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        le_tail = new QLineEdit(Dialog);
        le_tail->setObjectName(QString::fromUtf8("le_tail"));
        le_tail->setMinimumSize(QSize(40, 0));
        le_tail->setMaximumSize(QSize(40, 16777215));
        le_tail->setFont(font3);
        le_tail->setMaxLength(1);

        horizontalLayout_2->addWidget(le_tail);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 4);
        verticalLayout->setStretch(1, 4);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);

        verticalLayout_4->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        verticalLayout_4->setStretch(1, 2);
        verticalLayout_4->setStretch(2, 4);

        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btn_export = new QPushButton(Dialog);
        btn_export->setObjectName(QString::fromUtf8("btn_export"));
        btn_export->setFont(font1);

        verticalLayout_2->addWidget(btn_export);

        tb_out = new QTextBrowser(Dialog);
        tb_out->setObjectName(QString::fromUtf8("tb_out"));
        tb_out->setMinimumSize(QSize(250, 250));
        tb_out->setMaximumSize(QSize(250, 250));
        tb_out->setFont(font2);

        verticalLayout_2->addWidget(tb_out);


        horizontalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        btn_go = new QPushButton(Dialog);
        btn_go->setObjectName(QString::fromUtf8("btn_go"));
        btn_go->setMinimumSize(QSize(300, 0));
        btn_go->setMaximumSize(QSize(300, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(24);
        font4.setBold(true);
        font4.setWeight(75);
        btn_go->setFont(font4);
        btn_go->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_4->addWidget(btn_go);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_4);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "WordList", nullptr));
        btn_import->setText(QApplication::translate("Dialog", "Import", nullptr));
        cbox_choose->setItemText(0, QApplication::translate("Dialog", "Most Words", nullptr));
        cbox_choose->setItemText(1, QApplication::translate("Dialog", "Most Chars", nullptr));

        cbox_choose->setCurrentText(QApplication::translate("Dialog", "Most Words", nullptr));
        rbtn_circle->setText(QApplication::translate("Dialog", "allow circle", nullptr));
        label->setText(QApplication::translate("Dialog", "set head char\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Dialog", "set tail char\357\274\232", nullptr));
        btn_export->setText(QApplication::translate("Dialog", "Export", nullptr));
        btn_go->setText(QApplication::translate("Dialog", "GO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
