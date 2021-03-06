// by commy2
#include "script_component.hpp"

private ["_distanceP1", "_directionP1", "_azimuthP1", "_inclinationP1", "_distanceP2", "_directionP2", "_azimuthP2", "_inclinationP2"];

_distanceP1 = GVAR(pData) select 0;
_directionP1 = GVAR(pData) select 1;
_azimuthP1 = _directionP1 select 0;
_inclinationP1 = _directionP1 select 1;

_distanceP2 = call FUNC(getDistance);
_directionP2 = call FUNC(getDirection);
_azimuthP2 = _directionP2 select 0;
_inclinationP2 = _directionP2 select 1;

private ["_relDirection", "_relDistance", "_relHeight", "_relLength", "_lenghtP1", "_lenghtP2", "_relAzimuth"];

_relDirection = sqrt ((_azimuthP1 - _azimuthP2) ^ 2 + (_inclinationP1 - _inclinationP2) ^ 2);
_relDistance = sqrt (_distanceP1 ^ 2 + _distanceP2 ^ 2 - 2 * _distanceP1 * _distanceP2 * cos _relDirection);
_relHeight = (sin _inclinationP1 * _distanceP1) - (sin _inclinationP2 * _distanceP2);
_relLength = sqrt (_relDistance ^ 2 - _relHeight ^ 2); if (str(_relLength) == "-1.#IND") then {_relLength = 0};

_lenghtP1 = cos _inclinationP1 * _distanceP1;
_lenghtP2 = cos _inclinationP2 * _distanceP2;
_relAzimuth = (sin _azimuthP2 * _lenghtP2 - sin _azimuthP1 * _lenghtP1) atan2 (cos _azimuthP2 * _lenghtP2 - cos _azimuthP1 * _lenghtP1);
if (_relAzimuth < 0) then {_relAzimuth = _relAzimuth + 360};

if (_distanceP1 < -999 || {_distanceP2 < -999}) exitWith {
    [-1000, -1000]    // return
};

[_relAzimuth, _relLength]
