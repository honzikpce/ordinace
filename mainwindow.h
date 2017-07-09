#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>
#include <QtCore>
#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_rcLineEdit_textChanged(const QString &arg1);

    void on_surnameLineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *modelPacients = nullptr;
    QString baseQuerry;
};

#endif // MAINWINDOW_H
