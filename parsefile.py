import os
import numpy as np
from scipy import stats

filepath = 'C:/repos/laserbot/data/purple_NDC.txt'

with open(filepath, mode="r") as f:
    lines = f.readlines()

datalist = list()

for line in lines:
    position1 = line.find("Raw")
    position2 = line.find(":", position1) + 1
    line = line.replace("\n", "")
    if position2 > 0:
        newdata = line[position2:]
        datalist.append(newdata)

rowcount = len(datalist)
colcount = len(list(filter(None, datalist[0].split(" "))))

signals = np.empty([rowcount, colcount])

A = np.array([[1,2,3],[4,5,6]])

for i in range(rowcount):
    signals[i] = np.array(list(map(int, filter(None, datalist[i].split(" ")))))

signals.mean(axis=0)
singals.min(axis=0)
signals.max(axis=0)
stats.mode(signals)