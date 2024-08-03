#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QProcess>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void launchProgram();
    void killProgram();

private:
    QLineEdit *commandInput;
    QProcess *process;
    QPushButton *killButton;
};

#endif // MAINWINDOW_H
