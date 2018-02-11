![Logo](https://i.imgur.com/ms3zFMX.jpg)

Yet another Arduino powered remote control car.
Published under the GNU GPL 3.0 license, you can find more info in the [LICENCE](https://github.com/lordfriky/Arduino-Car/blob/master/LICENSE) file.
This project was made by:
- Daniel Hernández Muñoz (me, [@lordfriky](https://github.com/lordfriky))
- David de León Gonzalez
- Yerik Martín García

Our app is on Google Play, you can find it [here](https://play.google.com/store/apps/details?id=appinventor.ai_14s165.Arduino&hl=es_419).
## _¿What really is **Arduino-Car**?_
This was our first project, but it isn't really ours, this is just a copy of [TheTeacherG](https://www.youtube.com/channel/UCc-vG493VqpLmL5gbnCvU4A)'s remote control Arduino car. (Him source code can be find [here](https://www.dropbox.com/s/dsjw7u619affgaf/Carro%20Sensor%20de%20Distancia%20Bluetooth.txt?dl=0)).
More than the modified app, the thing that we presented was an idea of safe transportation.
## _The idea_
When we create _Arduino-Car_ we think about those people that, for some reason, couldn't drive a conventional car, so we want to make an alternative that even an 8 years old children could drive. From that the idea of building _Arduino-Car_ was born.
## _The development_
When we make the project we made a divition of our tasks. David de León was in charge of software stuff, so he has to make the code for the project, but lately he find the TheTeacherG's car and it was the most similar idea of we want it to make, so he just copy the code and made the modified app.

In the other hand, I was in carge of hardware stuff. In the beginning I made a (most likely) copy of the car that TheTeacherG made, but after the first presentation I note 2 problems, the autonomy and the stability. For the first problem I opted for use a custom batery made by laptop cells, and for the second problem I was adviced by Yerik Martín in use a new shell for the project, that that let us to use another pair of motors. When we buy the new shell none of the code was changed, I just have to connect the second's motors with his couples were.

As you may have guessed, Yerik Martín was (in part) the responsable for mechanical updates (he wasn't a part of the team when we pressent the early first version), and more than that, he has the responsable of the wonderful latests presentations, we are indebted with him.

The only uptate to the code was before the last presentation of the project. David change the interface of the app with our help for doing it more striking and remove a bug.
## _Prizes_
All the prizes wonned were from lasallian institutions, since the project wasn't carried beyond those borders. The first prize that _Arduino-Car_ won was a diploma from our school (Colegio Miguel de Bolonia). The project won the first place in the school's science fair and they took us to another science fair in the city of León, Guanajuato at the facilities of De La Salle Bajío university.

In that science fair we compete against a lot of interesting projects. But at the end we won the second place of our category. We believe that the great presentation maked by Yerik Martín was essential in our victory. You can find a prove of this win on [this page](http://bajio.delasalle.edu.mx/noticias/noticia.php?n=1906).

Lately, we were invited to an event in the city of Saltillo, Coahuila, now at the facilities of Colegio Ignacio Zaragoza. This wasn't a sciene fair as is, but it was an event where other lasallian schools share some of the talents that his students have. From this event we get a trophy, that doesn't have a place as is, but it was another acknowledgment of our work, and we proudly take it to our institution. That was the last presentation of the project.
## _Make your own one_
The needed material isn't too difficult to get. The needs an HC-05 or similar (as HC-06 or even HM-10 to get iOS compatibility) for app comunication, an L293D driver for motor controlling and a HC-SR04 for safety purposes. You can find an image of the connections above here or using the .fzz file on Fritzing. The image was made assuming that the HC-SR04 distance sensor goes in the front of the car.

![Connections](https://i.imgur.com/oyGz5N4.png)

For putting the Arduino in order you just have to charge the code provided (the .ino file) with Arduino IDE, nothing else. If you don't have it you can get it from the [Arduino page](https://www.arduino.cc/en/Main/Software).

If you want to modify the app or just know how it works you just have to import the .aia file to your MIT AppInventor account. ¡Feel free to make any modification you want!
## _Greetings_
This project wasn't supported a lot as our latest projects, but there's still two names that I want to mention:
- Javier Balan, fsc. For his big support to the project. His LinkedIn profile is right [here](https://mx.linkedin.com/in/javierbalan).
- Pascual de Alba Guillen. For his help in my tasks and for lenting me a couple of laptop battery cells.
