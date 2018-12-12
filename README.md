# botoneira-uaifaiuai
Entry panel with buttons to send tweet messages with relevant information to residents of a isolated neighborhood in Ubatuba city, São Paulo state, situated in Brasil.

## Team:
- [Aruan Moreira](aruanmoraes@gmail.com)
- [Mayra Bueno](https://github.com/baguy)
- [Beto Cadilhe](https://github.com/cadilhe)
- Edson

## Entry panel Botoneira UaiFaiUai
The entry panel has:
- One led to indicate it is turned on
- One led to indicate it is connected to the internet
- Three buttons
  - One button sends a warning that recicling garbage collector is entrying the neighborhood
  - One button sends a warning that normal garbage collector is entrying the neighborhood
  - One button sends a warning of risk of flooding
- Three leds, each blinks for 3 seconds when the it's respective button is pressed

## Webhook
The applet _Post a Tweet with the ESP8266_ by rffsantos16 in [IFTTT](https://ifttt.com/) was used to connect our NodeMCU ESP8266 to my twitter account @baguy_chan.

It was necessary to create a random number generator so Tweeter wouldn't block the warnings.

## Data
To verify the data, the applet _Automatically save every Tweet you post to a Google spreadsheet_ by leorstern was used to save every tweet to a Google spreadsheet in my Google Drive.
