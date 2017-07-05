#include "sartificialneuralwebkernel.h"


QVector<NeuronAnswer> SArtificialNeuralWebKernel::overlaps(const NeuronMap &map)
{
    QVector< NeuronAnswer > res;

    for( auto it = this->_neuralWeb.begin(); it != this->_neuralWeb.end(); it++ )
    {
        res.push_back( NeuronAnswer( it.key(), it.value().name(), it.value().overlap( map ) ) );
    }

    return res;
}

void SArtificialNeuralWebKernel::extendNeuron(const QString &id, const NeuronMap &map)
{
    this->_neuralWeb[ id ].extendNeuronMap( map );
}

void SArtificialNeuralWebKernel::addNeuron(const QString &name, const NeuronMap &map)
{
    QString id = name + QString::number( this->_neuralWeb.size()+1 );

    this->_neuralWeb[id] = Neuron( id, name, map );
}

NeuronMap SArtificialNeuralWebKernel::neuronMapFromImage(const QImage &image)
{
    qDebug() << image.height() << " " << image.width();

    NeuronMap map( image.height() );

    for( int i = 0; i < map.size(); i++ )
    {
        map[i].resize( image.width() );

        int b = 0;
        for( int j = 0; j < map.at(i).size(); j++ )
        {
            // 0.21 R + 0.71 G + 0.07 B
            int R = QColor( image.pixel(j, i) ).red();
            int G = QColor( image.pixel(j, i) ).green();
            int B = QColor( image.pixel(j, i) ).blue();
            map[i][j] = (0.21*R) + (0.71*G) + (0.07*B);
        }
    }

    return map;
}
