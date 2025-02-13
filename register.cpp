#include "register.h"
#include<QMessageBox>
#include <QFile>
#include <QTextStream>

registerDialog::registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerDialog)
{
    ui->setupUi(this);
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/log/logimage/King.jpg").scaled(this->size())));
    setPalette(pal);

    //set the window title
    this->setWindowTitle("log in");

     //invisible
     ui->lineEdit_password->setEchoMode(QLineEdit::Password);
     ui->lineEdit_confirmPassword->setEchoMode(QLineEdit::Password);
}

registerDialog::~registerDialog()
{
delete ui;
}

void registerDialog::on_btn_confirm_clicked()
{
    QString account = ui->lineEdit_account->text().trimmed(); // 去除多余空格
    QString password = ui->lineEdit_password->text().trimmed();
    QString confirmPassword = ui->lineEdit_confirmPassword->text().trimmed();
    // confirm the password
    if (account.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "wrong", "it can't be empty！");
        return;
    }
    if (password != confirmPassword) {
        QMessageBox::warning(this, "fail", "the password is inconsistent！");
        return;
    }
    // check if the user has already exist

    //QFile file("user_data.txt");
 // very important if you want to run this program remmember to change this path in your computer!!!!
    QFile file("C:\\Users\\imagination\\Desktop\\CSC3002_project_new 8\\user_data.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::warning(this, "wrong", "can't open the data file！");
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");
        if (fields.size() == 2 && fields[0] == account) {
            QMessageBox::warning(this, "fail", "the account has already existed！");
            file.close();
            return;
        }
    }
    file.close();
    // put the data to the file
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "wrong", "can't open the data file！！");
        return;
    }
    QTextStream out(&file);
    out << account << " " << password << "\n"; // split it by space
    file.close();
    QMessageBox::information(this, "success", "a success registration！");
    this->close(); // sgut down the interface
}

void registerDialog::on_btn_back_clicked()
{
     this->close();
}
