// Files from mruby-esp32 gems.
#include "../ext/mruby-esp32-wifi/src/mrb_esp32_wifi.c"

void
mrb_mruby_denko_wifi_esp32_gem_init(mrb_state* mrb) {
  ESP_ERROR_CHECK(esp_netif_init());
  ESP_ERROR_CHECK(esp_event_loop_create_default());
  esp_netif_create_default_wifi_sta();

  struct RClass *esp32_wifi_class = mrb_define_class(mrb, "WiFi", mrb->object_class);
  mrb_define_method(mrb, esp32_wifi_class, "initialize", mrb_esp32_wifi_init, MRB_ARGS_NONE());
  mrb_define_method(mrb, esp32_wifi_class, "connect", mrb_esp32_wifi_connect, MRB_ARGS_REQ(2));
  mrb_define_method(mrb, esp32_wifi_class, "disconnect", mrb_esp32_wifi_disconnect, MRB_ARGS_NONE());
  mrb_define_method(mrb, esp32_wifi_class, "on_connected", mrb_esp32_wifi_set_on_connected, MRB_ARGS_BLOCK());
  mrb_define_method(mrb, esp32_wifi_class, "on_disconnected", mrb_esp32_wifi_set_on_disconnected, MRB_ARGS_BLOCK());
}

void
mrb_mruby_denko_wifi_esp32_gem_final(mrb_state* mrb) {
}
