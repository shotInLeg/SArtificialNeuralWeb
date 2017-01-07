#ifndef SARTIFICIALNEURALWEB_H
#define SARTIFICIALNEURALWEB_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>

#include "SArtificialNeuralWebKernel/sartificialneuralwebkernel.h"

namespace Ui {
class SArtificialNeuralWeb;
}

class SArtificialNeuralWeb : public QMainWindow
{
    Q_OBJECT

public:
    explicit SArtificialNeuralWeb(QWidget *parent = 0);
    ~SArtificialNeuralWeb();

private slots:
    void on_bSelectImg_clicked();

    void on_bLoad_clicked();

    void on_bLernSelectImg_clicked();

    void on_bLernLoad_clicked();

    void on_bRateUp_clicked();

    void on_bCreateNew_clicked();

private:
    Ui::SArtificialNeuralWeb *ui;
    SArtificialNeuralWebKernel * anw;
    NeuronMap currentMap;
};

#endif // SARTIFICIALNEURALWEB_H
