#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BigNumbersLibrary.h"
#include <sstream>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//split the string into separate strings when detecting a space
std::vector<std::string> split(std::string str){
    std::vector<std::string> splitString;
    std::istringstream ss(str);
    do{
        std::string word;
        ss >> word;
        splitString.push_back(word);
    }while(ss);

    return splitString;
}

void MainWindow::on_actionAdd_triggered()
{

    QString text = ui->textEdit->toPlainText();
    //convert QString to string
    std::string input = text.toStdString();

    //convert the input string into separate strings
    std::vector<std::string> in = split(input);


    std::string num1 = in[0];
    std::string num2 = in[1];


    BigNumbers::MyBigNumbers a(num1);

    BigNumbers::MyBigNumbers b(num2);

    BigNumbers::MyBigNumbers c;

    c = a + b;

    QString result = QString::fromStdString(c.num);
    //clear the screen
    currentFile.clear();

    ui->textEdit->setText(result);

}

void MainWindow::on_actionSubtract_triggered()
{

    QString text = ui->textEdit->toPlainText();

    std::string input = text.toStdString();

    std::vector<std::string> in = split(input);


    std::string num1 = in[0];
    std::string num2 = in[1];

    BigNumbers::MyBigNumbers a(num1);

    BigNumbers::MyBigNumbers b(num2);

    BigNumbers::MyBigNumbers c;

    c = a - b;

    QString result = QString::fromStdString(c.num);
    //clear the screen
    currentFile.clear();

    ui->textEdit->setText(result);
}

void MainWindow::on_actionMultiply_triggered()
{

    QString text = ui->textEdit->toPlainText();

    std::string input = text.toStdString();

    std::vector<std::string> in = split(input);


    std::string num1 = in[0];
    std::string num2 = in[1];

    BigNumbers::MyBigNumbers a(num1);

    BigNumbers::MyBigNumbers b(num2);

    BigNumbers::MyBigNumbers c;

    c = a * b;

    QString result = QString::fromStdString(c.num);
    //clear the screen
    currentFile.clear();

    ui->textEdit->setText(result);
}

void MainWindow::on_actionDivide_triggered()
{

    QString text = ui->textEdit->toPlainText();

    std::string input = text.toStdString();

    std::vector<std::string> in = split(input);


    std::string num1 = in[0];
    std::string num2 = in[1];

    BigNumbers::MyBigNumbers a(num1);

    BigNumbers::MyBigNumbers b(num2);

    BigNumbers::MyBigNumbers c;

    c = a / b;

    QString result = QString::fromStdString(c.num);
    //clear the screen
    currentFile.clear();

    ui->textEdit->setText(result);

}

void MainWindow::on_actionModulo_triggered()
{

    QString text = ui->textEdit->toPlainText();

    std::string input = text.toStdString();

    std::vector<std::string> in = split(input);


    std::string num1 = in[0];
    std::string num2 = in[1];

    BigNumbers::MyBigNumbers a(num1);

    BigNumbers::MyBigNumbers b(num2);

    BigNumbers::MyBigNumbers c;

    c = a % b;

    QString result = QString::fromStdString(c.num);
    //clear the screen
    currentFile.clear();

    ui->textEdit->setText(result);

}
