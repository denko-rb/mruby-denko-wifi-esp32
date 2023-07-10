# mruby-denko-wifi-esp32

This gem implements Wi-Fi connectivity for the ESP32, running Denko on mruby.

It is part of [mruby-denko](https://github.com/denko-rb/mruby-denko), and should be used through the ESP-IDF projects in that repository.

You may wish to enable it together with the accompanying [MQTT client gem](https://github.com/denko-rb/mruby-denko-mqtt-esp32), or the core `mruby-socket` gem.

## Example

```ruby
wifi = WiFi.new

wifi.on_connected    { |ip| puts "Wi-Fi connected with IP: #{ip}" }
wifi.on_disconnected {      puts "Wi-Fi disconnected" }

wifi.connect('SSID', 'password')
```

## Dependencies

So far, this is purely a function remapping of [mruby-esp32-wifi](https://github.com/denko-rb/mruby-esp32-wifi), from `ESP32::WiFi` into `WiFi`. That repo is used as a submodule.
