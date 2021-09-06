# Open and load json file
import glob

jsonfiles = []
for file in glob.glob("*.json"):
    jsonfiles.append(file)

for cur in jsonfiles:
    with open(cur) as file:

