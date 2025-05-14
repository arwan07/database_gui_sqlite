#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectToDatabase();

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");

    setupModel();
}

MainWindow::~MainWindow()
{
    delete model;
    db.close();
    delete ui;
}

void MainWindow::connectToDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QCoreApplication::applicationDirPath() + "/company.db";
    db.setDatabaseName(path);
//    db.setDatabaseName("data.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "Failed to connect to database.");
    }
}

void MainWindow::setupModel()
{
    model = new QSqlTableModel(this, db);
//    model->setTable("users");
    model->setTable("employees");

    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    ui->tableView->setModel(model);
//    ui->tableView->hideColumn(0); // hide id column
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::on_addButton_clicked()
{
//    QString name = ui->nameLineEdit->text();
//    if (name.isEmpty()) return;
    QString empid = ui->EmpId_lineEdit->text();
    QString firstname = ui->FirstName_lineEdit->text();
    QString dept = ui->Dept_lineEdit->text();
    QString salary = ui->Salary_lineEdit->text();



    QSqlQuery query;
//    query.prepare("INSERT INTO users (name) VALUES (:name)");
//    query.bindValue(":name", name);
//    ,department_id,salary
//    ,:department_id,:salary
    query.prepare("INSERT INTO employees (employee_id,first_name) VALUES (:empid,:firstname)");
    query.bindValue(":empid", empid);
    query.bindValue(":firstname", firstname);
//    query.bindValue(":department_id", dept);
//    query.bindValue(":salary", salary);
    qDebug() << "Executing query:" << query.lastQuery();
    if (!query.exec()) {
        QMessageBox::warning(this, "Error", "Failed to insert data.");
    } else {
        model->select();
//        ui->nameLineEdit->clear();
        ui->EmpId_lineEdit->clear();
        ui->FirstName_lineEdit->clear();
        ui->Dept_lineEdit->clear();
        ui->Salary_lineEdit->clear();
    }
}

void MainWindow::on_editButton_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) return;

//    QString newName = ui->nameLineEdit->text();
//    if (newName.isEmpty()) return;
    QString newempid = ui->EmpId_lineEdit->text();
    QString newfirstname = ui->FirstName_lineEdit->text();
    QString newdept = ui->Dept_lineEdit->text();
    QString newsalary = ui->Salary_lineEdit->text();

    int row = index.row();
    model->setData(model->index(row, 0), newempid); // column 0 = empid
    model->setData(model->index(row, 1), newfirstname); // column 1 = name
    model->setData(model->index(row, 10), newdept); // column 10 = name
    model->setData(model->index(row, 7), newsalary); // column 7 = name

    if (!model->submitAll()) {
        QMessageBox::warning(this, "Error", "Failed to update data.");
    } else {
//       ui->nameLineEdit->clear();
        ui->EmpId_lineEdit->clear();
        ui->FirstName_lineEdit->clear();
        ui->Dept_lineEdit->clear();
        ui->Salary_lineEdit->clear();
    }
}
