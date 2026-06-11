# get altitude.txt and print it as a 2dhistogram using matplotlib in python
# maintain row/column structure as in file
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.colors as mcolors

# Define sea level at 0, range is -300 to 3000
vmin, vmax = -300, 3000

# Position of sea level (0) within the colormap [0, 1]
sea_level = abs(vmin) / (vmax - vmin)  # = 0.0909...

# Build a two-segment colormap: ocean (blue) below 0, land (terrain) above
colors_ocean = plt.cm.Blues_r(np.linspace(0.3, 0.9, 128))   # deep→shallow blue
colors_land  = plt.cm.terrain(np.linspace(0.25, 1.0, 128))  # green→brown→white

all_colors = np.vstack([colors_ocean, colors_land])
custom_cmap = mcolors.LinearSegmentedColormap.from_list('topo', all_colors)
norm = mcolors.TwoSlopeNorm(vmin=vmin, vcenter=0, vmax=vmax)

# Read the altitude data from the text file
data = []
with open("altitude.txt", "r") as f:
    for line in f:
        row = [float(x) for x in line.split()]
        data.append(row)

# Convert to a numpy array
data = np.array(data)

# Create a 2D histogram
plt.imshow(data, cmap=custom_cmap, norm=norm, origin='lower')
plt.colorbar(label='Elevation (m)')
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
plt.imshow(data2, cmap='Greens', origin='lower')
plt.colorbar(label='Fertility')
plt.title('Fertility Map')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.show()