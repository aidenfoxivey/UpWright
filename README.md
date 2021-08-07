# UpWright Upright is a project made for XHacks '21. 

## What is UpWright?

UpWright is an Arduino-based fall detection system. Essentially, it started
from the concern that my parents might have when I was out cycling as a younger
child. Children having a good experience with independence through cycling is
very useful for development. Regardless, parents are always concerned for the
safety of their children, so I figured I would make a solution for it.

Using a builtin gyroscope, the transmitter module for UpWright monitors the
upright position and acceleration of a child's bike and sends a message over RF
if there is fall detected. Overall, we hope to foster independence for
children, but ensure that parents still feel good about it regardless of where
their children go.

## Who are you?

I'm Aiden Fox-Ivey, an incoming Computer Engineering student at the University
of Waterloo. I love to work on/learn about low level programming and physics.
In my spare time, I love to cycle and cook vegan food. If you want to reach out
to me, feel free to send an email via aiden[at]fox-ivey[dotcom]. If you'd like
to see my resume, feel free to do so at [foxivey.dev](https://foxivey.dev).

## How can I use UpWright?

Unfortunately, you'll need to buy some of the physical hardware in order to get
UpWright going. It is an Arduino project after all. In my implementation, I
opted to use an Arduino Mega2560 for the transmitter, since having IO was
important to me. Being perfectly honest, I'm sure you could get away with using
an Arduino Nano instead. The receiver in this case is built using an Arduino
Nano. 

As for the actual sensing parts, the project is made using an MPU6050 IMU chip
and an nRF24L01+ PA LNA wireless transceiver. I chose both parts just for their
relative cheapness, high power, and low energy usage. Ideally, the transmitter
is powered entirely using a small battery, making it safer and easier to
transport. 

As it stands, here are the parts needed (aside from solder/wires):
* 2 nRF24LO1+ PA LNA wireless transceivers
* 1 MPU6050 inertial measurement unit
* 1 Arduino Nano
* 1 Arduino Mega2560

Note that you can use regular nRF25LO1+ transceivers with PA/LNA functionality,
but the cost is range dropping by a factor of about 10. 

As for the software, you can download it all via this repository and then run
it via the Arduino GUI or the CLI. 
