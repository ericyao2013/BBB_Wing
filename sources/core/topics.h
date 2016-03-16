#ifndef TOPICS_H
#define TOPICS_H

#include <QStringList>

namespace topics
{
    const QString altimeterStatus = "alt_status";
    const QString altimeterTemperature = "alt_temperature";
    const QString altimeterAltitude = "alt_altitude";

    const QString insStatus = "ins_status";
    const QString insTemperature = "ins_temperature";
    const QString insPitch = "ins_pitch";
    const QString insRoll = "ins_roll";
    const QString insYaw = "ins_yaw";

    const QString snsStatus = "sns_status";
    const QString snsSatellites = "sns_satellites";
    const QString snsFix = "sns_fix";
    const QString snsLatitude = "sns_latitude";
    const QString snsLongitude = "sns_longitude";
    const QString snsYaw = "sns_yaw";
    const QString snsVelocity = "sns_velocity";
    const QString snsAltitude = "sns_altitude";
    const QString snsClimb = "sns_climb";

    const QString transceiverStatus = "tr_status";
    const QString transceiverPps = "tr_pps";
    const QString transceiverBad = "tr_bad";

    const QStringList boardTopics = {
        altimeterStatus, altimeterAltitude, altimeterTemperature,
        insStatus, insTemperature, insPitch, insRoll, insYaw,
        snsStatus, snsSatellites, snsFix, snsLatitude, snsLongitude,
        snsYaw, snsVelocity, snsAltitude, snsClimb
    };
}

#endif // TOPICS_H