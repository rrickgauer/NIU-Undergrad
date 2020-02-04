import numpy as np
import matplotlib.pyplot as plt
import requests
import random

def getData():
    url = "https://raw.githubusercontent.com/pratoolbharti/NIU/master/Applied_Machine_Learning_S20/Homework-1/mpg.csv"
    response = requests.get(url, timeout=5)
    data = response.text.split("\n")
    del data[0]

    list = []

    for x in data:
        if len(x) > 0:
            list.append(getDict(x.replace("\"", "")))

    return list

def getDict(str):
    parts = str.split(",")

    thisdict = {
        "id"          : parts[0],
        "manufacturer": parts[1],
        "model"       : parts[2],
        "displacement": float(parts[3]),
        "year"        : float(parts[4]),
        "cylinder"    : float(parts[5]),
        "transmission": parts[6],
        "drive"       : parts[7],
        "city"        : float(parts[8]),
        "hwy"         : float(parts[9]),
        "fl"          : parts[10],
        "class"       : parts[11],
    }

    return thisdict

def getCities(data):
    cities = []

    for dict in data:
        cities.append(dict['city'])

    return cities

def getDisplacements(data):
    displacements = []
    for dict in data:
        displacements.append(dict['displacement'])

    return displacements

def getDataByDrive(data):

    fwd = []
    rwd = []
    fourwd = []

    for x in data:
        if x['drive'] == 'f':
            fwd.append(getCoordinateDict(x['displacement'], x['city']))
        elif x['drive'] == 'r':
            rwd.append(getCoordinateDict(x['displacement'], x['city']))
        else:
            fourwd.append(getCoordinateDict(x['displacement'], x['city']))

    driveData = {
        'fwd': fwd,
        'rwd': rwd,
        '4wd': fourwd
    }

    return driveData

def getCoordinateDict(x, y):
    point = {
        'x' : x,
        'y' : y
    }
    return point

def getRandFloat(min, max):
    return random.uniform(min, max)

def plotGraph1(axis):
    data = getData()
    dataByDrive = getDataByDrive(data)

    x = []
    y = []

    # plot fwd coordinates
    for item in dataByDrive['fwd']:
        x.append(item['x'])
        y.append(item['y'])

    axis.scatter(np.array(x), np.array(y), c='orange', label='FWD')


    x.clear()
    y.clear()

    # plot rwd coordinates
    for item in dataByDrive['rwd']:
        x.append(item['x'])
        y.append(item['y'])

    axis.scatter(np.array(x), np.array(y), c='lightblue', label='RWD')

    x.clear()
    y.clear()

    # plot 4wd coordinates
    for item in dataByDrive['4wd']:
        x.append(item['x'])
        y.append(item['y'])

    axis.scatter(np.array(x), np.array(y), c='black', label='4WD')
    axis.legend()

def plotGraph2(axis):
    data = getData()
    dataByDrive = getDataByDrive(data)

    x = []
    y = []

    # plot fwd coordinates
    for item in dataByDrive['fwd']:
        x.append(item['x'])
        y.append(item['y'])

    axis.scatter(np.array(x), np.array(y), c='orange', label='FWD', alpha=0.5)


    x.clear()
    y.clear()

    # plot rwd coordinates
    for item in dataByDrive['rwd']:
        x.append(item['x'])
        y.append(item['y'])

    axis.scatter(np.array(x), np.array(y), c='lightblue', label='RWD', alpha=0.5)

    x.clear()
    y.clear()

    # plot 4wd coordinates
    for item in dataByDrive['4wd']:
        x.append(item['x'])
        y.append(item['y'])

    axis.scatter(np.array(x), np.array(y), c='black', label='4WD', alpha=0.5)
    axis.legend()

def plotGraph3(axis):
    data = getData()
    dataByDrive = getDataByDrive(data)

    x = []
    y = []
    count = 0;

    jitterMin = 0.5
    jitterMax = 0.8

    # plot fwd coordinates
    for item in dataByDrive['fwd']:
        rand = getRandFloat(jitterMin, jitterMax)

        if count % 2 == 0:
            p = item['x'] + rand
            z = item['y'] - rand
        else:
            p = item['x'] - rand
            z = item['y'] + rand

        x.append(p)
        y.append(z)

    axis.scatter(np.array(x), np.array(y), c='orange', label='FWD', alpha=0.5)


    x.clear()
    y.clear()

    # plot rwd coordinates
    for item in dataByDrive['rwd']:
        rand = getRandFloat(jitterMin, jitterMax)

        if count % 2 == 0:
            p = item['x'] + rand
            z = item['y'] - rand
        else:
            p = item['x'] - rand
            z = item['y'] + rand

        x.append(p)
        y.append(z)


    axis.scatter(np.array(x), np.array(y), c='lightblue', label='RWD', alpha=0.5)

    x.clear()
    y.clear()

    # plot 4wd coordinates
    for item in dataByDrive['4wd']:
        rand = getRandFloat(jitterMin, jitterMax)

        if count % 2 == 0:
            p = item['x'] + rand
            z = item['y'] - rand
        else:
            p = item['x'] - rand
            z = item['y'] + rand

        x.append(p)
        y.append(z)


    axis.scatter(np.array(x), np.array(y), c='black', label='4WD', alpha=0.5)
    axis.legend()

def plotGraph4(axis):
    data = getData()
    dataByDrive = getDataByDrive(data)

    x = []
    y = []
    count = 0;

    jitterMin = 1.5
    jitterMax = 2.0

    # plot fwd coordinates
    for item in dataByDrive['fwd']:
        rand = getRandFloat(jitterMin, jitterMax)

        if count % 2 == 0:
            p = item['x'] + getRandFloat(jitterMin, jitterMax)
            z = item['y'] - getRandFloat(jitterMin, jitterMax)
        else:
            p = item['x'] - getRandFloat(jitterMin, jitterMax)
            z = item['y'] + getRandFloat(jitterMin, jitterMax)

        x.append(p)
        y.append(z)

    axis.scatter(np.array(x), np.array(y), c='orange', label='FWD', alpha=0.5)


    x.clear()
    y.clear()

    # plot rwd coordinates
    for item in dataByDrive['rwd']:
        rand = getRandFloat(jitterMin, jitterMax)

        if count % 2 == 0:
            p = item['x'] + getRandFloat(jitterMin, jitterMax)
            z = item['y'] - getRandFloat(jitterMin, jitterMax)
        else:
            p = item['x'] - getRandFloat(jitterMin, jitterMax)
            z = item['y'] + getRandFloat(jitterMin, jitterMax)

        x.append(p)
        y.append(z)


    axis.scatter(np.array(x), np.array(y), c='lightblue', label='RWD', alpha=0.5)

    x.clear()
    y.clear()

    # plot 4wd coordinates
    for item in dataByDrive['4wd']:
        rand = getRandFloat(jitterMin, jitterMax)

        if count % 2 == 0:
            p = item['x'] + getRandFloat(jitterMin, jitterMax)
            z = item['y'] - getRandFloat(jitterMin, jitterMax)
        else:
            p = item['x'] - getRandFloat(jitterMin, jitterMax)
            z = item['y'] + getRandFloat(jitterMin, jitterMax)

        x.append(p)
        y.append(z)


    axis.scatter(np.array(x), np.array(y), c='black', label='4WD', alpha=0.5)
    axis.legend()


fig, axs = plt.subplots(2, 2)


plotGraph1(axs[0, 0])
plotGraph2(axs[0, 1])
plotGraph3(axs[1, 0])
plotGraph4(axs[1, 1])

# set titles
axs[0,0].set_title('18.1')
axs[0,1].set_title('18.2')
axs[1,0].set_title('18.3')
axs[1,1].set_title('18.4')


xticks = [1, 2, 3, 4, 5, 6, 7, 8]
yticks = np.arange(5, 40, 5)

for ax in axs.flat:
    # set x and y axis labels and tick marks
    ax.set(xlabel='displacement (l)', ylabel='fuel economy (mpg)', xticks=xticks, yticks=yticks)

    # Hide x labels and tick labels for top plots and y ticks for right plots.
    ax.label_outer()


fig.tight_layout()
plt.show()



























































# eof
