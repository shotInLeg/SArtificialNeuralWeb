#include "sartificialneuralwebkernel.h"


SArtificialNeuralWebKernel::Neuron::Neuron(const QString &id, const QString &name, const NeuronMap &map)
{
    this->_id = id;
    this->_name = name;
    this->_map = map;
}

QString SArtificialNeuralWebKernel::Neuron::id() const
{
    return this->_id;
}

QString SArtificialNeuralWebKernel::Neuron::name() const
{
    return this->_name;
}

int SArtificialNeuralWebKernel::Neuron::overlap(const NeuronMap &map) const
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

void SArtificialNeuralWebKernel::Neuron::extendNeuronMap(const NeuronMap &map)
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
