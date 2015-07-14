#! /bin/sh
# /etc/init.d/MyApp
### BEGIN INIT INFO
# Provides:          MyApp.js
# Required-Start:    $remote_fs $syslog
# Required-Stop:     $remote_fs $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: Starts MyApp.js
# Description:       Start / stop MyApp.js at boot / shutdown.
### END INIT INFO
# If you want a command to always run, put it here
# Carry out specific functions when asked to by the system
case "$1" in start)
    echo "Starting MyApp.js"
    # run application you want to start
#    node /home/pi/app/MyApp/MyApp.js
   ;;
   stop)
    echo "Stopping MyApp.js"
    # kill application you want to stop
 #   killall MyApp.js
    ;;
  *)
    echo "Usage: /etc/init.d/MyApp {start|stop}"
    exit 1
esac
exit 0
