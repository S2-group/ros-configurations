# Arduino Current Meter

## Arduino IDE

First of all, you must download the Arduino IDE from [here](https://www.arduino.cc/en/software).

Now, you must follow the steps bellow.

## Setting Up the Arduino Nano as Board

<img src="img/setup_nano.png">

## Configuring the Libraries

Our current meter device requires two libraries:

- Adafruit Sensor

- Adafruit IO

Here is how we install them in the IDE:

<img src="img/add_libraries.png">

## Configuring the Communication Port

For that, it is required that your Arduino Nano is connected to a USB port. 

## Uploading the Code

Supposing that you have already opened the <i>.ino</i> in this folder and you followed all the previous steps, you should be able to upload the code to the Arduino Nano.

To check whether the code is working, just push the button in your circuit, so the LED should be lit.

<img src="img/upload.png">

In case you have throubles in Linux, follow [this](https://forum.arduino.cc/t/permission-denied-on-dev-ttyacm0/475568).
