class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12)
            hour = 0;

        double hourAngle = hour* 30 + minutes * 0.5;
        double minuteAngle = minutes* 6;

        double diff = abs(hourAngle- minuteAngle);

        return min(diff, 360.0 - diff);
    }
};