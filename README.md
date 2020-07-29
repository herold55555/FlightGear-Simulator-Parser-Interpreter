Flight Simulator is a cpp program that control a plane From FlightGear Game.

Created by sheinnn and herold55555

Link to Repository

Installation
Please read flightgear installations carefully! It explicitly says how to download on which OS and where the files exist once you download onto your machine. **newest mac users with Catalina, you may have problems with the simulator. I suggest finding a parter without the newest version of Mac OS. Those in dualboot on ubuntu, you can install flightgear from the app store (software center) that ubuntu has.

Install FlightGear to install Flight Simulator.

Download the code from our repo.

In the FlightGear Game Folder : game/flightgear/Protocol add the file generic_small.xml. The file is in the asset directory (in the code you download from github). Note: You may need to change the permissions for copying this file to the folder. In my computer the folder is at : '/usr/share/games/flightgear/Protocol'

Open the FlightGear app, go to settings and to Additional Settings write : --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small
--telnet=socket,in,10,127.0.0.1,5402,tcp

Copy fly.txt From the Assets folder to the same folder as the main.cpp.

Usage

Resources:
