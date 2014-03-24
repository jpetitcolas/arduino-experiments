var io   = require('socket.io').listen(8080);
var five = require('johnny-five');

var led;
var board = new five.Board();

board.on("ready", function() {

    led = new five.Led(13);

    io.sockets.on("connection", function(socket) {
        console.log("New connection: " + socket.id);

        socket.on("led:on", function() {
            led.on();
        })

        socket.on("led:off", function() {
            led.off();
        })
    });

});
