


filepath = 'C:/repos/laserbot/purple_NDC.txt'

with open(filepath, mode="r") as f:
    lines = f.readlines()

for line in lines:
    position1 = line.find("Raw")
    position2 = line.find(":", position1)
    if position2 > 0:
        newdata = line[position2:]