#ifndef SARTIFICIALNEURALWEBKERNEL_H
#define SARTIFICIALNEURALWEBKERNEL_H

#include <QString>
#include <QVector>
#include <QMap>
#include <QImage>
#include <QRgb>
#include <QColor>
#include <QDebug>

using NeuronMap = QVector< QVector< int > >;

struct NeuronAnswer
{
    QString id;
    QString name;
    int rate;

    NeuronAnswer(){}

    NeuronAnswer( const QString& id, const QString& name, int rate )
    {
        this->id = id;
        this->name = name;
        this->rate = rate;
    }
};

class SArtificialNeuralWebKernel
{
public:
    class Neuron
    {
    public:
        Neuron()
        {}

        Neuron( const QString& id, const QString& name, const NeuronMap& map )
        {
            this->_id = id;
            this->_name = name;
            this->_map = map;
        }

        QString id() const
        {
            return this->_id;
        }

        QString name() const
        {
            return this->_name;
        }

        int overlap( const NeuronMap& map ) const
        {
            if( map.size() != this->_map.size() || this->_map.size() < 1 )
                return -1;

            for( int i = 0; i < map.size(); i++ )
                if( map.at(i).size() != this->_map.at(i).size() || map.at(i).size() != map.at(0).size() )
                    return -1;

            int overlapRes = 0;

            for( int i = 0; i < map.size(); i++ )
            {
                for( int j = 0; j < map.at(i).size(); j++ )
                {
                    int n = this->_map.at(i).at(j);
                    int m = map.at(i).at(j);

                    if( abs(m-n) < 120 )
                    {
                        if( m < 250 )
                            overlapRes++;
                    }
                }
            }

            return overlapRes;
        }

        void extendNeuronMap( const NeuronMap& map )
        {
            if( map.size() != this->_map.size() || this->_map.size() < 1 )
                return;

            for( int i = 0; i < map.size(); i++ )
                if( map.at(i).size() != this->_map.at(i).size() || map.at(i).size() != map.at(0).size() )
                    return;

            for( int i = 0; i < map.size(); i++ )
            {
                for( int j = 0; j < map.at(i).size(); j++ )
                {
                    int n = this->_map.at(i).at(j);
                    int m = map.at(i).at(j);

                    if( m != 0 || n != 0 )
                    {
                        if( m < 250 )
                            n = round( (n+(n+m)/2)/2 );
                        this->_map[i][j] = n;
                    }
                }
            }
        }

    private:
        QString _id;
        QString _name;
        NeuronMap _map;
    };

    SArtificialNeuralWebKernel(){}

    QVector< NeuronAnswer > overlaps( const NeuronMap& map )
    {
        QVector< NeuronAnswer > res;

        for( auto it = this->_neuralWeb.begin(); it != this->_neuralWeb.end(); it++ )
        {
            res.push_back( NeuronAnswer( it.key(), it.value().name(), it.value().overlap( map ) ) );
        }

        return res;
    }

    void extendNeuron( const QString& id, const NeuronMap& map )
    {
        this->_neuralWeb[ id ].extendNeuronMap( map );
    }

    void addNeuron( const QString& name, const NeuronMap& map )
    {
        QString id = name + QString::number( this->_neuralWeb.size()+1 );

        this->_neuralWeb[id] = Neuron( id, name, map );
    }

    static NeuronMap neuronMapFromImage( const QImage& image )
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

protected:
    QMap<QString, Neuron> _neuralWeb;
};

using SANWK = SArtificialNeuralWebKernel;

#endif // SARTIFICIALNEURALWEBKERNEL_H
