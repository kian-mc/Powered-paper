<H1>Powered Paper</H1>

![PoweredPaper](https://github.com/kian-mc/Powered-paper/assets/71298052/a3fbfd22-64fd-43ab-8dcc-69cbbb79491d)


Powered Paper is a paper airplane that has a motion-activated motor attached that powers the paper airplane to fly farther
and with more power. It is meant as a toy that can be modified and played with with relative ease. The Basic design consists of 4 parts: The Airplane,
The Control Board, The Motor, and The Battery. The Airplane is a specially folded paper airplane designed to house all the components required. It is just made of cardstock. 
The control board is a custom-soldered PCB that houses the components of the craft. The components include a microcontroller, 
an accelerometer, a potentiometer, an LED, and a MOSFET. The microcontroller is a Seeeduino XIAO which runs all the code and 
integrates all the systems. The accelerometer is an MPU board that allows for real-time acceleration data through SCL and SDA pins. This requires a lot of custom
code to run well. The potentiometer is the Human Input Device and acts as the setting for how long you want the motor to stay on. The ranges are 
0 - 2.5 seconds. The LED is the output display which indicates when the controller is in flight mode and when the motor is powered. The Mosfet is
what switches the motor on and off and is used due to the amps drawn by the motor.


![wiringDiagram](https://github.com/kian-mc/Powered-paper/assets/71298052/857d869a-0414-479c-a28a-539125ce5726)


The motor is a 3.7 V drone motor I found on amazon that works with a propeller to provide thrust to the airplane. 
As it is, right now the motor has adequate power however it struggles with power consumption as it uses a lot of power.


![motor](https://github.com/kian-mc/Powered-paper/assets/71298052/b188ac22-1763-44e2-9b40-cb3e3702fb80)

The battery is a simple 3.7V 500mA Lithium Ion battery. I chose it due to its great power density to weight and it functions relatively reliably. 

![battery](https://github.com/kian-mc/Powered-paper/assets/71298052/0b8ab2c0-e501-401c-93ca-cb52841a5fed)


I think that the success of this device could have improved with better time management and a more realistic goal from the start. I originally wanted to control it with a remote however I ran into an issue with communicating via radio and switched the control to just be powered. I ran into issues with the center of mass and thrust if these were improperly balanced then the plane would fly very unreliably. Another bug issue is the power to weight as all the components are very heavy as is right now and it is causing a lack of performance due to this. The last big issue is the mounting of components as I have found it difficult to secure something to paper.

**Part cost layout**

| Part                                               | Cost  | Link                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
|----------------------------------------------------|-------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| MPU accelerometer                                  | 2.33  | https://www.amazon.com/QCCAN-GY-6500-MPU-6500-Gyroscope-Accelerometer/dp/B0B74QXZS8/ref=sr_1_7?crid=Z2GGN19FXQDS&dib=eyJ2IjoiMSJ9.nQ-HfKOFyZoszrV3cxLK6kLM6Av2m3NkmoEK2RJcsVT1ILpfwX1TDp6YgWED-utGwfI0IRk6a0IACh3W4vGIxzOkbRusnHLGsCglMAUhqZKYIManFEmGJl3w_U63NEzjzHTUuazjrnRxpdMFV9za57n7U63YtLXkGa9lSG-EJuKZ9576IuqhA3fVRnGZYOEllm9TcYa4Z94c1KHkYUgYA8Ha8nKQhaHdQKugTwQB_UyzG88sc_MsE7rReVLR02OVOjFkyzF3yeK5AjJ2hgZhzGbMq869KLGet1kTZQezVRk.JVdizRNd3LFu4EDLe9eCKfwvQ5svyZuaCbDjvxRtUUU&dib_tag=se&keywords=MPU&qid=1715790613&sprefix=mpu%2Caps%2C156&sr=8-7                                                   |
| Seeeduino XIAO                                     | 8.33  | https://www.amazon.com/Seeeduino-Smallest-Microcontroller-Interfaces-Compatible/dp/B08745JBRP/ref=sr_1_3?crid=35GPV6XC8794L&dib=eyJ2IjoiMSJ9.md6V_z9qq3vmg7ja9QtDNLn1sBeexeXVc0ICoaxmC_qs-lNOaokoS2pEchWlguuVSUfnPTJTOkR98c_XLsz7bQbRj-oEG5tDDwUY58lujxw7pmzee8Gast5hAocJyqS-NnQV6CDhlzO7up-3mKKg2QApEWivBeVleTQJy4BQzIUWo5Lcu0-MJssqSDC6qFeKw5xK8NfpfXtkyNw0gJXocI2gKkwrN8Ry8v-ETchpAG0.4OJWgDdDjvcHHX7e9ESq2hJdk9MWpi2baujbvLCiJJg&dib_tag=se&keywords=seeeduino%2BXIAO&qid=1715790705&sprefix=seeeduino%2Bxiao%2Caps%2C129&sr=8-3&th=1                                                                         |
| Motor                                              | 3     | https://www.amazon.com/YoungRC-Coreless-Brushed-Propeller-Quadcopter/dp/B078NL9KQQ/ref=sr_1_4?crid=358X1PJN9RROA&dib=eyJ2IjoiMSJ9.5RLye2TcluxM-qG3ntxphPo5e21vZ8tpOzngJVG8DTwqkZ9LxG6zIr1yeCBATh_FNxEgZ9SK43JxPJtJ0zwF_ARG2d3rFz-7CtVGITDqvy3rKvbK1UeOm1b4Bk76S0IykntDGj1DIQfeog_XrWYkoCwtJJAWLSzNlTtb5QChPFaYIR3z2qRJgnv0b5IgP8L9_XJZj-XyRIPvDmt73-hJO4Zi7BdJeIHzED1QkgJiR7Ft00AUjcIBftLA5o8wwrj95NTVh4iuhS7sSOm71tk1r91hGZUEXfG_gRxZ-g5_Yck.P9s-DDqFRK8tnHhnQyTL8yQ_O2zqUh4I03C93CVy7dk&dib_tag=se&keywords=drone+motor+dc&qid=1715790881&sprefix=drone+motor+dc%2Caps%2C170&sr=8-4                             |
| 500 mA Lithium ion Battery                         | 8.99  | https://www.amazon.com/Liter-energybattery-Rechargeable-601452-Connector/dp/B09GFS1VFR/ref=sr_1_6?crid=1TKDWSVKO6YFC&dib=eyJ2IjoiMSJ9.aFA9yjX-SZ44y8dKgWF7bqdE29nLbmJkqCzgbD9eB3nzZx2L7NT_qBGM--B00ZEH_8eWMoz6frd6JR8BlCXVFpukYKh7ff9dT5dz-7P7wcdT7aRaCZSCbFX1P9SO0r8u67Ky54810b4UC27ullVDVB42PjP85EMaOixgAREKxlEvE73BAaZOmJzMJsqfUzu96eQW04Omq92L03snrYknuD1l2CgSM3LJO8JNaUnjLGIpe0RSr7aBxyARLgX7W0_8LxCMqVJjV-Nng0DwKR93qQy8XQ7QtK9tOgRTMUrwaGY.t9sFQl9pROQEjSIxMKMGhnRnvgu3p0eVNymVchTSQdk&dib_tag=se&keywords=500+ma+lithium+ion+battery&qid=1709238713&sprefix=500+ma+lithium+ion+battery%2Caps%2C126&sr=8-6 |
| Mosfet, Wiring, PCB, solder, Potentiometer, Header | 15    | The lab                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
**Total Cost: $37.65**


One of the biggest lessons I learned from this capstone is that of time management. I tended to procrastinate during the middle stages when I was having difficulty with the radios and it resulted in a product that could have been a lot better. Another big lesson I learned was choosing a realisticly achievable project. I kind of anticipated things to go a lot smoother and so I had to remove the controller and instead just have it powered.

**How to build this**

First solder headers that match a MPU and an XIAO on a custom PCB

Then solder Mosfet and LED on

Now solder the (mosfet stuff) and a 220-ohm resistor to the negative side of the LED

Solder VCC and GND into the MPU

Now solder all the data pins from the components into the XIAO headers

Solder a battery connector on and solder positive directly to the XIAO for the VIN pin

Solder a potentiometer and connect it to power and ground.

connect the middle pin to the XIAO

solder the motor connector and connect it to the Mosfet

Now upload the code to the XIAO

Fold any paper airplane you would like but leave a cutout for the control board in the middle

Glue the board and motor in and attach the battery

Now you have the current prototype.




