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

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void exitApp();
private:
    void fileMenuImpl();
    void editMenuImpl();
    void formatMenuImpl();
    void viewMenuImpl();
    void helpMenuImpl();

    QTextEdit* m_textEdit;

    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* formatMenu;
    QMenu* viewMenu;
    QMenu* helpMenu;

    QAction* newAction;
    QAction* openAction;
    QAction* saveAction;
    QAction* exitAction;
};

#endif // NOTEPAD_H
