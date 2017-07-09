#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QtDebug>
#include <QSqlError>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create and open connection to the DB as a default DB
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("ordinace");
    db.setUserName("ordinace");
    db.setPassword("ordinace");
    bool ok = db.open();
    if (ok) qDebug() << "Pripojeni k databazi - OK.";
    else qDebug() << "Chyba : Nepodarilo se pripojit databazi! "  << db.lastError().text();

    // create model for pacients
    modelPacients = new QSqlQueryModel(this);
    baseQuerry = "SELECT rc, CONCAT(UPPER(prijmeni), ' ', jmeno, ' ', titulPred, ' ', titulZa) AS fullName FROM pacient";
    modelPacients->setQuery(baseQuerry);

    //bind widgets to model
    ui->tableViewPacients->setModel(modelPacients);

    // adjust table view appearance
    ui->tableViewPacients->setAlternatingRowColors(true);
    QFont newFont("Tahoma", 10, QFont::Normal, false);
    ui->tableViewPacients->setFont(newFont);
    ui->tableViewPacients->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete modelPacients;
}

void MainWindow::on_rcLineEdit_textChanged(const QString &arg1)
{
    QSqlQuery query;
    query.prepare(baseQuerry + " WHERE rc LIKE :rc AND prijmeni LIKE :surname");
    query.bindValue(":rc", ui->rcLineEdit->text() + "%");
    query.bindValue(":surname", ui->surnameLineEdit->text() + "%");


    query.exec();
    modelPacients->setQuery(query);

}

void MainWindow::on_surnameLineEdit_textChanged(const QString &arg1)
{
    QSqlQuery query;
    query.prepare(baseQuerry + " WHERE rc LIKE :rc AND prijmeni LIKE :surname");
    query.bindValue(":rc", ui->rcLineEdit->text() + "%");
    query.bindValue(":surname", ui->surnameLineEdit->text() + "%");


    query.exec();
    modelPacients->setQuery(query);
}
