![Logo](https://i.imgur.com/ms3zFMX.jpg)

Yet another Arduino powered remote control car.
Published under the GNU GPL 3.0 license, you can find more info in the [LICENCE](https://github.com/lordfriky/Arduino-Car/blob/master/LICENSE) file.
This project was made by:
- Daniel Hernández Muñoz (me, [@lordfriky](https://github.com/lordfriky))
- David de León Gonzalez
- Yerik Martín García

Our app is on Google Play, you can find it [here](https://play.google.com/store/apps/details?id=appinventor.ai_14s165.Arduino&hl=es_419).
## _¿What **Arduino-Car** really is?_
This was our first project, but it isn't really ours, this is just a copy of [TheTeacherG](https://www.youtube.com/channel/UCc-vG493VqpLmL5gbnCvU4A)'s remote control Arduino car. (His source code can be found [here](https://www.dropbox.com/s/dsjw7u619affgaf/Carro%20Sensor%20de%20Distancia%20Bluetooth.txt?dl=0)).
More than the modified app, the project we present is an idea of safe transportation.
## _The idea_
When we created _Arduino-Car_ we thought about those people that, for some reason, couldn't drive a conventional car, so we wanted to make an alternative that even an eight years old child could drive. From that the idea of building _Arduino-Car_ was born.
## _The development_
When we made the project we made a divition of our tasks. David de León was in charge of software stuff, so he had to design the code for the project, but later he find the TheTeacherG's car and it was the most similar idea of what we wanted to make, so he just copied the code and made the modified app.

In the other hand, I was in charge of hardware stuff. In the beginning I made a copy of the car that TheTeacherG made, but after the first presentation I noted two problems; the autonomy and the stability. For the first problem I opted to use a custom batery made with laptop cells, and for the second problem I was adviced by Yerik Martín in use a new shell for the car, which would allow us to use an extra pair of engines. When we bought the new shell, no part of the code was changed, I just had to connect the second pair of engines with their couples.

As you may have guessed, Yerik Martín was (in part) the responsable for mechanical updates (he wasn't a part of the team when we presented the early first version), and more than that, he was responsable for the wonderful latest presentations; we are in debt with him.

The only update to the code happened before the last presentation of the project. David changed the interface of the app with our help to make it more striking and to remove a bug.
## _Prizes_
All the prizes this project has won have come from lasallian institutions, since it has not been carried beyond those borders. The first prize that _Arduino-Car_ won was a diploma from our school (Colegio Miguel de Bolonia). The project won the first place in the school's science fair and they took us to another science fair in the city of León, Guanajuato at the facilities of De La Salle Bajío University.

In that science fair we competed against a lot of interesting projects. But at the end we won the second place in our category. We believe that the great presentation made by Yerik Martín was essential in our victory. You can find evidence of this victory on [this page](http://bajio.delasalle.edu.mx/noticias/noticia.php?n=1906).

Lately, we were invited to an event in the city of Saltillo, Coahuila, now at the facilities of Colegio Ignacio Zaragoza. This wasn't a sciene fair as is, but it was an event where other lasallian schools showed the talent that their students have. From this event we got a trophy, which did not represent a specific place in a competition, but it was another acknowledgment of our work, and we proudly took it to our institution. That was the last presentation of the project.
## _Do your own_
The material you need is not too difficult to get. You will need an HC-05 or similar (as HC-06 or even HM-10 to get iOS compatibility) for app comunication, an L293D driver for motor-controlling and a HC-SR04 for safety purposes. You can find an image of the connections below or using the .fzz file on Fritzing. The image was made assuming that the HC-SR04 distance sensor goes in front of the car.

![Connections](https://i.imgur.com/oyGz5N4.png)

To put the Arduino board in order you just have to charge the code provided (the .ino file) with Arduino IDE before connecting everything else, nothing more. If you don't have it you can get it from the [Arduino page](https://www.arduino.cc/en/Main/Software).

If you want to modify the app or just know how it works you just have to import the .aia file to your MIT AppInventor account. ¡Feel free to make any modification you want!
## _Greetings_
This project wasn't supported a lot as our latest projects, but there's still three names that I want to mention:
- Javier Balan, fsc. For his big support to the project. His LinkedIn profile is right [here](https://mx.linkedin.com/in/javierbalan).
- Pascual de Alba Guillen. For his help in my tasks and for lenting me a couple of laptop battery cells.
- Teacher Fernanda Brown. For helping me translating this readme.
