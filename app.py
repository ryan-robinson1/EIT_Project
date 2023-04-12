# Run Flask App with $python app.py. Ensure serial port is correct and connected arduino is streaming data.
from flask import Flask, render_template, jsonify
import serial

app = Flask(__name__)
ser = serial.Serial("COM5", 115200)


@app.route("/serial_data")
def get_current_time():
    data = ser.readline().decode().strip()  # read serial data
    return jsonify({"serial": data})


@app.route("/")
def index():
    return render_template("index.html")


if __name__ == "__main__":
    app.run()
