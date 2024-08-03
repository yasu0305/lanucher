#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), process(new QProcess(this)) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QLabel *label = new QLabel("Enter the command to launch:", this);
    layout->addWidget(label);

    commandInput = new QLineEdit(this);
    layout->addWidget(commandInput);

    QPushButton *launchButton = new QPushButton("Launch", this);
    layout->addWidget(launchButton);

    killButton = new QPushButton("Kill", this);
    layout->addWidget(killButton);
    killButton->setEnabled(false);  // 初期状態ではKillボタンを無効にする

    connect(launchButton, &QPushButton::clicked, this, &MainWindow::launchProgram);
    connect(killButton, &QPushButton::clicked, this, &MainWindow::killProgram);
}

MainWindow::~MainWindow() {}

void MainWindow::launchProgram() {
    QString command = commandInput->text();
    QStringList arguments;
    arguments << "-e" << command;
    process->start("terminal", arguments);

    if (process->waitForStarted()) {
        killButton->setEnabled(true);  // プロセスが正常に起動したらKillボタンを有効にする
    }
}

void MainWindow::killProgram() {
    if (process->state() == QProcess::Running) {
        process->terminate();
        process->waitForFinished();
        killButton->setEnabled(false);  // プロセスが終了したらKillボタンを無効にする
    }
}
