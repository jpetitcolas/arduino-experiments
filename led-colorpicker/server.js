var io   = require('socket.io').listen(8080);
var five = require('johnny-five');

var led;
var board = new five.Board();

board.on("ready", function() {

    led = new five.Led.RGB([9, 10, 11]);

    io.sockets.on("connection", function(socket) {
        console.log("New connection: " + socket.id);

        socket.on("changeColor", function(e) {
            led.color(e.color)
        });
    });

    this.repl.inject({ led: led });
});
