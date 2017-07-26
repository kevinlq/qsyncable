#include "immutabletype1.h"

class ImmutableType1Data : public QSharedData
{
public:
    ImmutableType1Data() {
        value1 = 0;
    }

    int value1;

};

ImmutableType1::ImmutableType1() : data(new ImmutableType1Data)
{

}

ImmutableType1::ImmutableType1(const ImmutableType1 &rhs) : data(rhs.data)
{

}

ImmutableType1 &ImmutableType1::operator=(const ImmutableType1 &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

ImmutableType1::~ImmutableType1()
{

}

bool ImmutableType1::isSharedWith(const ImmutableType1 &other) const
{
    return data == other.data;
}

int ImmutableType1::value1() const
{
    return data->value1;
}

void ImmutableType1::setValue1(int value1)
{
    data->value1 = value1;
}
