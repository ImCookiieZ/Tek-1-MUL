import sys
import json

# Open and load json file
with open(sys.argv[1]) as file:
    file_json = json.load(file)

# Get and set variables we need
for it in file_json['layers']:
    if it['name'] == 'background':
        data = it['data']
        height = it['height']
        width = it['width']
        a_size = height * width

# Create a new file to store the C array
new_file = open("collision.c", "w")
new_file.write("const int collision[" + str(height) + "][" + str(width) + "] = {\n")

# Fill the array in the C file
i_width = 0
for i in range(a_size):
    if i_width == 0:
        new_file.write("\t{")
    if i_width == width - 1:
        i_width = 0
        new_file.write(str(data[i]) + "},\n")
    else:
        i_width += 1
        new_file.write(str(data[i]) + " ,")
new_file.write("};")