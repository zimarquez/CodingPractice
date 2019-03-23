# Ismael Marquez, im6549

import graphics as gr
import time
import psutil

# time is in seconds
RUN_TIME = 60
UPDATE_PERIOD = 0.5

# update scale to change GUI size
SCALE = 3
WIDTH = 250 * SCALE
HEIGHT = 250 * SCALE

BAR_WIDTH = WIDTH/9 # should be WIDTH / (1 + 2*num_vertical_bars)
BAR_FLOOR = HEIGHT - 15*SCALE
BAR_CEIL = 100*SCALE
BAR_SCALE = (BAR_FLOOR - BAR_CEIL) / 80

BAR_FILL = gr.color_rgb(64,224,208)
BAR_OUTLINE = 'black'
BACKGROUND_COLOR = gr.color_rgb(32,32,32)
TXT_COLOR = 'white'

# sets up the GUI window
def Initialization():
    win = gr.GraphWin("Linux Monitor", WIDTH, HEIGHT)   
    win.setBackground(BACKGROUND_COLOR)
    return win

# clears sections of the screen using the designated background color
def ClearScreen(win):
    clr = gr.Rectangle(gr.Point(0,BAR_CEIL - 10), gr.Point(WIDTH, HEIGHT))
    clr.setFill(BACKGROUND_COLOR)
    clr.setOutline(BACKGROUND_COLOR)
    clr.draw(win)
    
    battery_inner = gr.Circle(gr.Point(WIDTH/4,HEIGHT/4), 35*SCALE)  
    battery_inner.setOutline(BACKGROUND_COLOR)
    battery_inner.setFill(BACKGROUND_COLOR)
    battery_inner.draw(win)

# Updates the display based on battery percentage and CPU core temps    
def UpdateWindow(win):
    
    # Get updated data
    cpu_temp_data = psutil.sensors_temperatures()
    battery_percent = psutil.sensors_battery()
    temp_offset = 20
    
    # Clear screen of old data
    ClearScreen(win)
    
    #########################
    #      TITLE INFO       #
    #########################
    battery_txt = gr.Text(gr.Point(WIDTH - WIDTH/3.5, HEIGHT/4 - 10), "Temperature \n& \nBattery Monitor \nVersion 1.0")
    battery_txt.setFill(TXT_COLOR)
    battery_txt.setSize(12*SCALE)
    battery_txt.draw(win)
    
    #########################
    #     BATTERY DATA      #
    #########################   
    battery_outer = gr.Circle(gr.Point(WIDTH/4,HEIGHT/4), 40*SCALE)  
    battery_outer.setOutline('red')
    battery_outer.setFill('red')
    battery_outer.draw(win)

    battery_inner = gr.Circle(gr.Point(WIDTH/4,HEIGHT/4), 35*SCALE)  
    battery_inner.setOutline(BACKGROUND_COLOR)
    battery_inner.setFill(BACKGROUND_COLOR)
    battery_inner.draw(win)
    
    battery_txt = gr.Text(gr.Point(WIDTH/4,HEIGHT/4), "Battery\n" + str(round(battery_percent[0], 2))+"%")
    battery_txt.setFill(TXT_COLOR)
    battery_txt.setSize(8*SCALE)
    battery_txt.draw(win)
    
    #########################
    #       CPU DATA        #
    #########################
    # Core 0
    core0_txt = gr.Text(gr.Point(BAR_WIDTH + BAR_WIDTH/2, HEIGHT - 8*SCALE), "Core 0")
    core0_txt.setFill(TXT_COLOR)
    
    # update bar height and temp value based on new data
    core0_height = BAR_FLOOR - (cpu_temp_data["coretemp"][1][1] - temp_offset) * BAR_SCALE
    core0_temp = gr.Text(gr.Point(BAR_WIDTH + BAR_WIDTH/2, core0_height - 10), str(cpu_temp_data["coretemp"][1][1]) + "°c")
    core0_temp.setFill(TXT_COLOR)
    core0 = gr.Rectangle(gr.Point(BAR_WIDTH, BAR_FLOOR),
                         gr.Point(BAR_WIDTH + BAR_WIDTH, core0_height))
    
    core0.setOutline(BAR_OUTLINE)
    core0.setFill(BAR_FILL)
    core0.draw(win)
    core0_txt.draw(win)
    core0_temp.draw(win)
    
    # Core 1
    core1_txt = gr.Text(gr.Point((BAR_WIDTH)*2 + BAR_WIDTH/2 + BAR_WIDTH, HEIGHT - 8*SCALE), "Core 1")
    core1_txt.setFill(TXT_COLOR)
    
    core1_height = BAR_FLOOR - (cpu_temp_data["coretemp"][2][1] - temp_offset) * BAR_SCALE
    core1_temp = gr.Text(gr.Point((BAR_WIDTH)*2 + BAR_WIDTH/2 + BAR_WIDTH, core1_height - 10), str(cpu_temp_data["coretemp"][2][1]) + "°c")
    core1_temp.setFill(TXT_COLOR)   
    core1 = gr.Rectangle(gr.Point((BAR_WIDTH)*2 + BAR_WIDTH, BAR_FLOOR),
                         gr.Point((BAR_WIDTH)*2 + BAR_WIDTH*2, core1_height))
    
    core1.setOutline(BAR_OUTLINE)
    core1.setFill(BAR_FILL)
    core1.draw(win)
    core1_txt.draw(win)
    core1_temp.draw(win)
    
    # Core 2
    core2_txt = gr.Text(gr.Point((BAR_WIDTH)*3 + BAR_WIDTH/2 + BAR_WIDTH*2, HEIGHT - 8*SCALE), "Core 2")
    core2_txt.setFill(TXT_COLOR)
   
    core2_height = BAR_FLOOR - (cpu_temp_data["coretemp"][3][1] - temp_offset) * BAR_SCALE
    core2_temp = gr.Text(gr.Point((BAR_WIDTH)*3 + BAR_WIDTH/2 + BAR_WIDTH*2, core2_height - 10), str(cpu_temp_data["coretemp"][3][1]) + "°c")
    core2_temp.setFill(TXT_COLOR)
    core2 = gr.Rectangle(gr.Point((BAR_WIDTH)*3 + BAR_WIDTH*2, BAR_FLOOR),
                         gr.Point((BAR_WIDTH)*3 + BAR_WIDTH*3, core2_height))
    
    core2.setOutline(BAR_OUTLINE)
    core2.setFill(BAR_FILL)
    core2.draw(win)
    core2_txt.draw(win)
    core2_temp.draw(win)
    
    # Core 3
    core3_txt = gr.Text(gr.Point((BAR_WIDTH)*4 + BAR_WIDTH/2 + BAR_WIDTH*3, HEIGHT - 8*SCALE), "Core 3")
    core3_txt.setFill(TXT_COLOR)
    
    core3_height = BAR_FLOOR - (cpu_temp_data["coretemp"][4][1] - temp_offset) * BAR_SCALE
    core3_temp = gr.Text(gr.Point((BAR_WIDTH)*4 + BAR_WIDTH/2 + BAR_WIDTH*3, core3_height - 10), str(cpu_temp_data["coretemp"][4][1]) + "°c")
    core3_temp.setFill(TXT_COLOR)    
    core3 = gr.Rectangle(gr.Point((BAR_WIDTH)*4 + BAR_WIDTH*3, BAR_FLOOR),
                         gr.Point((BAR_WIDTH)*4 + BAR_WIDTH*4, core3_height))
    
    core3.setOutline(BAR_OUTLINE)
    core3.setFill(BAR_FILL)
    core3.draw(win)
    core3_txt.draw(win)
    core3_temp.draw(win)
    
def main():
    window = Initialization()
    
    t_start = time.time()
    t_current = time.time()
    t_prev = time.time()
    
    while (1):
        t_current = time.time()
        while ((t_current - t_prev > UPDATE_PERIOD)):
            #print("Time: ", round((t_current - t_start), 2))
            UpdateWindow(window)
            t_prev = t_current
    
    window.getMouse()
    window.close()
    
if __name__== '__main__':
    main()

