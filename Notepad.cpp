#include "Notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow{parent}
{
    m_textEdit = new QTextEdit(this);
    setCentralWidget(m_textEdit);
    setWindowTitle("Notepad");
    resize(800,600);
}
