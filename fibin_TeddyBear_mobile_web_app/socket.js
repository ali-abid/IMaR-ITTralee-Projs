require('shelljs/global');
echo('Inside socket.js');
var app = require('http').createServer(handler)
  , io = require('socket.io').listen(app)
  , fs = require('fs')
  , Gpio = require('onoff').Gpio
  , b3 = new Gpio(23, 'in', 'both') // Currently the "start" button
  , b4 = new Gpio(17, 'in', 'both') // 	
  , b1 = new Gpio(18, 'in', 'both')
  , b2 = new Gpio(22, 'in', 'both')
 

io.set('log level', 1);
app.listen(8081);

function handler (req, res) {
  fs.readFile(__dirname + '/index.html',
  function (err, data) {
    if (err) {
      res.writeHead(500);
      return res.end('Error loading index.html');
    }

    res.writeHead(200);
    res.end(data);
  });
}
var n;
function randomButtons(){
    min = 1;
    max = 4
    n = Math.floor(Math.random() * (max - min + 1)) + min;
    //document.write(n);
     
     switch(n){
     	case 1:
			exec('espeak -v en "Press Left hand"');  // Button 1
        	break;
        case 2:
			exec('espeak -v en "Press Right hand"'); // Button 2
        	break;
        case 3:
        	exec('espeak -v en "Press Left leg"');  // Button 3
			break;
        case 4:
        	exec('espeak -v en "Press Right leg"'); // Button 4
        	break;
        default:
             document.write("\n Error");
     }
   }
  setInterval(function(){ 
    //code goes here that will be run every 5 seconds.
      randomButtons();
	  
	}, 10000);
 
 b4.watch(function(err, value) {
	if(value ==1){
	         exec('espeak -v en "You Pressed Right Leg"');
		if(n==4){
			if (err) exit();
			io.sockets.emit('b4', {v:1});
			echo('inside b4 function');
			exec('espeak -v en "Which is correct"');
			io.sockets.emit('b4' , {v:0});

		}else{
			io.sockets.emit('w', {v:1});
			echo('inside b4 But wrong');
			exec('espeak -v en "Which is wrong"');
			io.sockets.emit('w', {v:0});
		}
	}else{
		echo('ignore if button read twice ');
	}
    	
 });

b3.watch(function(err, value){
if (value ==1){
	exec('espeak -v en "You Pressed Left Leg"');
	if(n==3){
		if (err) exit();
		io.sockets.emit('b3', {v:1});
		echo('inside b3 function');
		exec('espeak -v en "Which is correct"');
		io.sockets.emit('b3' , {v:0});

	}else{
		io.sockets.emit('w', {v:1});
		echo('inside b3 But wrong');
		exec('espeak -v en "which is wrong"');
		io.sockets.emit('w', {v:0});
	}
   }else{
   	echo('igonre if button read tiwce');
	}
});

b2.watch(function(err, value){
if(value ==1){
	exec('espeak -v en "You Pressed Right Hand"');
	if(n==2){
		if (err) exit();
		io.sockets.emit('b2' , {v:1});
		echo('inside b2 function');
		exec('espeak -v en "Which is correct"');
		io.sockets.emit('b2' , {v:0});

    }else{
		io.sockets.emit('w', {v:1});
		echo('inside b2 But wrong');
		exec('espeak -v en "which is wrong"');
		io.sockets.emit('w', {v:0});
	}
  }else{
	echo('ignore if button read twice ');
	}
});

b1.watch(function(err, value){
if(value == 1){
	exec('espeak -v en "You Pressed Left Hand"');
	if(n==1){
		if (err) exit();
		io.sockets.emit('b1' , {v:1});
		echo('inside b1 function');
		exec('espeak -v en "which is correct"');
		io.sockets.emit('b1' , {v:0});

	}else{
		io.sockets.emit('w', {v:1});
		echo('inside b1 But wrong');
		exec('espeak -v en "which is wrong"');
		io.sockets.emit('w', {v:0});
	}
  }else{
	echo('ignore if button read twice');
	}
});
  

function exit() {
    b1.unexport();
    b2.unexport();
    b3.unexport();
    b4.unexport();
    process.exit();
}

process.on('SIGINT', exit);
