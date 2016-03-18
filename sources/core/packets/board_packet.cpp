#include "board_packet.h"

using namespace domain;

quint16 BoardDataPacket::crc()
{
    QByteArray array;
    QDataStream stream(&array, QIODevice::WriteOnly);
    stream << *this;
    return qChecksum(array.data(), array.length());
}

QDataStream& BoardDataPacket::operator >>(QDataStream& stream) const
{
    stream << latitude;
    stream << longitude;
    stream << altimeterAltitude;

    stream << velocity;
    stream << climb;

    stream << pitch;
    stream << roll;
    stream << yaw;

    stream << temperature;

    stream << altimeterStatus;
    stream << insStatus;
    stream << snsStatus;

    return stream;
}

QDataStream& BoardDataPacket::operator <<(QDataStream& stream)
{
    stream >> latitude;
    stream >> longitude;
    stream >> altimeterAltitude;

    stream >> velocity;
    stream >> climb;

    stream >> pitch;
    stream >> roll;
    stream >> yaw;

    stream >> temperature;

    stream >> altimeterStatus;
    stream >> insStatus;
    stream >> snsStatus;

    return stream;
}
