/************************************************************************
                                                                        Source
Code Form License Notice
                                                -------------------------------------------

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.

If it is not possible or desirable to put the notice in a particular
file, then You may include the notice in a location (such as a LICENSE
file in a relevant directory) where a recipient would be likely to look
for such a notice.
*************************************************************************/

#include "HKDKalmanFilter.h"
#include <Arduino.h>

KalmanFilter::KalmanFilter() {
	*KalmanAnglePR = 0;
	*KalmanUncertainityAnglePR = 2*2;
}

void KalmanFilter::kalman_1d(float KalmanState, float KalmanUncertainity, float KalmanInput, float KalmanMeasurement) {
	KalmanState = KalmanState + 0.004 * KalmanInput;
	KalmanUncertainity = KalmanUncertainity + 0.004 * 4 * 4;
	float KalmanGain = KalmanUncertainity / (KalmanUncertainity + 3 * 3);
	KalmanState = KalmanState + KalmanGain * (KalmanMeasurement - KalmanState);
	KalmanUncertainity = (1 - KalmanGain) * KalmanUncertainity;
	Kalman1DOutput[0] = KalmanState;
	Kalman1DOutput[1] = KalmanUncertainity;
}
