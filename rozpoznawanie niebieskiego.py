import cv2
import numpy as np
import serial
import time

cap = cv2.VideoCapture(1)


# przechwycenie klatki
cap, frame = cap.read()

# konwersja BGR do HSV
hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

# zdefiniowanie zakresu dla niebieskiego HSV
lower_blue = np.array([110,100,100])
upper_blue = np.array([130,255,255])

# zdefiniowanie zakresu dla czerwonego HSV
lower_red = np.array([0,100,100])
upper_red = np.array([5,255,255])

# zdefiniowanie zakresu dla zielonego HSV
lower_green = np.array([50,100,100])
upper_green = np.array([70,255,255])

# filtracja koloru niebieskiego w zakresie HSV
niebieski = cv2.inRange(hsv, lower_blue, upper_blue)

# filtracja koloru czerwonego w zakresie HSV
czerwony = cv2.inRange(hsv, lower_red, upper_red)

# filtracja koloru zeilonego w zakresie HSV
zielonego = cv2.inRange(hsv, lower_green, upper_green)

# stworzenie zakresu dla operacji morfologicznej
kernel = np.ones((15,15),np.uint8)

# operacje morfologiczne na kazdym kolorze

niebieski_bin = cv2.morphologyEx(niebieski, cv2.MORPH_CLOSE, kernel)
czerony_bin = cv2.morphologyEx(czerwony, cv2.MORPH_CLOSE, kernel)
zielony_bin = cv2.morphologyEx(zielonego, cv2.MORPH_CLOSE, kernel)

# sumowanie pikseli odpowiedniego koloru uzyskanego z obrazu binarnego

suma_niebieski= niebieski_bin.sum()
suma_zielony=zielony_bin.sum()
suma_czerwony=czerony_bin.sum()

print(suma_niebieski)
print(suma_zielony)
print(suma_czerwony)

# wyliczenie parametru koloru (jaki kolor podsawowy jest na zdjeciu)

if suma_niebieski>100000 and suma_czerwony>100000 and suma_zielony>100000:
    kolor='o'
elif suma_czerwony>900000 and suma_czerwony>suma_niebieski and suma_czerwony>suma_zielony:
    kolor='c'
elif suma_zielony>900000 and suma_zielony>suma_niebieski and suma_zielony>suma_czerwony:
    kolor='z'
elif suma_niebieski>900000 and suma_niebieski>suma_czerwony and suma_niebieski>suma_zielony:
    kolor='n'
else:
    kolor='o'

print(kolor)

ser=serial.Serial(
port='COM5',
baudrate=9600,
parity=serial.PARITY_NONE,
stopbits=serial.STOPBITS_ONE,
bytesize=serial.EIGHTBITS,
timeout=1
)
time.sleep(2)


while True:
    print(kolor)
    ser.write(str.encode(kolor))
    time.sleep(1)
    data = ser.read()
    print(data)


print(kolor)
cv2.imshow('frame',frame)
cv2.imshow('blue', niebieski_bin)
cv2.imshow('red', czerony_bin)
cv2.imshow('hsv',hsv)
cv2.imshow('green', zielony_bin)
cv2.imshow('z nieb', niebieski_bin)
cv2.waitKey(0)

