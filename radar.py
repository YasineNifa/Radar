import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np
from serial import *
import subprocess as sp


def update(i):
    global data
    data += (np.random.rand(50)+np.cos(i*2.*np.pi/50.))*2 
    data[-1] = data[0]
    l.set_data(theta, data )
    return l, 
with Serial(port='COM4', baudrate=9600, timeout=1, writeTimeout=1) as port_serie:
    if port_serie.isOpen():
        while True:
            fig = plt.figure(figsize=(4,4))
            ax = fig.add_subplot(111, projection='polar')
            ax.set_ylim(0,100)
            ligne = port_serie.readline()
            commande = [int (s) for s in ligne.split() if s.isdigit()]
            if commande:
                res = commande[0]
                l,  = ax.plot([],[])
                ani = animation.FuncAnimation(fig, update, frames=50, interval=200, blit=True)
            plt.show()
            #if commande:
                
                