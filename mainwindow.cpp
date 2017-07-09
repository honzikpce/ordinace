#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create and open connection to the DB as a default DB
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("ordinace");
    db.setUserName("root");
    db.setPassword("");
    bool ok = db.open();
    if (!ok) qDebug() << "Chyba : Nepodarilo se pripojit databazi! "  << db.lastError().text();

}

MainWindow::~MainWindow()
{
    delete ui;
}
