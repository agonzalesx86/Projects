const char MAIN_page[] PROGMEM = "
<html>
<head>
  <title> Generic Control Interface </title>
</head>

<body>
  <div>
    <h1>Generic Control Interface</h1>
    <p><i>Description: This interface was created to be able to control various I/O using the ESP8266 over WiFi.</i></p>
  </div>

<div>
  <h2>Control Set 1 (On/Off)</h2>
  <form action = "/LED" method = "POST">
    <input type="submit" value="LED Control">
  </form>
</div>


</body>

</html>";
