#include "sartificialneuralweb.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SArtificialNeuralWeb w;
    w.show();

    return a.exec();
}
