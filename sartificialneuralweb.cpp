#include "sartificialneuralweb.h"
#include "ui_sartificialneuralweb.h"

SArtificialNeuralWeb::SArtificialNeuralWeb(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SArtificialNeuralWeb)
{
    ui->setupUi(this);
    anw = new SANWK;
}

SArtificialNeuralWeb::~SArtificialNeuralWeb()
{
    delete ui;
}

///Страница определения

void SArtificialNeuralWeb::on_bSelectImg_clicked()
{
    QString path = QFileDialog::getOpenFileName( this, "Выбрать файл", ".", "*.jpg" );
    ui->ePathToImg->setText( path );
}

void SArtificialNeuralWeb::on_bLoad_clicked()
{
    QString fileName = ui->ePathToImg->text();
    QImage img( fileName );

    ui->imgWork->setPixmap( QPixmap::fromImage( img ) );
}

///Страница обучения

void SArtificialNeuralWeb::on_bLernSelectImg_clicked()
{
    QString path = QFileDialog::getOpenFileName( this, "Выбрать файл", ".", "*.jpg" );
    ui->eLernPathToImg->setText( path );
}

void SArtificialNeuralWeb::on_bLernLoad_clicked()
{

}

void SArtificialNeuralWeb::on_bRateUp_clicked()
{
    int num = ui->spRateUp->value();
    QString id = ui->twLernResult->item(num, 0)->text();
    anw->extendNeuron( id, currentMap );
}

void SArtificialNeuralWeb::on_bCreateNew_clicked()
{
    QString name = ui->eNewName->text();
    anw->addNeuron( name, currentMap );
}
