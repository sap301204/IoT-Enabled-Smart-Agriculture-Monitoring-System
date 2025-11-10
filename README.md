# IoT-Enabled Smart Agriculture Monitoring System

## Overview
An IoT-based solution using ESP32 and MQTT for monitoring soil, temperature, humidity, and light intensity.
Automates irrigation via relay and visualizes live data with Node-RED.

## Run Locally
```bash
docker compose up -d
python3 edge/mqtt_bridge.py
python3 hardware/simulator.py
```
Access Node-RED Dashboard at http://localhost:1880/ui

## Tech Stack
ESP32, DHT22, MQTT, Node-RED, Grafana, Python

## License
MIT License © 2025 Sayli
