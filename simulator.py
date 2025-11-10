# MQTT Simulator
import paho.mqtt.publish as publish, json, time, random
broker = "localhost"
while True:
    data = {
        "temp": round(random.uniform(22,35),1),
        "hum": round(random.uniform(40,80),1),
        "soil": random.randint(1000,2500),
        "light": random.randint(500,1500)
    }
    publish.single("farm/node1/data", json.dumps(data), hostname=broker)
    time.sleep(5)
