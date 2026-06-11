import matplotlib.pyplot as plt
import numpy as np
import matplotlib.colors as mcolors

# -----------------------------
# Colormap for altitude
# -----------------------------
vmin, vmax = -300, 3000
norm = mcolors.TwoSlopeNorm(vmin=vmin, vcenter=0, vmax=vmax)

colors_ocean = plt.cm.Blues_r(np.linspace(0.3, 0.9, 128))
colors_land = plt.cm.terrain(np.linspace(0.25, 1.0, 128))
all_colors = np.vstack([colors_ocean, colors_land])

custom_cmap = mcolors.LinearSegmentedColormap.from_list(
    "topo", all_colors
)

# -----------------------------
# Read altitude
# -----------------------------
altitude = np.loadtxt("altitude.txt")

# -----------------------------
# Read fertility
# -----------------------------
fertility = np.loadtxt("fertility.txt")

# -----------------------------
# Read tribe coordinates
# Format:
# x y
# x y
# ...
# -----------------------------
tribes = np.loadtxt("tribe.txt")

# Handle single-point file
tribes = np.atleast_2d(tribes)

x = tribes[:, 0]
y = tribes[:, 1]

# -----------------------------
# Altitude map + tribe points
# -----------------------------
plt.figure(figsize=(10, 8))

img = plt.imshow(
    altitude,
    cmap=custom_cmap,
    norm=norm,
    origin="lower"
)

plt.scatter(
    x,
    y,
    c="red",
    s=30,
    edgecolors="black",
    linewidths=0.5,
    label="Tribes"
)

plt.colorbar(img, label='Elevation (m)')
plt.title("Altitude Map with Tribes")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.show()

"""# -----------------------------
# Fertility map + tribe points
# -----------------------------
plt.figure(figsize=(10, 8))

img = plt.imshow(
    fertility,
    cmap="Greens",
    origin="lower"
)

plt.scatter(
    x,
    y,
    c="red",
    s=30,
    edgecolors="black",
    linewidths=0.5,
    label="Tribes"
)

plt.colorbar(img, label='Elevation (m)')
plt.title("Fertility Map with Tribes")
plt.xlabel("X")
plt.ylabel("Y")
plt.legend()
plt.show()"""