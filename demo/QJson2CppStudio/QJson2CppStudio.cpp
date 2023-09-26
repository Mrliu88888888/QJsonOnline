#include "QJson2CppStudio.h"
#include "QJson2Cpp.h"
#include <qdebug.h>
#include <qfileinfo.h>
#include <qmessagebox.h>
#include <qevent.h>
#include <qmimedata.h>
#ifdef _WIN32
#pragma execution_character_set("utf-8")
#endif

QJson2CppStudio::QJson2CppStudio(QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    this->setAcceptDrops(true);

    connect(ui.cbIsClass, &QCheckBox::stateChanged, this, [this](int state) {
        qDebug() << state;
        const QString text = Qt::CheckState::Checked == state ?
            "类名称（默认值MyClass）"
            : "结构体名称（默认值MyStruct）";
        ui.leObjName->setPlaceholderText(text);
        });

    connect(ui.leInFile, &QLineEdit::textChanged, this, [this](const QString& text) {
        QFileInfo inFileInfo(text);
        const auto outfilename = inFileInfo.suffix() == "json" ?
            inFileInfo.path() + '/' + inFileInfo.baseName() + ".cpp" : text + ".cpp";
        ui.leOutFile->setText(outfilename);
        });

    connect(ui.btnConv, &QPushButton::clicked, this, [this]() {
        if (!QFileInfo(ui.leInFile->text()).isFile()) {
            QMessageBox::information(this, "", "输入文件未找到，或者不是文件！");
            return 1;
        }
        if (QFileInfo::exists(ui.leOutFile->text())) {
            if (QMessageBox::information(this, "", "输出文件已经存在，是否替换此文件") != QMessageBox::Ok) {
                return 2;
            }
        }

        const auto res = json2cpp(ui.leInFile->text(), ui.leOutFile->text(), ui.leObjName->text(), ui.cbIsClass->isChecked());
        if (res != 0)
        {
            QMessageBox::information(this, "", QString("res: %1").arg(res));
        }
        });

    ui.cbIsClass->setChecked(true);
}

QJson2CppStudio::~QJson2CppStudio()
{}

void QJson2CppStudio::dragEnterEvent(QDragEnterEvent* event)
{
    qDebug() << "dragEnterEvent";
    if (event->mimeData()->hasUrls()) {
        for (const auto& url : event->mimeData()->urls()) {
            if (url.isLocalFile()) {
                if (QFileInfo(url.toLocalFile()).isFile()) {
                    event->acceptProposedAction();
                    break;
                }
            }
        }
    }
}

void QJson2CppStudio::dropEvent(QDropEvent* event)
{
    qDebug() << "dropEvent";
    for (const auto& url : event->mimeData()->urls()) {
        const auto filename = url.toLocalFile();
        if (QFileInfo(filename).isFile()) {
            ui.leInFile->setText(filename);
            break;
        }
    }
}
