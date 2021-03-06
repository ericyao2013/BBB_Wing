#ifndef FLIGHT_POINT_PACKET_H
#define FLIGHT_POINT_PACKET_H

#include "packet.h"

namespace domain
{
    class FlightPointPacket: public Packet
    {
    public:
        FlightPointPacket(double latitude = 0.0,
                          double longitude = 0.0,
                          float altitude = 0.0);

        double latitude;
        double longitude;
        float altitude;

        QDataStream& operator >>(QDataStream& stream) const override;
        QDataStream& operator <<(QDataStream& stream) override;

        static FlightPointPacket fromByteArray(const QByteArray& data);
    };
}

#endif // FLIGHT_POINT_PACKET_H
