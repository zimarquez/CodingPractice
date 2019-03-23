#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Mar  4 14:07:36 2019

@author: zim
"""

import psutil
import time
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import graphics as gr

# global const
NUM_CPU_CORES = 4
SAMPLE_PERIOD = 1 # time in seconds

t_start = time.time()
t_prev = time.time()
battery_percent = psutil.sensors_battery()
cpu_temp_data = psutil.sensors_temperatures()

cpu0_temp_start = 0
cpu1_temp_start = 0
cpu2_temp_start = 0
cpu3_temp_start = 0

WIDTH = 500
HEIGHT = 500

def InitGraphics():
    win = gr.GraphWin("Linux Monitor", WIDTH, HEIGHT)   
    win.setBackground('black')
    
    # core 0
    pt1 = gr.Point(250,250)
    pt2 = gr.Point(350,350)
    pt1.draw(win)
    pt2.draw(win)
    
    rect = gr.Rectangle(pt1, pt2)
    rect.setOutline('blue')
    rect.setFill('yellow')
    rect.setWidth(10)
    
def GetCoreTemps(temp_list):
    temp_list.append(cpu_temp_data["coretemp"][1][1])
    temp_list.append(cpu_temp_data["coretemp"][2][1])
    temp_list.append(cpu_temp_data["coretemp"][3][1])
    temp_list.append(cpu_temp_data["coretemp"][4][1])
    
def DisplayTempOverTime(time_period, seconds, display, temp_dict):
    # initialize start time and current time
    t_count = time.time()
    t_current = time.time()
    t_prev = time.time()
    
    i = 0 
    # loop for the given number of seconds
    while (seconds >= t_current - t_count):
        cpu_temp_data = psutil.sensors_temperatures()
        battery_percent = psutil.sensors_battery()
        t_current = time.time()
        
        # periodically gather the data
        if ((t_current - t_prev > time_period)):
            
            # print data
            if (display):
                print(round(t_current - t_start), str(round(battery_percent[0], 6))+"%")
                print("core 0:", cpu_temp_data["coretemp"][1][1]
                , "core 1:", cpu_temp_data["coretemp"][2][1]
                , "core 2:", cpu_temp_data["coretemp"][3][1]
                , "core 3:", cpu_temp_data["coretemp"][4][1])
            
            # store data
            temp_dict['time'].append(round(t_current - t_start))
            temp_dict['battery'].append(round(battery_percent[0], 6))
            
            temp_dict['core 0'].append(cpu_temp_data["coretemp"][1][1])
            temp_dict['core 1'].append(cpu_temp_data["coretemp"][2][1])
            temp_dict['core 2'].append(cpu_temp_data["coretemp"][3][1])
            temp_dict['core 3'].append(cpu_temp_data["coretemp"][4][1])
            i += 1
            
            t_prev = t_current

def RunContinuously(run_time_m, temp_dict):
    battery_start = psutil.sensors_battery()
    battery_end = psutil.sensors_battery()
    time_start = time.time()
    time_end = time.time()
 
    running = 1
    while (running):
        time_elapsed_m = round(time_end - time_start) / 60
        if (time_elapsed_m >= run_time_m):
            running = 0
        
        battery_end = psutil.sensors_battery()
        time_end = time.time()
    
    # Display time elapsed and battery % used
    print("Time elapsed: ", str(round(time_end - time_start))+"s")
    print("Battery spent: ", str(round(battery_start[0] - battery_end[0]))+"%")

def DisplayPlot():
    x = np.arange(1,10,1)
    
    plt.close("all")
    fig = plt.figure(figsize=(6,6), dpi=100)
    ax = fig.add_subplot(111)
    
    ax.plot(x, x**2, label="y = x**2")
    ax.plot(x, x**3, label="y = x**3")
    ax.legend(loc=2)

temperature_dictionary = {}
df = pd.Series()
def main():
    cpu_temp_start = []
    GetCoreTemps(cpu_temp_start)
    
    temperature_dictionary['time'] = []
    temperature_dictionary['battery'] = []
    temperature_dictionary['core 0'] = []
    temperature_dictionary['core 1'] = []
    temperature_dictionary['core 2'] = []
    temperature_dictionary['core 3'] = []
    
    DisplayTempOverTime(2, 10, 1, temperature_dictionary)
    
    df = pd.DataFrame(temperature_dictionary)
    df.to_csv("CPU_pandas.csv", index=False)
    
    cpu_temp_end = []
    GetCoreTemps(cpu_temp_end)

if __name__== '__main__':
    main()

