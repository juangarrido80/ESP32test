#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "driver/gpio.h"

#define LED_GPIO 2  // Altere esse valor se seu LED estiver em outro pino

static const char *TAG = "INICIALIZACAO";

void app_main(void)
{
    // Mensagem de boas-vindas no log
    ESP_LOGI(TAG, "Inicializando ESP32...");

    // Mostra o chip ID e a quantidade de memória flash
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);

    ESP_LOGI(TAG, "Este é o chip ESP32 com %d CPU core(s), WiFi%s%s, %dMB de flash",
             chip_info.cores,
             (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
             (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "",
             spi_flash_get_chip_size() / (1024 * 1024));

    // Loop infinito com um delay
    while (1) {
    // Liga o LED
        gpio_set_level(LED_GPIO, 1);
        ESP_LOGI(TAG, "LED ON");
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        // Desliga o LED
        gpio_set_level(LED_GPIO, 0);
        ESP_LOGI(TAG, "LED OFF");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
