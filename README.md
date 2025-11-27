# 🌾 IoT-Enabled Smart Agriculture Monitoring System

## 📖 Overview
This project uses an ESP32 microcontroller with soil, temperature, humidity, and light sensors to monitor farm conditions in real time and automate irrigation via MQTT and relay control.  
It provides a Node-RED or Grafana dashboard for visualization, alerts, and decision-making — ideal for precision agriculture and IoT training.

## 🚀 Features
- Real-time environmental monitoring  
- Automated irrigation control  
- Node-RED dashboard for data visualization  
- MQTT-based communication  
- Optional cloud storage & analytics (ThingSpeak / InfluxDB)  
- Local deployment using Docker Compose  

## ⚙️ Tech Stack
- **Hardware:** ESP32, DHT22, Soil Moisture Sensor, LDR, Relay Module  
- **Software:** Arduino IDE / PlatformIO, Python, Node-RED, Mosquitto MQTT, Grafana  
- **Protocols:** MQTT over Wi-Fi  
- **Deployment:** Local Docker or standalone PC setup  

## 🧩 Folder Structure
IoT-Smart-Agri/
├── hardware/ # ESP32 firmware + simulator
├── edge/ # Python MQTT bridge
├── dashboard/ # Node-RED / Grafana UI
├── dataset/ # Synthetic test data
├── analytics/ # ML & trend analysis
├── infra/ # Docker setup
├── docs/ # Reports & diagrams
└── .github/workflows/ # CI/CD pipeline

bash
Copy code

## 🧠 How to Run Locally
```bash
docker compose up -d
python3 edge/mqtt_bridge.py
python3 hardware/simulator.py
Open Node-RED dashboard at:
👉 http://localhost:1880/ui

📸 Demo Plan
Show live dashboard charts for temperature & soil moisture.

Dry the soil sensor → pump turns ON.

Wet the soil sensor → pump turns OFF.

Show Grafana trend and alerts.

🪪 License
Licensed under the MIT License © 2025 Sayli
