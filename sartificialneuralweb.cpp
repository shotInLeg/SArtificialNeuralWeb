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
    QString path = QFileDialog::getOpenFileName( this, "Выбрать файл", ".", "*.*" );
    ui->ePathToImg->setText( path );
}

void SArtificialNeuralWeb::on_bLoad_clicked()
{
    QString fileName = ui->ePathToImg->text();
    QImage img( fileName );

    ui->imgWork->setPixmap( QPixmap::fromImage( img ) );

    QVector<NeuronAnswer> neurons = anw->overlaps( SANWK::neuronMapFromImage( img ) );

    ui->spRateUp->setMaximum( neurons.size() );

    printResults( ui->twResults, neurons );

    int max = -1;
    for( int i = 0; i < neurons.size(); i++ )
    {
        if( max == -1 )
            max = 0;

        if( neurons.at(max).rate < neurons.at(i).rate )
            max = i;
    }

    if( max != -1 )
    {
        ui->lBestResult->setText( neurons.at(max).name );
    }
}
///Страница обучения

void SArtificialNeuralWeb::on_bLernSelectImg_clicked()
{
    QString path = QFileDialog::getOpenFileName( this, "Выбрать файл", ".", "*.*" );
    ui->eLernPathToImg->setText( path );
}

void SArtificialNeuralWeb::on_bLernLoad_clicked()
{
    QString fileName = ui->eLernPathToImg->text();
    QImage img( fileName );

    ui->imgLern->setPixmap( QPixmap::fromImage( img ) );

    currentMap = SANWK::neuronMapFromImage( img );
    int b = 0;
    QVector<NeuronAnswer> neurons = anw->overlaps( currentMap );

    for( int i = 0; i < neurons.size(); i++ )
        qDebug() << neurons.at(i).id << " " << neurons.at(i).rate;

    printResults( ui->twLernResult, neurons );
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

void SArtificialNeuralWeb::printResults(QTableWidget *table, const QVector<NeuronAnswer> &neurons )
{
    table->clear();

    table->setRowCount( neurons.size() );

    for( int i = 0; i < neurons.size(); i++ )
    {
        table->setItem( i, 0, new QTableWidgetItem( neurons.at(i).id ) );
        table->setItem( i, 1, new QTableWidgetItem( neurons.at(i).name ) );
        table->setItem( i, 2, new QTableWidgetItem( QString::number( neurons.at(i).rate ) ) );
    }
}
