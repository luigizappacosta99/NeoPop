# get altitude.txt and print it as a 2dhistogram using matplotlib in python
# maintain row/column structure as in file
import matplotlib.pyplot as plt
import numpy as np

# Read the altitude data from the text file
data = []
with open("altitude.txt", "r") as f:
    for line in f:
        row = [float(x) for x in line.split()]
        data.append(row)

# Convert to a numpy array
data = np.array(data)

# Create a 2D histogram
plt.imshow(data, cmap='terrain', origin='lower')
plt.colorbar(label='Altitude')
plt.title('Altitude Map')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.show()

# now do the same for fertility data
data2 = []
with open("fertility.txt", "r") as f:
    for line in f:
        row = [float(x) for x in line.split()]
        data2.append(row)

data2 = np.array(data2)
plt.imshow(data, cmap='Greens', origin='lower')
plt.colorbar(label='Fertility')
plt.title('Fertility Map')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.show()