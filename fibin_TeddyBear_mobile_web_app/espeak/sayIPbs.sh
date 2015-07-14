#! /bin/sh
# /etc/init.d/sayIPbs
## Some things that run always
# Carry out specific functions when asked to by the system

    echo "Starting script sayIPbs "
    espeak -v en "Please note My IP address"
    private=`hostname -I`
    string=" $private "
    echo $string | espeak -s 1 -v en-uk
    espeak -v en "And listening on port eight zero eight one"   
    
