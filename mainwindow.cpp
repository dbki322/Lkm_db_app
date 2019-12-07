#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qApp->addLibraryPath(qApp->applicationDirPath()+"/plugins");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("LKM2.db");
    db.open();
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Show0()
{
    QSqlTableModel * model = new QSqlTableModel;
        model->setTable("Client");
        model->setHeaderData(0, Qt::Horizontal, "Код клиента");
        model->setHeaderData(1, Qt::Horizontal, "ФИО");
        model->setHeaderData(2, Qt::Horizontal, "Номер телефона");
        model->setHeaderData(3, Qt::Horizontal, "Эл.почта");
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->show();
}
void MainWindow::Show1()
{
    QSqlTableModel * model = new QSqlTableModel;
        model->setTable("Cranes");
        model->setHeaderData(0, Qt::Horizontal, "Название");
        model->setHeaderData(1, Qt::Horizontal, "Цена");
        model->setHeaderData(2, Qt::Horizontal, "Марка");
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->show();}

void MainWindow::Show2(){
    QSqlTableModel * model = new QSqlTableModel;
        model->setTable("LKM_services");
        model->setHeaderData(0, Qt::Horizontal, "Услуга");
        model->setHeaderData(1, Qt::Horizontal, "Цена");
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->setModel(model);
        ui->tableView->show();
}
void MainWindow::Show3(){
    QSqlTableModel * model = new QSqlTableModel;
        model->setTable("Orders");
        model->setHeaderData(0, Qt::Horizontal, "Код заказа");
        model->setHeaderData(1, Qt::Horizontal, "Код клиента");
        model->setHeaderData(2, Qt::Horizontal, "Название крана");
        model->setHeaderData(3, Qt::Horizontal, "Дата заказа");
        model->setHeaderData(4, Qt::Horizontal, "Услуга");
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->setModel(model);
        ui->tableView->show();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QTextEdit *textEdit = new QTextEdit(ui->textEdit);
    QTextEdit *textEdit_2 = new QTextEdit(ui->textEdit_2);
    QTextEdit *textEdit_3 = new QTextEdit(ui->textEdit_3);
    QTextEdit *textEdit_4 = new QTextEdit(ui->textEdit_4);
    QLabel *label6 = new QLabel(ui->label_6);
    QLabel *label7 = new QLabel(ui->label_7);
    QLabel *label8 = new QLabel(ui->label_8);
    QLabel *label9 = new QLabel(ui->label_9);

    QSqlQuery query;

    switch(index){
    case 0:
    {
        ui->textEdit->setEnabled(true);
        ui->textEdit_2->setEnabled(true);
        ui->textEdit_3->setEnabled(true);
        ui->textEdit_4->setEnabled(false);
        ui->label_6->setText("ФИО");
        ui->label_7->setText("Номер телефона");
        ui->label_8->setText("Эл.почта");
        ui->label_9->setText("");
        Show0();

        break;
    }
    case 1:
    {   ui->textEdit->setEnabled(true);
        ui->textEdit_2->setEnabled(true);
        ui->textEdit_3->setEnabled(true);
        ui->textEdit_4->setEnabled(false);
        ui->label_6->setText("Название");
        ui->label_7->setText("Цена");
        ui->label_8->setText("Марка");
        ui->label_9->setText("");
        Show1();

        break;
    };
    case 2:
    {
        ui->textEdit->setEnabled(true);
        ui->textEdit_2->setEnabled(true);
        ui->textEdit_3->setEnabled(false);
        ui->textEdit_4->setEnabled(false);
        ui->label_6->setText("Услуга");
        ui->label_7->setText("Цена");
        ui->label_8->setText("");
        ui->label_9->setText("");
        Show2();

        break;
    };
    case 3:
    {
        ui->textEdit->setEnabled(true);
        ui->textEdit_2->setEnabled(true);
        ui->textEdit_3->setEnabled(true);
        ui->textEdit_4->setEnabled(true);
        ui->label_6->setText("Код клиента");
        ui->label_7->setText("Название крана");
        ui->label_8->setText("Дата заказа");
        ui->label_9->setText("Услуга");
        Show3();

        break;
    };
  };
};


void MainWindow::on_pushButton_clicked()
{
    int index = ui->comboBox->currentIndex();
    switch(index){
    case 0:
    {
        QSqlQuery query;
        query.prepare("INSERT INTO  Client (full_name_client, phone_number_client, email_client) VALUES(?, ?, ?)");
        query.addBindValue(ui->textEdit->toPlainText());
        query.addBindValue(ui->textEdit_2->toPlainText());
        query.addBindValue(ui->textEdit_3->toPlainText());
        query.exec();
        Show0();

        break;
    }
    case 1:
    {
        QSqlQuery query;
        query.prepare("INSERT INTO  Cranes (name_cranes, price_cranes, mark_cranes) VALUES(?, ?, ?)");
        query.addBindValue(ui->textEdit->toPlainText());
        query.addBindValue(ui->textEdit_2->toPlainText());
        query.addBindValue(ui->textEdit_3->toPlainText());
        query.exec();
        Show1();

        break;
    }
    case 2:
    {
        QSqlQuery query;
        query.prepare("INSERT INTO  LKM_services (type_services, price_services) VALUES(?, ?)");
        query.addBindValue(ui->textEdit->toPlainText());
        query.addBindValue(ui->textEdit_2->toPlainText());
        query.exec();
        Show2();

        break;
    }
    case 3:
    {
        QSqlQuery query;
        query.prepare("INSERT INTO  Orders (id_client_orders, crane_name_orders, date_orders,type_of_service_orders) VALUES(?, ?, ?, ?)");
        query.addBindValue(ui->textEdit->toPlainText());
        query.addBindValue(ui->textEdit_2->toPlainText());
        query.addBindValue(ui->textEdit_3->toPlainText());
        query.addBindValue(ui->textEdit_4->toPlainText());
        query.exec();
        Show3();

        break;
    }
  }
}

void MainWindow::on_pushButton_2_clicked()
{
    QTextEdit *textEdit_5 = new QTextEdit(ui->textEdit_5);
    QString txt = ui->textEdit_5->toPlainText();
    int number= txt.toInt()-1;
    int index = ui->comboBox->currentIndex();
    switch(index){
    case 0:
    {
        QSqlTableModel * model = new QSqlTableModel;
        model->setTable("Client");
        model->setHeaderData(0, Qt::Horizontal, "Код клиента");
        model->setHeaderData(1, Qt::Horizontal, "ФИО");
        model->setHeaderData(2, Qt::Horizontal, "Номер телефона");
        model->setHeaderData(3, Qt::Horizontal, "Эл.почта");
        model->select();
        model->removeRow(number);
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->show();

        break;
    }
    case 1:
    {
        QSqlTableModel * model = new QSqlTableModel;
        model->setTable("Cranes");
        model->setHeaderData(0, Qt::Horizontal, "Название");
        model->setHeaderData(1, Qt::Horizontal, "Цена");
        model->setHeaderData(2, Qt::Horizontal, "Марка");
        model->select();
        model->removeRow(number);
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->show();

        break;
    }
    case 2:
    {
        QSqlTableModel * model = new QSqlTableModel;
        model->setTable("LKM_services");
        model->setHeaderData(0, Qt::Horizontal, "Услуга");
        model->setHeaderData(1, Qt::Horizontal, "Цена");
        model->select(); model->removeRow(number);model->select();
        ui->tableView->setModel(model);
        ui->tableView->setModel(model);
        ui->tableView->show();

        break;
    }
    case 3:
    {
        QSqlTableModel * model = new QSqlTableModel;
        model->setTable("Orders");
        model->setHeaderData(0, Qt::Horizontal, "Код заказа");
        model->setHeaderData(1, Qt::Horizontal, "Код клиента");
        model->setHeaderData(2, Qt::Horizontal, "Название крана");
        model->setHeaderData(3, Qt::Horizontal, "Дата заказа");
        model->setHeaderData(4, Qt::Horizontal, "Услуга");
        model->select();
        model->removeRow(number);
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->show();

        break;
    }
  }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit_7->clear();
    QSqlQuery query;
    query.exec("SELECT crane_name_orders, date_orders, type_of_service_orders FROM Orders WHERE id_client_orders="+ui->textEdit_6->toPlainText());
    while (query.next())
    {
        QString crane = query.value(0).toString();
        QString date = query.value(1).toString();
        QString type = query.value(2).toString();
        ui->textEdit_7->insertPlainText("Краны: "+crane+" Дата заказа: "+date+" Тип услуги: "+type+"\n");
    }
}
