#include "wled.h"
/*
 * This v1 usermod file allows you to add own functionality to WLED more easily
 * See: https://github.com/wled-dev/WLED/wiki/Add-own-functionality
 * EEPROM bytes 2750+ are reserved for your custom use case. (if you extend #define EEPSIZE in const.h)
 * If you just need 8 bytes, use 2551-2559 (you do not need to increase EEPSIZE)
 *
 * Consider the v2 usermod API if you need a more advanced feature set!
 */

//Use userVar0 and userVar1 (API calls &U0=,&U1=, uint16_t)

#define BLINK_PIN 13


bool ledState = false;
unsigned long lastToggleTime = 0;




//gets called once at boot. Do all initialization that doesn't depend on network here
void userSetup()
{
  pinMode(BLINK_PIN, OUTPUT);

  // On envoie un message au Moniteur Série pour confirmer que notre code s'est bien lancé
  Serial.println("Hello from usermod.cpp! Pin setup complete.");pinMode(BLINK_PIN, OUTPUT);

  // On envoie un message au Moniteur Série pour confirmer que notre code s'est bien lancé
  Serial.println("Hello from usermod.cpp! Pin setup complete.");
}

//gets called every time WiFi is (re-)connected. Initialize own network interfaces here
void userConnected()
{

}

//loop. You can use "if (WLED_CONNECTED)" to check for successful connection
void userLoop()
{
  if (millis() - lastToggleTime > 500) { // Toutes les 1000ms (1 seconde)
    ledState = !ledState; // On inverse l'état de la LED (allumé -> éteint -> allumé...)
    digitalWrite(BLINK_PIN, ledState);
    lastToggleTime = millis(); // On met à jour le moment du dernier changement
  }
}
