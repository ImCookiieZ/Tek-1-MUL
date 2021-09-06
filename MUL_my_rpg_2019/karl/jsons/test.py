import sys
import json

# Open and load json file
import glob


def main():
    jsonfiles = []
    for file in glob.glob("*.json"):
        jsonfiles.append(file)
    array = get_names()
    for cur in jsonfiles:
        with open(cur) as file:
            file_json = json.load(file)
        # Get and set variables we need
        for it in file_json['layers']:
            if it['name'] == 'collisions':
                data = it['data']
                height = it['height']
                width = it['width']
                a_size = height * width

        # Create a new file to store the C array
        new_file = open("../../collisions/" + cur[:-5] + ".txt", "w")
        # Fill the array in the C file
        i_width = 0
        print(cur)
        for i in range(len(array)):
            for j in range(len(array[i])):
                if array[i][j] == cur[:-5]:
                    new_file.write(str(i) + '\n')
                    new_file.write(str(j) + '\n')

        for i in range(a_size):
            if i_width == width - 1:
                i_width = 0
                new_file.write(str(data[i]) + "\n")
            else:
                i_width += 1
                new_file.write(str(data[i]) + " ")
        for it in file_json['layers']:
            if it['name'] == 'link':
                data = it['data']
                height = it['height']
                width = it['width']
                a_size = height * width

        # Create a new file to store the C array
        new_file = open("../../links/" + cur[:-5] + ".txt", "w")
        # Fill the array in the C file
        i_width = 0
        print(cur)
        for i in range(len(array)):
            for j in range(len(array[i])):
                if array[i][j] == cur[:-5]:
                    new_file.write(str(i) + '\n')
                    new_file.write(str(j) + '\n')

        for i in range(a_size):
            if i_width == width - 1:
                i_width = 0
                new_file.write(str(data[i]) + "\n")
            else:
                i_width += 1
                new_file.write(str(data[i]) + " ")


def get_names():
    name_array = []
    name_line = []
    name_array.append("NULL")
    name_array.append("NULL")
    name_array.append("NULL")
    name_array.append("boss_map")
    name_array.append("NULL")
    name_array.append("gras_3")
    name_array.append("gras_5")
    name_line.append(name_array)
    name_array = []
    name_array.append("NULL")
    name_array.append("cave_2")
    name_array.append("cave_1")
    name_array.append("main")
    name_array.append("gras_1")
    name_array.append("gras_2")
    name_array.append("NULL")
    name_line.append(name_array)
    name_array = []
    name_array.append("NULL")
    name_array.append("cave_4")
    name_array.append("NULL")
    name_array.append("water_4")
    name_array.append("NULL")
    name_array.append("gras_4")
    name_array.append("NULL")
    name_line.append(name_array)
    name_array = []
    name_array.append("cave_5")
    name_array.append("cave_3")
    name_array.append("NULL")
    name_array.append("water_2")
    name_array.append("water_5")
    name_array.append("NULL")
    name_array.append("NULL")
    name_line.append(name_array)
    name_array = []
    name_array.append("NULL")
    name_array.append("NULL")
    name_array.append("NULL")
    name_array.append("water_1")
    name_array.append("water_3")
    name_array.append("NULL")
    name_array.append("NULL")
    name_line.append(name_array)
    return name_line

main()