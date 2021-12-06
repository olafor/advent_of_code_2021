#!/usr/bin/python3
# Dag 5 - Lanternfish

stimm = []
with open("LanternfishInput.txt") as fd:
    for element in fd:
        stimm.append(element.strip())

stimm = stimm[0].split(",")
stimm = [int(x) for x in stimm]
newFish = []
days = 80

while days > 0:
    for i in range(0, len(stimm)):
        if stimm[i] == 0:
            newFish.append(8)
            stimm[i] = 7

        stimm[i] -= 1

    if len(newFish) > 0:
        stimm.extend(newFish)
        newFish.clear()
    days -= 1

print(len(stimm))
