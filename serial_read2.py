
import time
import serial
import re
from flask import Flask, render_template

app = Flask(__name__)
          


ser = serial.Serial(
              
    port='/dev/ttyUSB0',
    baudrate = 115200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)


Line=ser.readline()


@app.route('/')
def index():
    return render_template('index.html')

if __name__ == '__main__':
    app.run(debug=True, host = '0.0.0.0')


