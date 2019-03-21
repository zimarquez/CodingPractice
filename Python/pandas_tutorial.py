#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Mar  7 19:27:11 2019

@author: zim
"""

import numpy as np
import pandas as pd

data_url = 'http://bit.ly/2cLzoxH'
df = pd.read_csv(data_url)

df = df.assign(gdp = (df.lifeExp) * df['pop'])

#print(df['country']['Australia'])

print(df['lifeExp'].describe())