#pragma once

#include <QtWidgets/QWidget>
#include "ui_QJson2CppStudio.h"

class QJson2CppStudio : public QWidget
{
    Q_OBJECT

public:
    QJson2CppStudio(QWidget* parent = nullptr);
    ~QJson2CppStudio();

protected:
    virtual void dragEnterEvent(QDragEnterEvent* event) override;
    virtual void dropEvent(QDropEvent* event) override;

private:
    Ui::QJson2CppStudioClass ui;
};
