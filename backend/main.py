from fastapi import FastAPI, Depends
from pydantic import BaseModel
import serial
from db import database

app = FastAPI()

# Adjust this to your Arduino's serial port
SERIAL_PORT = '/dev/cu.usbmodem2101'
BAUD_RATE = 9600

# Initialize serial connection
ser = serial.Serial(SERIAL_PORT, BAUD_RATE)

class ToggleRequest(BaseModel):
    state: int

@app.on_event("startup")
async def startup():
    await database.connect()

@app.on_event("shutdown")
async def shutdown():
    await database.disconnect()

@app.post("/toggle_led")
async def toggle_led(request: ToggleRequest):
    state = request.state
    if state not in [0, 1]:
        return {"error": "Invalid state. Use 0 or 1."}
    ser.write(str(state).encode())
    # Optionally, store the state in the database
    query = "INSERT INTO led_state (state) VALUES (:state)"
    await database.execute(query=query, values={"state": state})
    return {"state": state}
