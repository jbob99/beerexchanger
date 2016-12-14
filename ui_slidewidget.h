/********************************************************************************
** Form generated from reading UI file 'slidewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDEWIDGET_H
#define UI_SLIDEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SlideWidget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *SlideWidget)
    {
        if (SlideWidget->objectName().isEmpty())
            SlideWidget->setObjectName(QStringLiteral("SlideWidget"));
        SlideWidget->resize(171, 290);
        pushButton = new QPushButton(SlideWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(6, 130, 113, 32));
        pushButton_2 = new QPushButton(SlideWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(6, 164, 113, 32));
        widget = new QWidget(SlideWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(SlideWidget);

        QMetaObject::connectSlotsByName(SlideWidget);
    } // setupUi

    void retranslateUi(QWidget *SlideWidget)
    {
        SlideWidget->setWindowTitle(QApplication::translate("SlideWidget", "Form", 0));
        pushButton->setText(QApplication::translate("SlideWidget", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("SlideWidget", "PushButton", 0));
        label->setText(QApplication::translate("SlideWidget", "Slide Widget", 0));
    } // retranslateUi

};

namespace Ui {
    class SlideWidget: public Ui_SlideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDEWIDGET_H
