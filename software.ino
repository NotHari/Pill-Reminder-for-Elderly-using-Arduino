#include <Wire.h>
#include <hd44780.h>                     
#include <hd44780ioClass/hd44780_I2Cexp.h>

// Initialise LCD Object for 20 x 4 LCD I2C
hd44780_I2Cexp lcd;

// Pins to Set and Reset alarms
int onePillButton = 2;
int twoPillButton = 3;
int threePillButton = 4;
int reset = 5;

// Pins to Change Time
int mButton = 6;
int hButton = 7;

// Pins to send Output
int LED = 12;
int buzzer = 13;

// Default Time
int h = 7, m = 59, s = 55;

// Alarm State
int flag = 0;

void setup()
{
    lcd.begin(20, 4);
    pinMode(buzzer, OUTPUT);
    pinMode(hButton, INPUT);
    pinMode(mButton, INPUT);
    pinMode(LED, OUTPUT);
    pinMode(onePillButton, INPUT);
    pinMode(twoPillButton, INPUT);
    pinMode(threePillButton, INPUT);
    pinMode(reset, INPUT);
    lcd.setCursor(0, 0);
    lcd.print("   Welcome to Our   ");
    lcd.setCursor(0, 1);
    lcd.print("   Pill Reminder   ");
    lcd.setCursor(0, 3);
    lcd.print("     By Group 3     ");
    delay(3000);
    lcd.clear();
}

// To print time with formatting
void printTime()
{
    String time = String(" Time : ");
    if(h == 0)
      time = String(time + "00:");
    else if(h == 12)
      time = String(time +  "12:");
    else if (h % 12 < 10)
        time = String(time + "0" + h % 12 + ":");
    else
        time = String(time + h % 12 + ":");

    if (m < 10)
        time = String(time + "0" + m + ":");
    else
        time = String(time + m + ":");

    if (s < 10)
        time = String(time + "0" + s);
    else
        time = String(time + s);

    if (h < 12)
        time = String(time + " AM");
    else
        time = String(time + " PM");

    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(time);
}

// To increment time after every second
void timeIncrement()
{
    // One Minute has passed
    if (s == 59)
    {
        // One Hour has passed
        if (m == 59)
        {
            // One Day has passed
            if (h == 23)
            {
                h = 0, m = 0, s = 0;
            }
            else
            {
                m = 0;
                h += 1;
                s = 0;
            }
        }
        else
        {
            m += 1;
            s = 0;
        }
    }
    else
    {
        s += 1;
    }
}

// To set Time
void setTime(int hButtonState, int mButtonState)
{
    // Increments Hour
    if (hButtonState == 1)
    {
        if (h == 23)
        {
            h = 0;
        }
        else
        {
            h += 1;
        }
        hButtonState = 0;
    }

    // Increments Minute
    if (mButtonState == 1)
    {
        if (m == 59)
        {
            m = 0;
        }
        else
        {
            m += 1;
        }
        mButtonState = 0;
    }
}

// To set Alarm
void setAlarm(int onePillButtonState, int twoPillButtonState, int threePillButtonState, int resetState)
{
    // Sets 8AM alarm
    if (onePillButtonState == 1)
    {
        flag = 1;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" One alarm set for ");
        lcd.setCursor(0, 1);
        lcd.print("     8AM daily     ");
        lcd.setCursor(0, 2);
        lcd.print("   Get Well Soon   ");
    }
    // Sets 8AM and 8PM alarms
    else if (twoPillButtonState == 1)
    {
        flag = 2;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" Two alarms set for ");
        lcd.setCursor(0, 1);
        lcd.print(" 8AM and 8PM daily ");
        lcd.setCursor(0, 2);
        lcd.print("   Get Well Soon   ");
    }
    // Sets 8AM, 2PM and 8PM alarms
    else if (threePillButtonState == 1)
    {
        flag = 3;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Three alarms set for");
        lcd.setCursor(0, 1);
        lcd.print("8AM, 2PM & 8PM daily");
        lcd.setCursor(0, 2);
        lcd.print("   Get Well Soon   ");
    }

    // Stops Alarm
    if (resetState == 1)
    {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("     Alarm Off     ");
        lcd.setCursor(0, 2);
        lcd.print("   Stay Hydrated   ");
        digitalWrite(LED, LOW);
        digitalWrite(buzzer, LOW);
    }
}

// To play alarm
void playAlarm()
{
    // Plays 8AM alarm
    if (flag != 0) 
    {
        if (h == 8 && m == 0 && s == 0)
        {
            digitalWrite(LED, HIGH);
            digitalWrite(buzzer, HIGH);
            lcd.clear();
            lcd.setCursor(0, 1);
            lcd.print("   Have 8AM Pill   ");
            lcd.setCursor(0, 2);
            lcd.print("   Get Well Soon   ");
        }
    }

    // Plays 8PM Alarm
    if (flag == 2 || flag == 3)
    {
        if (h == 20 && m == 0 && s == 0)
        {
            digitalWrite(LED, HIGH);
            digitalWrite(buzzer, HIGH);
            lcd.clear();
            lcd.setCursor(0, 1);
            lcd.print("   Have 8PM Pill   ");
            lcd.setCursor(0, 2);
            lcd.print("   Get Well Soon   ");
        }
    }

    // Plays 2PM Alarm
    if (flag == 3)
    {
        if (h == 14 && m == 0 && s == 0)
        {
            digitalWrite(LED, HIGH);
            digitalWrite(buzzer, HIGH);
            lcd.clear();
            lcd.setCursor(0, 1);
            lcd.print("   Have 2PM Pill   ");
            lcd.setCursor(0, 2);
            lcd.print("   Get Well Soon   ");
        }
    }
}

void loop()
{
    int hButtonState = digitalRead(hButton);
    int mButtonState = digitalRead(mButton);
    int onePillButtonState = digitalRead(onePillButton);
    int twoPillButtonState = digitalRead(twoPillButton);
    int threePillButtonState = digitalRead(threePillButton);
    int resetState = digitalRead(reset);

    printTime();
    timeIncrement();
    setTime(hButtonState, mButtonState);
    setAlarm(onePillButtonState, twoPillButtonState, threePillButtonState, resetState);
    playAlarm();

    delay(1000);
}
