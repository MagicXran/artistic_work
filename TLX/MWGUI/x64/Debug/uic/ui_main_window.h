/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_windowClass
{
public:
    QWidget *centralWidget;
    QLineEdit *l1;
    QLineEdit *l2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *main_windowClass)
    {
        if (main_windowClass->objectName().isEmpty())
            main_windowClass->setObjectName(QString::fromUtf8("main_windowClass"));
        main_windowClass->resize(600, 400);
        centralWidget = new QWidget(main_windowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        l1 = new QLineEdit(centralWidget);
        l1->setObjectName(QString::fromUtf8("l1"));
        l1->setGeometry(QRect(150, 80, 113, 20));
        l2 = new QLineEdit(centralWidget);
        l2->setObjectName(QString::fromUtf8("l2"));
        l2->setGeometry(QRect(150, 130, 113, 20));
        main_windowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(main_windowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        main_windowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(main_windowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        main_windowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(main_windowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        main_windowClass->setStatusBar(statusBar);

        retranslateUi(main_windowClass);

        QMetaObject::connectSlotsByName(main_windowClass);
    } // setupUi

    void retranslateUi(QMainWindow *main_windowClass)
    {
        main_windowClass->setWindowTitle(QCoreApplication::translate("main_windowClass", "main_window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_windowClass: public Ui_main_windowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
