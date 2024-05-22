# Fullstack Arduino LED Toggle Project

## Overview

This project toggles an LED connected to an Arduino via a web interface. The backend is built with FastAPI, and the frontend with React, Vite, and Redux. The entire project runs in Docker containers.

## Project Structure


## Setup Instructions

### 1. Arduino

Upload the `arduino/led_toggle.ino` sketch to your Arduino.

### 2. Backend

Navigate to the `backend` directory and create a virtual environment:

```bash
cd ~/projects/fullstack-arduino-project/backend
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
```