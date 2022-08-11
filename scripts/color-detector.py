# IMPORTANT
# INSTALL VERSION 4.2.0 OF OPENCV: pip install opencv-python==4.2.0.34
# sudo apt-get install scrot

from turtle import color, onclick
from warnings import resetwarnings
import cv2
from cv2 import erode
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import pyautogui
from pynput import mouse, keyboard
import colorsys
import math

hMin = 0
sMin = 0
vMin = 0
hMax = 179
sMax = 255
vMax = 255

hMinTest = 0
sMinTest = 0
vMinTest = 0
hMaxTest = 179
sMaxTest = 255
vMaxTest = 255

cliques = 0
cliquesMax = 3
recebendoCliques = False

key = 'a'

def on_click(x, y, button, pressed):
    
    # add
    global cliques
    global cliquesMax
    global hMax
    global hMaxTest
    global sMax
    global sMaxTest
    global vMax
    global vMaxTest
    global hMin
    global hMinTest
    global sMin
    global sMinTest
    global vMin
    global vMinTest

    if pressed and recebendoCliques and button == mouse.Button.left:

        

        cliques = cliques + 1

        mousePosition = pyautogui.position()
        RGB_color = pyautogui.pixel(mousePosition.x, mousePosition.y)
        (r, g, b) = (RGB_color.red / 255, RGB_color.green / 255, RGB_color.blue / 255)
        (h, s, v) = colorsys.rgb_to_hsv(r, g, b)
        (h, s, v) = (int(h * 179), int(s * 255), int(v * 255))
        
        # interseção
        if cliques == 1:
            hMaxTest = h
            hMinTest = h
            sMaxTest = s
            sMinTest = s
            vMaxTest = v
            vMinTest = v
        else: 
            if hMaxTest < h:
                hMaxTest = h
            if hMinTest > h:
                hMinTest = h            
            if sMaxTest < s:
                sMaxTest = s
            if sMinTest > s:
                sMinTest = s
            if vMaxTest < v:
                vMaxTest = v
            if vMinTest > v:
                vMinTest = v
        if cliques >= cliquesMax:
            cv2.setTrackbarPos('HMin', 'Parâmetros', hMinTest)
            cv2.setTrackbarPos('SMin', 'Parâmetros', sMinTest)
            cv2.setTrackbarPos('VMin', 'Parâmetros', vMinTest)
            cv2.setTrackbarPos('HMax', 'Parâmetros', hMaxTest)
            cv2.setTrackbarPos('SMax', 'Parâmetros', sMaxTest)
            cv2.setTrackbarPos('VMax', 'Parâmetros', vMaxTest)

    # subtract
    if pressed and recebendoCliques and button == mouse.Button.right:
        cliques = cliques + 1

        mousePosition = pyautogui.position()
        RGB_color = pyautogui.pixel(mousePosition.x, mousePosition.y)
        (r, g, b) = (RGB_color.red / 255, RGB_color.green / 255, RGB_color.blue / 255)
        (h, s, v) = colorsys.rgb_to_hsv(r, g, b)
        (h, s, v) = (int(h * 179), int(s * 255), int(v * 255))
        
        # interseção
        if cliques == 1:
            hMaxTest = 179
            hMinTest = 0
            sMaxTest = 255
            sMinTest = 0
            vMaxTest = 255
            vMinTest = 0
        else: 
            if hMaxTest > h:
                hMaxTest = h
            if hMinTest < h:
                hMinTest = h            
            if sMaxTest > s:
                sMaxTest = s
            if sMinTest < s:
                sMinTest = s
            if vMaxTest > v:
                vMaxTest = v
            if vMinTest < v:
                vMinTest = v
        if cliques >= cliquesMax:
            # divide por 100 para deixar mais preciso, esse numero pode ser calibrado fuuturamente
            cv2.setTrackbarPos('HMin', 'Parâmetros', math.floor(hMinTest / 100))
            cv2.setTrackbarPos('SMin', 'Parâmetros', math.floor(sMinTest / 100))
            cv2.setTrackbarPos('VMin', 'Parâmetros', math.floor(vMinTest / 100))
            cv2.setTrackbarPos('HMax', 'Parâmetros', hMaxTest)
            cv2.setTrackbarPos('SMax', 'Parâmetros', sMaxTest)
            cv2.setTrackbarPos('VMax', 'Parâmetros', vMaxTest)

def on_press_keyboard(key):
    try:
        if key.char == 'q':
            capture.release()
            cv2.destroyAllWindows()
            cv2.waitKey(0)
        if key.char == 'r':
            reset()
        if key.char == 'e':
            setandoCliques()
        if key.char == 'f':
            set_red()
        if key.char == 'g':
            set_green()
            
    except AttributeError:
        pass

def reset (): 
    cv2.setTrackbarPos('HMin', 'Parâmetros', 0)
    cv2.setTrackbarPos('SMin', 'Parâmetros', 0)
    cv2.setTrackbarPos('VMin', 'Parâmetros', 0)
    cv2.setTrackbarPos('HMax', 'Parâmetros', 179)
    cv2.setTrackbarPos('SMax', 'Parâmetros', 255)
    cv2.setTrackbarPos('VMax', 'Parâmetros', 255)

    print("Máscara resetada!")
    global cliques
    cliques = 0
    
def set_red(): 
    cv2.setTrackbarPos('HMin', 'Parâmetros', 0)
    cv2.setTrackbarPos('SMin', 'Parâmetros', 118)
    cv2.setTrackbarPos('VMin', 'Parâmetros', 144)
    cv2.setTrackbarPos('HMax', 'Parâmetros', 4)
    cv2.setTrackbarPos('SMax', 'Parâmetros', 227)
    cv2.setTrackbarPos('VMax', 'Parâmetros', 255)

    print("Máscara calibrada em vermelho")
    global cliques
    cliques = 0

def set_green(): 
    cv2.setTrackbarPos('HMin', 'Parâmetros', 60)
    cv2.setTrackbarPos('SMin', 'Parâmetros', 82)
    cv2.setTrackbarPos('VMin', 'Parâmetros', 83)
    cv2.setTrackbarPos('HMax', 'Parâmetros', 97)
    cv2.setTrackbarPos('SMax', 'Parâmetros', 184)
    cv2.setTrackbarPos('VMax', 'Parâmetros', 211)

    print("Máscara calibrada em verde")
    global cliques
    cliques = 0

listener = mouse.Listener(on_click=on_click)
listener.start()

listener = keyboard.Listener(
    on_press=on_press_keyboard
    )
listener.start()

def setandoCliques ():
    global recebendoCliques
    if recebendoCliques == True:
        recebendoCliques = False
        print("Cliques desativados!")
    else:
        recebendoCliques = True
        print("Cliques ativados!")

def get_mask(hsv , lower_color , upper_color):
    lower = np.array(lower_color)
    upper = np.array(upper_color)
    
    mask = cv2.inRange(hsv , lower, upper)

    return mask

def nothing(x):
    pass

capture = cv2.VideoCapture(0)
skyratsImg = cv2.imread("./images/skyrats_logo.jpeg")
skyratsImgResize = cv2.resize(skyratsImg, (300, 300))

cv2.namedWindow('Camera - R: resetar máscara, E: ativar mouse e Q: sair')
cv2.namedWindow('Parâmetros')

cv2.createTrackbar('HMin', 'Parâmetros', 0, 179, nothing)
cv2.createTrackbar('SMin', 'Parâmetros', 0, 255, nothing)
cv2.createTrackbar('VMin', 'Parâmetros', 0, 255, nothing)
cv2.createTrackbar('HMax', 'Parâmetros', 179, 179, nothing)
cv2.createTrackbar('SMax', 'Parâmetros', 255, 255, nothing)
cv2.createTrackbar('VMax', 'Parâmetros', 255, 255, nothing)
cv2.createTrackbar('Erode', 'Parâmetros', 0, 100, nothing)
cv2.createTrackbar('Dilate', 'Parâmetros', 0, 100, nothing)
cv2.createTrackbar('Blur', 'Parâmetros', 1, 100, nothing)
cv2.createTrackbar('CliquesMáximos', 'Parâmetros', 1, 100, nothing)
cv2.createTrackbar('Cliques', 'Parâmetros', 1, cliquesMax, nothing)

cv2.setTrackbarPos('CliquesMáximos', 'Parâmetros', 10)

while True: 
    success, frame = capture.read()
    if success == False:
        raise ConnectionError
    hMin = cv2.getTrackbarPos('HMin', 'Parâmetros')
    sMin = cv2.getTrackbarPos('SMin', 'Parâmetros')
    vMin = cv2.getTrackbarPos('VMin', 'Parâmetros')
    hMax = cv2.getTrackbarPos('HMax', 'Parâmetros')
    sMax = cv2.getTrackbarPos('SMax', 'Parâmetros')
    vMax = cv2.getTrackbarPos('VMax', 'Parâmetros')
    cv2.setTrackbarMax('Cliques', 'Parâmetros', cliquesMax)

    cliquesMax = cv2.getTrackbarPos('CliquesMáximos', 'Parâmetros')

    cv2.setTrackbarPos('Cliques', 'Parâmetros', cliques)
    
    
    lower = [hMin, sMin, vMin]
    upper = [hMax, sMax, vMax]
    # get_mask(hsv, [160, 100, 20], [179, 255, 255])

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    mask = get_mask(hsv, lower, upper)

    
    result = cv2.bitwise_and(frame, frame, mask= mask)
    
    #plotting
    erode_size = cv2.getTrackbarPos('Erode', 'Parâmetros')
    dilate_size = cv2.getTrackbarPos('Dilate', 'Parâmetros')
    blur_size = cv2.getTrackbarPos('Blur', 'Parâmetros')

    erode_kernel = np.ones((erode_size, erode_size), np.float32)
    
    dilate_kernel = np.ones((dilate_size, dilate_size), np.float32)
    

    if blur_size == 0: 
        blur_size = 1
    blurredFrame = cv2.blur(result, (blur_size, blur_size))

    result = cv2.dilate(blurredFrame, dilate_kernel)
    result = cv2.erode(result, erode_kernel)
    
    cv2.imshow('Parâmetros', skyratsImgResize)
    cv2.imshow('Camera - R: resetar máscara, E: ativar mouse e Q: sair', result)
    
    if cv2.waitKey(20): key = cv2.waitKey(20)  
