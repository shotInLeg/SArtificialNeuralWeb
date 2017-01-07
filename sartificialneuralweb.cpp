#include "sartificialneuralweb.h"
#include "ui_sartificialneuralweb.h"

SArtificialNeuralWeb::SArtificialNeuralWeb(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SArtificialNeuralWeb)
{
    ui->setupUi(this);
}

SArtificialNeuralWeb::~SArtificialNeuralWeb()
{
    delete ui;
}
