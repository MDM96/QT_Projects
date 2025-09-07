#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QTextEdit>

class Notepad : public QMainWindow
{
    Q_OBJECT
public:
    explicit Notepad(QWidget *parent = nullptr);
signals:

private:
    QTextEdit* m_textEdit;
};

#endif // NOTEPAD_H
