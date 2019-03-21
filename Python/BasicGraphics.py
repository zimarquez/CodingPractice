#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Feb 25 18:36:11 2019

@author: zim
"""

import graphics as g


def main():
    win = g.GraphWin('Face', 200, 150) # give title and dimensions
    #win.yUp() # make right side up coordinates!

    eye1 = g.Circle(g.Point(5, 5), 5)
    eye1.setFill('red')
    eye1.draw(win)
    eye1 = g.Circle(g.Point(194, 5), 5)
    eye1.setFill('blue')
    eye1.draw(win)
    eye1 = g.Circle(g.Point(5, 100), 5)
    eye1.setFill('yellow')
    eye1.draw(win)
    eye1 = g.Circle(g.Point(194, 100), 5)
    eye1.setFill('green')
    eye1.draw(win)
    
    head = g.Circle(g.Point(40,100), 25) # set center and radius
    head.setFill("yellow")
    head.draw(win)

    eye1 = g.Circle(g.Point(30, 105), 5)
    eye1.setFill('blue')
    eye1.draw(win)

    eye2 = g.Line(g.Point(45, 105), g.Point(55, 105)) # set endpoints
    eye2.setWidth(3)
    eye2.draw(win)

    mouth = g.Oval(g.Point(30, 90), g.Point(50, 85)) # set corners of bounding box
    mouth.setFill("red")
    mouth.draw(win)

    label = g.Text(g.Point(100, 120), 'A face')
    label.draw(win)

    message = g.Text(g.Point(win.getWidth()/2, 20), 'Click anywhere to quit.')
    message.draw(win)
    win.getMouse()
    win.close()

main()