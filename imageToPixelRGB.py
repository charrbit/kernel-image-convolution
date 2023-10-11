import sys
import numpy as np
from PIL import Image

# Get image path from the script argument list
imagePath = sys.argv[1]

# Load the image
image = Image.open(imagePath)
imageMode = image.mode
imageSize = image.size

# Seperate the image into red, green, and blue bands
redBand = np.array(image.getdata(0))
greenBand = np.array(image.getdata(1))
blueBand = np.array(image.getdata(2))

# Write the band pixel values to their respective files
np.savetxt("imageRed.txt", redBand, fmt='%i')
np.savetxt("imageGreen.txt", greenBand, fmt='%i')
np.savetxt("imageBlue.txt", blueBand, fmt='%i')