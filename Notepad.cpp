#include "Notepad.h"
#include <QMenuBar>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

Notepad::Notepad(QWidget *parent)
    : QMainWindow{parent}
{
    m_textEdit = new QTextEdit(this);
    setCentralWidget(m_textEdit);
    setWindowTitle("Notepad");
    resize(800,600);

    fileMenuImpl();
    editMenuImpl();
    formatMenuImpl();
    helpMenuImpl();

}

void Notepad::fileMenuImpl()
{
    fileMenu = menuBar()->addMenu(tr("&File"));

    newAction = new QAction(tr("&New"), this);
    openAction = new QAction(tr("&Open"), this);
    saveAction = new QAction(tr("&Save"), this);
    exitAction = new QAction(tr("E&xit"), this);

    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(exitAction);

    QObject::connect(newAction, &QAction::triggered, this, &Notepad::newFile);
    QObject::connect(openAction, &QAction::triggered, this, &Notepad::openFile);
    QObject::connect(saveAction, &QAction::triggered, this, &Notepad::saveFile);
    QObject::connect(exitAction, &QAction::triggered, this, &Notepad::exitApp);

}

void Notepad::newFile()
{
    m_textEdit->clear();
    setWindowTitle("Untiltled");
}

void Notepad::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");
    if(fileName.isEmpty())
        return;
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    QTextStream in(&file);
    m_textEdit->setPlainText(in.readAll());
    file.close();
    setWindowTitle(fileName);

}

void Notepad::saveFile()
{

}

void Notepad::exitApp()
{

}


void Notepad::editMenuImpl()
{
    editMenu = menuBar()->addMenu(tr("&Edit"));
}

void Notepad::formatMenuImpl()
{
    formatMenu = menuBar()->addMenu(tr("&Format"));
}

void Notepad::viewMenuImpl()
{
    viewMenu = menuBar()->addMenu(tr("&View"));
}

void Notepad::helpMenuImpl()
{
    helpMenu = menuBar()->addMenu(tr("&Help"));
}
