# Edge MQTT Bridge
import paho.mqtt.client as mqtt
import json

BROKER = "localhost"
TOPIC_SUB = "farm/node1/data"
TOPIC_PUB = "farm/node1/command"

def on_message(client, userdata, msg):
    data = json.loads(msg.payload.decode())
    print(f"Received data: {data}")
    if data['soil'] < 1500:
        client.publish(TOPIC_PUB, "PumpON")
    else:
        client.publish(TOPIC_PUB, "PumpOFF")

client = mqtt.Client("edgeBridge")
client.on_message = on_message
client.connect(BROKER)
client.subscribe(TOPIC_SUB)
client.loop_forever()
