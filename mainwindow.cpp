#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditPrimeiroNumero->setFocus();
    ui->lineEditPrimeiroNumero->setValidator(new QIntValidator(1,999));
    ui->lineEditSegundoNumero->setValidator(new QIntValidator(1,999));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonExecutar_clicked()
{
    QString saida;
    n1=new NNatural();
    n2=new NNatural();

    try
    {
        n1->setNumero(ui->lineEditPrimeiroNumero->text().toLongLong());
        n2->setNumero(ui->lineEditSegundoNumero->text().toLongLong());

        if(ui->lineEditPrimeiroNumero->text()=="" || ui->lineEditSegundoNumero->text()=="")
        {
            throw QString("Vazio.");
        }

        if(ui->lineEditPrimeiroNumero->text().toLongLong()==0||ui->lineEditSegundoNumero->text().toLongLong()==0)
        {
            throw QString("Invalido.");
        }

        //Primeiro numero:

        saida=QString::number(n1->quadradoPerfeito());
        ui->tableWidgetTabela->item(0,0)->setText(saida);

        saida=QString::fromStdString(n1->ToString(n1->calcularFatorial()));
        ui->tableWidgetTabela->item(1,0)->setText(saida);

        saida=QString::number(n1->numeroPerfeito());
        ui->tableWidgetTabela->item(2,0)->setText(saida);

        saida=QString::number(n1->capicua());
        ui->tableWidgetTabela->item(3,0)->setText(saida);

        saida=QString::number(n1->numeroPrimo());
        ui->tableWidgetTabela->item(4,0)->setText(saida);

        saida=QString::fromStdString(n1->mudarBase(2));
        ui->tableWidgetTabela->item(5,0)->setText(saida);

        saida=QString::fromStdString(n1->mudarBase(8));
        ui->tableWidgetTabela->item(6,0)->setText(saida);

        saida=QString::fromStdString(n1->mudarBase(16));
        ui->tableWidgetTabela->item(7,0)->setText(saida);

        // Segundo numero:

        saida=QString::number(n2->quadradoPerfeito());
        ui->tableWidgetTabela->item(0,1)->setText(saida);

        saida=QString::fromStdString(n2->ToString(n2->calcularFatorial()));
        ui->tableWidgetTabela->item(1,1)->setText(saida);

        saida=QString::number(n2->numeroPerfeito());
        ui->tableWidgetTabela->item(2,1)->setText(saida);

        saida=QString::number(n2->capicua());
        ui->tableWidgetTabela->item(3,1)->setText(saida);

        saida=QString::number(n2->numeroPrimo());
        ui->tableWidgetTabela->item(4,1)->setText(saida);

        saida=QString::fromStdString(n2->mudarBase(2));
        ui->tableWidgetTabela->item(5,1)->setText(saida);

        saida=QString::fromStdString(n2->mudarBase(8));
        ui->tableWidgetTabela->item(6,1)->setText(saida);

        saida=QString::fromStdString(n2->mudarBase(16));
        ui->tableWidgetTabela->item(7,1)->setText(saida);

        //Entre si

        saida=QString::fromStdString(n1->ToString(n1->calcularMDC(n2->getNumero())));
        ui->tableWidgetTabela->item(8,0)->setText(saida);
        ui->tableWidgetTabela->item(8,1)->setText(saida);

        saida=QString::fromStdString(n1->ToString(n1->calcularMMC(n2->getNumero())));
        ui->tableWidgetTabela->item(9,0)->setText(saida);
        ui->tableWidgetTabela->item(9,1)->setText(saida);

        saida=QString::number(n1->primoEntreSi(n2->getNumero()));
        ui->tableWidgetTabela->item(10,0)->setText(saida);
        ui->tableWidgetTabela->item(10,1)->setText(saida);

        ui->lineEditPrimeiroNumero->setEnabled(false);
        ui->lineEditSegundoNumero->setEnabled(false);
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditPrimeiroNumero->clear();
        ui->lineEditSegundoNumero->clear();
        ui->lineEditPrimeiroNumero->setFocus();
    }
}
