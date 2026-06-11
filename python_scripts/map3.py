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
# Read data
# -----------------------------
altitude = np.loadtxt("altitude.txt")
humidity = np.loadtxt("humidity.txt")
vegetation = np.loadtxt("vegetation.txt")

# -----------------------------
# Create side-by-side figure
# -----------------------------
fig, (ax1, ax2, ax3) = plt.subplots(
    1, 3,
    figsize=(16, 8),
    constrained_layout=True
)

# -----------------------------
# Altitude map
# -----------------------------
img1 = ax1.imshow(
    altitude,
    cmap=custom_cmap,
    norm=norm,
    origin="lower"
)

ax1.set_title("Altitude Map")
ax1.set_xlabel("X")
ax1.set_ylabel("Y")

cbar1 = fig.colorbar(
    img1,
    ax=ax1,
    shrink=0.8
)
cbar1.set_label("Elevation (m)")

# -----------------------------
# Humidity map
# -----------------------------
img2 = ax2.imshow(
    humidity,
    cmap="Blues",
    origin="lower"
)

ax2.set_title("Humidity Map")
ax2.set_xlabel("X")
ax2.set_ylabel("Y")

cbar2 = fig.colorbar(
    img2,
    ax=ax2,
    shrink=0.8
)
cbar2.set_label("Humidity")

# -----------------------------
# Vegetation map
# -----------------------------
img3 = ax3.imshow(
    vegetation,
    cmap="Greens",
    origin="lower"
)

ax3.set_title("Vegetation Map")
ax3.set_xlabel("X")
ax3.set_ylabel("Y")

cbar3 = fig.colorbar(
    img3,
    ax=ax3,
    shrink=0.8
)
cbar3.set_label("Vegetation")

plt.show()