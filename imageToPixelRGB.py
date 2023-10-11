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

# Write the size and mode of the original image to a configuration file
configFilename = "imageConfig.txt"
with open(configFilename, "w") as outFile:
    outFile.write(f"{imageMode}\n")
    outFile.write(f"{imageSize[0]}\n") # Width
    outFile.write(f"{imageSize[1]}\n") # Height