//  Created by Jacob Greenberg-Bell on 1/15/20.
//  Copyright © 2020 Jake Greenberg-Bell. All rights reserved.

//  This program calculates how far El Chavo del 8 is from Acapulco and how long he
//  has to walk

#include <iostream>
using namespace std;

int main() {
    const float TOTAL_DISTANCE = 377.6; // distance from Mexico City to Acapulco
    const int WALKING_SPEED_KMH = 5; // estimated speed at which El Chavo del 8 will walk
    const int SECONDS_PER_DAY = 86400;
    const int SECONDS_PER_HOUR = 3600;
    const int SECONDS_PER_MINUTE = 60;
    float distanceTraveled = 0;
    int daysLeft = 0;
    int hoursLeft = 0;
    int minutesLeft = 0;
    int secondsLeft = 0;
    
    cout << "How many kilometers have you traveled so far?\n";
    cin >> distanceTraveled;
    float distanceRemaining = TOTAL_DISTANCE - distanceTraveled; /* distance left is simply the difference between the total and traveled distances */
    cout << "Uh-oh! You still have to walk " << distanceRemaining << " kilometers.\n";
    
    int totalSecondsLeft = (distanceRemaining / WALKING_SPEED_KMH * SECONDS_PER_HOUR) + 0.5; /* to calculate total seconds left, distance is divided by walking speed, which gives total hours left. This is then multiplied by seconds per hour to get total seconds left. 0.5 is added at end to ensure correct rounding of int. */
    
    daysLeft =  totalSecondsLeft / SECONDS_PER_DAY; // calculates days of walking left
    totalSecondsLeft = totalSecondsLeft % SECONDS_PER_DAY; /* modulus used to find remaining seconds, process is repeated for hours, minutes, and seconds */

    hoursLeft =  totalSecondsLeft / SECONDS_PER_HOUR;
    totalSecondsLeft %= SECONDS_PER_HOUR;

    minutesLeft =  totalSecondsLeft / SECONDS_PER_MINUTE;
    totalSecondsLeft %= SECONDS_PER_MINUTE;

    secondsLeft = totalSecondsLeft;
    
    cout << "If you walk 5km/h, that's going to take " << daysLeft << " days, "
         << hoursLeft << " hours, " << minutesLeft << " minutes, " << "and about "
         << secondsLeft << " seconds.\n";
    return 0;
    }
