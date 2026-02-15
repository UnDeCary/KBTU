package com.zlup.practice2;

public class Time {
    int hour;
    int minute;
    int second;

    public Time(int hour, int minute, int second) {
        if (hour < 0 || hour > 23) {
            System.out.println("Invalid hour");
            return;
        }
        else if (minute < 0 || minute > 59) {
            System.out.println("Invalid minute");
            return;
        }
        else if (second < 0 || second > 59) {
            System.out.println("Invalid second");
            return;
        }

        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public String toUniversal() {
        StringBuilder time = new StringBuilder();
        createTimeString(time, hour);

        return time.toString();
    }

    public String toStandard() {
        StringBuilder time = new StringBuilder();
        int displayHour = hour % 13;
        displayHour = hour > 12 ? displayHour + 1 : displayHour;
        createTimeString(time, displayHour);
        time.append(" ").append(hour > 12 ? "PM" : "AM");

        return time.toString();
    }

    private void createTimeString(StringBuilder time, int displayHour) {
        if (displayHour < 10) {
            time.append("0");
        }
        time.append(displayHour).append(':');
        if (minute < 10) {
            time.append("0");
        }
        time.append(minute).append(':');
        if (second < 10) {
            time.append("0");
        }
        time.append(second);
    }


    public Time add(Time time) {
        hour = (hour + time.hour) % 24;
        minute = (minute + time.minute) % 60;
        second = (second + time.second) % 60;
        return this;
    }

}
