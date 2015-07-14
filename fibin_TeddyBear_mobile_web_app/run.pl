#!use/bin/perl
use strict;
use warnings;

my $status0 = system("sudo /etc/init.d/nginx start");

#my $status = system("~/node/node-v0.10.2-linux-arm-pi/bin/node -v");
my $status5 = system("node socket.js");
my $status1 = system("node socket.js");
my $status2 = system("node socket.js");
my $status3 = system("node socket.js");
my $status4 = system("node socket.js");
print("Listening on port: 8081");
