#!/bin/sh
#--------------------------------------------------------------------------
# Code generated by the SmartSoft MDSD Toolchain Version 0.10.2
# The SmartSoft Toolchain has been developed by:
#  
# ZAFH Servicerobotic Ulm
# Christian Schlegel (schlegel@hs-ulm.de)
# University of Applied Sciences
# Prittwitzstr. 10
# 89075 Ulm (Germany)
#
# Information about the SmartSoft MDSD Toolchain is available at:
# smart-robotics.sourceforge.net
# 
# Please do not modify this file. It will be re-generated
# running the code generator.
#--------------------------------------------------------------------------

	    
#######
## case
case "$1" in
	    
	    
#########################################################################################
## start
start)
    	
### protected region for startup code			
# PROTECTED REGION ID(CustomUserStartupCode) ENABLED START
# put your custom startup code here

echo -n "
Please choose a world to load:

(0) Hospital
(1) Racetrack World
(2) Cylinder World
(3) Corner World
(4) Wallfollower World
(5) Wallfollower World 2

> "

read world

case "$world" in
	0)
		echo "Starting world hospital"
		playercfg="smart_hospital_small.cfg"
		;;

	1)
		echo "Starting world racetrack"
		playercfg="smart_racetrack.cfg"
		;;

	2)
		echo "Starting world cylinder"
		playercfg="smart_laboratory.cfg"
		;;

	3)	
		echo "Starting world cornermap"
		playercfg="smart_cornermap.cfg"
		;;

	4)	
		echo "Starting world wallfollower"
		playercfg="smart_wallfollower.cfg"
		;;

	5)	
		echo "Starting world wallfollower2"
		playercfg="smart_wallfollower2.cfg"
		;;

	*)
		echo "Unknown World: '$world'"
		exit
		;;
esac

xterm -e "cd $SMART_ROOT/src/components/SmartPlayerStageSimulator/src/player_stage;robot-player $playercfg" &

sleep 4

# PROTECTED REGION END    	
	    
## start naming service
if [ `ps -Al | grep -c Naming_Service` -eq 1 ]
then 
	echo "shuttting down CORBA Naming Service ..."
	killall Naming_Service
	echo "starting CORBA Naming Service ..."
	$TAO_ROOT/orbsvcs/Naming_Service/Naming_Service -m 0 -ORBEndpoint iiop://0.0.0.0:9999 &
	echo "CORBA Naming Service is running!"
else 
	echo "starting CORBA Naming Service ..."
	$TAO_ROOT/orbsvcs/Naming_Service/Naming_Service -m 0 -ORBEndpoint iiop://0.0.0.0:9999 &
	echo "CORBA Naming Service is running!"
fi




## start components
echo "starting components..."
xterm -e $SMART_ROOT/bin/smartLaserBaseEmpty -filename=SmartLaserBaseEmpty.ini -ORBInitRef NameService=corbaloc:iiop:0.0.0.0:9999/NameService &
xterm -e $SMART_ROOT/bin/smartPlayerStageSimulator -filename=SmartPlayerStageSimulator.ini -ORBInitRef NameService=corbaloc:iiop:0.0.0.0:9999/NameService &

;; ## start
		
		
#########################################################################################
## stop
stop)

echo "kill all components..."
killall smartLaserBaseEmpty
killall smartPlayerStageSimulator
## TODO: ssh <username>@<target> 'killall xxx'

if [ `ps -Al | grep -c Naming_Service` -eq 1 ]
then 
  echo "shuttting down CORBA Naming Service ..."
  killall Naming_Service
  echo "CORBA Naming Service is down!"
else 
  echo "CORBA Naming Service is not running!"
fi




### protected region for shutdown code			
# PROTECTED REGION ID(CustomUserShutdownCode) ENABLED START
# put your custom shutdown code here	

killall robot-player
	
# PROTECTED REGION END    
;; ## stop
		
		
		
#########################################################################################
## default
*)
echo "Usage: $0 {start|stop}"
exit 1
;; ## default

esac
