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

#ifndef HKD_KALMAN_H
#define HKD_KALMAN_H

class KalmanFilter {
public:
  KalmanFilter();

  float *KalmanAnglePR =
      new float[2]; // Kalman angle values //? P: Pitch, R: Roll
  float *KalmanUncertainityAnglePR =
      new float[2]; // Kalman uncertainity angle values //? P: Pitch, R: Roll
	float Kalman1DOutput[2] = {0,0}; //?  1: Angle Prediction, 2: Uncertainity Angle Prediction

	void kalman_1d(float, float, float, float);  
};

#endif